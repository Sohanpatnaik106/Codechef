#include<stdio.h>
#include<stdlib.h>

typedef struct _node 
{
	int x;
	int y;
	struct _node *nextx;
	struct _node *nexty; 
}node;

FILE *fp;

void insert_point(int x, int y, node **head, node **tail) {
	node *point = (node *)malloc(sizeof(node));
	point->nextx = NULL;
	point->nexty = NULL;

	if((*head) == NULL) {
		(*head) = point;
		(*tail) = point;
	}
	else {
		(*tail)->nextx = point->nextx;
		(*tail)->nexty = point->nexty;
		(*tail) = point;
	}
}

void printlist(node *head) {
	while(head != NULL) {
		printf("%d %d\n", head->x, head->y);
		head = head->nextx;
	}
}

int main() {
	fp = fopen("points.txt", "r");
	int x, y;
	node *head = NULL, *tail = NULL;
	while(!feof(fp)) {
		scanf("%d", &x);
		scanf("%d", &y);

		insert_point(x, y, &head, &tail);
	}
	printlist(head);
}