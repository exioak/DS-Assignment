#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct datatype_t
{
    char *name;
} datatype_t;

struct BST_node
{
    char *name1;
    struct BST_node *left;
    struct BST_node *right;
};

struct BST_node *Insert(struct BST_node *rootptr, datatype_t *d);

struct BST_node *Insert(struct BST_node *rootptr, datatype_t *d)
{
    if (rootptr == NULL)
    {
        rootptr = (struct BST_node *)malloc(sizeof(struct BST_node));
        rootptr->name1 = d->name;
        rootptr->left = rootptr->right = NULL;
    }
    else if (strcmp(rootptr->name1, d->name) < 0)
    {
        
        rootptr->left = Insert(rootptr->left, d);
    }
    else if (strcmp(rootptr->name1, d->name) > 0)
    {
       
        rootptr->right = Insert(rootptr->right, d);
    }
    else
    {
        assert(strcmp(rootptr->name1, d->name) == 0);
        printf("duplicate\n");
    }
    return rootptr;
}

static void BST_print_inorder(const char *tag, struct BST_node *node)
{
    if (tag != NULL)
        printf("%s:\n", tag);
    if (node != NULL)
    {
        BST_print_inorder(NULL, node->left);
        printf("%s \n", node->name1);
        BST_print_inorder(NULL, node->right);
    }
}

int main(void)
{
	datatype_t na[]={{"Dave"}};
	int index;
    datatype_t earth[] =
    {
        { "Arthi"},
        { "Christy"},
        { "Dorothy"},
        { "Fraser"},
        { "Eliza"},
    };
    enum { NUM_LINES = sizeof(earth) / sizeof(earth[0]) };
    struct BST_node *root = NULL;
    for (index = 0; index < NUM_LINES; index++)
    {
        //if (root != NULL)
           // printf("Root node: %s\n", (root->name1));
        root = Insert(root, &earth[index]);
        //BST_print_inorder("Insert complete", root);
    }
    BST_print_inorder("Insert complete", root);
    root = Insert(root, &na[0]);
    printf("\n\n");
    BST_print_inorder("Insert complete", root);
    return 0;
}
