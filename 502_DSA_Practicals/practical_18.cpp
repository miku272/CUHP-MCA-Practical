#include <iostream>
#include <stack>
#include <queue>

void reverseStack(std::stack<int> &stack)
{
    std::queue<int> queue;

    // Push all elements from stack to queue
    while (!stack.empty())
    {
        queue.push(stack.top());
        stack.pop();
    }

    // Push all elements from queue back to stack
    while (!queue.empty())
    {
        stack.push(queue.front());
        queue.pop();
    }
}

int main()
{
    std::stack<int> stack;

    // Push elements to stack
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    std::cout << "Original Stack: ";
    while (!stack.empty())
    {
        std::cout << stack.top() << " ";
        stack.pop();
    }

    reverseStack(stack);

    std::cout << "\nReversed Stack: ";
    while (!stack.empty())
    {
        std::cout << stack.top() << " ";
        stack.pop();
    }

    return 0;
}
