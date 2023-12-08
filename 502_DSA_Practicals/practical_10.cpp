#include <iostream>
#define MAX_SIZE 100

class Queue
{
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            std::cout << "Queue is full. Cannot enqueue element.\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        std::cout << "Enqueued " << value << " successfully.\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Cannot dequeue element.\n";
            return;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        std::cout << "Dequeued successfully.\n";
    }

    int getFront()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        std::cout << "Queue Operations:\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Get Front\n";
        std::cout << "4. Display\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter the value to enqueue: ";
            std::cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            std::cout << "Front element: " << q.getFront() << "\n";
            break;
        case 4:
            q.display();
            break;
        case 5:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
