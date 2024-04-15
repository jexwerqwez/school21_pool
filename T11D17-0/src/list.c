#include <stdlib.h>
#include "list.h"
#include "door_struct.h"
#include <stdio.h>

struct node* init(struct door* door) {
    struct node *root = (struct node*)malloc(sizeof(struct node));
    root->door = door;
    root->next = 0;
    return root;
}
struct node* add_door(struct node* elem, struct door* door) {
    struct node *tmp = elem->next;
    elem->next = init(door);
    elem->next->next = tmp;
    return elem;
}
struct node* remove_door(struct node* elem, struct node* root) {
    struct node *tmp = root;
    while (tmp->next < elem)
        tmp = tmp->next;
    tmp->next = elem->next;
    free(elem);
    return tmp;
}
void destroy(struct node* root) {
    if (root->next != 0) {
        destroy(root->next);
    }
    free(root);
}
struct node* find_door(int door_id, struct node* root) {
    struct node* ptr = root;
    while (ptr->next) {
        if (ptr->door->id == door_id)
            break;
        else
            ptr = ptr->next;
    }
    return ptr;
}

int count(struct node *root) {
    int count = 0;
    while (root != 0) {
        count++;
        root = root->next;
    }
    return count;
}
