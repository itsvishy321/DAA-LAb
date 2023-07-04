#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node {
    int id;         // unique identifier for the node
    int distance;   // shortest distance from source to this node
    bool visited;   // true if the node has been visited
    vector<pair<Node*, int>> neighbors;  // list of neighboring nodes and their edge weights
    Node(int _id) {
        id = _id;
        distance = INT_MAX;
        visited = false;
    }
};

// A comparison function for the priority queue
struct CompareNodes {
    bool operator() (const Node* a, const Node* b) {
        return a->distance > b->distance;
    }
};

// Dijkstra's algorithm for finding the shortest paths from a source node to all other nodes
void dijkstra(Node* source) {
    // Set the distance of the source node to 0
    source->distance = 0;

    // Create a priority queue of nodes ordered by their distances
    priority_queue<Node*, vector<Node*>, CompareNodes> pq;
    pq.push(source);

    // Process nodes until the queue is empty
    while (!pq.empty()) {
        // Get the node with the shortest distance from the priority queue
        Node* curr = pq.top();
        pq.pop();

        // If the node has already been visited, skip it
        if (curr->visited) {
            continue;
        }

        // Mark the node as visited
        curr->visited = true;

        // Update the distances of all neighboring nodes
        for (auto& neighbor : curr->neighbors) {
            Node* next = neighbor.first;
            int weight = neighbor.second;
            int newDistance = curr->distance + weight;
            if (newDistance < next->distance) {
                next->distance = newDistance;
                pq.push(next);
            }
        }
    }
}

int main() {
    // Create the graph
    vector<Node*> graph;
    for (int i = 0; i < 5; i++) {
        graph.push_back(new Node(i));
    }
    graph[0]->neighbors = {{graph[1], 9}, {graph[2], 6}, {graph[3], 5}};
    graph[1]->neighbors = {{graph[4], 3}};
    graph[2]->neighbors = {{graph[1], 2}, {graph[3], 4}};
    graph[3]->neighbors = {{graph[2], 7}, {graph[4], 1}};
    graph[4]->neighbors = {};

    // Run Dijkstra's algorithm on the graph
    dijkstra(graph[0]);

    // Print the shortest distances to all nodes from the source
    for (int i = 0; i < graph.size(); i++) {
        cout << "Shortest distance from node 0 to node " << i << " is " << graph[i]->distance << endl;
    }

    // Clean up the graph
    for (auto node : graph) {
        delete node;
    }

    return 0;
}
