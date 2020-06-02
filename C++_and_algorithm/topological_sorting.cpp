#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    queue<int> q;
    int* indegree;
public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    bool topological_sort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];

    indegree = new int[V];
    for(int i=0; i<V; i++)
        indegree[i] = 0;
}

Graph::~Graph()
{
    delete [] adj;
    delete [] indegree;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    ++indegree[w];
}

bool Graph::topological_sort()
{
    for(int i=0; i<V; ++i)
    {
        if(indegree[i]==0) q.push(i);
    }
    int count = 0;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        ++count;
        list<int>::iterator beg = adj[v].begin();
        for(; beg!=adj[v].end(); ++beg){
            if(!(--indegree[*beg])) q.push(*beg);
        }
    }
    if(count < V){
        return false;
    }else{
        return true;
    }
}

int main()
{
	Graph g(6);  
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	g.topological_sort();
	return 0;
}