#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
} node;

typedef struct NodeHeader{
    node* head;
    node* tail;
} nodeHeader;

void addNode(nodeHeader* header, int val){
    if(header->head == NULL){
        header->head = (node*)malloc(sizeof(node));
        header->head->value = val;
        header->head->next = NULL;
        header->tail = header->head;
    }
    else{
        node* current = header->head;
        while(current->next != NULL){
            current = current->next;
        }
        header->tail = (node*)malloc(sizeof(node));
        header->tail->value = val;
        header->tail->next = NULL;
        current->next = header->tail;
    }
}

void printNode(nodeHeader* header){
    node* current = header->head; 
    while(current->next != header->tail->next){
        printf("%d, ",current->value);
        current = current->next;    
    }
    printf("%d, ",current->value);
}

int main(){
    nodeHeader* nh = (nodeHeader*)malloc(sizeof(nodeHeader));
    nh->head = NULL;
    nh->tail = NULL;
    addNode(nh,1);
    addNode(nh,2);
    addNode(nh,3);

    printNode(nh);
}
