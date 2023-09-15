#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct node {
    int data;
    struct node* prev;
    struct node* next;
};

// Function to print the linked list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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

// Function to create a new node
struct node* createnode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void addToStart(struct node** head, int data) {
    struct node* newNode = createnode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Function to add a node at the end of the list
void addToEnd(struct node** head, int data) {
    struct node* newNode = createnode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to add a node after the nth node
void addAfterNth(struct node** head, int data, int n) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* newNode = createnode(data);
    struct node* temp = *head;
    int i;
    for (i = 1; i < n && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

// Function to delete the first node
void deleteFirst(struct node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete the last node
void deleteLast(struct node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
}

// Function to delete the nth node
void deleteNth(struct node** head, int n) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;
    int i;
    for (i = 1; i < n && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Function to merge two linked lists
struct node* mergeList(struct node* list1, struct node* list2) {
    if (list1 == NULL) {
    	return list2;
	}
    if (list2 == NULL) {
    	return list1;
	}
    
    struct node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
    list2->prev = temp;
    
    return list1;
}

// Function to reverse the linked list
void reverseList(struct node** head) {
    struct node* temp = NULL;
    struct node* current = *head;
    
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Function to sort the linked list using Bubble Sort
void sortList(struct node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // No need to sort if the list is empty or has only one element
    }

    int swapped;
    struct node* temp;
    struct node* end = NULL;

    while (1) {
        swapped = 0;
        temp = *head;

        while (temp->next != end) {
            if (temp->data > temp->next->data) {
                // Swap data values
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = 1;
            }
            temp = temp->next;
        }
        end = temp;

        if (swapped == 0) {
            break;
        }
    }
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
