#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct _STUDENT {
	char name[50];
	int sno;
	float gpa;
	char phon[20];
	char province[30];
}Student;

typedef struct _NODE {
	Student std;
	struct _NODE *next;
}Node;

int main(void) {
	FILE *fp;
	Node *head = NULL;
	Node *curr;

	fp = fopen("mydata.txt", "r");
	if (fp == NULL)
		return;

	curr = head;
	while (!feof(fp)) {
		Node *newNode = (Node *)malloc(sizeof(Node));

		if (head == NULL){
			head = (Node *)malloc(sizeof(Node));
			head->next = newNode;
		}
		else
			curr->next = newNode;

		fscanf(fp, "%s %d %f %s %s", newNode->std.name, &newNode->std.sno, &newNode->std.gpa, newNode->std.phon, newNode->std.province);
		curr = newNode;
		newNode->next = NULL;

		printf("%s %d %f %s %s\n", curr->std.name, curr->std.sno, curr->std.gpa, curr->std.phon, curr->std.province);
	}

	fclose(fp);

	return 0;
}
