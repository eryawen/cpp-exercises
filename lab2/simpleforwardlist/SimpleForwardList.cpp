//
// Created by mk on 29.04.2017.
//

#include "SimpleForwardList.h"

ForwardList *CreateNode(int value) {
    ForwardList *head = new ForwardList;
    head->value = value;
    return head;
}

void DestroyList(ForwardList *list) {
    while (list != nullptr) {
        ForwardList *next = list->next;
        delete list;
        list = next;
        next = nullptr;
    }
}

ForwardList *PushFront(ForwardList *list, int value) {
    if (list == nullptr) {
        return nullptr;
    }
    ForwardList *new_head = new ForwardList;
    new_head->value = value;
    new_head->next = list;
    return new_head;
}

void Append(ForwardList *list, ForwardList *tail) {
    if (list == nullptr) {
        list = tail;
        return;
    }
    ForwardList *node = list;
    while (node != nullptr && node->next != nullptr) {
        node = node->next;
    }
    node->next = tail;
}