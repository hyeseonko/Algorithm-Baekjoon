#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define TRUE 1
//#define FALSE 0

typedef int Data; //Data�� �ڷ����� ���߿� �ٲ� ���� ����Ͽ� �� �����ϳ��� �ٲ㵵 �Ǵϱ�.

typedef struct node {
	Data data;
	struct node* next;
}Node;

typedef struct {
	Node* front;
	Node *rear;
	int qcount;
}Queue;


/* Queue�� �ʱ�ȭ�� */
void Qinit(Queue *pq);

/* push X�� �Է��ϸ� �־��� */
void Push(Queue *pq, Data data);

/* pop�� �Է��ϸ� �� �� ����ϰ� ������ ������ -1 ���*/
void Pop(Queue *pq);

/* ť�� ����ִ� ���� ���� ���*/
void Size(Queue *pq);

/* ��������� 1 ���, �ƴϸ� 0 ���*/
void Empty(Queue *pq);

/* ���� �տ� �ִ� �ִ� ���� ���, ������ -1 ��� */
void Front(Queue *pq);

/* ���� �ڿ� �ִ� �ִ� ���� ���, ������ -1 ��� */
void Back(Queue *pq);

main() {

	Queue q; Qinit(&q);
	int num;
	char command[10000];
	char c_buffer[5];
	int i = 0;
	int j, k;
	int len;
	Data tempdata;

	scanf("%d", &num);
	getchar();          // �״��� gets�� ���������� ����Ű�� �νĸ��ϴϱ� getchar �־���� ��.

	while(i!=num)
	{
	//	fflush(stdin);
		gets(command);
		len = strlen(command);
		if (!strncmp(command, "push", 4)) // push���
		{
			k = 0;
			memset(c_buffer, NULL, len);  // �ູ�� �Լ� memset (ptr, value to initialize, length)

			for (j = 5; command[j] != '\0'; j++)
			{
				c_buffer[k++] = command[j];
			}

			tempdata = atoi(c_buffer);
			Push(&q, tempdata);
		}
	
		else if (strcmp(command, "pop") == 0)
		{
			Pop(&q);
		}
		else if (strcmp(command, "size") == 0)
		{
			Size(&q);
		}
		else if (strcmp(command, "empty") == 0)
		{
			Empty(&q);
		}
		else if (strcmp(command, "front") == 0)
		{
			Front(&q);
		}
		else if (strcmp(command, "back") == 0)
		{
			Back(&q);
		}
		else
		{
			puts("Wrong command!");
		}
		i++;
	}
}


void Qinit(Queue *pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->qcount = 0;
}

void Push(Queue *pq, Data data) {
	Node *newnode = (Node*)malloc(sizeof(Node));  // create node which to be added.
	newnode->data = data;
	newnode->next = NULL;

	if (pq->qcount == 0){      // if the queue is empty then front = rear = newnode
		pq->front = newnode;
		pq->rear = newnode;
	}
	else {                     
		pq->rear->next = newnode;
		pq->rear = newnode;
	}
	pq->qcount++;
}

void Pop(Queue *pq) {
	Node *delnode;      // NODE to be removed 
	Data *deldata;      // DATA to be deleted
	if (pq->qcount == 0)
	{
		puts("-1");
	}
	else {
		delnode = pq->front;
		deldata = delnode->data;
		pq->front = pq->front->next;
		pq->qcount--;

		free(delnode); 
		printf("%d\n", deldata);
	}
}

void Size(Queue *pq) {
	printf("%d\n", pq->qcount);
}

void Empty(Queue *pq) {

	if (pq->qcount == 0) puts("1");
	else puts("0");
}

void Front(Queue *pq) {
	if (pq->qcount == 0) {
		puts("-1"); 
	}
	else {
		printf("%d\n", pq->front->data);
	}
}

void Back(Queue *pq){
	if (pq->qcount == 0) {
		puts("-1");
	}
	else {
		printf("%d\n", pq->rear->data);
	}
}