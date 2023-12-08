#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    CircularQueue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue more elements." << endl;
            return;
        }

        if (isEmpty())
        {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;

        cout << "Enqueued element: " << data << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue any element." << endl;
            return;
        }

        int data = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        size--;

        cout << "Dequeued element: " << data << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << arr[rear] << endl;
    }
};

int main()
{
    int capacity;
    cout << "Enter the capacity of the circular queue: ";
    cin >> capacity;

    CircularQueue queue(capacity);

    int choice, data;
    while (true)
    {
        cout << "-------------------------" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "-------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to enqueue: ";
            cin >> data;
            queue.enqueue(data);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
