#include "Syscalls.h"

struct TreeNode {
    I64 value;
    struct TreeNode *left, *right;
};

struct QueueNode {
    struct TreeNode *treeNode;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

U0 QueueInit(struct Queue *q) {
    q->front = q->rear = NULL;
}

U0 Enqueue(struct Queue *q, struct TreeNode *node) {
    struct QueueNode *newNode = MAlloc(sizeof(struct QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

struct TreeNode* Dequeue(struct Queue *q) {
    if (q->front == NULL) return NULL;
    struct QueueNode *temp = q->front;
    struct TreeNode *tempNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    MFree(temp);
    return tempNode;
}

U0 BFS(struct TreeNode *root) {
    if (root == NULL) return;
    struct Queue q;
    QueueInit(&q);
    Enqueue(&q, root);
    while (q.front != NULL) {
        struct TreeNode *node = Dequeue(&q);
        PrintF("%d ", node->value);
        if (node->left != NULL) Enqueue(&q, node->left);
        if (node->right != NULL) Enqueue(&q, node->right);
    }
}

U0 Main() {
    // Example tree:
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5

    struct TreeNode n4 = {4, NULL, NULL};
    struct TreeNode n5 = {5, NULL, NULL};
    struct TreeNode n2 = {2, &n4, &n5};
    struct TreeNode n3 = {3, NULL, NULL};
    struct TreeNode n1 = {1, &n2, &n3};

    BFS(&n1);
}
