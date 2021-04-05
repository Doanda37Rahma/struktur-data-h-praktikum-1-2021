#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define P 200
#define L 200

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

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

 
int maxHist(int row[], int C)
{
    // Create an empty stack.
    // The stack holds indexes of
    // hist[] array/ The bars stored
    // in stack are always
    // in increasing order of their heights.
    Stack result;
    stack_init(&result);
	
 
    int top_val; // Top of stack
 
    int max_area = 0; // Initialize max area in current
    // row (or histogram)
 
    int area = 0; // Initialize area with current top
 
    // Run through all bars of given histogram (or row)
    int i = 0;
    while (i < C) {
        // If this bar is higher than the bar on top stack,
        // push it to stack
        if (stack_isEmpty(&result) || row[stack_top(&result)] <= row[i])
            stack_push(&result, i++);
 
        else {
            // If this bar is lower than top of stack, then
            // calculate area of rectangle with stack top as
            // the smallest (or minimum height) bar. 'i' is
            // 'right index' for the top and element before
            // top in stack is 'left index'
            top_val = row[stack_top(&result)];
            stack_pop(&result);
            area = top_val * i;
 
            if (!stack_isEmpty(&result))
                area = top_val * (i - stack_top(&result) - 1);
            if (max_area < area) max_area = area;
        }
    }
 
    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (!stack_isEmpty(&result)) {
        top_val = row[stack_top(&result)];
        stack_pop(&result);
        area = top_val * i;
        if (!stack_isEmpty(&result))
            area = top_val * (i - stack_top(&result) - 1);
 
        if (max_area < area) max_area = area;
    }
    return max_area;
}

int main() {
	
	int arr[P][L];
	int tc, min, p, l;
	
	scanf("%d%d", &tc ,&min);
	int i, j, k;
	char c;
	for (i=0; i<tc; i++)
	{
		scanf("%d%d\n", &p, &l);
		for (j=0; j<p; j++) {
			
			for (k=0; k<l; k++){
				c = getchar();
				if (k==l-1 && j!= p-1) scanf("\n");
				arr[j][k] = (int)c - '0';
			}
		}
		for (j=0; j<p; j++) {
			for (k=0; k<l; k++) {
				if (arr[j][k]) arr[j][k] = 0;
				else arr[j][k] = 1; 
			}
		}
		for (j=0; j<p; j++) {
			if (j) {
				for (k=0; k<l; k++) {
					if (arr[j][k]) arr[j][k] += arr[j-1][k];
				}
			}
		}
		
		int ada = 0;
		for (j=0; j<p; j++) {
			if (maxHist(arr[j], l) > min) ada =1; 
		}
	
		if (ada) printf("IYA\n");
		else printf("TIDAK\n");	
	}
	
    return 0;
}
