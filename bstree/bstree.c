#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define true 1
#define false 0
#define BOOL int

#define DEBUG
#ifdef DEBUG
#define Assert(exp, msg) assert((exp))
#else
#define Assert(exp, msg)        \
    do                          \
    {                           \
        if (!(exp))             \
        {                       \
            perror(msg);        \
            exit(EXIT_FAILURE); \
        }                       \
    } while (0)
#endif

typedef int KEY_TYPE;

#define BTREE_ENTRY(name, type) \
    struct _tag_##name          \
    {                           \
        type *left;             \
        type *right;            \
    }

typedef struct _bstree_node
{
    KEY_TYPE key;
    BTREE_ENTRY(_bstree_node, _bstree_node)
    bst;
} bstree_node;

typedef struct _bstree
{
    bstree_node *root;
} bstree;

bstree_node *create_bstree_node(KEY_TYPE key)
{
    bstree_node *node = (bstree_node *)malloc(sizeof(bstree_node));

    Assert(node != NULL, "bstree_node malloc error");

    node->key = key;
    node->bst.left = node->bst.right = NULL;

    return node;
}

void destroy_bstree_node(bstree_node *node)
{
    Assert(node != NULL, "destroy node error");

    node->bst.left = node->bst.right = NULL;
    free(node);
}

BOOL insert_bstree_node(bstree *tree, KEY_TYPE key)
{
    Assert(tree != NULL, "tree is null ");
    if (tree->root == NULL)
    {
        tree->root = create_bstree_node(key);
        return true;
    }

    bstree_node *node = tree->root;
    bstree_node *tmp = tree->root;

    while (node != NULL)
    {
        tmp = node;
        node = (key <= node->key) ? node->bst.left : node->bst.right;
    }

    if (key <= tmp->key)
    {
        tmp->bst.left = create_bstree_node(key);
    }
    else
    {
        tmp->bst.right = create_bstree_node(key);
    }

    return true;
}

void walk_bstree_node(bstree_node *node)
{
    if (node == NULL)
        return;

    walk_bstree_node(node->bst.left);
    printf("%4d ", node->key);
    walk_bstree_node(node->bst.right);
}

#define walk_bstree(tree) walk_bstree_node(tree->root)

int main(int argc, char const *argv[])
{
    bstree *tree = (bstree *)calloc(1, sizeof(bstree));
    insert_bstree_node(tree, 1);
    insert_bstree_node(tree, 11111);
    insert_bstree_node(tree, 11);
    insert_bstree_node(tree, 11);
    insert_bstree_node(tree, 111);
    insert_bstree_node(tree, 11);
    insert_bstree_node(tree, 1111);
    insert_bstree_node(tree, 1111);
    insert_bstree_node(tree, 1111);
    insert_bstree_node(tree, 11199);

    walk_bstree(tree);
    return 0;
}
