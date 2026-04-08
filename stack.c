#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next_node;
}node_s;

static node_s *top = NULL;

void add(int data)
{
    node_s *new_node = malloc(sizeof(node_s));

    new_node->data = data;
    printf("New element to be inserted is %d\n", new_node->data);

    new_node->next_node = top;
    top = new_node;
}

void delete(int data)
{
    if(top == NULL)
    {
       printf("No element to delete\n");
       return;
    }
    else if(top->data == data)
    {
        printf("The number to be deleted is %d\n", top->data);
    }
    else
    {
        printf("Only the top of stack element can be deleted\n");
    }
}

void traverse()
{
    for(node_s *cursor = top; cursor != NULL; cursor = cursor->next_node)
    {
        printf("%d\n", cursor->data);
    }
}

int main()
{
    printf("Implementing stack - DSA\n");

    printf("Adding the elements in stack\n");

    add(1);
    add(2);
    add(3);
    add(4);
    add(5);

    printf("Traverse the stack and list the elements\n");
    
    traverse();

    delete(2);
    delete(5);
    return 0;
}
