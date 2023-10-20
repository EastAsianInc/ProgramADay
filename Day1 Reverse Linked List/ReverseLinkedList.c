#include <stdio.h>
#include <stdlib.h>

// This is a singly linked list, whose data can only be of type int
// Alias Node for easier reading

typedef struct Node
{
    int data;
    struct Node* next;
} Node;


//This is an old function from homework
int makeList(Node **list)
{
    if (NULL == list)
    {
        printf("Error somewhere in makeList");
        return 0;
    }
    *list = NULL;
    return 0;
}

//Same list created from makeList, if want to have dynamic data should change int to a void*, that's a struct change
int insertAtHead(Node **list, int *data)
{
    if(NULL == list || NULL == data)
    {
        //Error
        printf("Error inserting at head");
        return 1;
    }

    Node *newHead = (Node*)malloc(sizeof(Node));
    //if malloc fails
    if(NULL == newHead)
    {
        //Error
        return 1;
    }

    newHead -> data = *data;
    newHead -> next = *list;

    *list = newHead;

    return 0;
}

//Takes start of a linked list, returns the linked list reversed
Node* reverseLinkedList(Node *head)
{
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void printLinkedList(Node *head)
{
    Node* current = head;
    while (current != NULL)
    {
        printf("%d -> ", current -> data);
        current = current ->next;
    }
    printf("NULL\n");
}


int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *list;
    makeList(&list); // Create an empty list

    int values[] = {5,4,3,2,1};

    // Insert values at the head of the list
    for (int i = 0; i < 5; i++) {
        insertAtHead(&list, &values[i]);
    }

    printf("Original Linked List: ");
    printLinkedList(list);

    // Reverse the linked list
    list = reverseLinkedList(list);

    printf("Reversed Linked List: ");
    printLinkedList(list);

    // Free the memory 
    Node *current = list;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}