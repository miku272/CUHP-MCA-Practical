/*
Perform stack operation using Linked List Implementation.
*/

#include <iostream>

#include "stack.h"

int main(int argc, char const *argv[])
{
    Stack *st = new Stack();

    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);

    while (!st->is_empty())
    {
        std::cout << st->pop() << " ";
    }

    delete st;

    return 0;
}
