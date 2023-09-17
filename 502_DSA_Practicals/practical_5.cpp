/*
Implement Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list and concatenate two Linked List.
*/

#include <iostream>

class Node
{
private:
    int data;
    Node *next;

public:
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    int get_data()
    {
        return this->data;
    }

    void set_data(int data)
    {
        this->data = data;
    }

    Node *get_next()
    {
        return this->next;
    }

    void set_next(Node *next)
    {
        this->next = next;
    }

    ~Node()
    {
        free(this->next);
    };
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        this->head = this->tail = NULL;
    };

    LinkedList(Node *head)
    {
        this->head = this->tail = head;
    }

    Node *get_head()
    {
        return this->head;
    }

    void set_head(Node *head)
    {
        this->head = head;
    }

    Node *get_tail()
    {
        return this->tail;
    }

    void set_tail(Node *tail)
    {
        this->tail = tail;
    }

    Node *insert_at_first(int data)
    {
        Node *new_node = new Node(data);

        if (this->head == NULL)
        {
            this->head = this->tail = new_node;
            return this->head;
        }

        new_node->set_next(this->head);
        this->head = new_node;

        return this->head;
    }

    Node *insert_at_last(int data)
    {
        Node *new_node = new Node(data);

        if (this->head == NULL)
        {
            this->head = this->tail = new_node;
            return this->tail;
        }

        this->tail->set_next(new_node);
        this->tail = new_node;

        return this->tail;
    }

    int search_in_list(int key)
    {
        int i = 0;
        Node *temp = this->head;

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

    int delete_at_first()
    {
        if (this->head == NULL)
        {
            std::cout << "List is empty. Nothing to delete...";
            return -1;
        }

        Node *delete_node = this->head;
        int deleted_data = delete_node->get_data();

        this->head = delete_node->get_next();

        free(delete_node);

        return deleted_data;
    }

    int delete_at_last()
    {
        if (this->head == NULL)
        {
            std::cout << "List is empty. Nothing to delete...";
            return -1;
        }

        Node *prev_node, *temp = this->head;
        int deleted_data = 0;

        while (temp->get_next() != this->tail)
        {
            temp = temp->get_next();
        }

        prev_node = temp;
        deleted_data = prev_node->get_next()->get_data();

        free(prev_node->get_next());

        prev_node->set_next(NULL);
        this->tail = prev_node;

        return deleted_data;
    }

    void print_list()
    {
        Node *temp = this->head;

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
        std::cout << "NULL";

        free(temp);
    }

    ~LinkedList()
    {
        free(this->head);
        free(this->tail);
    };
};

int main(int argc, char const *argv[])
{
    LinkedList list;

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

    // list.delete_at_first();
    // list.delete_at_first();

    // list.delete_at_last();
    // list.delete_at_last();

    list.print_list();

    // std::cout << list.search_in_list(10);

    return 0;
}
