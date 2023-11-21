#include <iostream>

#include "linklist.h"

class Queue
{
private:
    SinglyLinkedList *queue_list;

public:
    Queue()
    {
        this->queue_list = new SinglyLinkedList();
    }

    bool is_empty()
    {
        return this->queue_list->is_empty();
    }

    void enqueue(int data)
    {
        queue_list->insert_at_last(data);
    }

    int dequeue()
    {
        if (this->is_empty())
        {
            std::cout << "Queue is empty. Nothing to remove";
            return -1;
        }

        return this->queue_list->delete_at_first();
    }

    int peek()
    {
        if (this->is_empty())
        {
            std::cout << "Queue is empty. Nothing to remove";
            return -1;
        }

        return this->queue_list->get_head()->get_data();
    }

    ~Queue()
    {
        delete this->queue_list;
    }
};