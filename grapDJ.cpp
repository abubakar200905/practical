#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

const int INF = INT_MAX; // Infinity value for no path

// Function to find the node with the minimum distance from the set of unvisited nodes
int minDistance(const vector<int>& dist, const vector<bool>& visited, int n) {
    int min = INF, minIndex;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Dijkstra's Algorithm to find the shortest path from source to all other nodes
void dijkstra(const vector<vector<int>>& graph, int source, int n) {
    vector<int> dist(n, INF); // Distance array initialized to INF
    vector<bool> visited(n, false); // Boolean array to track visited nodes
    dist[source] = 0; // Distance to source is 0

    // Loop through all nodes
    for (int count = 0; count < n - 1; count++) {
        // Find the unvisited node with the minimum distance
        int u = minDistance(dist, visited, n);

        visited[u] = true; // Mark the node as visited

        // Update distance for each adjacent node
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v]; // Relaxation step
            }
        }
    }

    // Print the final distances
    cout << "Shortest distances from source node " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To node " << i << " : ";
        if (dist[i] == INF) {
            cout << "No path\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
}

int main() {
    int n; // Number of landmarks
    cout << "Enter the number of landmarks: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, INF));

    // Input graph data (adjacency matrix)
    cout << "Enter the adjacency matrix (use " << INF << " for no direct path):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int source;
    cout << "Enter the source node (0 to " << n-1 << "): ";
    cin >> source;

    // Run Dijkstra's Algorithm
    dijkstra(graph, source, n);

    return 0;
}
