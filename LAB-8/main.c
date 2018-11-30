#include <stdio.h>
#include <stdlib.h>

struct tree_node {
    struct tree_node *left_child;
    struct tree_node *right_child;
    int info;
};

void insert_node(struct tree_node **root, int new_element_value) {

    while(*root != NULL){
        if (new_element_value < (*root)->info){
            root = &(*root)->left_child;
        }else{
            root = &(*root)->right_child;
        }
    }
    *root = malloc (sizeof **root);
    (*root)->info = new_element_value;
    (*root)->left_child = NULL;
    (*root)->right_child = NULL;
}


void preorder(struct tree_node *root) {
    if(root == NULL)
    {
        printf("\nThe BST is empty");
        return;
    }

    printf("%d,", root->info);
    if (root->left_child) preorder(root->left_child);
    if (root->right_child) preorder(root->right_child);
}

//to be implemented
void postorder(struct tree_node *root) {
    if(root == NULL)
    {
        printf("\nThe BST is empty");
        return;
    }

    if (root->left_child) postorder(root->left_child);
    if (root->right_child) postorder(root->right_child);
    printf("%d, ", root->info);
}

//to be implemented
void inorder(struct tree_node *root) {
    if(root == NULL)
    {
        printf("\nThe BST is empty");
        return;
    }

    if (root->left_child) inorder(root->left_child);
    printf("%d, ", root->info);
    if (root->right_child) inorder(root->right_child);
}


int search_node(struct tree_node *root, int searched_value){
    int found = 0;
    struct tree_node *current;

    current = root;
    while ( (current != NULL) && (found == 0) ){
        if (current->info == searched_value){
            found = 1;
        }else if ( searched_value > current->info){
            current = current->right_child;
        }else if ( searched_value < current->info  ){
            current = current->left_child;
        }
    }

    return found;
}

//to be implemented
int pop_node(struct tree_node *root, int searched_value){
    int found = 0;
    int aux = 0;
    int lr_check;
    struct tree_node *current;
    struct tree_node *parent;
    struct tree_node *iterator;

    // search the node and determine if it exists
    if (search_node(root, searched_value)) {
        found = 1;
    }

    // if the node is not present in the BST
    if (found == 0) {
        printf("\n Node not found");
        return 0;
    }

    //poping operations
    parent = root;

    // if the searched node is the root:
    if (parent->info == searched_value) {
        iterator = parent->right_child;

        aux = parent->info;

        while (iterator->left_child != NULL) {
            iterator = iterator->left_child;
        }

        iterator->left_child = parent->left_child;
        *root = *parent->right_child;

    } else {

        // ohterwise find the node and its parent:
        while (parent->left_child->info != searched_value && parent->right_child->info != searched_value) {
            if (searched_value < parent->info) {
                parent = parent->left_child;
            }
            if (searched_value > parent->info) {
                parent = parent->right_child;
            }
        }
        if (searched_value == parent->left_child->info) {
            current = parent->left_child;
            lr_check = 0;
        } else {
            current = parent->right_child;
            lr_check = 1;
        }

        aux = current->info;

        // found node has no children:
        if (current->left_child == NULL && current->right_child == NULL) {
            free(current);

            if (lr_check == 0) {
                parent->left_child = NULL;
            } else {
                parent->right_child = NULL;
            }

            // found node has one child:
        } else if (current->left_child == NULL || current->right_child == NULL) {

            if (current->left_child == NULL) {
                if (lr_check == 0) {
                    parent->left_child = current->right_child;
                } else {
                    parent->right_child = current->right_child;
                }
            } else {
                if (lr_check == 0) {
                    parent->left_child = current->left_child;
                } else {
                    parent->right_child = current->left_child;
                }
            }

            free(current);

            // found node has 2 children:
        } else {
            iterator = current->right_child;

            while (iterator->left_child != NULL) {
                iterator = iterator->left_child;
            }

            iterator->left_child = current->left_child;

            if (lr_check == 0) {
                parent->left_child = current->right_child;
            } else {
                parent->right_child = current->right_child;
            }

            free(current);
        }
    }

    return aux;
}


int main(void) {
    struct tree_node *root;
    root=NULL;
    int choice;
    int data;
    int aux;

    while( 1 > 0 )
    {
        printf("\nPress 1 for inserting a node in BST fashion: ");
        printf("\nPress 2 for traversing the tree in preorder fashion :");
        printf("\nPress 3 for traversing the tree in postorder fashion :");
        printf("\nPress 4 for traversing the tree in inorder fashion :");
        printf("\nPress 5 for searching:");
        printf("\nPress 6 for poping and element:");
        printf("\nPress 7 to exit :");


        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the value to be inserted:");
                scanf("%d",&data);
                insert_node(&root, data);
                break;

            case 2: preorder(root);
                break;

            case 3: postorder(root);
                break;

            case 4: inorder(root);
                break;

            case 5:
                printf("\nEnter the value to be searched:");
                scanf("%d",&data);
                aux = search_node(root, data);
                (aux == 1) ? printf("Element found") : printf("Element not found");
                break;
            case 6:
                printf("\nEnter the value to be poped:");
                scanf("%d",&data);
                aux = pop_node(root, data);
                (aux != -2) ? printf("Element poped %d",aux) : printf("Element not found");
                break;
            case 7: exit(0);
                break;
            default: printf("\nYou have entered an invalid choice. Please try again");
        }
    }

    free(root);

    return 0;
}