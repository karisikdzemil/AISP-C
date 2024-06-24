//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//    int data;
//    struct node *link;
//};
//
//void print_data(struct node *head) {
//    struct node *ptr = head;
//    if (head == NULL) {
//        printf("list is empty\n");
//    } else {
//        while (ptr != NULL) {
//            printf("%d\n", ptr->data);
//            ptr = ptr->link;
//        }
//    }
//}
//
//void add_at_end(struct node *head, int data) {
//    struct node *ptr, *temp;
//    ptr = head;
//    temp = malloc(sizeof(struct node));
//
//    temp->data = data;
//    temp->link = NULL;
//
//    while (ptr->link != NULL) {
//        ptr = ptr->link;
//    }
//    ptr->link = temp;
//}
//
//// Funkcija add_beg je izmenjena da koristi pokazivač na pokazivač (struct node **head_ref)
//void add_beg(struct node **head_ref, int data) {
//    struct node *temp = malloc(sizeof(struct node));
//    temp->data = data;
//    temp->link = *head_ref;
//    *head_ref = temp;
//}
//
//int main() {
//    struct node *head = malloc(sizeof(struct node));
//    head->data = 45;
//    head->link = NULL;
//
//    struct node *current = malloc(sizeof(struct node));
//    current->data = 98;
//    current->link = NULL;
//    head->link = current;
//
//    current = malloc(sizeof(struct node));
//    current->data = 3;
//    current->link = NULL;
//    head->link->link = current;
//
//    // Pozivamo add_beg sa &head da bismo prosledili pokazivač na pokazivač
//    add_beg(&head, 10);
//    add_at_end(head, 67);
//    print_data(head);
//
//    // Oslobađanje memorije
//    struct node *ptr = head;
//    struct node *temp;
//    while (ptr != NULL) {
//        temp = ptr;
//        ptr = ptr->link;
//        free(temp);
//    }
//
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} NODE;

NODE* createNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(NODE** head_ref, int new_data) {
    NODE* newNode = createNode(new_data);
    NODE* last = *head_ref;
    
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = newNode;
    newNode->prev = last;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void stampajProste(NODE* head) {
    NODE* temp = head;
    while (temp != NULL) {
        if (isPrime(temp->data)) {
            printf("%d ", temp->data);
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    NODE* head = NULL;
    
    append(&head, 11);
    append(&head, 20);
    append(&head, 17);
    append(&head, 23);
    append(&head, 15);

    printf("Prosti brojevi u listi su: ");
    stampajProste(head);

    return 0;
}
