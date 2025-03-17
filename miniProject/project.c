#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    char* op;
    struct node* lefthand;
    struct node* righthand;
} Node;

Node* newNode(char* op, Node* lefthand, Node* righthand) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->op = strdup(op);
    n->lefthand = lefthand;
    n->righthand = righthand;
    return n;
}

void pre2in(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->lefthand == NULL && root->righthand == NULL) {
        printf("%s ", root->op);
        return;
    }
    printf("( ");
    pre2in(root->lefthand);
    printf("%s ", root->op);
    pre2in(root->righthand);
    printf(") ");
}

int is_booleanOp(char *str) {
    if (!strcmp(str, "&") || !strcmp(str, "|") || !strcmp(str, "^"))
        return 1;
    return 0;
}

int is_arithmeticOp(char *str) {
    if (!strcmp(str, "+") || !strcmp(str, "-") || !strcmp(str, "*") || !strcmp(str, "/"))
        return 1;
    return 0;
}

int calc_complexity(Node* root) {
    if (root == NULL)
        return 0;

    if (!is_booleanOp(root->op) && !is_arithmeticOp(root->op))
        return 0;

    int complexity = 0;

    if (root->lefthand != NULL) {
        if ((is_booleanOp(root->op) && is_arithmeticOp(root->lefthand->op)) ||
            (is_arithmeticOp(root->op) && is_booleanOp(root->lefthand->op))) {
            complexity += 1;
        }
        complexity += calc_complexity(root->lefthand);
    }

    if (root->righthand != NULL) {
        if ((is_booleanOp(root->op) && is_arithmeticOp(root->righthand->op)) ||
            (is_arithmeticOp(root->op) && is_booleanOp(root->righthand->op))) {
            complexity += 1;
        }
        complexity += calc_complexity(root->righthand);
    }

    return complexity;
}

int parse_operand(char* operand) {
    int value;
    if (*(operand+1) == 'x') {
        sscanf(operand, "0x%x", &value);
        return value;
    }
    sscanf(operand, "%d", &value);
    return value;
}

int calc_MBA(Node* root) {
    if (root == NULL)
        return 0;

    if (root->lefthand == NULL && root->righthand == NULL) {
        if (!strcmp(root->op, "x") || !strcmp(root->op, "y") || !strcmp(root->op, "z")) {
            int value;
            printf("Enter value for %s: ", root->op);
            scanf("%d", &value);
            return value;
        }
        return parse_operand(root->op);
    }

    int left_value = calc_MBA(root->lefthand);
    int right_value = calc_MBA(root->righthand);

    if (!strcmp(root->op, "+")) {
        return left_value + right_value;
    } else if (!strcmp(root->op, "-")) {
        return left_value - right_value;
    } else if (!strcmp(root->op, "*")) {
        return left_value * right_value;
    } else if (!strcmp(root->op, "/")) {
        if (right_value == 0) {
            printf("Error: Division by zero\n");
            exit(1);
        }
        return left_value / right_value;
    } else if (!strcmp(root->op, "&")) {
        return left_value & right_value;
    } else if (!strcmp(root->op, "|")) {
        return left_value | right_value;
    } else if (!strcmp(root->op, "^")) {
        return left_value ^ right_value;
    }
    return 0;
}

