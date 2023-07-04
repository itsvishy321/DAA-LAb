#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<int> >adj;
        void addEdge(int u, int v, bool direction){
            adj[u].push_back(v);
            if(direction == 0){
                adj[v].push_back(u);
            }
        }

        void printGraph(){
            for(auto i : adj){
                cout<<i.first<<" -> ";
                for(auto k : i.second){
                    cout<<k<<" , ";
                }cout<<endl;
            }
        }

        void BFSTraversal(int start, int n){
            int visited[n+1];
            fill_n(visited,n+1,0); 
            queue<int>q;
            q.push(start);
            visited[start] = 1;
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                cout<<temp<<" ";
                for(auto i : adj[temp]){
                    if(visited[i]==0){
                        q.push(i);
                        visited[i] = 1;
                    }
                }
            }cout<<endl;

        }
};

int main(){
    int n;
    cout<<"Enter the number of vertices in the graph"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges in the graph"<<endl;
    cin>>m;
    Graph g; 
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.printGraph();

    int startNode;
    cout<<"Enter a starting node"<<endl;
    cin>>startNode;
    g.BFSTraversal(startNode,n);
    return 0;
}
