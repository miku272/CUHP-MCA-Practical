/*
Perform Stack Operations using Array implementation
*/

#include <iostream>

class Stack
{
private:
    int size;
    int *stack_arr;
    int curr;

public:
    Stack()
    {
        this->size = 10;
        this->stack_arr = new int[this->size];
        this->curr = -1;
    }

    Stack(int size)
    {
        this->size = size;
        this->stack_arr = new int[this->size];
        this->curr = -1;
    }

    bool is_empty()
    {
        return this->curr == -1;
    }

    void push(int data)
    {
        if (this->curr == this->size - 1)
        {
            std::cout << "Stack is full. Cannot insert more elements";
            return;
        }

        this->stack_arr[++this->curr] = data;
    }

    int pop()
    {
        if (is_empty())
        {
            std::cout << "Stack is empty. Nothing to pop";
            return -1;
        }

        int popped_data = this->stack_arr[this->curr--];

        if (this->curr < -1)
        {
            this->curr = -1;
        }

        return popped_data;
    }

    int peek()
    {
        if (is_empty())
        {
            std::cout << "Stack is empty. Nothing to peek";
            return -1;
        }

        return this->stack_arr[this->curr];
    }

    ~Stack()
    {
        delete this->stack_arr;
    }
};

int main(int argc, char const *argv[])
{
    Stack *st = new Stack();

    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);
    st->push(6);
    st->push(7);
    st->push(8);
    st->push(9);
    st->push(10);

    while (!st->is_empty())
    {
        std::cout << st->pop() << " ";
    }

    delete st;

    return 0;
}
