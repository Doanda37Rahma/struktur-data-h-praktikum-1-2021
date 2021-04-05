
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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

int main(int argc, char const *argv[])
{
    Stack ray;
    Stack kakak;
 
    stack_init(&ray);
    stack_init(&kakak);
    
    int N, T, a, b;
    
    scanf("%d", &N);
    scanf("%d", &T);
    
    if (N<1) {
    	printf("Ray SangaT MaraH!\n");
    	return 0;
	}
	
    int i, j;
    for (i=N; i>0; i--) {
    	stack_push(&ray, i);
	}
    for (i=0; i<T; i++)
    {
    	scanf("%d%d", &a, &b );
    	if (a==1) {
    		for (j=0; j<b && !stack_isEmpty(&ray); j++) {
				stack_push(&kakak, stack_top(&ray));
				stack_pop(&ray);	    		
			}
		} else if (a==2) {
    		for (j=0; j<b && !stack_isEmpty(&kakak); j++) {
				stack_push(&ray, stack_top(&kakak));
				stack_pop(&kakak);	    					
			}
		} else {
			printf("TumpukAnnya saLah! :(\n");
			return 0;
		}
	}

	int rayE=0, kakakE=0; 
	
	while (!stack_isEmpty(&ray) || !stack_isEmpty(&kakak)) {
		if (!stack_isEmpty(&ray)) {
			printf("%d ", stack_top(&ray));
			stack_pop(&ray);
		} else {
			rayE+=1;
		}
		if (rayE>0) {
			printf("- ");
			rayE=-10000;
		} else if (rayE < 0) {
			printf(" ");
		}
		if (!stack_isEmpty(&kakak)) {
			printf("%d", stack_top(&kakak));
			stack_pop(&kakak);
		} else {
			kakakE+=1;
		}
		if (kakakE>0) {
			printf(":(");
			kakakE=-10000;
		}
		putchar('\n');
	}
	
    return 0;
}
