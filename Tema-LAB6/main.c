#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;

    struct node *next;
    struct node *prev;
} list_node;

//head node is globaly defined
list_node *head;

//outputs the list
void print_list() {
    list_node *iterator = head;

    while (iterator != NULL) {
        printf("%d ", iterator->value);
        iterator = iterator->next;
    }

    printf("\n");
}

//insert a node at the start of the list
void push_at_head(int number) {
    list_node *new_node = malloc(sizeof(list_node));

    new_node->value = number;
    new_node->prev = NULL;

    if (head == NULL) {
        new_node->next = NULL;
        head = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

//insert a node at the end of the list
void push_at_end(int number) {
    list_node *new_node = malloc(sizeof(list_node));
    list_node *iterator = head;

    new_node->value = number;
    new_node->next = NULL;

    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
    } else {
        while (iterator->next != NULL) {
            iterator = iterator->next;
        }

        new_node->prev = iterator;
        iterator->next = new_node;
    }
}

//insert a node at a given position
void push_at_position(int number, int position) {
    list_node *new_node = malloc(sizeof(list_node));
    list_node *iterator = head;

    int pos_iterator = 0;

    new_node->value = number;

    if (head == NULL) {
        new_node->next = NULL;
        new_node->prev = NULL;
        head = new_node;
        return;
    }

    while (iterator->next != NULL) {
        if (pos_iterator == position) {
            break;
        }
        pos_iterator++;
        iterator = iterator->next;
    }

    if (pos_iterator < position) {
        printf("Position out of range! \n");
        return;
    }

    if (iterator->prev == NULL) {
        new_node->next = iterator;
        new_node->prev = NULL;
        iterator->prev = new_node;

        head = new_node;
        return;
    }

    list_node *temp = iterator->prev;

    new_node->next = iterator;
    new_node->prev = temp;
    temp->next = new_node;
    iterator->prev = new_node;
}

//remove node from the head
void pop_from_head() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    head = head->next;
    head->prev = NULL;
}

//remove node from the end
void pop_from_end() {
    list_node *iterator = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (iterator->next != NULL) {
        iterator = iterator->next;
    }

    iterator = iterator->prev;
    iterator->next = NULL;
}

//remove node from given position
void pop_from_positon(int position) {
    list_node* iterator = head;

    int pos_iterator = 0;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (iterator->next != NULL) {
        if (pos_iterator == position) {
            break;
        }
        pos_iterator++;
        iterator = iterator->next;
    }

    if (iterator->prev == NULL) {
        pop_from_head();
        return;
    }
    if (iterator->next == NULL) {
        pop_from_end();
        return;
    }

    list_node *temp = iterator->next;
    iterator = iterator->prev;
    iterator->next = temp;
    temp->prev = iterator;
}

//sorting the nodes using insertion-sort
void list_insertion_sort() {
    list_node *fwd_iterator = head->next;
    list_node *bck_iterator;

    int fwd_pos = 1;
    int bck_pos;

    if (head == NULL) {
        printf("List is empty \n");
        return;
    }

    while (fwd_iterator != NULL) {

        bck_iterator = fwd_iterator->prev;
        bck_pos = fwd_pos - 1;

        int move_check = 0;

        while (bck_iterator != NULL && bck_iterator->value > fwd_iterator->value) {
            bck_iterator = bck_iterator->prev;
            bck_pos--;
            move_check  = 1;
        }

        if (bck_iterator == NULL) {
            push_at_head(fwd_iterator->value);
        } else if (move_check == 1) {
            push_at_position(fwd_iterator->value, bck_pos + 1);
        }

        if (move_check == 1) {
            if (fwd_iterator->next == NULL) {
                pop_from_end();
            } else {
                pop_from_positon(fwd_pos + 1);
            }
        }

        fwd_iterator = fwd_iterator->next;
        fwd_pos++;
    }
}

int main() {
    head = NULL;

    push_at_head(1);
    push_at_head(2);
    push_at_head(3);
    push_at_head(4);

    push_at_end(7);
    push_at_end(8);
    push_at_end(9);
    push_at_end(10);

    push_at_position(6, 4);
    push_at_position(5, 5);

    print_list();

    list_insertion_sort();

    print_list();

    free(head);

    return 0;
}