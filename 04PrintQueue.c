#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0
#define MAXSIZE 100		/* ���е�������� */

typedef struct node
{     
	int no;				/* ��ӡ�����ʶ�� */
	char *text; 		/* Ҫ��ӡ������ */
	struct node *next; 	/* ָ����һ������ָ�� */
} Task; 				/* ���ṹ��Task */

typedef struct
{     
	Task *front; 		/* ͷָ�� */
	Task *rear; 		/* βָ�� */
} LinkedQueue;

/*---------------------------------------------------------*/
/* ��ʼ��һ���յ���ʽ����                  			 	   */
/*---------------------------------------------------------*/
int InitQueue(LinkedQueue *Q)	
{  
	Q->front = (Task*)malloc(sizeof(Task));	
	if(Q->front != NULL)
	{  
		Q->rear = Q->front;		
		Q->front->next = NULL;
		return SUCCESS;
	}
	else
		return FAILURE;		/* �ڴ����ʧ�ܣ�*/
}

/*---------------------------------------------------------*/
/* �����е�����Ԫ�ش�ӡ���                			 	   */
/*---------------------------------------------------------*/
OutputPrintTask(LinkedQueue Q)		
{ 
	Task *p;
	printf("\n��ǰ����\n");
	printf("��ҵ��, �ı�");
	for(p=Q.front->next; p; p=p->next)
		/* ��������д�ӡ��ҵ�ı�ʶ�ź����� */
		printf("\n %d, %s", p->no, p->text); 
}


/*---------------------------------------------------------*/
/* ��Ӳ���                			 	   				   */
/* ��ʶ��no + ��ӡ������text���뵽���еĶ�β			   */
/*---------------------------------------------------------*/
void EnPrintTaskQueue(LinkedQueue *Q, int no, char *text)
{     
	Task *p;
	p = (Task*)malloc(sizeof(Task));
	p->text = (char*)malloc(strlen(text)*sizeof(char)+1);
	/*���ٿռ��Ŵ�ӡ������*/
	strcpy(p->text, text);
	p->no = no;
	p->next = NULL;
	/*�½�����, �޸Ķ�βָ��*/
	Q->rear->next = p;				
	Q->rear = p;
}

/*---------------------------------------------------------*/
/* ���Ӳ���                			 	   				   */
/* ����ӡ�����ʶ��no��Ҫ��ӡ������text����			   	   */
/*---------------------------------------------------------*/
int DePrintTaskQueue(LinkedQueue *Q)	
{     
	Task *p;
	if (Q->front == Q->rear)	/* ������û��Ԫ�ز��ܳ��� */
		return FAILURE;
	p = Q->front->next;
	if(Q->rear == p)
		Q->rear = Q->front;		/* ��������ֻ��һ��Ԫ�س���ʱ�޸�βָ�� */
	Q->front->next = p->next;	/* ��p������ */
	printf("��ǰ��ӡ�������: %d\n",  p->no);
	printf("��ǰ��ӡ����: %s\n",  p->text);
	free(p);
	return SUCCESS;
}

/*---------------------------------------------------------*/
/* ������                                   			   */
/*---------------------------------------------------------*/
void main()										
{   
	LinkedQueue Q; int m, no; char str[MAXSIZE];
	InitQueue(&Q);		/* ��ʼ������ */
	while (1)
	{  
		printf("\n*** ��Ӵ�ӡ����:1 *** \n");/* ��ӡ�˵� */
		printf("*** ִ�д�ӡ����:2 *** \n");
		printf("*** ������0 ***\n");
		printf("\n��ѡ������");
		scanf("%d",  &m);
		if(m==0) 
			break;
		if (m==1)
		{ 
			printf("�����룺��ź��ı����ݣ�ʹ��,������ı�����С��100��\n");
			scanf("%d, %s",  &no,  str);
			EnPrintTaskQueue(&Q,  no,  str);    /* ��ҵ��� */
			OutputPrintTask(Q); 				/* �����ǰ����ȫ����ҵ */
		}
		else
		{
			/* ��ҵ��ӳ� ��ȫ����ҵ */  
			DePrintTaskQueue(&Q);              
		}
	}
}
