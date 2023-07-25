#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
    CONSTANT
} TypeTag;

typedef struct Node {
    TypeTag type;
    int value; // For CONSTANT nodes, this holds the constant value
    struct Node *left;
    struct Node *right;
} Node;

Node* makeFunc(TypeTag type) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void calc(Node *node) {
    if (node == NULL) {
        printf("Node is NULL!\n");
        return;
    }

    if (node->type == CONSTANT) {
        // Do nothing, the value is already assigned
        return;
    }

    calc(node->left);
    calc(node->right);

    switch (node->type) {
        case ADD:
            node->value = node->left->value + node->right->value;
            break;
        case SUB:
            node->value = node->left->value - node->right->value;
            break;
        case MUL:
            node->value = node->left->value * node->right->value;
            break;
        case DIV:
            node->value = node->left->value / node->right->value;
            break;
        default:
            printf("Invalid TypeTag!\n");
            break;
    }
}

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int* fib = (int*)malloc((n + 1) * sizeof(int));
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int result = fib[n];
    free(fib);
    return result;
}

int main() {
    Node *add = makeFunc(ADD);
    add->left = makeFunc(CONSTANT);
    add->left->value = 10;
    add->right = makeFunc(CONSTANT);
    add->right->value = 6;

    Node *mul = makeFunc(MUL);
    mul->left = makeFunc(CONSTANT);
    mul->left->value = 5;
    mul->right = makeFunc(CONSTANT);
    mul->right->value = 4;

    Node *sub = makeFunc(SUB);
    sub->left = mul;
    sub->right = add;

    Node *fibo = makeFunc(CONSTANT);
    fibo->value = fibonacci(sub->value);

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    printf("add : %d\n", add->value);
    printf("mul : %d\n", mul->value);
    printf("sub : %d\n", sub->value);
    printf("fibo : %d\n", fibo->value);

    free(add); //To avoid memory leak, free the memory.
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}