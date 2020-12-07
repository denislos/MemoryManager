
#include <stdlib.h>

#include "memman.h"

#include "tree.h"

int main()
{
    tree_t tree;
    tree_create(&tree, 5);

    tree_add_left(tree.root, 6);
    tree_add_right(tree.root, 10);
    tree_add_right(tree.root->right, 15);
    tree_add_right(tree.root->left, 21);
    tree_add_right(tree.root->left->right, 54);

    tree_print_dfs(&tree);

    tree_destroy(&tree);

    MM_VERIFY_EMPTY();

    return EXIT_SUCCESS;
}