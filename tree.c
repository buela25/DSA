
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

/*DSA - Implementation of trees*/

typedef struct node
{
    char data;
    struct node* left;//left node
    struct node* right;//right node

}node_s;

node_s *root = NULL;

void preorder(node_s *ptr)
{
    if(ptr == NULL)
        return;

    printf("%c\n", ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}

/*Add the data - every node has root, left_child, right_child*/
void add(char data)
{
    printf("New element to add is %c\n", data);
    node_s *new = malloc(sizeof(node_s));

    new->data =  data;
    new->left =  NULL;
    new->right = NULL;

    //Add the first element , root
    if(root == NULL)
    {
        root = new;
        printf("element added_root :%c\n", data);
        return;
    }

    //Add the elements in left subtree
    if(root->left == NULL)
    {
        root->left = new;
        printf("element added_rleft :%c\n", data);
        return;
    }
    else
    {
        //track the path it traversed - left subtree
        printf("left_tree-enqueue:%p\n", root->left);
        enqueue((void*)(root->left));
    }

    //Add the elements in right subtree
    if(root->right == NULL)
    {
        root->right = new;
        printf("element added_r_right :%c\n", data);
        destroy_queue();
        return;
    }
    else
    {
        //track the path it traversed - right subtree
        printf("right_tree-enqueue:%p\n", root->left);
        enqueue((void*)(root->right));
    }

    while(queue_empty() == false)
    {
        node_s *element = (node_s*)dequeue();
        
        printf("tree_dequeue address is %p\n", element);

        if(element->left == NULL)
        {
            element->left = new;
            printf("while_loop_eleft:%c\n", element->left->data);
            destroy_queue();
            return;
        }
        else
        {
            //track the path it traversed - right subtree
            printf("tree_wl_enqueue_Address:%p\n", element->left);
            enqueue((void*)(element->left));
        }

        if(element->right == NULL)
        {
            element->right = new;
            printf("while_loop_eright:%c\n", element->right->data);
            destroy_queue();
            return;
        }
        else
        {
            //track the path it traversed - right subtree
            printf("tree_wr_enqueue_Address:%p\n", element->right);
            enqueue((void*)(element->right));
        }
    }

}

int main()
{
    add('A');
    add('B');
    add('C');
    add('D');
    add('E');
    add('F');
    add('G');
    preorder(root);

    return 0;
}
