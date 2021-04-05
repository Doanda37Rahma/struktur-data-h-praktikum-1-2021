#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN 16

typedef struct stackNode_t {
    int sisa;
    char mapel[LEN];
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value, char buku[LEN]);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
char* stack_topMapel(Stack *stack);
unsigned stack_size(Stack *stack);

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value, char buku[LEN]) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->sisa = value;
        strcpy(newNode->mapel, buku);
        
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
        return stack->_top->sisa;
    return 0;
}

char* stack_topMapel(Stack *stack)
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->mapel;
    return 0;
}

/*******************************/

typedef struct pqueueNode_t {
    int data;
    struct pqueueNode_t *next;
} PQueueNode;

typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int value);
void pqueue_pop(PriorityQueue *pqueue);
int  pqueue_top(PriorityQueue *pqueue);

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, int value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value < pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->data < value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}

void pqueue_remove(PriorityQueue *pqueue, int value)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp, *prev;
        temp = pqueue->_top;

        if (temp->data == value) {
            pqueue_pop(pqueue);
            return;
        }
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        pqueue->_size--;
    }
}

int main(int argc, char const *argv[])
{
    Stack books;
    stack_init(&books);

    PriorityQueue pBooks;
    pqueue_init(&pBooks);

	int testc,
		num,
		moveCount;
	char buku[LEN];

	scanf("%d", &testc);
	
	moveCount = 0;
	int i = 0;
	for (; i<testc; i++)
	{
		scanf("%d", &num);
		if (num > 0) {
			scanf("%s", buku);
			stack_push(&books, num, buku);
			pqueue_push(&pBooks, num);
		} else if (num == 0) {
			scanf("%s", buku);
		} else if (num < 0) {
			if (!stack_isEmpty(&books)) {
				while (!stack_isEmpty(&books) && 
						pqueue_top(&pBooks) != stack_top(&books)) {
					moveCount++;
					pqueue_remove(&pBooks, stack_top(&books));
					stack_pop(&books);
				}
				if (stack_top(&books)) {
					printf("%d %s\n", moveCount, stack_topMapel(&books));
					stack_pop(&books);
					pqueue_pop(&pBooks);
				}
				moveCount = 0;
			}
		}
	}
	
    return 0;
}
