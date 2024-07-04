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
////    head = del_list(head);
//    head = reverse(head);
//    
//    count_of_nodes(head);
//    return 0;
//}

//SINGLY LINKED LIST/////////////END///////

//DOUBLY LINKED LIST//////////////////////

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *addToEmpty(struct node *head, int data){
    struct node * temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node *addAtBeg(struct node *head, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    
    temp->next = head;
    head->prev = temp;
    head = temp;
    
    return head;
}

struct node *addAtEnd(struct node *head, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    struct node *tp = NULL;
    tp = head;
    while(tp->next!=NULL){
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    
    return head;
}

struct node *addAfterPos(struct node *head, int data, int position){
    struct node *NewP = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    
    NewP = addToEmpty(NewP, data);
    
    while(position != 1){
        temp = temp->next;
        position--;
    }
    if(temp->next == NULL){
        temp->next = NewP;
        NewP->prev = temp;
    }else{
        temp2 = temp->next;
        temp->next = NewP;
        temp2->prev = NewP;
        NewP->prev = temp;
        NewP->next = temp2;
    }
    return head;
}

struct node *addBeforePos(struct node *head, int data, int position){
    struct node *NewP = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    
    NewP = addToEmpty(NewP, data);
    
    while(position>2){
        temp=temp->next;
        position--;
    }
    if(position == 1){
        NewP = addAtBeg(NewP, data);
    }
    else{
        temp2 = temp->next;
        temp->next = NewP;
        temp2->prev = NewP;
        NewP->prev = temp;
        NewP->next = temp2;
        
    }
    return head;
}

struct node *createList(struct node *head){
    int n, i, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    if(n==0)
        return head;
    
    printf("Enter the element for the node 1: ");
    scanf("%d", &data);
    head = addToEmpty(head, data);
    
    for(i=1;i<n;i++){
        printf("Enter the element for the node %d: ", i+1);
        scanf("%d", &data);
        head = addAtEnd(head, data);
    }
    return head;
}

struct node *delfirst(struct node *head){
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}

void print (struct node *head){
    struct node *ptr = NULL;
    ptr = head;
    while(ptr!=NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main(void){
    
    struct node *head = NULL;
    
    head = addToEmpty(head, 34);
//    head = addAtBeg(head, 34);
    head = addAtEnd(head, 45);
    head = addAtEnd(head, 9);
//    head = addAfterPos(head, 7, 2);
//    head = addBeforePos(head, 25, 3);
//    head = createList(head);
  
    printf("Before Deletion: \n");
    print(head);
    head = delfirst(head);
    printf("After delition: \n");
    print(head);

    return 0;
}
