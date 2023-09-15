#include<stdio.h>
#include<stdlib.h>

// node structure definition
struct node {
	int data;
	struct node* next;
};

// function to swap two numbers
void swap(struct node* a, struct node* b) {
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

// function to print list
void printList(struct node* head) {
	if (head == NULL) {
        printf("List is empty\n");
        return;
    }
	struct node* temp = head;
	while(temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

// function to create and return a new node
struct node* createNode(int data) {
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void addToStart(struct node** head, int data);
void addToEnd(struct node** head, int data);
void addAfterNth(struct node** head, int data, int n);

void deleteFirst(struct node** head);
void deleteLast(struct node** head);
void deleteNth(struct node** head, int n);

void reverseList(struct node** head);
void sortList(struct node** head);
int searchKey(struct node* head, int key);
struct node* mergeList(struct node* list1, struct node* list2);

int main() {
	struct node* head1 = NULL;
	addToStart(&head1, 20);
	addAfterNth(&head1, 10, 0);
	addToEnd(&head1, 30);
	printList(head1);
	
	struct node* head2 = NULL;
	addToStart(&head2, 50);
	addAfterNth(&head2, 110, 0);
	addToEnd(&head2, 60);
	printList(head2);
	
	struct node* mergedList = mergeList(head1, head2);
	printList(mergedList);
	sortList(&mergedList);
	printList(mergedList);
	
	int pos = searchKey(mergedList, 50);
	printf("%d", pos);
	
	return 0;
}

// function to add a node at the start of list
void addToStart(struct node** head, int data) {
	struct node* newNode = createNode(data);
	newNode->next = *head;	
	*head = newNode;
}

// function to add a node at the end of list
void addToEnd(struct node** head, int data) {
	struct node* newNode = createNode(data);
	if(*head == NULL) {
		*head = newNode;
		return;
	}
	struct node* current = *head;
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;
}

// function to add new node after nth node
void addAfterNth(struct node** head, int data, int n) {
	if(*head == NULL) {
		printf("List is empty!\n");
		return;
	}
	if(n<=0) {
		printf("Invalid Index!\n");
		return;
	}
	struct node* current = *head;
	int i;
	for(i=1; current!=NULL && i<n; i++) {
		current = current->next;
	}
	
	if(current == NULL) {
		printf("Index out of range!\n");
		return;
	}
	struct node* newNode = createNode(data);
	newNode->next = current->next;
	current->next = newNode;
}

// function to delete first node of list
void deleteFirst(struct node** head) {
	if(*head==NULL) {
		printf("List is already empty!\n");
		return;
	}
	struct node* temp = *head;
	*head = (*head)->next;
	free(temp);
}

// function to delete last node of list
void deleteLast(struct node** head) {
	if(*head == NULL) {
		printf("List is already empty!\n");
		return;
	}
	if((*head)->next==NULL) {
		free(*head);
		*head = NULL;
		return;
	}
	struct node* current = *head;
	while(current->next->next!=NULL) {
		current = current->next;
	}
	free(current->next);
	current->next = NULL;
}

void deleteNth(struct node** head, int n) {
	if(*head == NULL) {
		printf("List is already empty!\n");
		return;
	}
	if(n<=0) {
		printf("Invalid index!\n");
		return;
	}
	if(n==1) {
		struct node* temp = *head;
		*head = (*head)->next;
		free(temp);
		return;
	}
	struct node* current = *head;
	int i;
	for(i=1; current!=NULL && i<n-1; i++) {
		current = current->next;
	}
	if(current==NULL || current->next == NULL) {
		printf("Index out of range!\n");
		return;
	}
	struct node* temp = current->next;
	current->next = temp->next;
	free(temp);
}

void reverseList(struct node** head) {
	struct node* prevNode = NULL;
	struct node* currentNode = *head;
	struct node* nextNode = NULL;
	
	while(currentNode != NULL) {
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}
	
	*head = prevNode;
}

void sortList(struct node** head) {
	if(*head == NULL) {
		printf("List is empty!\n");
		return;
	}
	
	int swapped;
	struct node* current;
	struct node* last = NULL;
	
	swapped=1;
	while(swapped) {
		swapped = 0;
		current = *head;
		
		while(current->next!=last) {
			if(current->data > current->next->data) {
				swap(current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
		last = current;
	}
}

struct node* mergeList(struct node* list1, struct node* list2) {
	if(list2 == NULL) {
		return list1;
	}
	struct node* mergedList = list1;
	struct node* temp = mergedList;
	while(temp->next!=NULL) {
		temp = temp->next;
	}
	temp->next = list2;
	return mergedList;
}

int searchKey(struct node* head, int key) {
	int position = 1;
	struct node* current = head;
	
	while(current != NULL) {
		if(current->data==key) {
			return position;
		}	
		current = current->next;
		position++;
	}
	
	return -1;
}
