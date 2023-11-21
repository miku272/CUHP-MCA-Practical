/*
Perform Queue Operation using Linked list implementation.
*/

#include <iostream>

#include "queue.h"

int main(int argc, char const *argv[])
{
    Queue *q = new Queue();

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);

    while (!q->is_empty())
    {
        std::cout << q->dequeue() << " ";
    }

    delete q;

    return 0;
}
