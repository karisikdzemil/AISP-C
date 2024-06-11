#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *link;
};

int main(){
    struct node *head = malloc(sizeof(struct node));
    head -> data=45;
    head -> link = NULL;
    
    struct node *current = malloc (sizeof(struct node));
    head -> link = current;
    current -> data = 85;
    current -> link = NULL;
    
    struct node *third = malloc(sizeof(struct node));
    third -> data = 21;
    third -> link = NULL;
    current -> link = third;
    
    return 0;
}
