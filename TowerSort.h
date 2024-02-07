#include <stdio.h>
#include <stdlib.h>

#include "LList.h"

/*
TOWER SORT :

Sort the given linked list in O(n*log2(k)) time complexity and O(1) space complexity.
Arguments :
    head - The head node of the linked list
    reverse - Set to 0 to sort normally, 1 to sort in descending order
*/
void TowerSort(LList* head, uchar reverse) {

    Node* undefined = malloc(sizeof(Node));

    // Loop control
    uchar level = 0;
    long brokenCeil = 1;
    uchar hasSign = 0;
    uchar checkSign = 0;
    long ceiling = 1;

    // Sorting variables
    long v;
    uchar b;
    uchar bprev;
    Node* firstOneEver;
    Node* oneStart;
    Node* oneEnd;
    Node* lastDiff;
    Node* prev;
    Node* current;
    Node* next;

    while (brokenCeil || hasSign) {
        
        ceiling *= 2; // Power ceiling

        // Sorting variables
        firstOneEver = NULL;
        oneStart = NULL;
        oneEnd = undefined;
        lastDiff = undefined;
        prev = NULL;
        bprev = 2; // 2 for undefined
        current = NULL;
        next = *head;
        
        // Check if continue or check sign (top of the tower)
        if (!brokenCeil) { // Only possibility is having a sign
            checkSign = 1;
            hasSign = 0;
        }
        brokenCeil = 0;

        // Loop through all elements
        while (next != NULL) {
            current = next;
            next = current->next;
            
            // Define bit value to sort
            v = current->v;
            if (checkSign)
                b = v >= 0 ? 1 : 0;
            else {
                if (v < 0) {
                    v = -v;
                    b = !((v >> level) & 1);
                    hasSign = 1;
                }
                else
                    b = (v >> level) & 1;
                if (v >= ceiling) // If breaks the ceiling, there's more to check
                    brokenCeil++;
            }
            if (reverse)
                b = !b;

            // Main sorting logic

            if (b) { // == 1
                if (bprev != 1) {
                    if (firstOneEver == NULL)
                        firstOneEver = current;
                    oneStart = prev;
                    oneEnd->next = current;
                    if (!bprev) // == 0
                        lastDiff = prev;
                }
                if (next == NULL) {
                    lastDiff->next = firstOneEver;
                    current->next = NULL;
                }
            }
            else { // == 0
                if (bprev == 1) {
                    oneEnd = prev;
                    if (oneStart == NULL)
                        *head = current;
                    else
                        oneStart->next = current;
                    lastDiff = prev;
                }
                if (next == NULL) {
                    lastDiff->next = NULL;
                    current->next = firstOneEver;
                }
            }
            bprev = b;
            prev = current;
        }
        level++; // Next bit in hierarchy
    }
}