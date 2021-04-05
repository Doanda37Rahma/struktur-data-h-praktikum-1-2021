#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}


int main(int argc, char const *argv[])
{
    Stack gjl;
    Stack gnp;
    Stack urut;
	Stack rev;

    stack_init(&gjl);
    stack_init(&gnp);
    stack_init(&urut);
    stack_init(&rev);

	int n,
		i, 
		plat;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &plat);
		if (plat % 2 != 0) {
	    	stack_push(&gjl, plat);
		} else {
			stack_push(&gnp, plat);
		}
	}
	while (!stack_isEmpty(&gjl)) {
		stack_push(&urut, stack_top(&gjl));
		stack_pop(&gjl);
	}

	while (!stack_isEmpty(&gnp)) {
		stack_push(&rev, stack_top(&gnp));
		stack_pop(&gnp);
	}
	while (!stack_isEmpty(&rev)) {
		stack_push(&urut, stack_top(&rev));
		stack_pop(&rev);
	}

	printf("Urutan Mobil Roy : ");
    while (!stack_isEmpty(&urut)) {
        printf("%d", stack_top(&urut));
        if (urut._size == 1) printf("\n");
        else printf(" ");
        stack_pop(&urut);
    }
	puts("");
    return 0;
}
