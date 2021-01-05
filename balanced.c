#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


char* TERMS[] = {"()", "[]", "{}"};

struct node_t {
    char data;
    struct node_t* next;
};

struct node_t* push_stack(char c, struct node_t* stack) {
    struct node_t* new_node = (struct node_t*)malloc(sizeof(struct node_t));
    new_node->data = c;
    new_node->next = stack;
    return new_node;
}

struct node_t* pop_stack(struct node_t* stack) {
    struct node_t* del_node = stack;
    stack = del_node->next;
    free(del_node);
    return stack;
}

bool empty_stack(struct node_t* stack) {
    if (stack == NULL) return true;
    return false;
}

bool is_open_term(char open_term) {
    for (int i = 0; i < 3; ++i) {
        if (TERMS[i][0] == open_term) {
            return true;
        }
    }
    return false;
}

bool match(char open_term, char close_term) {
    for (int i = 0; i < 3; ++i) {
        if (TERMS[i][0] == open_term) {
            if (TERMS[i][1] == close_term) return true;
            return false;
        }
    }
    return false;
}

bool is_balanced(char* expression) {
    struct node_t* st = NULL;
    int n = strlen(expression);
    char c;
    for (int i = 0; i < n; ++i) {
        c = expression[i];
        if (is_open_term(c)) {
            st = push_stack(c, st);
        }
        else {
            if (empty_stack(st)) {
                return false;
            }
            char t = st->data;
            if (!match(t, c)) {
                return false;
            }
            st = pop_stack(st);
        }
    }
    return empty_stack(st);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        perror("Please pass string to program\n");
        exit(-1);
    }
    if (is_balanced(argv[1])) {
        printf("Balanced\n");
    }
    else {
        printf("Not balanced\n");
    }
    return 0;
}
