#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next; 
};

struct node* CreateNode(int val)
{
    struct node* NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode->data = val;
    NewNode->next = NULL;
    return NewNode;
}



void InsertAtBeginning(struct node** headref, int val)
{
    struct node* NewNode = CreateNode(val);
    NewNode->next = *headref;
    *headref = NewNode;
}

void InsertAtEnd(struct node** headref, int val)
{
    struct node* NewNode = CreateNode(val);
    if(*headref == NULL)
    {
        *headref = NewNode;
        return;
    }

    struct node* current = *headref;
    while(current->next!= NULL)
    {
        current = current->next;
    }
    current->next = NewNode;
}

void printll(struct node* head)
{
    struct node* current = head;
    while(current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
}

int main(){
    struct node* head = NULL;
    InsertAtBeginning(&head, 10);
    InsertAtBeginning(&head, 20);
    InsertAtBeginning(&head, 30);
    InsertAtEnd(&head, 30);
    printll(head);
    struct node* current = head;
  while (current != NULL){
    struct node* temp = current;
    current = current-> next;
    free(temp);
   }

}

