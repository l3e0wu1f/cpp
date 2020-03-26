// This is the implementation file of project 5
// Name: Josh Lewis
// Email: jblewis@mail.fhsu.edu
// Date: 3/17/2018

#include <iostream>
#include "CSCI361Proj5.h"

using namespace std;
using namespace FHSULINKEDLIST;

size_t list_length(const Node* head_ptr)
{
    if(head_ptr == NULL) { return 0; }
    size_t count = 0;
    const Node* current_ptr;
    for(current_ptr = head_ptr; current_ptr != NULL; current_ptr = current_ptr ->link) {
        count++;
    }
    return count;
}

void list_head_insert(Node*& head_ptr, const Node::Item& entry)
{
    Node* newNode = new Node;
    newNode -> data = entry;
    newNode -> link = head_ptr; // make new node's link the old head_ptr
    head_ptr = newNode; // head points to new node
}

void list_insert(Node* previous_ptr, const Node::Item& entry)
{
    if(previous_ptr == NULL) {return;}
    Node* newNode = new Node;
    newNode -> data = entry;
    newNode -> link = previous_ptr -> link;
    previous_ptr -> link = newNode;
}

Node* list_search(Node* head_ptr, const Node::Item& target)
{
    for(; head_ptr != NULL; head_ptr = head_ptr -> link) {
        if(head_ptr -> data == target) {
            return head_ptr;
        }
    }
    return NULL;
}

Node* list_locate(Node* head_ptr, size_t position)
{
    size_t i = 1;
    for(; i < position && head_ptr != NULL; head_ptr = head_ptr -> link) {
        i++;
    }
    return head_ptr;
}

void list_head_remove(Node*& head_ptr)
{
    if(head_ptr == NULL) {
        return; // If empty, do nothing
    }
    if(head_ptr -> link == NULL) {
        delete head_ptr;
        head_ptr = NULL;
        return;
    }
    Node* remove_ptr = head_ptr;
    head_ptr = remove_ptr -> link;
    delete remove_ptr;
}

void list_remove(Node* previous_ptr)
{
    if(previous_ptr == NULL || previous_ptr -> link == NULL) {
        return; // If empty, do nothing
    }
    Node* remove_ptr = previous_ptr -> link;
    previous_ptr -> link = remove_ptr -> link;
    delete remove_ptr;
}

void list_clear(Node*& head_ptr)
{
    while(head_ptr != NULL) {
        list_head_remove(head_ptr);
    }
}

void list_copy(Node* source_ptr, Node*& head_ptr)
{
    if(source_ptr == NULL) { // if source empty, head_ptr = null
        head_ptr = NULL;
        return;
    }
    head_ptr = NULL;
    list_head_insert(head_ptr, source_ptr -> data);
    source_ptr = source_ptr -> link;
    Node* previous_ptr = head_ptr;
    while(source_ptr != NULL){
        list_insert(previous_ptr, source_ptr -> data);
        source_ptr = source_ptr -> link;
        previous_ptr = previous_ptr -> link;
    }
}

size_t list_occurrences(Node* head_ptr, const Node::Item& target)
{
    size_t count = 0;
    for(; head_ptr != NULL; head_ptr = head_ptr -> link) {
        if(head_ptr -> data == target) {
            count++;
        }
        return count;
    }
}

void list_tail_attach(Node*& head_ptr, const Node::Item& entry)
{
    if(head_ptr == NULL) {
        list_head_insert(head_ptr, entry);
        return;
    }
    Node* tail_ptr = head_ptr;
    while(tail_ptr -> link != NULL) {
        tail_ptr = tail_ptr -> link;
    }
    list_insert(tail_ptr, entry);
}

void list_tail_remove(Node*& head_ptr)
{
    if(head_ptr == NULL) { return; }
    if(head_ptr -> link == NULL) {
        list_head_remove(head_ptr);
        return;
    }
    Node* before_tail = head_ptr;
    while (before_tail -> link -> link != NULL) {
        before_tail = before_tail -> link;
    }
    list_remove(before_tail);
}

Node* list_copy_front(Node* source_ptr, size_t n)
{
    Node* head_ptr = NULL;
    if(n == 0 || source_ptr == NULL) { // if there's nothing to copy
        return head_ptr;
    }
    list_head_insert(head_ptr, source_ptr -> data);
    size_t count = 1; // number copied
    source_ptr = source_ptr -> link;
    Node* previous_ptr = head_ptr;
    while(source_ptr != NULL && count < n){
        list_insert(previous_ptr, source_ptr -> data);
        source_ptr = source_ptr -> link;
        previous_ptr = previous_ptr -> link;
        count++;
    }
    return head_ptr;
}
