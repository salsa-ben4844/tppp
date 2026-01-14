#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct SNode {
    char data;
    struct SNode *next;
} SNode;

typedef struct QNode {
    char data;
    struct QNode *next;
} QNode;

/* -------- Queue Structure -------- */
typedef struct {
    QNode *front;
    QNode *rear;
} Queue;

/* -------- Stack Functions -------- */
SNode* push(SNode *top, char ch) {
    SNode *newNode = (SNode *)malloc(sizeof(SNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = ch;
    newNode->next = top;
    return newNode;
}

SNode* pop(SNode *top, char *value) {
    if (top == NULL)
        return NULL;

    SNode *temp = top;
    *value = temp->data;
    top = temp->next;
    free(temp);
    return top;
}


void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue *q, char ch) {
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = ch;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue *q, char *value) {
    if (q->front == NULL)
        return;

    QNode *temp = q->front;
    *value = temp->data;
    q->front = temp->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

/* -------- Main Program -------- */
int main() {
    char str[200];
    SNode *top = NULL;
    Queue q;
    initQueue(&q);

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove newline character */
    str[strcspn(str, "\n")] = '\0';

    /* Fill stack and queue */
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            char ch = toupper(str[i]);
            top = push(top, ch);
            enqueue(&q, ch);
        }
    }

    /* Compare */
    char sVal, qVal;
    int isPalindrome = 1;

    while (top != NULL && q.front != NULL) {
        top = pop(top, &sVal);
        dequeue(&q, &qVal);

        if (sVal != qVal) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
