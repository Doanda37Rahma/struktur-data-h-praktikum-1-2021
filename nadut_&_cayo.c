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
    Stack blocks;
    Stack revB;

    stack_init(&blocks);
    stack_init(&revB);

	int testc,
		blockCount, 
		block;
	int i=0;
	scanf("%d", &testc);
	for (; i<testc; i++)
	{
		int j=0;
		scanf("%d", &blockCount);
		for (; j<blockCount; j++)
		{
			scanf("%d", &block);
			while (!stack_isEmpty(&blocks) && stack_top(&blocks) < block) {
				stack_pop(&blocks);
			}
			stack_push(&blocks, block);
		}
		while (!stack_isEmpty(&blocks)) {
			stack_push(&revB, stack_top(&blocks));
			stack_pop(&blocks);
		}
		printf("Susunan blok yang disusun Nadut dan Cayo adalah : ");
	    while (!stack_isEmpty(&revB)) {
	        printf("%d ", stack_top(&revB));
	        stack_pop(&revB);
	    }
		puts("");

		while (!stack_isEmpty(&blocks)) {
			stack_pop(&blocks);
		}
	    while (!stack_isEmpty(&revB)) {
	        stack_pop(&revB);
	    }		
	}
		
    return 0;
}
