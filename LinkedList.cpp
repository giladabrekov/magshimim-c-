#include "LinkedList.h"

void initList(LinkedList* list)
{
    list->head = nullptr;
}

void cleanList(LinkedList* list)
{
    while (!isEmptyList(list))
    {
        removeFirst(list);
    }
}

void insertFirst(LinkedList* list, unsigned int value)
{
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = list->head;
    list->head = newNode;
}

int removeFirst(LinkedList* list)
{
    if (isEmptyList(list))
    {
        return -1;
    }

    Node* temp = list->head;
    int value = temp->value;
    list->head = list->head->next;

    delete temp;

    return value;
}

bool isEmptyList(LinkedList* list)
{
    return list->head == nullptr;
}