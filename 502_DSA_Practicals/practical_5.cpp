/*
Implement Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list and concatenate two Linked List.
*/

#include <iostream>

#include "Node.h"

class LinkedList
{
private:
    SinglyNode *head;
    SinglyNode *tail;

public:
    LinkedList()
    {
        this->head = this->tail = NULL;
    };

    LinkedList(SinglyNode *head)
    {
        this->head = this->tail = head;
    }

    SinglyNode *get_head()
    {
        return this->head;
    }

    void set_head(SinglyNode *head)
    {
        this->head = head;
    }

    SinglyNode *get_tail()
    {
        return this->tail;
    }

    void set_tail(SinglyNode *tail)
    {
        this->tail = tail;
    }

    SinglyNode *insert_at_first(int data)
    {
        SinglyNode *new_SinglyNode = new SinglyNode(data);

        if (this->head == NULL)
        {
            this->head = this->tail = new_SinglyNode;
            return this->head;
        }

        new_SinglyNode->set_next(this->head);
        this->head = new_SinglyNode;

        return this->head;
    }

    SinglyNode *insert_at_last(int data)
    {
        SinglyNode *new_SinglyNode = new SinglyNode(data);

        if (this->head == NULL)
        {
            this->head = this->tail = new_SinglyNode;
            return this->tail;
        }

        this->tail->set_next(new_SinglyNode);
        this->tail = new_SinglyNode;

        return this->tail;
    }

    int search_in_list(int key)
    {
        int i = 0;
        SinglyNode *temp = this->head;

        while (temp != NULL)
        {
            if (temp->get_data() == key)
            {
                return i;
            }

            i++;
            temp = temp->get_next();
        }

        return -1;
    }

    void reverse_linked_list()
    {
        SinglyNode *next = NULL, *current = this->head, *prev = NULL;

        while (current != NULL)
        {
            next = current->get_next();

            current->set_next(prev);

            prev = current;
            current = next;
        }

        head = prev;
    }

    void concatenate_linked_list(LinkedList *list)
    {
        this->tail->set_next(list->get_head());

        this->tail = list->get_tail();
    }

    int delete_at_first()
    {
        if (this->head == NULL)
        {
            std::cout << "List is empty. Nothing to delete...";
            return -1;
        }

        SinglyNode *delete_SinglyNode = this->head;
        int deleted_data = delete_SinglyNode->get_data();

        this->head = delete_SinglyNode->get_next();

        delete delete_SinglyNode;

        return deleted_data;
    }

    int delete_at_last()
    {
        if (this->head == NULL)
        {
            std::cout << "List is empty. Nothing to delete...";
            return -1;
        }

        SinglyNode *prev_SinglyNode, *temp = this->head;
        int deleted_data = 0;

        while (temp->get_next() != this->tail)
        {
            temp = temp->get_next();
        }

        prev_SinglyNode = temp;
        deleted_data = prev_SinglyNode->get_next()->get_data();

        delete prev_SinglyNode->get_next();

        prev_SinglyNode->set_next(NULL);
        this->tail = prev_SinglyNode;

        return deleted_data;
    }

    void print_list()
    {
        SinglyNode *temp = this->head;

        if (this->head == NULL)
        {
            std::cout << "List is empty";
            return;
        }

        while (temp != NULL)
        {
            std::cout << temp->get_data() << " -> ";
            temp = temp->get_next();
        }
        std::cout << "NULL\n";

        delete temp;
    }

    ~LinkedList()
    {
        // free(this->head);
        // free(this->tail);
        SinglyNode *temp;

        while (this->head != NULL)
        {
            temp = this->head->get_next();
            delete this->head;
            this->head = temp;
        }

        delete this->head;
    };
};

int main(int argc, char const *argv[])
{
    LinkedList list, list1;

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

    // list1.insert_at_last(6);
    // list1.insert_at_last(7);
    // list1.insert_at_last(8);
    // list1.insert_at_last(9);
    // list1.insert_at_last(10);

    // list.concatenate_linked_list(&list1);

    // list.delete_at_first();
    // list.delete_at_first();

    // list.delete_at_last();
    // list.delete_at_last();

    // list.reverse_linked_list();

    list.print_list();

    // std::cout << list.search_in_list(10);

    return 0;
}
