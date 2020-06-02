# union by rank and path compression
from collections import defaultdict


class Subset:
    def __init__(self, parent, rank):
        self.parent = parent
        self.rank = rank

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def find(self, subsets, node):
        if subsets[node].parent == node:
            return node
        else:
            subsets[node].parent = self.find(subsets, subsets[node].parent)
            return subsets[node].parent

    def union(self, subsets, x, y):
        if subsets[x].rank > subsets[y].rank:
            subsets[y].parent = x
        elif subsets[y].rank > subsets[x].rank:
            subsets[x].parent = y
        else:
            subsets[y].parent = x
            subsets[x].rank += 1

    def isCyclic(self):
        subsets = [Subset(i, 0) for i in range(self.V)]

        for i in self.graph:
            for j in self.graph[i]:

                x = self.find(subsets, i)
                y = self.find(subsets, j)
                if x == y:
                    return True
                self.union(subsets, x, y)
                
g = Graph(3)
g.addEdge(0, 1)
g.addEdge(1, 2)
g.addEdge(2, 0)

if g.isCyclic():
    print("Graph contains cycle.")
else:
    print("Graph does not contain cycle.")