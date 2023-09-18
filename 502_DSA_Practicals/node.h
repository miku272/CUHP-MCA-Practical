#include <iostream>

class SinglyNode
{
private:
    int data;
    SinglyNode *next;

public:
    SinglyNode()
    {
        this->data = 0;
        this->next = NULL;
    }

    SinglyNode(int data)
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

    SinglyNode *get_next()
    {
        return this->next;
    }

    void set_next(SinglyNode *next)
    {
        this->next = next;
    }

    ~SinglyNode()
    {
        delete this->next;
    };
};

class DoublyNode
{
private:
    int data;
    DoublyNode *next;
    DoublyNode *prev;

public:
    DoublyNode()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    DoublyNode(int data)
    {
        this->data = data;
        this->prev = NULL;
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

    DoublyNode *get_prev()
    {
        return this->prev;
    }

    void set_prev(DoublyNode *prev)
    {
        this->prev = prev;
    }

    DoublyNode *get_next()
    {
        return this->next;
    }

    void set_next(DoublyNode *next)
    {
        this->next = next;
    }

    ~DoublyNode()
    {
        delete this->prev;
        delete this->next;
    }
};