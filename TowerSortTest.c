#include <math.h>
#include <time.h>
#include <sys/time.h>

#include "TowerSort.h"

uchar isSorted(LList list) {

    Node* current = list->next;
    long vprev = list->v;
    while (current != NULL) {
        if (vprev > current->v)
            return 0;
        current = current->next;
    }
    return 1;
}

struct timeval testSort(long n, long range, uchar display) {
    
    struct timeval tval_before, tval_after, tval_result;

    // Random data
    int bits = ceil(log2f(range));
    printf("[Sorting on %d bits + sign]\n", bits);
    LList list = NULL;
    for (long i = 0; i < n; i++) {
        long r = rand() % (range * 2 - 1) - range + 1;
        list = addNode(list, r);
    }
    if (display) {
        printf("\nRandom data :\n\n");
        dispList(list);
    }

    // Execution
    gettimeofday(&tval_before, NULL);
    TowerSort(&list, 0);
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);

    // Verif
    if (display) {
        printf("\nAfter sorting :\n\n");
        dispList(list);
        printf("\n");
    }
    if (!isSorted(list)) {
        printf("!!! NOT SORTED !!!\n");
        dispList(list);
    }
    else
        printf("Sorted !\n");

    freeList(list);

    return tval_result;
}

int main(int argc, char* argv[]) {
    
    // Arguments
    if (argc < 3) {
        printf("Usage : %s <n> <range> <print?>\n", argv[0]);
        return 1;
    }
    long n = atol(argv[1]);
    long range = atol(argv[2]);
    if (n <= 0 || range <= 0) {
        printf("Invalid values, <n> and <range> must be positive integers.\n");
        return 1;
    }
    uchar display = 0;
    if (argc == 4 && atol(argv[3]) == 1)
        display = 1;

    srand(time(NULL)); 
    struct timeval time_result;
    
    time_result = testSort(n, range, display);
    printf("Execution time : %ld.%06ld second(s).\n", (long int) time_result.tv_sec, (long int) time_result.tv_usec);

    return 0;
}