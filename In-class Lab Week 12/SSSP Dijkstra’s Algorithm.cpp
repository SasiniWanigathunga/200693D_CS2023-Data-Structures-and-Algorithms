#include <iostream>
#include <limits>
using namespace std;

#define INFINITY 9999
#define MAX_NODES 6

void dijkstra(int G[MAX_NODES][MAX_NODES], int numNodes, int startNode) {
    int cost[MAX_NODES][MAX_NODES], distance[MAX_NODES], pred[MAX_NODES];
    bool visited[MAX_NODES];
    int count, mindistance, nextnode, i, j;

    // Initialize cost matrix and distance array
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
        }
    }

    for (i = 0; i < numNodes; i++) {
        distance[i] = cost[startNode][i];
        pred[i] = startNode;
        visited[i] = false;
    }

    distance[startNode] = 0;
    visited[startNode] = true;
    count = 1;

    while (count < numNodes - 1) {
        mindistance = INFINITY;

        // Find the node with the minimum distance
        for (i = 0; i < numNodes; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = true;
        for (i = 0; i < numNodes; i++) {
            if (!visited[i] && (mindistance + cost[nextnode][i] < distance[i])) {
                distance[i] = mindistance + cost[nextnode][i];
                pred[i] = nextnode;
            }
        }
        count++;
    }

    // Print the distance and path of each node
    for (i = 0; i < numNodes; i++) {
        if (i != startNode) {
            cout << "Time taken from node " << startNode << " to " << i << " = " << distance[i] << endl;
            cout << "Path: " << i;

            j = i;
            do {
                j = pred[j];
                cout << " <- " << j;
            } while (j != startNode);

            cout << endl;
        }
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };
    int numNodes = 6;
    for (int i=0; i<6; i++){
        int startNode = i;  
        cout << "start node: " << startNode << endl;
        dijkstra(graph, numNodes, startNode);
        cout << endl;
    }
    

    

    return 0;
}
