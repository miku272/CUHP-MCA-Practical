#include <iostream>

#include "node.h"

class SinglyLinkedList
{
private:
    SinglyNode *head;
    SinglyNode *tail;

public:
    SinglyLinkedList()
    {
        this->head = this->tail = NULL;
    };

    SinglyLinkedList(SinglyNode *head)
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

    bool is_empty()
    {
        return this->head == NULL;
    }

    SinglyNode *insert_at_first(int data)
    {
        SinglyNode *new_singly_node = new SinglyNode(data);

        if (this->head == NULL)
        {
            this->head = this->tail = new_singly_node;
            return this->head;
        }

        new_singly_node->set_next(this->head);
        this->head = new_singly_node;

        return this->head;
    }

    SinglyNode *insert_at_index(int data, int index)
    {
        if (index < 0)
        {
            std::cout << "\n\nError: Invalid Index\n\n";

            return NULL;
        }

        if (index == 0 || this->head == NULL)
        {
            return insert_at_first(data);
        }

        SinglyNode *new_singly_node = new SinglyNode(data);
        SinglyNode *temp = this->head;

        int i = 0;
        while (i < index - 1)
        {
            if (temp == NULL)
            {
                break;
            }

            temp = temp->get_next();
            i++;
        }

        if (temp == this->tail || temp == NULL)
        {
            this->tail->set_next(new_singly_node);
            this->tail = new_singly_node;

            return this->tail;
        }

        new_singly_node->set_next(temp->get_next());
        temp->set_next(new_singly_node);

        return new_singly_node;
    }

    SinglyNode *insert_at_last(int data)
    {
        SinglyNode *new_singly_node = new SinglyNode(data);

        if (this->head == NULL)
        {
            this->head = this->tail = new_singly_node;
            return this->tail;
        }

        this->tail->set_next(new_singly_node);
        this->tail = new_singly_node;

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

    void concatenate_linked_list(SinglyLinkedList *list)
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

        delete_SinglyNode->set_next(NULL);

        delete delete_SinglyNode;

        return deleted_data;
    }

    int delete_at_index(int index)
    {
        if (this->head == NULL)
        {
            std::cout << "List is empty. Nothing to delete...";
            return -1;
        }

        if (index == 0)
        {
            return delete_at_first();
        }

        SinglyNode *delete_node, *temp = this->head;
        int deleted_data = 0;

        int i = 0;
        while (i < index - 1)
        {
            if (temp == NULL)
            {
                break;
            }

            temp = temp->get_next();

            i++;
        }

        if (temp == this->tail || temp == NULL)
        {
            return delete_at_last();
        }

        delete_node = temp->get_next();
        deleted_data = delete_node->get_data();

        temp->set_next(delete_node->get_next());

        delete_node->set_next(NULL);

        delete delete_node;

        return deleted_data;
    }

    int delete_at_last()
    {
        if (this->head == NULL)
        {
            std::cout << "List is empty. Nothing to delete...";
            return -1;
        }

        SinglyNode *prev_SinglyNode = this->head;
        int deleted_data = 0;

        while (prev_SinglyNode->get_next() != this->tail)
        {
            prev_SinglyNode = prev_SinglyNode->get_next();
        }

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

    // ~SinglyLinkedList()
    // {
    //     // free(this->head);
    //     // free(this->tail);
    //     SinglyNode *temp;

    //     while (this->head != NULL)
    //     {
    //         temp = this->head->get_next();
    //         delete this->head;
    //         this->head = temp;
    //     }

    //     delete this->head;
    //     delete temp;
    // };
};

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

    DoublyNode *insert_at_index(int data, int index)
    {
        if (index < 0)
        {
            std::cout << "\n\nError: Invalid Index\n\n";

            return NULL;
        }

        if (index == 0 || this->head == NULL)
        {
            return insert_at_first(data);
        }

        DoublyNode *new_doubly_node = new DoublyNode(data);
        DoublyNode *temp = this->head;

        int i = 0;
        while (i < index - 1)
        {
            if (temp == NULL)
            {
                break;
            }

            temp = temp->get_next();
            i++;
        }

        if (temp == this->tail || temp == NULL)
        {
            new_doubly_node->set_prev(this->tail);

            this->tail->set_next(new_doubly_node);
            this->tail = new_doubly_node;

            return this->tail;
        }

        new_doubly_node->set_next(temp->get_next());
        new_doubly_node->set_prev(temp);

        temp->set_next(new_doubly_node);

        return new_doubly_node;
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
        if (this->head == NULL)
        {
            std::cout << "List is empty. Nothing to delete...";
            return -1;
        }

        DoublyNode *delete_node = this->head;
        int deleted_data = delete_node->get_data();

        this->head = this->head->get_next();
        this->head->set_prev(NULL);

        delete_node->set_next(NULL);
        delete delete_node;

        return deleted_data;
    }

    int delete_at_index(int index)
    {
        if (this->head == NULL)
        {
            std::cout << "List is empty. Nothing to delete...";
            return -1;
        }

        if (index == 0)
        {
            return delete_at_first();
        }

        DoublyNode *delete_node, *temp = this->head;
        int deleted_data = 0;

        int i = 0;
        while (i < index - 1)
        {
            if (temp == NULL)
            {
                break;
            }

            temp = temp->get_next();

            i++;
        }

        if (temp == this->tail || temp == NULL)
        {
            return delete_at_last();
        }

        delete_node = temp->get_next();

        temp->set_prev(delete_node->get_prev());
        temp->set_next(delete_node->get_next());

        delete_node->set_prev(NULL);
        delete_node->set_next(NULL);

        delete delete_node;

        return deleted_data;
    }

    int delete_at_last()
    {
        if (this->head == NULL)
        {
            std::cout << "List is empty. Nothing to delete...";
            return -1;
        }

        DoublyNode *prev_doubly_node = this->head;
        int deleted_data = 0;

        while (prev_doubly_node->get_next() != this->tail)
        {
            prev_doubly_node = prev_doubly_node->get_next();
        }

        deleted_data = prev_doubly_node->get_next()->get_data();

        prev_doubly_node->set_prev(NULL);
        prev_doubly_node->set_next(NULL);
        delete prev_doubly_node->get_next();

        prev_doubly_node->set_next(NULL);
        this->tail = prev_doubly_node;

        return deleted_data;
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

    // ~DoublyLinkedList()
    // {
    //     DoublyNode *temp;

    //     while (this->head != NULL)
    //     {
    //         temp = this->head->get_next();
    //         delete this->head;
    //         this->head = temp;
    //     }

    //     delete this->head;
    //     delete temp;
    // }
};