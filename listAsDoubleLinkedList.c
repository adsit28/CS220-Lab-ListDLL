/** 
 * ================================================================
 * Name: 
 * Section: 
 * Project: Implementation of Double-Linked List Library
 * Doc - completed entirely by chatgpt
 * =================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "listAsDoubleLinkedList.h"

// Create a new empty linked list
DoubleLinkedList* createLinkedList() {
    DoubleLinkedList* list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    if (!list) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->numberOfElements = 0;
    return list;
}

// Delete the linked list and free all allocated memory
void deleteLinkedList(DoubleLinkedList* list) {
    if (list) {
        Node* current = list->head;
        Node* nextNode;
        while (current) {
            nextNode = current->next;
            free(current);
            current = nextNode;
        }
        free(list);
    }
}

// Add a new element to the end of the list
void appendElementLinkedList(DoubleLinkedList* list, int element) {
    if (!list) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = element;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail) {
        list->tail->next = newNode;
    } else {
        list->head = newNode;  // The list was empty, so newNode is both head and tail
    }

    list->tail = newNode;
    list->numberOfElements++;
}

// Get the number of elements in the linked list
int lengthOfLinkedList(DoubleLinkedList* list) {
    if (!list) return 0;
    return list->numberOfElements;
}

// Print the elements of the linked list
void printLinkedList(DoubleLinkedList* list) {
    if (!list) return;

    Node* current = list->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Get the element at a specified position in the list
int getElementLinkedList(DoubleLinkedList* list, int position) {
    if (!list || position < 0 || position >= list->numberOfElements) {
        return -1;  // Return -1 if the position is out of bounds
    }

    Node* current = list->head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    return current->data;
}

// Delete the element at a given position
void deleteElementLinkedList(DoubleLinkedList* list, int position) {
    if (!list || position < 0 || position >= list->numberOfElements) return;

    Node* current = list->head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }

    if (current->prev) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;  // We're deleting the head node
    }

    if (current->next) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;  // We're deleting the tail node
    }

    free(current);
    list->numberOfElements--;
}

// Insert a new element at a given position
void insertElementLinkedList(DoubleLinkedList* list, int position, int element) {
    if (!list || position < 0 || position > list->numberOfElements) return;

    if (position == list->numberOfElements) {
        appendElementLinkedList(list, element);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = element;

    Node* current = list->head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }

    newNode->prev = current->prev;
    newNode->next = current;

    if (current->prev) {
        current->prev->next = newNode;
    } else {
        list->head = newNode;  // Inserting at the head
    }

    current->prev = newNode;
    list->numberOfElements++;
}

// Change the element at a given position
void changeElementLinkedList(DoubleLinkedList* list, int position, int newElement) {
    if (!list || position < 0 || position >= list->numberOfElements) return;

    Node* current = list->head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }

    current->data = newElement;
}

// Find the position of an element in the list
int findElementLinkedList(DoubleLinkedList* list, int element) {
    if (!list) return -1;

    Node* current = list->head;
    int position = 0;

    while (current) {
        if (current->data == element) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;  // Element not found
}


