/*
Implement Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list and concatenate two Linked List.
*/

#include <iostream>

#include "linklist.h"

int main(int argc, char const *argv[])
{
    SinglyLinkedList list, list1;

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

    list.insert_at_index(10, 50);

    // list1.insert_at_last(6);
    // list1.insert_at_last(7);
    // list1.insert_at_last(8);
    // list1.insert_at_last(9);
    // list1.insert_at_last(10);

    // list.concatenate_linked_list(&list1);

    // list.delete_at_first();
    // list.delete_at_index(2);
    // list.delete_at_last();

    // list.reverse_linked_list();

    list.print_list();

    // std::cout << list.search_in_list(10);

    return 0;
}
