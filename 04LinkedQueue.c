#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define MAXSIZE 100			/* ���е�������� */

typedef int ElemtType;		/* ����ElemtType����������Ϊint */


/* ��������--���е���ʽ�洢�ṹ */
typedef struct QueueNode
{
	ElemtType data;
	struct QueueNode *next;
}QueueNode,*QueuePtr;

typedef struct
{
	QueuePtr front,rear;	/* ��ͷ����βָ�� */
} LinkedQueue;

/* ����һ���ն���Q */
int InitQueue(LinkedQueue *Q)
{
	Q->rear = (QueuePtr) malloc(sizeof(QueueNode));
	Q->front = Q->rear;
	if(!Q->front)
		return FAILURE;
	Q->front->next=NULL;
	return SUCCESS;
}

/* ����еĳ��� */
int QueueLength(LinkedQueue *Q)
{
	int i=0;
	QueuePtr p;
	p=Q->front;
	while(Q->rear!=p)
	{
		i++;
		p=p->next;
	}
	return i;
}

/* ��Q��Ϊ�ն��� */
void ClearQueue(LinkedQueue*Q)
{
	QueuePtr p,q;
	Q->rear=Q->front;
	p=Q->front->next;
	Q->front->next=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
}

/* ��QΪ�ն���, �򷵻�SUCCESS, ���򷵻�FAILURE */
int IsQueueEmpty(LinkedQueue *Q)
{
	if(Q->front->next==NULL)
		return SUCCESS;
	else
		return FAILURE;
}

/* ����Ԫ��eΪQ���µĶ�βԪ�� */
int EnQueue(LinkedQueue*Q,ElemtType e)
{
	QueuePtr p=malloc(sizeof(QueueNode));
	if(!p)/* �洢����ʧ�� */
		return FAILURE;
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return SUCCESS;
}

/* �����в���, ����e����Q�Ķ�ͷԪ��, ������SUCCESS, ���򷵻�FAILURE */
int GetHead(LinkedQueue Q,ElemtType *e)
{
	QueuePtr p;
	if(Q.front==Q.rear)
		return FAILURE;
	p=Q.front->next;
	*e=p->data;
	return SUCCESS;
}

/* �����в���, ɾ��Q�Ķ�ͷԪ��, ��e������ֵ, ������SUCCESS, ���򷵻�FAILURE */
int DeQueue(LinkedQueue *Q,ElemtType *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return FAILURE;
	p=Q->front->next;
	*e=p->data;
	Q->front->next=p->next;
	if(Q->rear==p)
		Q->rear=Q->front;
	free(p);
	return SUCCESS;
}


/* ���ٶ���Q(���ۿշ����) */
void DestroyQueue(LinkedQueue*Q)
{
	while(Q->front)
	{
		Q->rear=Q->front->next;
		free(Q->front);
		Q->front=Q->rear;
	}
}

void main()
{    
	LinkedQueue Q;
	ElemtType in_data1, in_data2, in_data3, e;

	/* ��ʼ������ */	
	printf("creat a queue.\n");
	printf("init result = %d.\n ", InitQueue (&Q)); 

	/*������������*/
	printf("Input a data: ");      
	scanf("%d", &in_data1);
	EnQueue (&Q, in_data1);
	printf("Input a data: ");      
	scanf("%d", &in_data2);
	EnQueue (&Q, in_data2);
	printf("Input a data: ");      
	scanf("%d", &in_data3);
	EnQueue (&Q, in_data3);
	
	if( !IsQueueEmpty(&Q)){
		printf("the queue's lenth is: %d\n",  QueueLength(&Q));  
		DeQueue(&Q, &e); 
		printf("the queue's lenth is: %d\n",  QueueLength(&Q));  
	}

}
