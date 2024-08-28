#include <stdio.h>
#include <stdlib.h>

// Definicija strukture za čvor binarnog stabla
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Funkcija za kreiranje novog čvora
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memorija nije dostupna!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Funkcija za umetanje novog čvora u binarno stablo pretrazivanja
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Funkcija za ispis listova binarnog stabla
void printLeaves(Node* root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            printf("%d ", root->data);
        }
        printLeaves(root->left);
        printLeaves(root->right);
    }
}

// Funkcija za in-order obilazak stabla
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
// Funkcija za brisanje stabla
void deleteTree(Node* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

int main(void) {
    Node* root = NULL;
    int values[] = {13, 5, 22, 27, 15, 8, 3, 11};
    int n = sizeof(values) / sizeof(values[0]);

    // Umetanje čvorova iz niza u binarno stablo
    for (int i = 0; i < n; i++) {
        root = insertNode(root, values[i]);
    }

    // Ispis stabla u in-order režimu (sortirani ispis)
    printf("In-order obilazak: ");
    inOrderTraversal(root);
    printf("\n");

    // Ispis listova stabla
    printf("Listovi stabla: ");
    printLeaves(root);
    printf("\n");

    // Brisanje stabla
    deleteTree(root);

    return 0;
}

//struct Node {
//    int data;
//    struct Node* left;
//    struct Node* right;
//};
//
//// Note : Unlike other languages, C does not support
//// Object Oriented Programming. So we need to write
//// a separat method for create and instance of tree node
//struct Node* newNode(int item) {
//    struct Node* temp =
//       (struct Node*)malloc(sizeof(struct Node));
//    temp->key = item;
//    temp->left = temp->right = NULL;
//    return temp;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX 100
//
//typedef struct {
//    int items[MAX];
//    int front, rear;
//} Queue;
//
//void init(Queue *q) {
//    q->front = 0;
//    q->rear = -1;
//}
//
//int isEmpty(Queue *q) {
//    return q->front > q->rear;
//}
//
//int isFull(Queue *q) {
//    return q->rear == MAX - 1;
//}
//
//int enque(Queue *q, int value) {
//    if (isFull(q)) {
//        printf("Queue is full\n");
//        return -1;
//    }
//    q->items[++(q->rear)] = value;
//    return 0;
//}
//
//int deque(Queue *q) {
//    if (isEmpty(q)) {
//        printf("Queue is empty\n");
//        return -1;
//    }
//    return q->items[(q->front)++];
//}
//
//int front(Queue *q) {
//    if (isEmpty(q)) {
//        printf("Queue is empty\n");
//        return -1;
//    }
//    return q->items[q->front];
//}
//
//int main(void) {
//    Queue q;
//    
//    init(&q);
//    enque(&q, 10);
//    enque(&q, 20);
//    enque(&q, 30);
//    enque(&q, 40);
//    deque(&q);
//    printf("Front item: %d\n", front(&q));
//
//    return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX 100
//
//typedef struct {
//    int items[MAX];
//    int front, rear;
//} Queue;
//
//void init(Queue *q) {
//    q->front = 0;
//    q->rear = -1;
//}
//
//int isEmpty(Queue *q) {
//    return q->front > q->rear;
//}
//
//int isFull(Queue *q) {
//    return q->rear == MAX - 1;
//}
//
//int enque(Queue *q, int value) {
//    if (isFull(q)) {
//        printf("Queue is full\n");
//        return -1;
//    }
//    q->items[++(q->rear)] = value;
//    return 0;
//}
//
//int deque(Queue *q) {
//    if (isEmpty(q)) {
//        printf("Queue is empty\n");
//        return -1;
//    }
//    return q->items[(q->front)++];
//}
//
//int front(Queue *q) {
//    if (isEmpty(q)) {
//        printf("Queue is empty\n");
//        return -1;
//    }
//    return q->items[q->front];
//}
//
//int main(void) {
//    Queue q;
//    
//    init(&q);
//    enque(&q, 10);
//    enque(&q, 20);
//    enque(&q, 30);
//    enque(&q, 40);
//    deque(&q);
//    printf("Front item: %d\n", front(&q));
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//    struct node *prev;
//    int data;
//    struct node *next;
//};
//
//struct node *addEmpty(struct node *head, int data){
//    struct node *ptr = malloc(sizeof(struct node));
//    ptr->prev = NULL;
//    ptr->data = data;
//    ptr->next = NULL;
//    head = ptr;
//    return head;
//}
//struct node *addEnd (struct node *head, int data){
//    struct node *ptr = malloc(sizeof(struct node));
//    ptr->prev = NULL;
//    ptr->data = data;
//    ptr->next = NULL;
//    
//    struct node *temp = head;
//    while(temp->next != NULL){
//        temp = temp->next;
//    }
//    temp->next = ptr;
//    ptr->prev = temp;
//    return head;
//}
//
//void print(struct node *head){
//    struct node *temp = head;
//    while(temp != NULL){
//        printf("%d\n", temp->data);
//        temp = temp->next;
//    }
//}
//
//
//int main(void){
//    struct node *head = NULL;
//    
//    head = addEmpty(head, 10);
//    head = addEnd(head, 20);
//    head = addEnd(head, 30);
//    head = addEnd(head, 40);
//    print(head);
//    
//    return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//    struct node *prev;
//    int data;
//    struct node *next;
//};
//
//// Funkcija za dodavanje prvog elementa u praznu listu
//struct node *addEmpty(struct node *tail, int data) {
//    struct node *temp = malloc(sizeof(struct node));
//    temp->prev = temp; // Prev i next pokazivači upućuju na samog sebe
//    temp->data = data;
//    temp->next = temp;
//    tail = temp;
//    return tail;
//}
//
//// Funkcija za dodavanje elementa na kraj liste
//struct node *addEnd(struct node *tail, int data) {
//    struct node *temp = malloc(sizeof(struct node));
//    temp->data = data;
//
//    if (tail == NULL) {
//        // Ako je lista prazna, dodajemo prvi element
//        return addEmpty(tail, data);
//    } else {
//        // Ažuriramo pokazivače za kružnu listu
//        temp->next = tail->next; // temp.next pokazuje na prvi element
//        temp->prev = tail;
//        tail->next->prev = temp; // Prvi element sada pokazuje na novi zadnji element
//        tail->next = temp;       // Tail.next pokazuje na novi zadnji element
//        tail = temp;             // Ažuriramo tail na novi zadnji element
//        return tail;
//    }
//}
//
//// Funkcija za ispis podataka iz kružne liste
//void printData(struct node *tail) {
//    if (tail == NULL) {
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX 100
//
//typedef struct {
//    int items[MAX];
//    int front, rear;
//} Que;
//
//void init(Que *q) {
//    q->front = 0;  // Postavljamo front na 0
//    q->rear = -1;  // Početni rear je -1 jer nema elemenata
//}
//
//int isEmpty(Que *q) {
//    return q->rear < q->front;  // Proveravamo da li je rear ispred fronta
//}
//
//int isFull(Que *q) {
//    return q->rear == MAX - 1;  // Proveravamo da li je rear dostigao MAX-1
//}
//
//void enque(Que *q, int value) {
//    if (isFull(q)) {
//        printf("Queue is overflow\n");
//        return;
//    }
//    q->items[++(q->rear)] = value;  // Povećavamo rear i dodajemo element
//}
//
//int deque(Que *q) {
//    if (isEmpty(q)) {
//        printf("Queue is Empty\n");
//        return -1;
//    } else {
//        return q->items[(q->front)++];  // Vraćamo element i povećavamo front
//    }
//}
//
//int front(Que *q) {
//    if (isEmpty(q)) {
//        printf("Queue is Empty\n");
//        return -1;
//    } else {
//        return q->items[q->front];  // Vraćamo element sa fronta
//    }
//}
//
//int main() {
//    Que q;
//    init(&q);  // Prosleđivanje pokazivača na Que objekat
//    enque(&q, 10);
//    enque(&q, 20);
//    enque(&q, 30);
//    enque(&q, 40);
//    
//    printf("Front element: %d\n", front(&q));
//    
//    while (!isEmpty(&q)) {
//        printf("Dequeued: %d\n", deque(&q));  // Ispisujemo i uklanjamo sve elemente
//    }
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//    struct node *prev;
//    int data;
//    struct node *next;
//};
//
//struct node *addEmtpy(struct node *head, int data){
//    struct node *temp = malloc(sizeof(struct node));
//    temp->prev = NULL;
//    temp->data = data;
//    temp->next = NULL;
//    head = temp;
//    return head;
//}
//
//struct node *addEnd(struct node *head, int data){
//    struct node *temp = malloc(sizeof(struct node));
//    temp->prev = NULL;
//    temp->data = data;
//    temp->next = NULL;
//    
//    struct node *ptr = head;
//    while(ptr->next != NULL){
//        ptr = ptr->next;
//    }
//    ptr->next = temp;
//    temp->prev = ptr;
//    return head;
//}
//
//void stampajParne (struct node *head){
//    struct node *ptr = head;
//    while(ptr != NULL){
//        if(ptr->data % 2 == 0){
//            printf("%d\n", ptr->data);
//        }
//        ptr = ptr->next;
//    }
//}
//
//
//
//
//int main() {
//    struct node *head = NULL;
//    
//    head = addEmtpy(head, 12);
//    head = addEnd(head, 33);
//    head = addEnd(head, 24);
//    head = addEnd(head, 36);
//    stampajParne(head);
//
//
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//struct node{
//    struct node *prev;
//    int data;
//    struct node *next;
//};
//void AddEmpty(struct node *head, int data){
//    head = malloc(sizeof(struct node));
//    head->prev = NULL;
//    head->data = data;
//    head->next = NULL;
//}
//void count(struct node *head){
//    int count = 0;
//    struct node *ptr = head;
//    while(ptr!=NULL){
//        printf("%d\n", ptr->data);
//        count++;
//        ptr = ptr->next;
//    }
//    printf("Number of nodes is: %d\n", count);
//}
//int main (void){
//    struct node head;
//    AddEmpty(&head, 23);
//    count(&head);
//
//    return 0;
//}

//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define TABLE_SIZE 10
//
//typedef struct {
//    int key;
//    int value;
//} HashItem;
//
//HashItem* hashTable[TABLE_SIZE];
//
//int hashFunction(int key) {
//    return key % TABLE_SIZE;
//}
//
//void initHashTable() {
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        hashTable[i] = NULL;
//    }
//}
//
//void insert(int key, int value) {
//    int hashIndex = hashFunction(key);
//    int originalIndex = hashIndex;
//    
//    // Linear probing
//    while (hashTable[hashIndex] != NULL && hashTable[hashIndex]->key != key) {
//        hashIndex = (hashIndex + 1) % TABLE_SIZE;
//        
//        // If we loop back to the original index, table is full
//        if (hashIndex == originalIndex) {
//            printf("Hash table is full\n");
//            return;
//        }
//    }
//    
//    if (hashTable[hashIndex] != NULL) {
//        free(hashTable[hashIndex]);
//    }
//    hashTable[hashIndex] = (HashItem*) malloc(sizeof(HashItem));
//    hashTable[hashIndex]->key = key;
//    hashTable[hashIndex]->value = value;
//}
//
//int search(int key) {
//    int hashIndex = hashFunction(key);
//    int originalIndex = hashIndex;
//    
//    while (hashTable[hashIndex] != NULL) {
//        if (hashTable[hashIndex]->key == key) {
//            return hashTable[hashIndex]->value;
//        }
//        
//        hashIndex = (hashIndex + 1) % TABLE_SIZE;
//        
//        if (hashIndex == originalIndex) {
//            break;
//        }
//    }
//    return -1; // Indicates not found
//}
//
//void display() {
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        if (hashTable[i] != NULL) {
//            printf("Index %d: Key = %d, Value = %d\n", i, hashTable[i]->key, hashTable[i]->value);
//        } else {
//            printf("Index %d: NULL\n", i);
//        }
//    }
//}
//
//int main() {
//    initHashTable();
//    
//    insert(1, 10);
//    insert(2, 20);
//    insert(12, 30);
//    insert(22, 40);
//    insert(32, 50);
//    
//    display();
//    
//    printf("Value for key 22: %d\n", search(22));
//    printf("Value for key 3: %d\n", search(3));
//    
//    return 0;
//}
//


//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//#define MAX 100
//
//typedef struct {
//    int front;
//    int items[MAX];
//    int rear;
//} Que;
//
//void init(Que *q) {
//    q->front = -1;
//    q->rear = -1;
//}
//
//bool isEmpty(Que *q) {
//    return q->front == -1 || q->front > q->rear;
//}
//
//bool isFull(Que *q) {
//    return q->rear == MAX - 1;
//}
//
//void sort(Que *q) {
//    for (int i = q->front; i <= q->rear; i++) {
//        for (int j = i + 1; j <= q->rear; j++) {
//            if (q->items[i] < q->items[j]) {
//                int temp = q->items[i];
//                q->items[i] = q->items[j];
//                q->items[j] = temp;
//            }
//        }
//    }
//}
//
//void enque(Que *q, int value) {
//    if (isFull(q)) {
//        printf("Queue is full.\n");
//        return;
//    }
//    if (isEmpty(q)) {
//        q->front = 0;
//    }
//    q->items[++(q->rear)] = value;
//    sort(q);
//}
//
//int deque(Que *q) {
//    if (isEmpty(q)) {
//        printf("Queue is empty.\n");
//        return -1;
//    }
//    int value = q->items[(q->front)++];
//    if (q->front > q->rear) { // Reset queue if all elements are dequeued
//        q->front = -1;
//        q->rear = -1;
//    }
//    return value;
//}
//
//int front(Que *q) {
//    if (isEmpty(q)) {
//        printf("Queue is empty.\n");
//        return -1;
//    }
//    return q->items[q->front];
//}
//
//int main(void) {
//    Que q;
//    init(&q);
//
//    if (isEmpty(&q)) {
//        printf("Queue is empty.\n");
//    }
//
//    enque(&q, 23);
//    enque(&q, 45);
//    enque(&q, 67);
//
//    printf("Front element is %d\n", front(&q));
//
//    printf("Dequeued element is %d\n", deque(&q));
//    printf("Dequeued element is %d\n", deque(&q));
//
//    if (isEmpty(&q)) {
//        printf("Queue is empty.\n");
//    } else {
//        printf("Queue is not empty.\n");
//    }
//
//    return 0;
//}
//

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//    struct node *prev;
//    int data;
//    struct node *next;
//};
//
//struct node *AddEmpty(struct node *head, int data) {
//    head = malloc(sizeof(struct node));
//    head->prev = NULL;
//    head->data = data;
//    head->next = NULL;
//    
//    return head;
//}
//
//struct node *AddEnd(struct node *head, int data) {
//    struct node *temp = malloc(sizeof(struct node));
//    temp->prev = NULL;
//    temp->data = data;
//    temp->next = NULL;
//    struct node *ptr = head;
//    while (ptr->next != NULL) {
//        ptr = ptr->next;
//    }
//    ptr->next = temp;
//    temp->prev = ptr;
//    
//    return head;
//}
//
//struct node *parni(struct node *head) {
//    struct node *temp = NULL;
//    struct node *ptr = head;
//    
//    while (ptr != NULL) {
//        if (ptr->data % 2 == 0) {
//            if (temp == NULL) {
//                temp = AddEmpty(temp, ptr->data);
//            } else {
//                temp = AddEnd(temp, ptr->data);
//            }
//        }
//        ptr = ptr->next;
//    }
//    
//    return temp;
//}
//
//void countNode(struct node *head) {
//    struct node *ptr = head;
//    int count = 0;
//    while (ptr != NULL) {
//        printf("%d\n", ptr->data);
//        count++;
//        ptr = ptr->next;
//    }
//    printf("Number of nodes is: %d\n", count);
//}
//
//int main(void) {
//    struct node *head = NULL;
//    
//    head = AddEmpty(head, 23);
//    head = AddEnd(head, 36);
//    head = AddEnd(head, 45);
//    head = AddEnd(head, 65);
//    head = AddEnd(head, 32);
//    head = AddEnd(head, 76);
//    head = AddEnd(head, 11);
//    
//    printf("Original list:\n");
//    countNode(head);
//    
//    head = parni(head);
//    
//    printf("List with even numbers:\n");
//    countNode(head);
//    
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//#define MAX 100
//
//typedef struct {
//    int front;
//    int items[MAX];
//    int rear;
//} Que;
//
//void init(Que *q) {
//    q->front = -1;
//    q->rear = -1;
//}
//
//bool isEmpty(Que *q) {
//    return q->front == -1 || q->front > q->rear;
//}
//
//bool isFull(Que *q) {
//    return q->rear == MAX - 1;
//}
//
//void enque(Que *q, int value) {
//    if (isFull(q)) {
//        printf("Queue is full.\n");
//        return;
//    }
//    if (isEmpty(q)) {
//        q->front = 0;
//    }
//    q->items[++(q->rear)] = value;
//}
//
//int deque(Que *q) {
//    if (isEmpty(q)) {
//        printf("Queue is empty.\n");
//        return -1;
//    }
//    int value = q->items[(q->front)++];
//    if (q->front > q->rear) { // Reset queue if all elements are dequeued
//        q->front = -1;
//        q->rear = -1;
//    }
//    return value;
//}
//
//int front(Que *q) {
//    if (isEmpty(q)) {
//        printf("Queue is empty.\n");
//        return -1;
//    }
//    return q->items[q->front];
//}
//
//int main(void) {
//    Que q;
//    init(&q);
//
//    if (isEmpty(&q)) {
//        printf("Queue is empty.\n");
//    }
//
//    enque(&q, 23);
//    enque(&q, 45);
//    enque(&q, 67);
//
//    printf("Front element is %d\n", front(&q));
//
//    printf("Dequeued element is %d\n", deque(&q));
//    printf("Dequeued element is %d\n", deque(&q));
//    
//    if (isEmpty(&q)) {
//        printf("Queue is empty.\n");
//    } else {
//        printf("Queue is not empty.\n");
//    }
//
//    return 0;
//}
//
//
//
////#include <stdio.h>
//#include <stdlib.h>
//
//#define TABLE_SIZE 10
//#define EMPTY_SLOT -1
//
//// Struktura za heš tabelu
//typedef struct {
//    int* table;
//} HashTable;
//
//// Inicijalizacija heš tabele
//HashTable* createHashTable() {
//    HashTable* hashTable = (HashTable*) malloc(sizeof(HashTable));
//    hashTable->table = (int*) malloc(TABLE_SIZE * sizeof(int));
//    
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        hashTable->table[i] = EMPTY_SLOT;
//    }
//
//    return hashTable;
//}
//
//// Heš funkcija
//int hashFunction(int key) {
//    return key % TABLE_SIZE;
//}
//
//// Funkcija za umetanje ključa u heš tabelu koristeći linearno hesiranje
//void insert(HashTable* hashTable, int key) {
//    int hashIndex = hashFunction(key);
//
//    // Linearno hesiranje - traženje sledećeg slobodnog slota
//    while (hashTable->table[hashIndex] != EMPTY_SLOT) {
//        hashIndex = (hashIndex + 1) % TABLE_SIZE;
//    }
//
//    hashTable->table[hashIndex] = key;
//}
//
//// Funkcija za pretragu ključa u heš tabeli
//int search(HashTable* hashTable, int key) {
//    int hashIndex = hashFunction(key);
//    
//    // Linearno pretraga
//    while (hashTable->table[hashIndex] != EMPTY_SLOT) {
//        if (hashTable->table[hashIndex] == key) {
//            return hashIndex;
//        }
//        hashIndex = (hashIndex + 1) % TABLE_SIZE;
//    }
//
//    return -1; // Ključ nije pronađen
//}
//
//// Funkcija za štampanje heš tabele
//void printHashTable(HashTable* hashTable) {
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        if (hashTable->table[i] == EMPTY_SLOT) {
//            printf("Slot %d: EMPTY\n", i);
//        } else {
//            printf("Slot %d: %d\n", i, hashTable->table[i]);
//        }
//    }
//}
//
//// Oslobađanje memorije zauzete heš tabelom
//void freeHashTable(HashTable* hashTable) {
//    free(hashTable->table);
//    free(hashTable);
//}
//
//int main() {
//    HashTable* hashTable = createHashTable();
//    
//    insert(hashTable, 5);
//    insert(hashTable, 15);
//    insert(hashTable, 25);
//    insert(hashTable, 35);
//
//    printHashTable(hashTable);
//
//    int key = 25;
//    int index = search(hashTable, key);
//    if (index != -1) {
//        printf("Key %d found at index %d\n", key, index);
//    } else {
//        printf("Key %d not found\n", key);
//    }
//
//    freeHashTable(hashTable);
//    return 0;
//}
//
//
//

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

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//typedef struct Node {
//    int data;
//    struct Node* next;
//    struct Node* prev;
//} NODE;
//
//NODE* createNode(int data) {
//    NODE* newNode = (NODE*)malloc(sizeof(NODE));
//    newNode->data = data;
//    newNode->next = NULL;
//    newNode->prev = NULL;
//    return newNode;
//}
//
//void append(NODE** head_ref, int new_data) {
//    NODE* newNode = createNode(new_data);
//    NODE* last = *head_ref;
//    
//    if (*head_ref == NULL) {
//        *head_ref = newNode;
//        return;
//    }
//
//    while (last->next != NULL) {
//        last = last->next;
//    }
//    
//    last->next = newNode;
//    newNode->prev = last;
//}
//
//bool isPrime(int n) {
//    if (n <= 1) return false;
//    for (int i = 2; i * i <= n; i++) {
//        if (n % i == 0) return false;
//    }
//    return true;
//}
//
//void stampajProste(NODE* head) {
//    NODE* temp = head;
//    while (temp != NULL) {
//        if (isPrime(temp->data)) {
//            printf("%d ", temp->data);
//        }
//        temp = temp->next;
//    }
//    printf("\n");
//}
//
//int main() {
//    NODE* head = NULL;
//    
//    append(&head, 11);
//    append(&head, 20);
//    append(&head, 17);
//    append(&head, 23);
//    append(&head, 15);
//
//    printf("Prosti brojevi u listi su: ");
//    stampajProste(head);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct node{
//    int data;
//    struct node *link;
//};
//
//void count_nodes(struct node *head){
//    int count = 0;
//    struct node *ptr = NULL;
//    ptr = head;
//    while(ptr != NULL){
//        printf("%d\n", ptr->data);
//        ptr = ptr->link;
//        count++;
//    }
//    printf("number of nodes is: %d", count);
//}
//void add_at_end(struct node *head, int data){
//    struct node *ptr = NULL;
//    ptr = head;
//    struct node *temp = malloc(sizeof(struct node));
//    temp->data = data;
//    temp->link = NULL;
//    
//    while(ptr->link!=NULL){
//        ptr=ptr->link;
//    }
//    ptr->link = temp;
//}
//
//void add_at_begin(struct node **head, int d){
//    struct node *ptr = malloc(sizeof(struct node));
//    ptr->data = d;
//    ptr->link = NULL;
//    
//    ptr->link = *head;
//    *head = ptr;
//}
//
//void add_at_pos(struct node *head, int pos, int d){
//    struct node *ptr = NULL;
//    ptr = head;
//    struct node *ptr2= malloc(sizeof(struct node));
//    ptr2->data = d;
//    ptr2->link = NULL;
//    pos = pos;
//    
//    pos--;
//    while(pos!=1){
//        ptr=ptr->link;
//        pos--;
//    }
//    ptr2->link = ptr->link;
//    ptr->link = ptr2;
//}
//
//int main (){
//    struct node *head = malloc(sizeof(struct node));
//    head->data = 45;
//    head->link = NULL;
//    
//    struct node *current = malloc(sizeof(struct node));
//    current->data = 98;
//    current -> link =NULL;
//    head->link = current;
//    
//    current = malloc(sizeof(struct node));
//    current -> data = 3;
//    current ->link = NULL;
//    head->link->link = current;
//
//    int pos = 3;
//    add_at_begin(&head, 7);
//    add_at_pos(head, pos, 99);
//    add_at_end(head, 67);
//    count_nodes(head);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//    int data;
//    struct node *link;
//};
//
//void count_nodes(struct node *head){
//    int count = 0;
//    struct node *ptr = NULL;
//    ptr = head;
//    while(ptr != NULL){
//        printf("%d\n", ptr->data);
//        ptr = ptr->link;
//        count++;
//    }
//    printf("number of nodes is: %d\n", count);
//}
//
//void add_end(struct node *head, int d){
//    struct node *temp = malloc(sizeof(struct node));
//    temp ->data = d;
//    temp-> link = NULL;
//    struct node *ptr = NULL;
//    ptr = head;
//    while(ptr->link != NULL){
//        ptr = ptr ->link;
//    }
//    ptr->link = temp;
//}
//void add_begin(struct node **head, int d){
//    struct node *temp = malloc(sizeof(struct node));
//    temp->data = d;
//    temp-> link = NULL;
//    struct node *ptr = NULL;
//    temp->link = *head;
//    *head = temp;
//}
//void add_pos(struct node *head, int d, int pos){
//    struct node *ptr = NULL;
//    ptr = head;
//    struct node *ptr2 = malloc(sizeof(struct node));
//    ptr2->data = d;
//    ptr2->link = NULL;
//    
//    pos--;
//    while(pos!=1){
//        ptr=ptr->link;
//        pos--;
//    }
//    ptr2->link = ptr->link;
//    ptr->link = ptr2;
//}
//int main (){
//    struct node *head = malloc(sizeof(struct node));
//    head->data = 20;
//    head->link = NULL;
//    
//    struct node *current = malloc(sizeof(struct node));
//    current->data = 30;
//    current->link = NULL;
//    head->link = current;
//    
//    current = malloc(sizeof(struct node));
//    current->data = 40;
//    current->link = NULL;
//    head ->link->link = current;
//    
//    add_begin(&head, 10);
//    add_end(head, 50);
//    add_pos(head, 25, 3);
//    count_nodes(head);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//typedef struct {
//    int *colection;
//    int capacity;
//    int size;
//}Stack;
//
//Stack *createStack(int capacity){
//    if(capacity <= 0) return NULL;
//    
//    Stack *stack = malloc(sizeof(Stack));
//    if(stack == NULL) return NULL;
//    
//    stack->colection = malloc(sizeof(int) * capacity);
//    
//    if(stack->colection == NULL){
//        free(stack);
//        return NULL;
//    }
//    stack->capacity = capacity;
//    stack->size = 0;
//    return stack;
//}
//    
//void destryStack (Stack *stack){
//    if(stack->colection!=NULL){
//        free(stack->colection);
//        free(stack);
//    }
//}
//
//bool isFull(Stack *stack){
//    return stack->capacity==stack->size;
//}
//
//bool isEmpty(Stack *stack){
//    return stack->size == 0;
//}
//bool push(Stack *stack, int item){
//    if(isFull(stack)) return false;
//    stack->colection[stack->size] = item;
//    stack->size++;
//    return true;
//}
//bool pop (Stack *stack, int *item){
//    if(isEmpty(stack)) return false;
//    stack->size--;
//    *item = stack->colection[stack->size];
//    
//    return true;
//}
//
//bool peek (Stack *stack, int *item){
//    if(isEmpty(stack)) return false;
//    
//    *item = stack->colection[stack->size-1];
//    return true;
//}
//
//int main (void){
//    Stack *stack = createStack(5);
//    if(stack == NULL){
//        printf("Error creating stack!\n");
//        return 1;
//    }
//    
//    if(isEmpty(stack)) printf("Stack is empty!\n");
//    
//    push(stack, 7);
//    printf("Size of stack: %d\n", stack->size);
//    push(stack, 3);
//    push(stack, 4);
//    push(stack, 2);
//    push(stack, 9);
//
//    if(isFull(stack)) printf("Stack is full!\n");
//    printf("Size of stack: %d\n", stack->size);
//
//    bool try_push = push(stack, 3);
//    if(try_push == false) printf("Push failed!\n");
//    
//    int peek_value = 0;
//    peek(stack, &peek_value);
//    printf("The peek value is: %d\n", peek_value);
//    
//    int pop_val = 0;
//    for(int i=0;i<5;i++){
//        pop(stack, &pop_val);
//        printf("The poped value is: %d\n", pop_val);
//    }
//    
//    bool try_pop = pop(stack, &pop_val);
//    if(try_pop == false) printf("Pop is failed!\n");
//    
//    bool try_peek = peek(stack, &peek_value);
//    if(try_peek == false) printf("peek is failed!\n");
//    
//    
//    destryStack(stack);
//    
//    
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//typedef struct{
//    int *colection;
//    int capacity;
//    int size;
//} Stack;
//
//Stack *createStack (int capacity){
//    if(capacity <= 0) return NULL;
//    
//    Stack *stack = malloc(sizeof(Stack));
//    if(stack == NULL) return NULL;
//    
//    stack->colection = malloc(sizeof(int)*capacity);
//    if(stack->colection == NULL){
//        free(stack->colection);
//        free(stack);
//        return NULL;
//    }
//    stack->capacity = capacity;
//    stack->size = 0;
//    return stack;
//}
//
//void destroyStack(Stack* stack){
//    if(stack->colection!=NULL){
//        free(stack->colection);
//        free(stack);
//    }
//}
//
//bool isFull(Stack *stack){
//    return stack->capacity == stack->size;
//}
//bool isEmpty(Stack *stack){
//    return stack->size == 0;
//}
//
//bool push(Stack *stack, int data){
//    if(isFull(stack)) return false;
//    
//    stack->size++;
//    stack->colection[stack->size] = data;
//    return true;
//}
//bool pop (Stack *stack, int *data){
//    if(isEmpty(stack)) return false;
//    
//    stack->size--;
//    *data = stack->colection[stack->size+1];
//    return true;
//}
//bool peek (Stack *stack, int *data){
//    if(isEmpty(stack)) return NULL;
//    
//    *data = stack->colection[stack->size];
//    return true;
//}
//
//int main (void){
//    Stack *stack = createStack(5);
//    
//    push(stack, 4);
//    if(isEmpty(stack)) printf("Nema nist burko\n");
//    printf("data: %d\n", stack->size);
//    push(stack, 9);
//    push(stack, 3);
//    push(stack, 7);
//    push(stack, 2);
//    if(isFull(stack)) printf("Stack is full\n");
//    printf("data: %d\n", stack->size);
//    
//    int peek_el = 0;
//    peek(stack, &peek_el);
//    printf("Peek element: %d\n", peek_el);
//    
//    int pop_el = 0;
//    for(int i = 0;i<5;i++){
//        pop(stack, &pop_el);
//        printf("Poped element: %d\n", pop_el);
//    }
//    if(isEmpty(stack)) printf("stack is empty\n");
//    
//    destroyStack(stack);
//    return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//#define MAX 100
//
//typedef struct {
//    int items[MAX];
//    int front, rear;
//}Queue;
//
//void init (Queue *q){
//    q->front = -1;
//    q->rear = -1;
//}
//int isEmpty(Queue *q){
//    return q->front == -1||q->front >q->rear;
//}
//int isFull (Queue *q){
//    return q->rear == q->front -1;
//}
//void enque (Queue *q, int value){
//    if(isFull(q)){
//        printf("Enque failed, queue is full!\n");
//        return;
//    }if(isEmpty(q))
//        q->front = 0;
//    
//        q->items[++(q->rear)] = value;
//}
//int deque(Queue *q){
//    if(isEmpty(q)){
//        printf("Queue is empty!\n");
//        return -1;
//    }else{
//        return q->items[(q->front)++];
//    }
//}
//int front(Queue *q){
//    if(isEmpty(q)){
//        printf("Que is empty");
//        return -1;
//    }else{
//        return q->items[(q->front)];
//    }
//}
//
//int main(void){
//    Queue q;
//    init(&q);
//    
//    enque(&q, 10);
//    enque(&q, 20);
//    enque(&q, 30);
//
//    printf("First element Queue: %d\n", front(&q));
//    deque(&q);
//    printf("First element Queue: %d\n", front(&q));
//    return 0;
//
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#define MAX 100
//
//typedef struct {
//    int items[MAX];
//    int top;
//} Stack;
//
//void init(Stack *s) {
//    s->top = -1;
//}
//
//bool isEmpty(Stack *s) {
//    return s->top == -1;
//}
//
//bool isFull(Stack *s) {
//    return s->top == MAX - 1;
//}
//
//void push(Stack *s, int data) {
//    if (isFull(s)) {
//        printf("Stack is full\n");
//        return;
//    }
//    s->items[++(s->top)] = data;
//}
//
//int pop(Stack *s) {
//    if (isEmpty(s)) {
//        printf("Stack is already empty\n");
//        return -1; // Indikator greške
//    }
//    return s->items[(s->top)--];
//}
//
//int peek(Stack *s) {
//    if (isEmpty(s)) {
//        printf("Stack is empty\n");
//        return -1; // Indikator greške
//    }
//    return s->items[s->top];
//}
//
//int main(void) {
//    Stack s;
//    init(&s);
//    
//    push(&s, 23);
//    push(&s, 43);
//    push(&s, 77);
//    
//    printf("Element na vrhu steka: %d\n", peek(&s));
//    printf("Element uklonjen sa steka: %d\n", pop(&s));
//    printf("Element na vrhu steka: %d\n", peek(&s));
//    
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//typedef struct {
//    int *collection;
//    int capacity;
//    int size;
//} Stack;
//
//Stack *createStack(int capacity) {
//    if (capacity <= 0) return NULL;
//    
//    Stack *stack = (Stack *)malloc(sizeof(Stack));
//    if (stack == NULL) return NULL;
//    
//    stack->collection = (int *)malloc(sizeof(int) * capacity);
//    if (stack->collection == NULL) {
//        free(stack);
//        return NULL;
//    }
//        
//    stack->capacity = capacity;
//    stack->size = 0;
//    return stack;
//}
//
//void destroyStack(Stack *stack) {
//    if (stack != NULL) {
//        free(stack->collection);
//        free(stack);
//    }
//}
//
//bool isFull(Stack *stack) {
//    return stack->size == stack->capacity;
//}
//
//bool isEmpty(Stack *stack) {
//    return stack->size == 0;
//}
//
//bool push(Stack *stack, int item) {
//    if (isFull(stack)) return false;
//    
//    stack->collection[stack->size] = item;
//    stack->size++;
//    return true;
//}
//
//bool pop(Stack *stack, int *item) {
//    if (isEmpty(stack)) return false;
//    
//    stack->size--;
//    *item = stack->collection[stack->size];
//    return true;
//}
//
//bool peek(Stack *stack, int *item) {
//    if (isEmpty(stack)) return false;
//    
//    *item = stack->collection[stack->size - 1];
//    return true;
//}
//
//int main(void) {
//    Stack *stack = createStack(20);
//    
//    if (stack == NULL) {
//        printf("Error creating stack.\n");
//        return 1;
//    }
//
//    push(stack, 10);
//    push(stack, 20);
//    push(stack, 30);
//
//    int peek_val = 0;
//    int pop_val = 0;
//    
//    if (peek(stack, &peek_val)) {
//        printf("Peek value is: %d\n", peek_val);
//    } else {
//        printf("Stack is empty. Cannot peek.\n");
//    }
//
//    if (pop(stack, &pop_val)) {
//        printf("Popped value is: %d\n", pop_val);
//    } else {
//        printf("Stack is empty. Cannot pop.\n");
//    }
//    
//    if (peek(stack, &peek_val)) {
//        printf("Peek value after pop is: %d\n", peek_val);
//    } else {
//        printf("Stack is empty. Cannot peek.\n");
//    }
//
//    destroyStack(stack);
//    return 0;
//}
//


//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//#define MAX 100
//
//typedef struct{
//    int items[MAX];
//    int front, rear;
//}Queue;
//
//void init (Queue *que){
//    que->front = -1;
//    que->rear = -1;
//}
//
//int isEmpty(Queue *que){
//    return que->front == -1||que->front>que->rear;
//}
//int isfull(Queue *que){
//    return que->rear == MAX -1;
//}
//void enque (Queue *que, int value){
//    if(isfull(que)) printf("Queue is overflow");
//    
//    if(isEmpty(que))
//        que->front = 0;
//    que->items[++(que->rear)] = value;
//}
//int deque (Queue *que){
//    if (isEmpty(que)) {
//        printf("Queue underflow!\n");
//        return -1;
//    }
//    return que->items[(que->front)++];
//}
//int front (Queue * que){
//    if(isEmpty(que)){
//        printf("Queue is empty!\n");
//        return -1;
//    }else{
//        return que->items[que->front];
//    }
//    
//}

//int main(void){
//    Queue que;
//    init(&que);
//    enque(&que, 20);
//    enque(&que, 30);
//    enque(&que, 40);
//    
//    printf("Element na pocetku reda: %d\n", front(&que));
//    deque(&que);
//    printf("Element na pocetku reda: %d\n", front(&que));
//    return 0;
//}
//
//
//
//

//

//#include <stdio.h>
//#include <stdlib.h>
//
//// Definicija strukture čvora
//typedef struct Node {
//    int data;
//    struct Node *left;
//    struct Node *right;
//} Node;
//
//// Funkcija za kreiranje novog čvora
//Node* createNode(int data) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    newNode->data = data;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    return newNode;
//}
//
//// Funkcija za umetanje elementa u binarno stablo pretrage
//Node* insert(Node* root, int data) {
//    if (root == NULL) {
//        return createNode(data);
//    }
//    if (data < root->data) {
//        root->left = insert(root->left, data);
//    } else if (data > root->data) {
//        root->right = insert(root->right, data);
//    }
//    return root;
//}
//
//// Rekurzivna funkcija za ispisivanje listova stabla
//void printLeaves(Node* root) {
//    if (root == NULL) {
//        return;
//    }
//    if (root->left == NULL && root->right == NULL) {
//        printf("%d ", root->data);
//    }
//    printLeaves(root->left);
//    printLeaves(root->right);
//}
//
//// Glavni program
//int main(void) {
//    int arr[] = {13, 5, 22, 27, 15, 8, 3, 11};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    
//    Node* root = NULL;
//    for (int i = 0; i < n; i++) {
//        root = insert(root, arr[i]);
//    }
//    
//    printf("Listovi stabla su: ");
//    printLeaves(root);
//    printf("\n");
//    
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//#define TABLE_SIZE 10
//#define EMPTY_SLOT -1
//
//// Struktura za heš tabelu
//typedef struct {
//    int* table;
//} HashTable;
//
//// Inicijalizacija heš tabele
//HashTable* createHashTable() {
//    HashTable* hashTable = (HashTable*) malloc(sizeof(HashTable));
//    hashTable->table = (int*) malloc(TABLE_SIZE * sizeof(int));
//    
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        hashTable->table[i] = EMPTY_SLOT;
//    }
//
//    return hashTable;
//}
//
//// Heš funkcija
//int hashFunction(int key) {
//    return key % TABLE_SIZE;
//}
//
//// Funkcija za umetanje ključa u heš tabelu koristeći linearno hesiranje
//void insert(HashTable* hashTable, int key) {
//    int hashIndex = hashFunction(key);
//
//    // Linearno hesiranje - traženje sledećeg slobodnog slota
//    while (hashTable->table[hashIndex] != EMPTY_SLOT) {
//        hashIndex = (hashIndex + 1) % TABLE_SIZE;
//    }
//
//    hashTable->table[hashIndex] = key;
//}
//
//// Funkcija za pretragu ključa u heš tabeli
//int search(HashTable* hashTable, int key) {
//    int hashIndex = hashFunction(key);
//    
//    // Linearno pretraga
//    while (hashTable->table[hashIndex] != EMPTY_SLOT) {
//        if (hashTable->table[hashIndex] == key) {
//            return hashIndex;
//        }
//        hashIndex = (hashIndex + 1) % TABLE_SIZE;
//    }
//
//    return -1; // Ključ nije pronađen
//}
//
//// Funkcija za štampanje heš tabele
//void printHashTable(HashTable* hashTable) {
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        if (hashTable->table[i] == EMPTY_SLOT) {
//            printf("Slot %d: EMPTY\n", i);
//        } else {
//            printf("Slot %d: %d\n", i, hashTable->table[i]);
//        }
//    }
//}
//
//// Oslobađanje memorije zauzete heš tabelom
//void freeHashTable(HashTable* hashTable) {
//    free(hashTable->table);
//    free(hashTable);
//}
//
//int main() {
//    HashTable* hashTable = createHashTable();
//    
//    insert(hashTable, 5);
//    insert(hashTable, 15);
//    insert(hashTable, 25);
//    insert(hashTable, 35);
//
//    printHashTable(hashTable);
//
//    int key = 25;
//    int index = search(hashTable, key);
//    if (index != -1) {
//        printf("Key %d found at index %d\n", key, index);
//    } else {
//        printf("Key %d not found\n", key);
//    }
//
//    freeHashTable(hashTable);
//    return 0;
//}
//
//




// ISPOCETKA/////////////////////////////////////////

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node{
//    int data;
//    struct node *link;
//};
//
////COUNT and PRINT list
//void count_of_nodes(struct node *head){
//    int count = 0;
//    if(head == NULL){
//        printf("list is empty. \n");
//    }else{
//        struct node *ptr = NULL;
//        ptr = head;
//        while(ptr != NULL){
//            count++;
//            printf("%d\n", ptr->data);
//            ptr = ptr -> link;
//        }
//        printf("Broj cvorova liste: %d\n", count);}
//}
//// ADD AT END/////////////////
//void add_at_end(struct node *head, int data){
//    struct node *ptr, *temp;
//    ptr=head;
//    temp = malloc(sizeof(struct node));
//    temp->data = data;
//    temp->link = NULL;
//    while(ptr->link!=NULL){
//        ptr=ptr->link;
//    }
//    ptr->link=temp;
//}
////ADD AT BEGIN//////////
//    void add_at_begin(struct node **head, int d){
//    struct node *ptr = malloc(sizeof(struct node));
//    ptr->data=d;
//    ptr->link=NULL;
//    
//    ptr->link=*head;
//    *head=ptr;
//}
//
////ADD AT CERTAIN/////////////////////////////
//void add_at_pos(struct node *head, int data, int pos){
//    struct node *ptr = head;
//    struct node *ptr2 = malloc(sizeof(struct node));
//    ptr2->data=data;
//    ptr2->link=NULL;
//    pos--;
//    while(pos!=1){
//        ptr = ptr->link;
//        pos--;
//    }
//    ptr2->link = ptr->link;
//    ptr->link = ptr2;
//}
//
////DELETE FIRST NODE//////////////
//struct node *del_first(struct node *head){
//    if(head == NULL){
//        printf("List is alredy empty!");
//    }else{
//        struct node *temp = head;
//        head = head->link;
//        free(temp);
//        temp = NULL;
//    }
//    return head;
//}
//
////DELETING THE LAST NODE/////////////////
//
////void del_last (struct node *head){
////    if(head == NULL){
////        printf("List is empty!");
////    }else if(head->link == NULL){
////        free(head);
////        head = NULL;
////    }else{
////        struct node *temp = head;
////        struct node *temp2 = head;
////        
////        while(temp->link != NULL){
////            temp2 = temp;
////            temp = temp->link;
////        }
////        temp2->link = NULL;
////        free(temp);
////        temp = NULL;
////        }
////}
//
////DELETING THE FIRST NODE USING SINGLE POINTER////////////////////
//
//void del_last (struct node *head){
//    if(head == NULL){
//        printf("List is empty!");
//    }else if(head->link == NULL){
//        free(head);
//        head = NULL;
//    }else{
//        struct node *temp = head;
//        
//        while(temp->link->link != NULL){
//            temp = temp->link;
//        }
//        free(temp->link);
//        temp->link = NULL;
//        }
//}
//
////DELETING THE NODE AT A PARTICULAR POSITION///////////////////
//
//void del_pos(struct node **head, int pos){
//    struct node *previous = *head;
//    struct node *current = *head;
//    if (*head == NULL){
//        printf("List is already empty!");
//    }else if(pos == 1){
//        *head = current->link;
//        free(current);
//        current = NULL;
//    }else{
//        while(pos!=1){
//            previous=current;
//            current = current->link;
//            pos--;
//        }
//        previous->link = current->link;
//        free(current);
//        current = NULL;
//    }
//    
//}
//
//struct node *del_list(struct node *head){
//    struct node *temp = head;
//    while(temp!=NULL){
//        temp=temp->link;
//        free(head);
//        head=temp;
//    }
//    return head;
//}
//
////REVERSE A SINGLE LINKED LIST /////////////////////////
//
//struct node *reverse(struct node *head){
//    struct node *prev = NULL;
//    struct node *next = NULL;
//    
//    while (head != NULL){
//        next = head->link;
//        head->link = prev;
//        prev = head;
//        head = next;
//    }
//    head = prev;
//    return head;
//}
//
//int main (void){
//    struct node *head = (struct node *)malloc(sizeof(struct node));
//    head -> data = 45;
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
//    head -> link -> link = current;
// 
//    
//    add_at_begin(&head, 5);
//    add_at_pos(head, 67, 3);
//    add_at_end(head, 7);
//    
//    head = del_first(head);
//    del_last(head);
//    del_pos(&head, 2);
//    head = del_list(head);
//    head = reverse(head);
//    
//    count_of_nodes(head);
//    return 0;
//}

//SINGLY LINKED LIST/////////////END///////

//DOUBLY LINKED LIST//////////////////////

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node{
//    struct node *prev;
//    int data;
//    struct node *next;
//};
//
//struct node *addToEmpty(struct node *head, int data){
//    struct node * temp = malloc(sizeof(struct node));
//    temp->prev = NULL;
//    temp->data = data;
//    temp->next = NULL;
//    head = temp;
//    return head;
//}
//
//struct node *addAtBeg(struct node *head, int data){
//    struct node *temp = malloc(sizeof(struct node));
//    temp->prev = NULL;
//    temp->data = data;
//    temp->next = NULL;
//    
//    temp->next = head;
//    head->prev = temp;
//    head = temp;
//    
//    return head;
//}
//
//struct node *addAtEnd(struct node *head, int data){
//    struct node *temp = malloc(sizeof(struct node));
//    temp->prev = NULL;
//    temp->data = data;
//    temp->next = NULL;
//    struct node *tp = NULL;
//    tp = head;
//    while(tp->next!=NULL){
//        tp = tp->next;
//    }
//    tp->next = temp;
//    temp->prev = tp;
//    
//    return head;
//}
//
//struct node *addAfterPos(struct node *head, int data, int position){
//    struct node *NewP = NULL;
//    struct node *temp = head;
//    struct node *temp2 = NULL;
//    
//    NewP = addToEmpty(NewP, data);
//    
//    while(position != 1){
//        temp = temp->next;
//        position--;
//    }
//    if(temp->next == NULL){
//        temp->next = NewP;
//        NewP->prev = temp;
//    }else{
//        temp2 = temp->next;
//        temp->next = NewP;
//        temp2->prev = NewP;
//        NewP->prev = temp;
//        NewP->next = temp2;
//    }
//    return head;
//}
//
//struct node *addBeforePos(struct node *head, int data, int position){
//    struct node *NewP = NULL;
//    struct node *temp = head;
//    struct node *temp2 = NULL;
//    
//    NewP = addToEmpty(NewP, data);
//    
//    while(position>2){
//        temp=temp->next;
//        position--;
//    }
//    if(position == 1){
//        NewP = addAtBeg(NewP, data);
//    }
//    else{
//        temp2 = temp->next;
//        temp->next = NewP;
//        temp2->prev = NewP;
//        NewP->prev = temp;
//        NewP->next = temp2;
//        
//    }
//    return head;
//}
//
//struct node *createList(struct node *head){
//    int n, i, data;
//    printf("Enter the number of nodes: ");
//    scanf("%d", &n);
//    
//    if(n==0)
//        return head;
//    
//    printf("Enter the element for the node 1: ");
//    scanf("%d", &data);
//    head = addToEmpty(head, data);
//    
//    for(i=1;i<n;i++){
//        printf("Enter the element for the node %d: ", i+1);
//        scanf("%d", &data);
//        head = addAtEnd(head, data);
//    }
//    return head;
//}
//
//struct node *delfirst(struct node *head){
//    head = head->next;
//    free(head->prev);
//    head->prev = NULL;
//    return head;
//}
//struct node *delLast(struct node *head){
//    struct node *temp, *temp2;
//    temp = head;
//    while(temp->next!=NULL)
//        temp = temp->next;
//    temp2 = temp->prev;
//    temp2->next = NULL;
//    free(temp);
//    return head;
//    
//}
//
//struct node *delInter(struct node *head, int pos){
//    struct node *temp = head;
//    struct node *temp2;
//    while(pos>1){
//        temp = temp->next;
//        pos--;
//    }
//    temp2 = temp->prev;
//    temp2->next = temp->next;
//    temp->next->prev=temp2;
//    free(temp);
//    temp=NULL;
//    return head;
//}
//
//struct node *reverse(struct node *head){
//    struct node *ptr1 = head;
//    struct node *ptr2 = ptr1->next;
//    
//    ptr1->next = NULL;
//    ptr1->prev = ptr2;
//    
//    while(ptr2!=NULL){
//        ptr2->prev = ptr2->next;
//        ptr2->next = ptr1;
//        ptr1 = ptr2;
//        ptr2 = ptr2->prev;
//    }
//    head = ptr1;
//    return head;
//    
//}
//
//void print (struct node *head){
//    struct node *ptr = NULL;
//    ptr = head;
//    while(ptr!=NULL){
//        printf("%d\n", ptr->data);
//        ptr = ptr->next;
//    }
//}
//int main(void){
//    
//    struct node *head = NULL;
//    
//    head = addToEmpty(head, 34);
////    head = addAtBeg(head, 34);
//    head = addAtEnd(head, 45);
//    head = addAtEnd(head, 9);
////    head = addAfterPos(head, 7, 2);
////    head = addBeforePos(head, 25, 3);
////    head = createList(head);
//  
//    printf("Before revesing: \n");
//    print(head);
//    head = reverse(head);
//    printf("After reversing: \n");
//    print(head);
//
//    return 0;
//}

//END OF DOUBLY LINKED LIST /////////////////
//CIRCULAR SINGLE LINKED LIST ////////////////////////

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//    int data;
//    struct node *next;
//};
//struct node *addToEmpty(int data){
//    struct node *temp = malloc(sizeof(struct node));
//    temp->data = data;
//    temp->next = temp;
//    return temp;
//}
//struct node *addAtBegin(struct node *tail, int data){
//    struct node *temp = malloc(sizeof(struct node));
//    temp->data = data;
//    temp->next = NULL;
//    
//    temp->next = tail->next;
//    tail->next = temp;
//    return tail;
//}
//
//struct node *addAtEnd(struct node *tail, int data){
//    struct node *temp = malloc(sizeof(struct node));
//    temp->data = data;
//    temp->next = NULL;
//    
//    temp->next = tail->next;
//    tail->next = temp;
//    tail = tail->next;
//    return tail;
//}
//
//struct node *addAfterPos(struct node *tail, int data, int pos){
//    struct node *newP = malloc(sizeof(struct node));
//    newP->data = data;
//    newP->next = NULL;
//    
//    struct node *p = tail->next;
//    while(pos!=1){
//        p = p->next;
//        pos--;
//    }
//    newP->next = p->next;
//    p->next = newP;
//     if(p == tail)
//         tail = tail->next;
//
//    return tail;
//}
//
//struct node *createList(struct node *tail){
//    int i, n, data;
//    printf("Enter the number of nodes of the linked list: ");
//    scanf("%d", &n);
//    
//    if(n==0)
//        return tail;
//    printf("Enter the element 1: ");
//    scanf("%d", &data);
//    tail = addToEmpty(data);
//    for(i=1;i<n;i++){
//        printf("Enter the element %d: ", i+1);
//        scanf("%d", &data);
//        tail = addAtEnd(tail, data);
//    }
//    return tail;
//}
//
//struct node *delFirst(struct node *tail){
//    struct node *temp = tail->next;
//    if(temp==NULL)
//        return tail;
//    if(temp==tail){
//        free(tail);
//        tail=NULL;
//        return tail;
//    }else{
//        tail->next = temp->next;
//        free(temp);
//        temp = NULL;
//        return tail;
//    }
//}
//
//struct node *delLast(struct node *tail){
//    if (tail == NULL)
//        return tail;
//    if(tail->next == NULL){
//        free(tail);
//        tail = NULL;
//        return tail;
//    }else{
//        struct node *temp = tail->next;
//        while(temp->next != tail){
//            temp = temp->next;
//        }
//        temp->next = tail->next;
//        free(tail);
//        tail = temp;
//        return tail;
//    }
//}
//
//struct node *delInter(struct node *tail, int pos){
//    if(tail==NULL)
//        return tail;
//    struct node *temp = tail->next;
//    if(tail->next == tail){
//        free(tail);
//        tail = NULL;
//        return tail;
//    }
//    while(pos>2){
//        temp = temp->next;
//        pos--;
//    }
//    struct node *temp2 = temp->next;
//    temp->next = temp2->next;
//    if(temp2 == tail)
//        tail = temp;
//    free(temp2);
//    temp2 = NULL;
//    return tail;
//}
//
//int searchEl(struct node *tail, int element){
//    struct node *temp;
//    int index = 0;
//    
//    if(tail == NULL)
//        return -2;
//    temp = tail->next;
//    do{
//        if(temp->data==element)
//            return index;
//        temp = temp->next;
//        index++;
//    }while(temp!=tail->next);
//        return -1;
//}
//
//void countEl(struct node *tail){
//    struct node *temp = tail->next;
//    int count = 1;
//    while (temp != tail){
//        count++;
//        temp = temp->next;
//    }
//    printf("There are %d elements in the list.\n", count);
//}
//
//void print(struct node *tail){
//    if(tail == NULL){
//        printf("No node in the list.\n");
//    }else{
//        struct node *p = tail->next;
//        do {
//            printf("%d\n", p->data);
//            p = p->next;
//        } while (p!=tail->next);
//    }
//}
//
//int main (void){
//    struct node* tail = NULL;
//    int element;
//    tail = addToEmpty(45);
//    tail = addAtBegin(tail, 34);
//    tail = addAtEnd(tail, 56);
//    tail = addAfterPos(tail, 77, 3);
//    
//    printf("Enter the element: ");
//    scanf("%d", &element);
//    int index = searchEl(tail, element);
//    
//    if(index == -1){
//        printf("Element not found!\n");
//    }if(index == -2){
//        printf("Linked list is empty!\n");
//    }else{
//        printf("Element %d is at index %d.\n", element, index);
//    }
////    tail = createList(tail);
////    printf("Before deleteing:\n");
////    print(tail);
////    printf("After deleting:\n");
////    tail = delLast(tail);
////    tail = delFirst(tail);
////    tail = delInter(tail, 3);
////    countEl(tail);
//    
//    
//    print(tail);
//    
//    return 0;
//}

// END OF CIRCULAR SINGLY LIKED LIST///////////////////

//  CIRCULAR DOUBLY LINKED LIST //////////////////////
    
//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//    struct node *prev;
//    int data;
//    struct node *next;
//};
//struct node *addAtEmpty(int data){
//    struct node *temp = malloc(sizeof(struct node));
//    temp->prev = NULL;
//    temp->data = data;
//    temp->next = temp;
//    return temp;
//}
//struct node *addAtBegin(struct node *tail, int data){
//    struct node *temp = malloc(sizeof(struct node));
//    temp->prev = NULL;
//    temp->data = data;
//    temp->next = NULL;
//    
//    struct node *temp2 = tail->next;
//    
//    if(tail==NULL){
//        tail=addAtEmpty(data);
//    }else{
//        temp->prev = tail;
//        temp->next = temp2;
//        temp2->prev = temp;
//        tail->next = temp;
//    }
//    return tail;
//}
//
//struct node *addAtEnd(struct node *tail, int data){
//    struct node *newP = malloc(sizeof(struct node));
//    newP->prev = NULL;
//    newP->data = data;
//    newP->next = NULL;
//    
//    if(tail==NULL){
//        return newP;
//    }else{
//        struct node *temp = tail->next;
//        newP->next = tail->next;
//        newP->prev = tail;
//        tail->next = newP;
//        temp->prev = newP;
//        tail = newP;
//    }
//    return tail;
//}
//
//struct node *addAfterPos(struct node *tail, int data, int pos){
//    struct node *newP = malloc(sizeof(struct node));
//    newP->prev = NULL;
//    newP->data = data;
//    newP->next = NULL;
//    
//    if(tail == NULL)
//        return newP;
//    
//    struct node *temp = tail->next;
//    while(pos>1){
//        temp = temp->next;
//        pos--;
//    }
//    newP->next = temp->next;
//    newP->prev = temp;
//    temp->next->prev = newP;
//    temp->next = newP;
//    if(temp == tail)
//        tail = tail->next;
//    
//    return tail;
//}
//
//struct node *delFirst(struct node *tail){
//    struct node *temp = tail->next;
//    if(tail==NULL)
//        return tail;
//    if(temp == tail){
//        free(tail);
//        tail = NULL;
//        return tail;
//    }
//    tail->next = temp->next;
//    temp->next->prev = tail;
//    free(temp);
//    temp = NULL;
//    
//    return tail;
//}
//
//struct node *delLast(struct node *tail){
//    struct node *temp;
//    temp = tail->prev;
//    if(tail==NULL)
//        return tail;
//    if(temp == tail){
//        free(tail);
//        tail = NULL;
//        return tail;
//    }
//    temp->next = tail->next;
//    tail->next->prev = temp;
//    free(tail);
//    tail = temp;
//    return tail;
//    
//}
//struct node *delInter(struct node *tail, int pos){
//    struct node *temp = tail->next;
//    while(pos>1){
//        temp = temp->next;
//        pos--;
//    }
//    struct node *temp2 = temp->prev;
//    temp2->next = temp->next;
//    temp->next->prev = temp2;
//    free(temp);
//    if(temp==tail)
//        tail = temp2;
//    return  tail;
//}
//
//void print(struct node *tail){
//    struct node *temp = tail->next;
//    
//    do{
//        printf("%d\n", temp->data);
//        temp = temp->next;
//    }while(temp != tail->next);
//}
//
//int main(void){
//    struct node *tail = NULL;
//    tail = addAtEmpty(12);
//    tail = addAtEnd(tail, 24);
//    tail = addAtEnd(tail, 67);
////    tail = addAfterPos(tail, 78, 2);
//    
//      tail = delInter(tail, 2);
////    tail = delFirst(tail);
////    tail = delLast(tail);
//    print(tail);
//    return 0;
//}

//STACK/////// DATA STERUCTURE////////////


//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//// Struktura za stek
//typedef struct {
//    int *collection;  // pokazivač na niz
//    int capacity;     // kapacitet steka
//    int size;         // trenutna veličina steka
//} Stack;
//
//// Funkcija za kreiranje steka
//Stack *createStack(int capacity) {
//    if (capacity <= 0) return NULL;
//    
//    Stack *stack = (Stack *)malloc(sizeof(Stack));
//    if (stack == NULL) return NULL;
//    
//    stack->collection = (int *)malloc(sizeof(int) * capacity);
//    if (stack->collection == NULL) {
//        free(stack);
//        return NULL;
//    }
//    stack->capacity = capacity;
//    stack->size = 0;
//    
//    return stack;
//}
//
//// Funkcija za uništavanje steka
//void destroyStack(Stack *stack) {
//    if (stack != NULL) {
//        free(stack->collection);
//        free(stack);
//    }
//}
//
//// Funkcija koja proverava da li je stek pun
//bool isFull(Stack *stack) {
//    return stack->size == stack->capacity;
//}
//
//// Funkcija koja proverava da li je stek prazan
//bool isEmpty(Stack *stack) {
//    return stack->size == 0;
//}
//
//// Funkcija za dodavanje elementa na stek
//bool push(Stack *stack, int item) {
//    if (isFull(stack)) return false;
//    
//    stack->collection[stack->size] = item;
//    stack->size++;
//    
//    return true;
//}
//
//// Funkcija za uklanjanje elementa sa steka
//bool pop(Stack *stack, int *item) {
//    if (isEmpty(stack)) return false;
//    
//    stack->size--;
//    *item = stack->collection[stack->size];
//    
//    return true;
//}
//
//// Funkcija za pregled elementa na vrhu steka
//bool peek(Stack *stack, int *item) {
//    if (isEmpty(stack)) return false;
//    
//    *item = stack->collection[stack->size - 1];
//    
//    return true;
//}
//int main(void) {
//    Stack *stack = createStack(5);
//    
//    if (stack == NULL) {
//        printf("Error creating stack.\n");
//        return 1;
//    }
//    
//    if (isEmpty(stack)) printf("Stack is empty.\n");
//    
//    push(stack, 2);
//    printf("Size of stack: %d\n", stack->size);
//    
//    push(stack, 9);
//    push(stack, 4);
//    push(stack, 7);
//    push(stack, 8);
//    
//    if (isFull(stack)) printf("Stack is full.\n");
//    printf("Size of stack: %d\n", stack->size);
//    
//    bool try_push = push(stack, 5);
//    if(try_push==false) printf("Push failed.\n");
//    
//    int peek_val = 0;
//    peek(stack, &peek_val);
//    printf("Peek value is: %d\n", peek_val);
//    
//    int pop_val = 0;
//    
//    for(int i = 0;i < 5;i++){
//        pop(stack, &pop_val);
//        printf("The poped value is: %d\n", pop_val);
//    }
//    
//    bool try_pop = pop(stack, &pop_val);
//    if(try_pop == false) printf("pop failed!\n");
//    
//    bool try_peek = pop(stack, &peek_val);
//    if(try_peek == false) printf("peek failed!\n");
//
//    
//    destroyStack(stack);
//    
//    return 0;
//}


//QUEUE//////////////////////////////////////////////////////

//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX 100 // Maksimalna veličina reda
//
//typedef struct {
//    int items[MAX];
//    int front, rear;
//} Queue;
//
//void init(Queue *q) {
//    q->front = -1;
//    q->rear = -1;
//}
//
//int isEmpty(Queue *q) {
//    return q->front == -1 || q->front > q->rear;
//}
//
//int isFull(Queue *q) {
//    return q->rear == MAX - 1;
//}
//
//void enqueue(Queue *q, int value) {
//    if (isFull(q)) {
//        printf("Queue overflow\n");
//        return;
//    }
//    if (isEmpty(q)) {
//        q->front = 0;
//    }
//    q->items[++(q->rear)] = value;
//}
//
//int dequeue(Queue *q) {
//    if (isEmpty(q)) {
//        printf("Queue underflow\n");
//        return -1;
//    } else {
//        return q->items[(q->front)++];
//    }
//}
//
//int front(Queue *q) {
//    if (isEmpty(q)) {
//        printf("Queue is empty\n");
//        return -1;
//    } else {
//        return q->items[q->front];
//    }
//}
//
//int main(void) {
//    Queue q;
//    init(&q);
//
//    enqueue(&q, 10);
//    enqueue(&q, 20);
//    enqueue(&q, 30);
//
//    printf("Element na pocetku reda: %d\n", front(&q));
//    dequeue(&q);
//    printf("Element na pocetku reda: %d\n", front(&q));
//
//    return 0;
//}

//  QUEUE WITH LINKED LIST

//#include <stdio.h>
//#include <stdlib.h>
//
//// Struktura za čvor u povezanoj listi
//typedef struct Node {
//    int data;
//    struct Node* next;
//} Node;
//
//// Struktura za red
//typedef struct Queue {
//    Node* front; // Pokazivač na prvi element u redu
//    Node* rear;  // Pokazivač na poslednji element u redu
//} Queue;
//
//// Funkcija za inicijalizaciju reda
//void init(Queue* q) {
//    q->front = NULL;
//    q->rear = NULL;
//}
//
//// Funkcija za proveru da li je red prazan
//int isEmpty(Queue* q) {
//    return q->front == NULL;
//}
//
//// Funkcija za dodavanje elemenata u red (enqueue)
//void enqueue(Queue* q, int value) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    if (newNode == NULL) {
//        printf("Memory allocation error\n");
//        return;
//    }
//    newNode->data = value;
//    newNode->next = NULL;
//
//    if (isEmpty(q)) {
//        q->front = newNode;
//        q->rear = newNode;
//    } else {
//        q->rear->next = newNode;
//        q->rear = newNode;
//    }
//}
//
//// Funkcija za uklanjanje elemenata iz reda (dequeue)
//int dequeue(Queue* q) {
//    if (isEmpty(q)) {
//        printf("Queue is empty\n");
//        return -1;
//    }
//    Node* temp = q->front;
//    int data = temp->data;
//    q->front = q->front->next;
//
//    if (q->front == NULL) {
//        q->rear = NULL;
//    }
//    free(temp);
//    return data;
//}
//
//// Funkcija za pristup prvom elementu reda (peek/front)
//int front(Queue* q) {
//    if (isEmpty(q)) {
//        printf("Queue is empty\n");
//        return -1;
//    }
//    return q->front->data;
//}
//
//int main(void) {
//    Queue q;
//    init(&q);
//
//    enqueue(&q, 10);
//    enqueue(&q, 20);
//    enqueue(&q, 30);
//    
//    printf("Front of the queue: %d\n", front(&q));
//    printf("Element removed from the queue: %d\n", dequeue(&q));
//    printf("Front of the queue: %d\n", front(&q));
//
//    return 0;
//}
//

// BINARY TREE///////////////////////

//#include <stdio.h>
//#include <stdlib.h>
//
//// Definicija strukture čvora
//typedef struct Node {
//    int data;
//    struct Node *left;
//    struct Node *right;
//} Node;
//
//// Funkcija za kreiranje novog čvora
//Node* createNode(int data) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    newNode->data = data;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    return newNode;
//}
//
//// Funkcija za umetanje elementa u binarno stablo pretrage
//Node* insert(Node* root, int data) {
//    if (root == NULL) {
//        return createNode(data);
//    }
//    if (data < root->data) {
//        root->left = insert(root->left, data);
//    } else if (data > root->data) {
//        root->right = insert(root->right, data);
//    }
//    return root;
//}
//
//// Rekurzivna funkcija za ispisivanje listova stabla
//void printLeaves(Node* root) {
//    if (root == NULL) {
//        return;
//    }
//    if (root->left == NULL && root->right == NULL) {
//        printf("%d ", root->data);
//    }
//    printLeaves(root->left);
//    printLeaves(root->right);
//}
//
//// Glavni program
//int main(void) {
//    int arr[] = {13, 5, 22, 27, 15, 8, 3, 11};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    
//    Node* root = NULL;
//    for (int i = 0; i < n; i++) {
//        root = insert(root, arr[i]);
//    }
//    
//    printf("Listovi stabla su: ");
//    printLeaves(root);
//    printf("\n");
//    
//    return 0;
//}

// HESIRANJE///////////////////////////////////

//#include <stdio.h>
//#include <stdlib.h>
//
//#define TABLE_SIZE 11
//
//typedef struct {
//    int* table;
//    int size;
//} HashTable;
//
//// Funkcija za inicijalizaciju hash tabele
//void initHashTable(HashTable* ht) {
//    ht->table = (int*)malloc(TABLE_SIZE * sizeof(int));
//    ht->size = TABLE_SIZE;
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        ht->table[i] = -1;  // -1 označava prazno mesto
//    }
//}
//
//// Hash funkcija
//unsigned int hashFunction(int key) {
//    return key % TABLE_SIZE;
//}
//
//// Funkcija za umetanje u hash tabelu
//void insert(HashTable* ht, int key) {
//    unsigned int index = hashFunction(key);
//    int originalIndex = index;
//    while (ht->table[index] != -1) {
//        index = (index + 1) % TABLE_SIZE;
//        if (index == originalIndex) {
//            printf("Hash table is full\n");
//            return;
//        }
//    }
//    ht->table[index] = key;
//}
//
//// Funkcija za pretragu u hash tabeli
//int search(HashTable* ht, int key) {
//    unsigned int index = hashFunction(key);
//    int originalIndex = index;
//    while (ht->table[index] != -1) {
//        if (ht->table[index] == key) {
//            return index;
//        }
//        index = (index + 1) % TABLE_SIZE;
//        if (index == originalIndex) {
//            return -1; // Ključ nije pronađen
//        }
//    }
//    return -1; // Ključ nije pronađen
//}
//
//// Funkcija za brisanje iz hash tabele
//void delete(HashTable* ht, int key) {
//    int index = search(ht, key);
//    if (index == -1) {
//        printf("Key not found\n");
//        return;
//    }
//    ht->table[index] = -1;
//}
//
//// Glavni program
//int main(void) {
//    HashTable ht;
//    initHashTable(&ht);
//
//    int arr[] = {13, 5, 22, 27, 15, 8, 3, 11};
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    // Umetanje elemenata u hash tabelu
//    for (int i = 0; i < n; i++) {
//        insert(&ht, arr[i]);
//    }
//
//    // Prikaz umetnutih elemenata
//    printf("Hash table:\n");
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        if (ht.table[i] != -1) {
//            printf("Index %d: %d\n", i, ht.table[i]);
//        } else {
//            printf("Index %d: EMPTY\n", i);
//        }
//    }
//
//    // Pretraga elemenata u hash tabeli
//    printf("\nPretraga u hash tabeli:\n");
//    for (int i = 0; i < n; i++) {
//        int index = search(&ht, arr[i]);
//        if (index != -1) {
//            printf("Key %d found at index %d\n", arr[i], index);
//        } else {
//            printf("Key %d not found\n", arr[i]);
//        }
//    }
//
//    // Oslobađanje memorije
//    free(ht.table);
//
//    return 0;
//}
//


//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Node{
//    struct node *prev;
//    int data;
//    struct node *next;
//}Node;
//
//
//int main(void){
//    
//    return 0;
//}
