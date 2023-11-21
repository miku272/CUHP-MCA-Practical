#include <iostream>

#include "linklist.h"

class Stack
{
private:
    SinglyLinkedList *stack_list;

public:
    Stack()
    {
        this->stack_list = new SinglyLinkedList();
    }

    bool is_empty()
    {
        return this->stack_list->is_empty();
    }

    void push(int data)
    {
        this->stack_list->insert_at_first(data);
    }

    int pop()
    {
        if (stack_list->is_empty())
        {
            return -1;
        }

        return this->stack_list->delete_at_first();
    }

    int peek()
    {
        return this->stack_list->get_head()->get_data();
    }

    ~Stack()
    {
        delete this->stack_list;
    }
};