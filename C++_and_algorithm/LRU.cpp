#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <list>

using namespace std;

struct Node
{
    int key;
    int value;
    Node *pre;
    Node *next;
};

class LRUCache
{
private:
    int count;
    int size;
    map<int, Node *> mp;
    Node *cacheHead;
    Node *cacheTail;
public:
    LRUCache(int capacity)
    {
        size = capacity;
        cacheHead = NULL;
        cacheTail = NULL;
        count = 0;
    }

    int get(int key)
    {
        if(cacheHead == NULL)
            return -1;
        map<int, Node *>::iterator it = mp.find(key);
        if(it == mp.end()){
            return -1;
        }
        else{
            Node *p = it->second;
            pushFront(p);
        }
        return cacheHead->value;
    }

    void set(int key, int value)
    {
        if(cacheHead == NULL)
        {
            cacheHead = (Node *)malloc(sizeof(Node));
            cacheHead->key = key;
            cacheHead->value = value;
            cacheHead->pre = NULL;
            cacheHead->next = NULL;
            mp[key] = cacheHead;
            cacheTail = cacheHead;
            count++;
        }
        else
        {
            map<int, Node*>::iterator it = mp.find(key);
            if(it==mp.end())
            {
                if(count==size)
                {
                    if(cacheHead==cacheTail&&cacheHead!=NULL)
                    {
                        mp.erase(cacheHead->key);
                        cacheHead->key = key;
                        cacheHead->value = value;
                        mp[key] = cacheHead;
                    }
                    else
                    {
                        Node *p = cacheTail;
                        cacheTail->pre->next = cacheTail->next;
                        cacheTail = cacheTail->pre;

                        mp.erase(p->key);

                        p->key = key;
                        p->value = value;

                        p->next = cacheHead;
                        p->pre = cacheHead->pre;
                        cacheHead->pre = p;
                        cacheHead = p;
                        mp[cacheHead->key] = cacheHead;
                    }
                    
                }
                else
                {
                    Node * p = (Node *)malloc(sizeof(Node));
                    p->key = key;
                    p->value = value;

                    p->next = cacheHead;
                    p->pre = NULL;
                    cacheHead->pre = p;
                    cacheHead = p;
                    mp[cacheHead->key] = cacheHead;
                    count ++;
                }
                
            }
            else
            {
                Node *p = it->second;
                p->value = value;
                pushFront(p);
            }
            
        }
        
    }


    void pushFront(Node *cur)
    {
        if(count==1)
            return;
        if(cur==cacheHead)
            return;
        if(cur==cacheTail)
            cacheTail = cur->pre;
        
        cur->pre->next = cur->next;
        if(cur->next!=NULL)
            cur->next->pre = cur->pre;
        cur->next = cacheHead;
        cur->pre = NULL;
        cacheHead->pre = cur;
        cacheHead = cur;
    }

    void printCache()
    {
        Node *p =cacheHead;
        while(p!=NULL)
        {
            cout << p->key << " ";
            p=p->next;
        }
        cout << endl;
    }
    
};



int main()
{

    LRUCache cache(3);

    cache.set(1, 1);
    cache.set(2, 2);
    cache.set(3, 3);
    cache.set(4, 4);

    cout<<cache.get(4)<<endl;
    cache.printCache();

    
}


