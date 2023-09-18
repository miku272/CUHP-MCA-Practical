/*
Implement Doubly Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list.
*/

#include <iostream>

#include "node.h"

class DoublyLinkedList
{
private:
    DoublyNode *head;
    DoublyNode *tail;

public:
    DoublyLinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    DoublyLinkedList(DoublyNode *head)
    {
        this->head = head;
        this->tail = NULL;
    }

    DoublyNode *insert_at_first(int data)
    {
        DoublyNode *new_node = new DoublyNode(data);

        if (this->head == NULL)
        {
            this->head = this->tail = new_node;
            return new_node;
        }

        this->head->set_prev(new_node);
        new_node->set_next(this->head);
        head = new_node;

        return new_node;
    }

    DoublyNode *insert_at_last(int data)
    {
        DoublyNode *new_node = new DoublyNode(data);

        if (this->head == NULL)
        {
            this->head = this->tail = new_node;
            return new_node;
        }

        this->tail->set_next(new_node);
        new_node->set_prev(this->tail);
        this->tail = new_node;

        return new_node;
    }

    int delete_at_first()
    {
    }

    int delete_at_last()
    {
    }

    void print_list()
    {
        if (this->head == NULL)
        {
            std::cout << "List is empty...";
            return;
        }

        DoublyNode *temp = this->head;

        while (temp != NULL)
        {
            std::cout << temp->get_data() << " <-> ";
            temp = temp->get_next();
        }
        std::cout << "NULL\n";
    }

    void reverse_print_list()
    {
        if (this->head == NULL)
        {
            std::cout << "List is empty...";
            return;
        }

        DoublyNode *temp = this->tail;

        while (temp != NULL)
        {
            std::cout << temp->get_data() << " <-> ";
            temp = temp->get_prev();
        }
        std::cout << "NULL\n";
    }

    ~DoublyLinkedList()
    {
        DoublyNode *temp;

        while (this->head != NULL)
        {
            temp = this->head->get_next();
            delete this->head;
            this->head = temp;
        }

        delete this->head;
    }
};

int main(int argc, char const *argv[])
{
    DoublyLinkedList list;

    // list.insert_at_first(5);
    // list.insert_at_first(4);
    // list.insert_at_first(3);
    // list.insert_at_first(2);
    // list.insert_at_first(1);

    list.insert_at_last(1);
    list.insert_at_last(2);
    list.insert_at_last(3);
    list.insert_at_last(4);
    list.insert_at_last(5);

    list.print_list();
    // list.reverse_print_list();

    return 0;
}
