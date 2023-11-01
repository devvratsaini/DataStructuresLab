#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

struct Queue {
	int items[MAX_SIZE];
	int front;
	int rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue* queue) {
	return (queue->front == -1);
}

int isFull(struct Queue* queue) {
	return (queue->rear == MAX_SIZE-1);
}

void enqueue(struct Queue* queue, int value) {
	if(isFull(queue)) {
		printf("Queue is full. Cannot enqueue %d.\n", value);
		return;
	}
	
	if(isEmpty(queue)) {
		queue->front = 0;
	}
	queue->rear++;
	queue->items[queue->rear] = value;
	printf("%d enqueued to the queue.\n", value);
}

int dequeue(struct Queue* queue) {
	if(isEmpty(queue)) {
		printf("Queue is empty. Cannot dequeue.\n");
		return -1;
	}
	
	int item = queue->items[queue->front];
	if(queue->front == 0 && queue->rear == 0) {
		queue->front = -1;
		queue->rear = -1;
	}
	else {
		queue->front++;
	}
	
	return item;
}

int main() {
	struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("%d dequeued from the queue.\n", dequeue(queue));
    printf("%d dequeued from the queue.\n", dequeue(queue));

    enqueue(queue, 40);

    printf("Front item is %d\n", queue->items[queue->front]);
    printf("Rear item is %d\n", queue->items[queue->rear]);

    return 0;
}
