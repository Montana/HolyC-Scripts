#include "Syscalls.h"

struct Node {
    I64 value;
    struct Node* neighbors[10]; 
    I64 neighborsCount;
};

U0 AddNeighbor(struct Node* node, struct Node* neighbor) {
    node->neighbors[node->neighborsCount++] = neighbor;
}

U0 DFS(struct Node* node, I64* visited) {
    if (visited[node->value]) return;
    visited[node->value] = 1;
    PrintF("%d ", node->value);

    for (I64 i = 0; i < node->neighborsCount; i++) {
        DFS(node->neighbors[i], visited);
    }
}

U0 Main() {
    struct Node nodes[5];
    I64 visited[5] = {0};

    
    for (I64 i = 0; i < 5; i++) {
        nodes[i].value = i;
        nodes[i].neighborsCount = 0;
    }

    AddNeighbor(&nodes[0], &nodes[1]);
    AddNeighbor(&nodes[0], &nodes[2]);
    AddNeighbor(&nodes[1], &nodes[3]);
    AddNeighbor(&nodes[2], &nodes[3]);
    AddNeighbor(&nodes[3], &nodes[4]);

    
    DFS(&nodes[0], visited);
}
