#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "door_struct.h"
#include "list.h"

void add_door_test();
void remove_door_test();

int main() {
    add_door_test();
    remove_door_test();
    return 0;
}

void remove_door_test() {
    struct door door1 = {1, 0};
    struct door door2 = {0, 0};
    struct node* root_ = init(&door1);
    remove_door(add_door(root_, &door2), root_);
    if (count(root_) == 1) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
    remove_door(add_door(root_, &door2), root_);
    if (count(root_) == 1) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
    find_door(1, root_);
    destroy(root_->next);
}

void add_door_test() {
    struct door door1 = {1, 14};
    struct door door2 = {0, 1};
    struct node* root = init(&door1);
    if (add_door(root, &door2)->door == &door2)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    if (count(root) >= 2)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    destroy(root->next);
    free(root);
}