Node* base_parser_idx(int idx, char* prefix_expr, int* parent_add_i) {
    Node* root = NULL;
    Node* left = NULL;
    Node* right = NULL;

    int operand_num = 0;
    int isOperand = 0;
    int isOperator = 0;
    char* operator;
    char op1[11];
    char op2[11];
    char str[11];
    int my_add_i = 0;
    strcpy(op1, "");
    strcpy(op2, "");
    strcpy(str, "");

    for (int i = idx; i < strlen(prefix_expr); i++) {
        if (prefix_expr[i] == '+') {
            operator = "+";
            isOperator = 1;
        }
        else if (prefix_expr[i] == '-') {
            operator = "-";
            isOperator = 1;
        }
        else if (prefix_expr[i] == '*') {
            operator = "*";
            isOperator = 1;
        }
        else if (prefix_expr[i] == '/') {
            operator = "/";
            isOperator = 1;
        }
        else if (prefix_expr[i] == '&') {
            operator = "&";
            isOperator = 1;
        }
        else if (prefix_expr[i] == '|') {
            operator = "|";
            isOperator = 1;
        }
        else if (prefix_expr[i] == '^') {
            operator = "^";
            isOperator = 1;
        }
        else if (prefix_expr[i] == 'x') {
            if (isOperand) {
                sprintf(str, "%s%c", str, prefix_expr[i]);
                continue;
            }
            if (operand_num == 0)
                strcpy(op1, "x");
            else if (operand_num == 1)
                strcpy(op2, "x");
            operand_num += 1;
        }
        else if (prefix_expr[i] == 'y') {
            if (operand_num == 0)
                strcpy(op1, "y");
            else if (operand_num == 1)
                strcpy(op2, "y");
            operand_num += 1;
        }
        else if (prefix_expr[i] == 'z') {
            if (operand_num == 0)
                strcpy(op1, "z");
            else if (operand_num == 1)
                strcpy(op2, "z");
            operand_num += 1;
        }
        else if (prefix_expr[i] == '(') {
            if (!isOperator)    continue;
            if (operand_num == 0) {
                left = base_parser_idx(i + 1, prefix_expr, &my_add_i);
            }
            else if (operand_num == 1) {
                right = base_parser_idx(i + 1, prefix_expr, &my_add_i);
            }
            operand_num += 1;
            i = my_add_i;
        }
        else if (prefix_expr[i] == ')') {
            *parent_add_i = i;
            break;
        }
        else if (prefix_expr[i] == ' ') {
            if (!isOperand)     continue;
            isOperand = 0;
            if (operand_num == 0)
                strcpy(op1, str);
            else if (operand_num == 1)
                strcpy(op2, str);
            operand_num += 1;
            strcpy(str, "");
        }
        else if (prefix_expr[i] == '0' || prefix_expr[i] == '1' || prefix_expr[i] == '2' || prefix_expr[i] == '3' || prefix_expr[i] == '4' ||
                 prefix_expr[i] == '5' || prefix_expr[i] == '6' || prefix_expr[i] == '7' || prefix_expr[i] == '8' || prefix_expr[i] == '9') {
            isOperand = 1;
            sprintf(str, "%s%c", str, prefix_expr[i]);
        }
        else if (isOperand) {
            sprintf(str, "%s%c", str, prefix_expr[i]);
        }
        else {
            if(isOperator) {
                printf("Error: Operand Expression in [%c]\n", prefix_expr[i]);
                exit(1);
            }
            else {
                printf("Error: Operator Expression in [%c]\n", prefix_expr[i]);
                exit(1);
            }
        }
    }
    if (isOperand) {
        isOperand = 0;
        if (operand_num == 0)
            strcpy(op1, str);
        else if (operand_num == 1)
            strcpy(op2, str);
        operand_num += 1;
        strcpy(str, "");
    }

    if (operand_num == 1) {
        if (left == NULL) {
            right = newNode(op1, NULL, NULL);
            root = newNode(operator, NULL, right);
        }
        else {
            root = newNode(operator, NULL, left);
        }
    }
    else {
        if (operand_num != 2) {
            printf("Error: Number of Operand\n");
            exit(1);
        }
        if (left == NULL) {
            left = newNode(op1, NULL, NULL);
        }
        if (right == NULL) {
            right = newNode(op2, NULL, NULL);
        }
        root = newNode(operator, left, right);
    }
    return root;
}

Node* base_parser(char* prefix_expr){
    int temp;
    return base_parser_idx(0, prefix_expr, &temp);
}

int main() {
    char exp[100];
    printf("Enter a prefix expression: ");
    fgets(exp, 100, stdin);
    exp[strcspn(exp, "\n")] = '\0';

    Node* root = base_parser(exp);
    printf("Inorder: ");
    pre2in(root);
    printf("\nComplexity: %d\n", calc_complexity(root));
    printf("MBA Result: %d\n", calc_MBA(root));

    return 0;
}
