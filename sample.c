#include <stdio.h>
#include <stdlib.h>
#include "shannon.c"
#include "queue.h"

// SLIST.
typedef struct slist_data_s slist_data_t;
struct slist_data_s {
    int value;
    SLIST_ENTRY(slist_data_s) entries;
};

// SLIST.
void slist(int n) {
    int i=0;
    slist_data_t *datap=NULL;

    SLIST_HEAD(slisthead, slist_data_s) head;
    SLIST_INIT(&head);

    // Write.
    for (i=0; i<n; i++) {
        datap = malloc(sizeof(slist_data_t));
        datap->value = (int) (randshannon() * 1000.);
        printf("Insert: %d\n", datap->value);
        SLIST_INSERT_HEAD(&head, datap, entries);
    }
    printf("\n");

    // Read1.
    SLIST_FOREACH(datap, &head, entries) {
        printf("Read1: %d\n", datap->value);
    }
    printf("\n");

    // Read2 (remove).
    while (!SLIST_EMPTY(&head)) {
        datap = SLIST_FIRST(&head);
        printf("Read2: %d\n", datap->value);
        SLIST_REMOVE_HEAD(&head, entries);
        free(datap);
    }
}

// LIST.
typedef struct list_data_s list_data_t;
struct list_data_s {
    int value;
    LIST_ENTRY(list_data_s) entries;
};

// LIST.
void list(int n) {
    int i=0;
    list_data_t *datap=NULL;

    LIST_HEAD(listhead, list_data_s) head;
    LIST_INIT(&head);

    // Write.
    for (i=0; i<n; i++) {
        datap = malloc(sizeof(list_data_t));
        datap->value = (int) (randshannon() * 1000.);
        printf("Insert: %d\n", datap->value);
        LIST_INSERT_HEAD(&head, datap, entries);
    }
    printf("\n");

    // Read1.
    LIST_FOREACH(datap, &head, entries) {
        printf("Read1: %d\n", datap->value);
    }
    printf("\n");

    // Read2 (remove).
    while (!LIST_EMPTY(&head)) {
        datap = LIST_FIRST(&head);
        printf("Read2: %d\n", datap->value);
        LIST_REMOVE(datap, entries);
        free(datap);
    }
}

// STAILQ.
typedef struct stailq_data_s stailq_data_t;
struct stailq_data_s {
    int value;
    STAILQ_ENTRY(stailq_data_s) entries;
};

// STAILQ.
void stailq(int n) {
    int i=0;
    stailq_data_t *datap=NULL;

    STAILQ_HEAD(stailqhead, stailq_data_s) head;
    STAILQ_INIT(&head);

    // Write1 (head).
    for (i=0; i<n; i++) {
        datap = malloc(sizeof(stailq_data_t));
        datap->value = (int) (randshannon() * 1000.);
        printf("Insert head: %d\n", datap->value);
        STAILQ_INSERT_HEAD(&head, datap, entries);
    }
    printf("\n");

    // Read1.
    STAILQ_FOREACH(datap, &head, entries) {
        printf("Read1: %d\n", datap->value);
    }
    printf("\n");

    // Read2 (remove).
    while (!STAILQ_EMPTY(&head)) {
        datap = STAILQ_FIRST(&head);
        printf("Read2: %d\n", datap->value);
        STAILQ_REMOVE_HEAD(&head, entries);
        free(datap);
    }
    printf("\n");

    // Write2 (tail).
    for (i=0; i<n; i++) {
        datap = malloc(sizeof(stailq_data_t));
        datap->value = (int) (randshannon() * 1000.);
        printf("Insert tail: %d\n", datap->value);
        STAILQ_INSERT_TAIL(&head, datap, entries);
    }
    printf("\n");

    // Read1.
    STAILQ_FOREACH(datap, &head, entries) {
        printf("Read1: %d\n", datap->value);
    }
    printf("\n");

    // Read2 (remove).
    while (!STAILQ_EMPTY(&head)) {
        datap = STAILQ_FIRST(&head);
        printf("Read2: %d\n", datap->value);
        STAILQ_REMOVE_HEAD(&head, entries);
        free(datap);
    }
}

