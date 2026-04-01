#include <stdio.h>
#include <stdlib.h>

/*Queue implementation
    1. add() -    new element will always be added at the end of queue
    2. delete() - an element can be deleted from traversing through front of queue
*/

typedef struct node
{
    int data;
    struct node* next_node;

}node_s;

static node_s* head = NULL;
static node_s* tail = NULL;

void traverse(void)
{
    node_s *cursor;

    for(cursor = head;
                cursor != NULL;
                cursor = cursor->next_node)
    {
        printf("%d ", cursor->data);
        printf("-->");
    }
    printf("NULL\n");
}

int delete(int data)
{
    node_s *c;
    node_s *p;

    if(head == NULL)
        return -1;

    if(head->data == data)
    {
        node_s *tmp = head;
        head = tmp->next_node;
        free(tmp);
    }

    for(c = head; c->next_node != NULL; c = c->next_node)
    {
        if(c->next_node->data == data)
        {
            p = c;
            node_s *temp = c->next_node;

            p->next_node = temp->next_node;

            free(temp);
            break;
        }
    }

    return -1;
}

int add_at_end(int data)
{
    node_s *new = malloc(sizeof(node_s));
    node_s *cursor;

    if(!new)
    {
        printf("New element memory allocation failed\n");
        return -1;
    }

    new->data = data;
    new->next_node = NULL;

    /*Remembering the last element will reduce the runtime of handling queues,
    no need to traverse till the last element  - EFFICIENT*/

    tail->next_node = new;
    tail = new;
    

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
    tail = head;
    return 0;
}

int main()
{
    init(1);

    /*Add elements at the end/tail of queue*/
    for(int i = 2; i < 10; i++)
    {
        add_at_end(i);
    }

    printf("Listing elements before deletion\n");

    traverse();

    delete(2);
    delete(9);
    delete(1); 
    
    printf("Listing the elements after deletion:\n");

    traverse();

    return 0;
}
