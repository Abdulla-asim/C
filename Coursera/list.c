#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}list;

list* create_list(int d);
list* add_to_front(int d, list *h);
list* array_to_list(int array[], int size);
list* add_to_back(int d, list *l);
void print_list(list *h, char *title);

int main()
{
    
}

int is_empty(list *l)
{
    return (l == NULL);
}

list* create_list(int d)
{
    list* head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list* add_to_front(int d, list *h)
{
    list* head = create_list(d);
    head -> data = d;
    head -> next = h;
    return head;
}

list* add_to_back(int d, list *l)
{
    list* tail = l;
    do
    {
        tail = tail -> next; 
    } while (tail -> next != NULL);
    
    tail -> next = create_list(d);
    tail = tail -> next;
    tail -> next = NULL;
}

list* array_to_list(int array[], int size)
{
    list* head = create_list(array[0]);
    for (int i = 1; i < size; i ++)
        head = add_to_front(array[i], head);

    return head;
}

void print_list(list *h, char *title)
{
    printf("%s", title);
    while(h != NULL)
    {
        printf("%d", h -> data);
        h = h -> next;
    }
}