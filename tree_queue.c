#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct q_node
{
    void* node;
    struct q_node* next_node;
}q_node_s;

q_node_s *q_head = NULL;
q_node_s *q_tail = NULL;

bool queue_empty(void)
{
    if(q_head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
} 

void enqueue(void* node_to_explore)
{
    //Element will be added @end/tail of queue

    q_node_s *new_entry  = malloc(sizeof(q_node_s));
    new_entry->node      = node_to_explore;
    new_entry->next_node = NULL;
    printf("enqueue address is %p\n", node_to_explore);

    if(q_head == NULL)
    {
        q_head = new_entry;
        q_tail = new_entry;
    }

    else
    {
        q_tail->next_node = new_entry;
        q_tail = new_entry;
    }

}

void* dequeue(void)
{
    if(q_head == NULL)
    {
        return NULL;
    }

    // Store current head
    q_node_s *temp = q_head;

    // Get data to return
    void *return_address = temp->node;

    // Move head
    q_head = temp->next_node;

    // If queue becomes empty
    if(q_head == NULL)
    {
        q_tail = NULL;
    }

    // Free ONLY queue node
    free(temp);

    printf("Dequeue_address:%p\n", return_address);
    return return_address;
}

void destroy_queue()
{
    q_node_s *ptr = q_head;

    if(ptr == NULL)
        return;

    while(ptr != NULL)
    {
        q_node_s *temp = ptr;
        ptr = ptr->next_node;
        free(temp);
    }

    q_head =  NULL;
    q_tail =  NULL;
}
