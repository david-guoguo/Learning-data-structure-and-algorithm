#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define MAXSIZE 100			/* 队列的最大容量 */

typedef int ElemtType;		/* 定义ElemtType的数据类型为int */


/* 单链队列--队列的链式存储结构 */
typedef struct QueueNode
{
	ElemtType data;
	struct QueueNode *next;
}QueueNode,*QueuePtr;

typedef struct
{
	QueuePtr front,rear;	/* 队头、队尾指针 */
} LinkedQueue;

/* 构造一个空队列Q */
int InitQueue(LinkedQueue *Q)
{
	Q->rear = (QueuePtr) malloc(sizeof(QueueNode));
	Q->front = Q->rear;
	if(!Q->front)
		return FAILURE;
	Q->front->next=NULL;
	return SUCCESS;
}

/* 求队列的长度 */
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

/* 将Q清为空队列 */
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

/* 若Q为空队列, 则返回SUCCESS, 否则返回FAILURE */
int IsQueueEmpty(LinkedQueue *Q)
{
	if(Q->front->next==NULL)
		return SUCCESS;
	else
		return FAILURE;
}

/* 插入元素e为Q的新的队尾元素 */
int EnQueue(LinkedQueue*Q,ElemtType e)
{
	QueuePtr p=malloc(sizeof(QueueNode));
	if(!p)/* 存储分配失败 */
		return FAILURE;
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return SUCCESS;
}

/* 若队列不空, 则用e返回Q的队头元素, 并返回SUCCESS, 否则返回FAILURE */
int GetHead(LinkedQueue Q,ElemtType *e)
{
	QueuePtr p;
	if(Q.front==Q.rear)
		return FAILURE;
	p=Q.front->next;
	*e=p->data;
	return SUCCESS;
}

/* 若队列不空, 删除Q的队头元素, 用e返回其值, 并返回SUCCESS, 否则返回FAILURE */
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


/* 销毁队列Q(无论空否均可) */
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

	/* 初始化队列 */	
	printf("creat a queue.\n");
	printf("init result = %d.\n ", InitQueue (&Q)); 

	/*输入三个数据*/
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