// TAILQ.
typedef struct tailq_data_s tailq_data_t;
struct tailq_data_s {
    int value;
    TAILQ_ENTRY(tailq_data_s) entries;
};

// TAILQ.
void tailq(int n) {
    int i=0;
    tailq_data_t *datap=NULL;

    TAILQ_HEAD(tailqhead, tailq_data_s) head;
    TAILQ_INIT(&head);


    // Forward.
    printf("- Forward\n");

    // Write1 (head).
    for (i=0; i<n; i++) {
        datap = malloc(sizeof(tailq_data_t));
        datap->value = (int) (randshannon() * 1000.);
        printf("Insert head: %d\n", datap->value);
        TAILQ_INSERT_HEAD(&head, datap, entries);
    }
    printf("\n");

    // Read1.
    TAILQ_FOREACH(datap, &head, entries) {
        printf("Read1: %d\n", datap->value);
    }
    printf("\n");

    // Read2 (remove).
    while (!TAILQ_EMPTY(&head)) {
        datap = TAILQ_FIRST(&head);
        printf("Read2: %d\n", datap->value);
        TAILQ_REMOVE(&head, datap, entries);
        free(datap);
    }
    printf("\n");

    // Write2 (tail).
    for (i=0; i<n; i++) {
        datap = malloc(sizeof(tailq_data_t));
        datap->value = (int) (randshannon() * 1000.);
        printf("Insert tail: % d\n", datap->value);
        TAILQ_INSERT_TAIL(&head, datap, entries);
    }
    printf("\n");

    // Read1.
    TAILQ_FOREACH(datap, &head, entries) {
        printf("Read1: %d\n", datap->value);
    }
    printf("\n");

    // Read2 (remove).
    while (!TAILQ_EMPTY(&head)) {
        datap = TAILQ_FIRST(&head);
        printf("Read2: %d\n", datap->value);
        TAILQ_REMOVE(&head, datap, entries);
        free(datap);
    }
    printf("\n");


    // Reverse.
    printf("- Reverse\n");

    // Write1 (head).
    for (i=0; i<n; i++) {
        datap = malloc(sizeof(tailq_data_t));
        datap->value = (int) (randshannon() * 1000.);
        printf("Insert head: %d\n", datap->value);
        TAILQ_INSERT_HEAD(&head, datap, entries);
    }
    printf("\n");

    // Read1.
    TAILQ_FOREACH_REVERSE(datap, &head, tailqhead, entries) {
        printf("Read1: %d\n", datap->value);
    }
    printf("\n");

    // Read2 (remove).
    while (!TAILQ_EMPTY(&head)) {
        datap = TAILQ_LAST(&head, tailqhead);
        printf("Read2: %d\n", datap->value);
        TAILQ_REMOVE(&head, datap, entries);
        free(datap);
    }
    printf("\n");

    // Write2 (tail).
    for (i=0; i<n; i++) {
        datap = malloc(sizeof(tailq_data_t));
        datap->value = (int) (randshannon() * 1000.);
        printf("Insert tail: % d\n", datap->value);
        TAILQ_INSERT_TAIL(&head, datap, entries);
    }
    printf("\n");

    // Read1.
    TAILQ_FOREACH_REVERSE(datap, &head, tailqhead, entries) {
        printf("Read1: %d\n", datap->value);
    }
    printf("\n");

    // Read2 (remove).
    while (!TAILQ_EMPTY(&head)) {
        datap = TAILQ_LAST(&head, tailqhead);
        printf("Read2: %d\n", datap->value);
        TAILQ_REMOVE(&head, datap, entries);
        free(datap);
    }
}

// MAIN.
int main(int argc, char *argv[]) {
    // Usage.
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("### SLIST ###\n");
    printf("\n");
    slist(atoi(argv[1]));
    printf("\n\n");

    printf("### LIST ###\n");
    printf("\n");
    list(atoi(argv[1]));
    printf("\n\n");

    printf("### STAILQ ###\n");
    printf("\n");
    stailq(atoi(argv[1]));
    printf("\n\n");

    printf("### TAILQ ###\n");
    printf("\n");
    tailq(atoi(argv[1]));

    return EXIT_SUCCESS;
}
