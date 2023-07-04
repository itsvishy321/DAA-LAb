#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (DSU) data structure
struct DSU
{
    vector<int> parent;
    vector<int> rank;

    // Initialize DSU with n disjoint sets
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find the parent of a node in a set
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Merge two sets by rank
    void merge(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x == root_y)
            return;

        if (rank[root_x] < rank[root_y])
        {
            parent[root_x] = root_y;
        }
        else if (rank[root_x] > rank[root_y])
        {
            parent[root_y] = root_x;
        }
        else
        {
            parent[root_y] = root_x;
            rank[root_x]++;
        }
    }

    // Check if two nodes belong to the same set
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

// Edge struct with source, destination and weight
struct Edge
{
    int u;
    int v;
    int w;

    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

// Kruskal's algorithm to find Minimum Spanning Tree
vector<Edge> kruskal(vector<Edge> &edges, int n)
{
    // Initialize DSU
    DSU dsu(n);

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.w < b.w; });

    vector<Edge> mst;

    // Iterate over sorted edges and add to MST if it doesn't create a cycle
    for (auto e : edges)
    {
        if (!dsu.same(e.u, e.v))
        {
            dsu.merge(e.u, e.v);
            mst.push_back(e);
        }
    }

    return mst;
}

// Example usage
int main()
{
    int n = 6;
    vector<Edge> edges = {Edge(1, 2, 2), Edge(1, 3, 9), Edge(2, 3, 3), Edge(2, 4, 1), Edge(3, 5, 4), Edge(4, 5, 2)};
    vector<Edge> mst = kruskal(edges, n);
    int mspWeight = 0;

    cout << endl << "Minimum Spanning Tree:\n";
    for (auto e : mst)
    {
        cout << e.u << " - " << e.v << " : " << e.w << "\n";
        mspWeight += e.w;
    }

    cout<<"Minimum Spanning Tree Weight : "<< mspWeight<<endl<<endl;

    return 0;
}
