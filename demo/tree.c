

#include "tree.h"

#include "memman.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

MM_TYPE_REGISTER(tree_node_t);
MM_TYPE_REGISTER(tree_t);

void tree_create(tree_t* tree, int data)
{
    tree_node_t* tree_node = MM_ALLOC(tree_node_t);
    assert(tree_node != MM_NULLPTR);

    tree_node->left = MM_NULLPTR;
    tree_node->right = MM_NULLPTR;
    tree_node->data = data;

    tree->root = tree_node;
}

void tree_add_left(tree_node_t* target_node, int data)
{
    assert(target_node->left == MM_NULLPTR);

    target_node->left = MM_ALLOC(tree_node_t);
    assert(target_node->left != MM_NULLPTR);

    target_node->left->left  = MM_NULLPTR;
    target_node->left->right = MM_NULLPTR;
    target_node->left->data = data;
}

void tree_add_right(tree_node_t* target_node, int data)
{
    assert(target_node->right == MM_NULLPTR);

    target_node->right = MM_ALLOC(tree_node_t);
    assert(target_node->right != MM_NULLPTR);

    target_node->right->left  = MM_NULLPTR;
    target_node->right->right = MM_NULLPTR;
    target_node->right->data = data; 
}

void dfs_visitor(tree_node_t* node, int (*visitor)(tree_node_t*))
{
    if (node == MM_NULLPTR)
        return;
    
    if (node->left != MM_NULLPTR)
        dfs_visitor(node->left, visitor);
    
    if (node->right != MM_NULLPTR)
        dfs_visitor(node->right, visitor);
    
    visitor(node);
}

int tree_destroy_visitor(tree_node_t* node)
{
    MM_DEALLOC(node);
    return 0;
}

void tree_destroy(tree_t* tree)
{
    dfs_visitor(tree->root, tree_destroy_visitor);
}

int print_visitor(tree_node_t* node)
{
    printf("%d\n", node->data);
    return 0;
}

void tree_print_dfs(tree_t* tree)
{
    dfs_visitor(tree->root, print_visitor);
}

