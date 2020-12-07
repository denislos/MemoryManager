

#ifndef MEMMAN_DEMO_TREE_H
#define MEMMAN_DEMO_TREE_H

typedef struct tree_node_t {
    int data;
    struct tree_node_t* left;
    struct tree_node_t* right;
} tree_node_t;

typedef struct tree_t {
    tree_node_t* root;
} tree_t;

void tree_create(tree_t* tree, int data);

void tree_add_left(tree_node_t* target_node, int data);
void tree_add_right(tree_node_t* target_node, int data);

void tree_print_dfs(tree_t* tree);

void tree_destroy(tree_t* tree);

#endif // MEMMAN_DEMO_TREE_H