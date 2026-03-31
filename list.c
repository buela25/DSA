#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next_node;

}node_s;

node_s *head = NULL;

void traverse(void)
{
    for(node_s *n = head;
        n->next_node != NULL;
        n = n->next_node)
    {
        printf("%d\n", n->data);
    }
}

int insert(int key, int val)
{
    node_s *new = malloc(sizeof(node_s));

    if(!new)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    new->data = val;
    new->next_node = NULL;

    for(node_s *c = head;
        c->next_node != NULL;
        c = c->next_node)
    {
        if(c->data == key)
        {
            //Store the next node for reference
            node_s* temp = c->next_node;
            c->next_node = new;
            new->next_node = temp;
        }
    }

    return 0;
}

int delete(int data)
{
    node_s *p, *c;

    for(c = head;
        c->next_node != NULL;
        c = c->next_node)
    {
        if(c->next_node->data == data)
        {
            p = c;
            p->next_node = c->next_node->next_node;
        }
    }

    return 0;
}

int search(int data)
{
    for(node_s* c = head;
        c->next_node != NULL;
        c = c->next_node)
    {
        if(c->data == data)
        {
            printf("Element found is %d\n", c->data);
            return 1;
        }
    }

    return 0;
}

int add_at_front(int data)
{
    node_s *new = malloc(sizeof(node_s));
    node_s *cursor;

    if(!new)
    {
        printf("Memory allocation failed\n");
        return -1;
    }

    new->data = data;
    new->next_node = NULL;

    for(cursor = head;
        cursor->next_node != NULL;
        cursor = cursor->next_node)
    {
        /*do nothing*/
    }

    cursor->next_node = new;
    new = head;

    return 0;
}

int add_at_end(int data)
{
    node_s *new = malloc(sizeof(node_s));
    node_s *cursor;

    if(!new)
    {
        printf("Element memory allocation failed\n");
        return -1;
    }

    new->data = data;
    new->next_node =  NULL;

    for(cursor = head;
        cursor->next_node != NULL;
        cursor = cursor->next_node)
    {
        /*do nothing*/
    }

    cursor->next_node = new;

    return 0;
}

int init(int data)
{
    head = malloc(sizeof(node_s));
    if(!head)
    {
        printf("Memory allocation failed\n");
        return -1;
    }

    head->data = data;
    head->next_node = NULL;

    return 0;
}

int main()
{
    init(1);

    /*add the elements at the end of list*/
    
    // printf("Adding elements at the end\n");

    // for(int i = 2; i < 10; i++)
    // {
    //     add_at_end(i);
    // }

    // traverse();

    /*add elements at the front of list*/

    printf("Adding elements at the front\n");
    
    for(int i = 2; i < 10; i++)
    {
        add_at_front(i);
    }

    traverse();

    if(!search(8))
    {
        printf("Element not found\n");
    }

    delete(5);

    printf("Listing elements after deletion\n");

    traverse();

    printf("Inserting elements after specific element\n");

    insert(3, 13);
    insert(4, 15);
    traverse();

    return 0;
}
