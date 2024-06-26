#ifndef SRC_LIST_H_
#define SRC_LIST_H_
struct node {
    struct door* door;
    struct node* next;
};

struct node* init(struct door* door);
struct node* add_door(struct node* elem, struct door* door);
struct node* find_door(int door_id, struct node* root);
struct node* remove_door(struct node* elem, struct node* root);
void destroy(struct node* root);
void add_door_test();
void remove_door_test();
int count(struct node *root);

#endif  // SRC_LIST_H_
