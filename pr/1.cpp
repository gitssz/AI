#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;

class Graph{
    public:

    map<int, list<int>> adjList;    
    map<int, bool> visited;
    queue<int> q;
    
    void addEdge(int src, int dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void DFS(int node){
        visited[node] = true;
        cout << node << " ";
        for(int i : adjList[node]){
            if(!visited[i]) DFS(i);
        }
    }

    void BFS(){
        if(q.empty()) return;
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i : adjList[node]){  //iterating over neighbor i of the 'node'
             if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
        BFS(); //continue bfs traversal for next node if any n its neighbors
    }
};


int main(){
    Graph g;
    int n,a,b,ch;

    cout<<"Enter operation you wish to perform :\n1. DFS\n2. BFS\n";
    cin>>ch;

    cout<<"Enter no. of edges: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter vertices of edge "<<(i+1)<<": ";
        cin>>a>>b;
        g.addEdge(a,b);
    }

    switch(ch)
    {
        case 1:
            g.DFS(0);
        case 2:
            g.q.push(0);
            g.visited[0] = true;
            g.BFS();
    }
    

    return 0;
}