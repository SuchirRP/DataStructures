#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node* List;

int length(struct node* head) {
    struct node* current = head;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

struct node* BuildTwoThree() {
    struct node* head = NULL;
    struct node* second = NULL;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = NULL;

    return head;
}

void LinkTest() {
    struct node* head = BuildTwoThree();
    struct node* newNode;

    newNode = malloc(sizeof(struct node));
    newNode->data = 1;

    newNode->next = head;
    printf("Length = %d\n", length(newNode));
}

void WrongPush(struct node* head, int data) {
    struct node* newNode = malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = head;

    head = newNode;
}

void WrongPushTest() {
    List head = BuildTwoThree();

    printf("Length = %d\n", length(head));
    WrongPush(head, 1);

    printf("Length = %d\n", length(head));
}

void Push(struct node** headRef, int data) {
    struct node* newNode = malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

void PushTest() {
    struct node* head = BuildTwoThree();
    Push(&head, 1);
    printf("Length = %d\n", length(head));
    Push(&head, 13);
    printf("Length = %d\n", length(head));
}

int main() {
    PushTest();
}
