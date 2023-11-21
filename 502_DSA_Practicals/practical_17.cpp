/*
Write a program to reverse a stack using additional stack
*/

#include <iostream>

#include "stack.h"

Stack *reverse_stack(Stack *st)
{
    Stack *temp_stack = new Stack();

    while (!st->is_empty())
    {
        temp_stack->push(st->pop());
    }

    return temp_stack;
}

int main(int argc, char const *argv[])
{
    Stack *st = new Stack();

    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);

    st = reverse_stack(st);
    while (!st->is_empty())
    {
        std::cout << st->pop() << " ";
    }

    delete st;

    return 0;
}
