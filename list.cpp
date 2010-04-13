#include <stdio.h>
#include "list.h"

scolarships::students::List::Node * head;
scolarships::students::List::Node * tail;

void scolarships::students::List::Create()
{
    head = NULL;
    tail = NULL;
}

void scolarships::students::List::Destroy()
{
    Node * nodeToDelete = head;
    while (nodeToDelete != NULL)
    {
        Node * temp = nodeToDelete;
        nodeToDelete = nodeToDelete->next;
        delete temp;
    }
}

void scolarships::students::List::Add(Student * student)
{
    Node * newNode = new Node;
    newNode->element = student;
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
}

void scolarships::students::List::Sort( int (*CmpFunc)(Student *, Student *) )
{

}

void scolarships::students::List::Map(void (*CallbackFunc) (Student*))
{
    Node * node = head;
    while (node != NULL)
    {
        CallbackFunc(node->element);
        node = node->next;
    }
}
