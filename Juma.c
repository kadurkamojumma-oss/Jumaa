#include <stdio.h>
#include <string.h>

#define SIZE 5

typedef struct {
    char arr[SIZE];
    int head;
    int tail;
    int count;
} CB;

void init(CB *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int full(CB *cb) {
    if (cb->count == SIZE)
        return 1;
    else
        return 0;
}

int empty(CB *cb) {
    if (cb->count == 0)
        return 1;
    else
        return 0;
}

void write(CB *cb, char x) {
    if (full(cb)) {
        printf("Buffer Overflow\n");
        return;
    }
    cb->arr[cb->tail] = x;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count = cb->count + 1;
}

char read(CB *cb) {
    char x;
    if (empty(cb)) {
        printf("Buffer Underflow\n");
        return 0;
    }
    x = cb->arr[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count = cb->count - 1;
    return x;
}

int main() {
    CB cb;
    init(&cb);

    char name[50];
    char full[100];
    char c;
    int i;

    printf("Enter your name: ");
    scanf("%s", name);

    strcpy(full, name);
    strcat(full, "CE-ESY");

    printf("Full name: %s\n", full);

    for (i = 0; i < strlen(full); i++) {
        write(&cb, full[i]);
    }

    printf("Output: ");
    while (!empty(&cb)) {
        c = read(&cb);
        printf("%c", c);
    }
    printf("\n");

    if (empty(&cb)) {
        printf("Buffer is empty.\n");
    }

    return 0;
}
