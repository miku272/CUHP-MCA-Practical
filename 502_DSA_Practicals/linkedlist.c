#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct LinkedList
{
    struct Node *head;
    struct Node *tail;
};

struct LinkedList *init_linkedlist()
{
    struct LinkedList *linked_list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    linked_list->head = linked_list->tail = NULL;

    return linked_list;
}

int is_empty(struct LinkedList *ll)
{
    if (ll->head == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

struct Node *insert_at_first(struct LinkedList *ll, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (ll->head == NULL)
    {
        ll->head = ll->tail = new_node;
        return ll->head;
    }

    new_node->next = ll->head;
    ll->head = new_node;

    return ll->head;
}

struct Node *insert_at_index(struct LinkedList *ll, int data, int index)
{
    if (index < 0)
    {
        printf("\nInvalid Index...\n");
        return NULL;
    }

    if (index == 0 || ll->head == NULL)
    {
        return insert_at_first(ll, data);
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    struct Node *temp = ll->head;
    int i = 0;
    while (i < index - 1)
    {
        if (temp == NULL)
        {
            break;
        }

        temp = temp->next;
        i++;
    }

    if (temp == ll->tail || temp == NULL)
    {
        ll->tail->next = new_node;
        ll->tail = new_node;

        return ll->tail;
    }

    new_node->next = temp->next;
    temp->next = new_node;

    return new_node;
}

struct Node *insert_at_last(struct LinkedList *ll, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (ll->head == NULL)
    {
        ll->head = ll->tail = new_node;
        return ll->tail;
    }

    ll->tail->next = new_node;
    ll->tail = new_node;

    return new_node;
}

int search_in_ll(struct LinkedList *ll, int key)
{
    int i = 0;
    struct Node *temp = ll->head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return i;
        }

        i++;
        temp = temp->next;
    }

    return -1;
}

void reverse_ll(struct LinkedList *ll)
{
    struct Node *next = NULL, *curr = ll->head, *prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    ll->head = prev;
}

void concatenate_ll(struct LinkedList *ll1, struct LinkedList *ll2)
{
    ll1->tail->next = ll2->head;
    ll1->tail = ll2->tail;
}

int delete_at_first(struct LinkedList *ll)
{
    if (ll->head == NULL)
    {
        printf("\nList is empty. Nothing to delete...\n");
        return -1;
    }

    struct Node *delete_node = ll->head;
    int deleted_data = delete_node->data;

    ll->head = delete_node->next;

    free(delete_node);

    return deleted_data;
}

int delete_at_last(struct LinkedList *ll)
{
    if (ll->head == NULL)
    {
        printf("\nList is empty. Nothing to delete...\n");
        return -1;
    }

    struct Node *prev_node = ll->head;
    int deleted_data = 0;

    while (prev_node->next != ll->tail)
    {
        prev_node = prev_node->next;
    }

    deleted_data = prev_node->next->data;

    free(prev_node->next);

    prev_node->next = NULL;
    ll->tail = prev_node;

    return deleted_data;
}

int delete_at_index(struct LinkedList *ll, int index)
{
    if (ll->head == NULL)
    {
        printf("\nList is empty. Nothing to delete...\n");
        return -1;
    }

    if (index == 0)
    {
        return delete_at_first(ll);
    }

    struct Node *delete_node, *temp = ll->head;
    int deleted_data = 0;

    int i = 0;
    while (i < index - 1)
    {
        if (temp == NULL)
        {
            break;
        }

        i++;
        temp = temp->next;
    }

    if (temp == ll->tail || temp == NULL)
    {
        return delete_at_last(ll);
    }

    delete_node = temp->next;
    temp->next = delete_node->next;

    free(delete_node);

    return deleted_data;
}

void print_list(struct LinkedList *ll)
{
    if (ll->head == NULL)
    {
        printf("\nList is empty. Nothing to print...\n");
        return;
    }

    struct Node *temp = ll->head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    struct LinkedList *linked_list = init_linkedlist();
    int option = 0, data = 0, index = 0, key = 0;
    char repeat = 'y';

    do
    {
        system("cls");

        printf("1. Insert at first.\n2. Insert at last.\n3. Insert at index\n4. Search in list.\n5. Reverse the list\n6. Delete at first\n7. Delete at last\n8. Delete at index\n9. Print list\n");

        printf("Enter your choice: ");
        scanf("%d", &option);
        printf("\n\n");

        switch (option)
        {
        case 1:
            printf("Enter your data: ");
            scanf("%d", &data);

            insert_at_first(linked_list, data);

            break;

        case 2:
            printf("Enter your data: ");
            scanf("%d", &data);

            insert_at_last(linked_list, data);

            break;

        case 3:
            printf("Enter your data: ");
            scanf("%d", &data);

            printf("\nEnter the index you want to enter it: ");
            scanf("%d", &index);

            insert_at_index(linked_list, data, index);

            break;

        case 4:
            printf("Enter the element you want to search: ");
            scanf("%d", &key);

            index = search_in_ll(linked_list, key);

            if (index != -1)
            {
                printf("\nElement found at index %d", index);
            }
            else
            {
                printf("\nElement not found in the list...");
            }

            break;

        case 5:
            reverse_ll(linked_list);

            printf("Reversed list: ");
            print_list(linked_list);

            break;

        case 6:
            data = delete_at_first(linked_list);

            printf("\nDeleted first element: %d\n", data);

            break;

        case 7:
            data = delete_at_last(linked_list);

            printf("\nDeleted last element: %d\n", data);

            break;

        case 8:
            printf("\nEnter the index you want to delete: \n");
            scanf("%d", &index);

            data = delete_at_index(linked_list, index);

            printf("Deleted %d at index %d\n", data, index);

            break;

        case 9:
            printf("\n");
            print_list(linked_list);

            break;

        default:
            printf("\nYou entered a wrong choice...\n");
        }

        fflush(stdin);
        printf("\n Do you want to continue? (y or Y): ");
        scanf("%c", &repeat);
    } while (repeat == 'y' || repeat == 'Y');
    free(linked_list);

    return 0;
}
