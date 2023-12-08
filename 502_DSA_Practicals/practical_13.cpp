#include <iostream>
using namespace std;

// Node structure for polynomial term
struct Node
{
    int coefficient;
    int exponent;
    Node *next;
};

// Function to insert a term into the polynomial
void insertTerm(Node **head, int coefficient, int exponent)
{
    Node *newNode = new Node;
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = nullptr;

    if (*head == nullptr)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to add two polynomials
Node *addPolynomials(Node *poly1, Node *poly2)
{
    Node *result = nullptr;
    Node *temp = nullptr;
    Node *prev = nullptr;
    while (poly1 != nullptr && poly2 != nullptr)
    {
        if (poly1->exponent > poly2->exponent)
        {
            if (result == nullptr)
            {
                result = temp = poly1;
            }
            else
            {
                temp->next = poly1;
                temp = temp->next;
            }
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            if (result == nullptr)
            {
                result = temp = poly2;
            }
            else
            {
                temp->next = poly2;
                temp = temp->next;
            }
            poly2 = poly2->next;
        }
        else
        {
            poly1->coefficient += poly2->coefficient;
            if (result == nullptr)
            {
                result = temp = poly1;
            }
            else
            {
                temp->next = poly1;
                temp = temp->next;
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != nullptr)
    {
        temp->next = poly1;
        temp = temp->next;
        poly1 = poly1->next;
    }

    while (poly2 != nullptr)
    {
        temp->next = poly2;
        temp = temp->next;
        poly2 = poly2->next;
    }

    return result;
}

// Function to display the polynomial
void displayPolynomial(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->coefficient << "x^" << temp->exponent;
        if (temp->next != nullptr)
        {
            cout << " + ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *poly1 = nullptr;
    Node *poly2 = nullptr;

    // Scanning polynomial 1
    int n;
    cout << "Enter the number of terms in polynomial 1: ";
    cin >> n;
    cout << "Enter the terms (coefficient exponent):" << endl;
    for (int i = 0; i < n; i++)
    {
        int coefficient, exponent;
        cin >> coefficient >> exponent;
        insertTerm(&poly1, coefficient, exponent);
    }

    // Scanning polynomial 2
    cout << "Enter the number of terms in polynomial 2: ";
    cin >> n;
    cout << "Enter the terms (coefficient exponent):" << endl;
    for (int i = 0; i < n; i++)
    {
        int coefficient, exponent;
        cin >> coefficient >> exponent;
        insertTerm(&poly2, coefficient, exponent);
    }

    // Adding polynomials
    Node *sum = addPolynomials(poly1, poly2);

    // Displaying the result
    cout << "Sum of the polynomials: ";
    displayPolynomial(sum);

    return 0;
}
