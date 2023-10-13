/*
Implement Doubly Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list.
*/

#include <iostream>

#include "linklist.h"

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

    // list.insert_at_index(10, 2);

    // list.delete_at_first();

    // list.delete_at_index(3);

    // list.delete_at_last();

    list.print_list();
    // list.reverse_print_list();

    return 0;
}
