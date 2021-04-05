#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pqueueNode_t {
    int masuk;
    int keluar;
    struct pqueueNode_t *next;
} PQueueNode;

typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int in, int out);
void pqueue_pop(PriorityQueue *pqueue);
int  pqueue_top(PriorityQueue *pqueue);
int  pqueue_needRenov(PriorityQueue *pqueue);

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, int in, int out)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->masuk = in;
    newNode->keluar = out;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (in < pqueue->_top->masuk) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->masuk < in)
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
        return pqueue->_top->masuk;
    else return 0;
}

void pqueue_sortCars(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp;
        temp = pqueue->_top;
		
		int tempval;
        while (temp->next != NULL) {
			if (temp->masuk == temp->next->masuk) {
				if (temp->keluar > temp->next->keluar) {
					tempval = temp->keluar;
					temp->keluar = temp->next->keluar;
					temp->next->keluar = tempval;
				}
			}
			temp = temp->next;
        }
    }
}

int  pqueue_needRenov(PriorityQueue *pqueue) {
    PQueueNode *temp = pqueue->_top;
    if (temp->masuk == temp->keluar) return 1;
    if (temp->keluar <= temp->next->masuk) return 0;
    while ( temp->next != NULL ) {
		if (temp->next->masuk == temp->next->keluar) return 1;

		temp = temp->next;
        if ((temp->masuk >= pqueue->_top->masuk && 
			 temp->masuk < pqueue->_top->keluar) &&
			 temp->keluar > pqueue->_top->keluar)
			return 1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
    PriorityQueue cars;

    pqueue_init(&cars);

    int testc;
   	int carCount,
   		cap,
   		timeIn,
   		timeOut,
		renov;
    
    scanf("%d", &testc);
    
    int i=0;
    for (; i<testc; i++)
    {
		scanf("%d%d", &carCount ,&cap);
    	int j=0;
    	for (; j<carCount; j++) {
    		scanf("%d%d", &timeIn,&timeOut);
    		pqueue_push(&cars, timeIn, timeOut);
		}
		pqueue_sortCars(&cars);
		if (pqueue_needRenov(&cars))
			printf("Hmm harus renovasi garasi nich\n");
		else
			printf("Hore gausah renov garasi\n");
	    while (!pqueue_isEmpty(&cars)) {
	        pqueue_pop(&cars);
	    }
	}

    return 0;
}
