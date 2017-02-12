/*
 * File:   main_linkedList.c
 * Author: vignesh
 * Comments: Linked List C Implementation
 * Created on 16 December 2009, 11:12
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *_Node;
struct Node { char key; _Node next; };
static _Node Head, Tail, Curr;

static inline _Node initialise_head(){
    Head = (_Node)calloc(1, sizeof *Head);
    Tail = (_Node)calloc(1, sizeof *Tail);
    Head->key = -1;
    Tail->key = -2;
    Head->next = Tail;
    Tail->next = NULL;
    return Head;
}

static inline _Node add_node(_Node curr_node, char val){
    curr_node = (curr_node->next = (_Node)calloc(1, sizeof *curr_node));
    curr_node->key = val;
    curr_node->next = Tail;
    return curr_node;
}

static inline void delete_all_nodes(){
    static _Node curr_node;
    for(curr_node = Head->next; Head->next !=Tail; curr_node = Head->next){
        Head->next = curr_node->next;
        free(curr_node);
    }
    return;
}

static void print_all_nodes(){
    static _Node curr_node;
    for (curr_node = Head; curr_node != Tail; curr_node = curr_node->next)
        printf ("Key: %i\n", curr_node->key);
    return;
}

int main()
{
    static char i;
    Curr = initialise_head(); // initialises the head with the tail before further operations

    for (i = 0; i <= 10; i++)
        Curr = add_node(Curr, i); // invoked add_node function and inserts the node, in this case sequentially

    print_all_nodes(); // prints all added nodes
    delete_all_nodes(); // frees all nodes except the head and tail
    print_all_nodes(); // prints only the head as per given condition
    return 0;
}
