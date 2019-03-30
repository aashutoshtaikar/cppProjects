#include <iostream>
#include <vector>

class SinglyLinkedListNode{
public:
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) 
{
    SinglyLinkedListNode* curr;
    SinglyLinkedListNode* n;
    n->data = data;

    for(int pos = 0; pos<=position; pos++){    
        if (position==0){                           //insert to head position
            n->next = head;
            head = n;
        }
        else if(pos==position && curr->next!=NULL){ //between 
            n->next = curr->next;
            curr->next = n;
        }
        else if(pos==position && curr->next==NULL){  //last
            curr->next = n;
            n->next = NULL;
        }
        if(position==0 || pos==position){ 
            break;
        }
        else {
            curr = curr->next;
        }
    }

    return head;
}

int main(int argc, char const *argv[])
{
    SinglyLinkedListNode* test;

    return 0;
}
