#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertAtBeginning(struct Node** head, int val);
void insertAtEnd(struct Node** head, int val);
void deleteNode(struct Node** head, int key);
void displayList(struct Node* head);
void freeList(struct Node* head);

int main() {
    struct Node* head = NULL; // Initialize empty list

    // Insert elements
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Linked List after insertions: ");
    displayList(head);

    // Delete elements
    printf("\nDeleting node with value 20...\n");
    deleteNode(&head, 20);
    displayList(head);

    printf("\nDeleting node with value 30...\n");
    deleteNode(&head, 30);
    displayList(head);

    // Free memory before exiting
    freeList(head);
    return 0;
}

// Insert a new node at the start of the list
void insertAtBeginning(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

// Insert a new node at the end of the list
void insertAtEnd(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete the first occurrence of a node containing the key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Case 1: Head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        free(temp);         // Free old head
        return;
    }

    // Case 2: Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the linked list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Print the entire linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free allocated memory to avoid memory leaks
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

