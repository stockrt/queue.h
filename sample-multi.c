#include <stdio.h>
#include <stdlib.h>
#include "shannon.c"
#include "queue.h"

// Left-alone struct (no _ENTRY pointers here).
typedef struct data_s data_t;
struct data_s {
    int value;
};

// Node with a pointer to the actual data.
typedef struct tailqnode_s tailqnode_t;
struct tailqnode_s {
    data_t *dp;
    //void *dp;
    TAILQ_ENTRY(tailqnode_s) entries;
};

// MAIN.
int main(int argc, char *argv[]) {
    int n=0, i=0;
    data_t *datap=NULL;
    tailqnode_t *nodep=NULL;

    // Usage.
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return EXIT_FAILURE;
    }

    n = atoi(argv[1]);

    TAILQ_HEAD(first_tailqhead, tailqnode_s) first_head;
    TAILQ_INIT(&first_head);

    TAILQ_HEAD(second_tailqhead, tailqnode_s) second_head;
    TAILQ_INIT(&second_head);

    // Write.
    for (i=0; i<n; i++) {
        datap = malloc(sizeof(data_t));
        datap->value = (int) (randshannon() * 1000.);
        printf("Insert: %d\n", datap->value);

        // first_head
        nodep = malloc(sizeof(tailqnode_t));
        nodep->dp = datap;
        TAILQ_INSERT_TAIL(&first_head, nodep, entries);

        // second_head
        nodep = malloc(sizeof(tailqnode_t));
        nodep->dp = datap;
        TAILQ_INSERT_HEAD(&second_head, nodep, entries);
    }
    printf("\n");

    // Read1.
    TAILQ_FOREACH(nodep, &first_head, entries) {
        printf("Read1 first_head: %d\n", nodep->dp->value);
    }
    TAILQ_FOREACH(nodep, &second_head, entries) {
        printf("Read1 second_head: %d\n", nodep->dp->value);
    }
    printf("\n");

    // Read2 (remove).
    while (!TAILQ_EMPTY(&first_head)) {
        nodep = TAILQ_FIRST(&first_head);
        printf("Read2 first_head: %d\n", nodep->dp->value);
        TAILQ_REMOVE(&first_head, nodep, entries);
        free(nodep);
    }
    while (!TAILQ_EMPTY(&second_head)) {
        nodep = TAILQ_FIRST(&second_head);
        printf("Read2 second_head: %d\n", nodep->dp->value);
        TAILQ_REMOVE(&second_head, nodep, entries);
        free(nodep->dp);
        free(nodep);
    }

    return EXIT_SUCCESS;
}
