#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uchar;

typedef struct Node {
    long v;
    struct Node* next;
} Node;

typedef struct Node* LList;

Node* addNode(LList list, long val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->v = val;
    newNode->next = list;
    return newNode;
}

void dispList(LList list) {
    Node* current = list;
    while (current != NULL) {
        printf("%ld ", current->v);
        current = current->next;
    }
    printf("\n");
}

void freeList(LList list) {
    Node* current = list;
    Node* temp;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
}