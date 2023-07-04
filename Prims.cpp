#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<pair<int, int>> adj[MAXN];
int parent[MAXN], weight[MAXN];

void make_set(int v) {
    parent[v] = v;
    weight[v] = INT_MAX;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    parent[b] = a;
}

void prim(int start) {
    for (int i = 1; i <= MAXN; i++) {
        make_set(i);
    }
    weight[start] = 0;
    set<pair<int, int>> q;
    q.insert({0, start});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto edge : adj[v]) {
            int to = edge.first;
            int w = edge.second;
            if (w < weight[to]) {
                q.erase({weight[to], to});
                weight[to] = w;
                parent[to] = v;
                q.insert({weight[to], to});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    prim(1);
    int total_weight = 0;
    for (int i = 1; i <= n; i++) {
        total_weight += weight[i];
    }
    cout << total_weight << endl;
    return 0;
}
