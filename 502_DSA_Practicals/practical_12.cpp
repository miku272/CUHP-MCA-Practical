#include <iostream>

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;
};

// Class for the double-ended queue
class Deque
{
private:
    Node *front;
    Node *rear;

public:
    // Constructor
    Deque()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the deque is empty
    bool isEmpty()
    {
        return (front == nullptr);
    }

    // Function to insert an element at the front of the deque
    void insertFront(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front = newNode;
        }

        std::cout << "Element " << value << " inserted at the front." << std::endl;
    }

    // Function to insert an element at the rear of the deque
    void insertRear(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        std::cout << "Element " << value << " inserted at the rear." << std::endl;
    }

    // Function to delete an element from the front of the deque
    void deleteFront()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty. Cannot delete from front." << std::endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;

            std::cout << "Element deleted from the front." << std::endl;
        }
    }

    // Function to delete an element from the rear of the deque
    void deleteRear()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty. Cannot delete from rear." << std::endl;
        }
        else
        {
            Node *temp = front;
            while (temp->next != rear)
            {
                temp = temp->next;
            }

            delete rear;
            rear = temp;
            rear->next = nullptr;

            std::cout << "Element deleted from the rear." << std::endl;
        }
    }

    // Function to display the elements of the deque
    void display()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty." << std::endl;
        }
        else
        {
            Node *temp = front;
            std::cout << "Elements of the deque: ";
            while (temp != nullptr)
            {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    Deque deque;
    int choice, value;

    do
    {
        std::cout << "1. Insert at front" << std::endl;
        std::cout << "2. Insert at rear" << std::endl;
        std::cout << "3. Delete from front" << std::endl;
        std::cout << "4. Delete from rear" << std::endl;
        std::cout << "5. Display" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter the value to insert at the front: ";
            std::cin >> value;
            deque.insertFront(value);
            break;
        case 2:
            std::cout << "Enter the value to insert at the rear: ";
            std::cin >> value;
            deque.insertRear(value);
            break;
        case 3:
            deque.deleteFront();
            break;
        case 4:
            deque.deleteRear();
            break;
        case 5:
            deque.display();
            break;
        case 6:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }

        std::cout << std::endl;
    } while (choice != 6);

    return 0;
}
