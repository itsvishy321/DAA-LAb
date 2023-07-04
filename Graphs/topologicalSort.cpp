#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    void checkk(int v, bool visited[], stack<int> &s);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void topSort();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w) { adj[v].push_back(w); }
void Graph::checkk(int v, bool visited[], stack<int> &s)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            checkk(*i, visited, s);
    s.push(v);
}
void Graph::topSort()
{
    stack<int> s;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            checkk(i, visited, s);
    while (s.empty() == false)
    {
        cout << s.top() << " ";
        s.pop();
    }
    delete[] visited;
}
int main()
{
    int n;
    cout << "No. of vertices: " << endl;
    cin >> n;
    Graph g(n);
    int count;
    cout << "NO of edges" << endl;
    cin >> count;
    cout << "Enter Edges between vertex in (u,v) fashion" << endl;
    for (int i = 0; i < count; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << "Topological Sort" << endl;
    g.topSort();
    return 0;
}