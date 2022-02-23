#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0
#define MAXSIZE 100		/* 队列的最大容量 */

typedef struct node
{     
	int no;				/* 打印任务标识号 */
	char *text; 		/* 要打印的内容 */
	struct node *next; 	/* 指向下一个结点的指针 */
} Task; 				/* 结点结构体Task */

typedef struct
{     
	Task *front; 		/* 头指针 */
	Task *rear; 		/* 尾指针 */
} LinkedQueue;

/*---------------------------------------------------------*/
/* 初始化一个空的链式队列                  			 	   */
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
		return FAILURE;		/* 内存分配失败！*/
}

/*---------------------------------------------------------*/
/* 将队列的所有元素打印输出                			 	   */
/*---------------------------------------------------------*/
OutputPrintTask(LinkedQueue Q)		
{ 
	Task *p;
	printf("\n当前队列\n");
	printf("作业号, 文本");
	for(p=Q.front->next; p; p=p->next)
		/* 输出队列中打印作业的标识号和内容 */
		printf("\n %d, %s", p->no, p->text); 
}


/*---------------------------------------------------------*/
/* 入队操作                			 	   				   */
/* 标识号no + 打印的内容text加入到队列的队尾			   */
/*---------------------------------------------------------*/
void EnPrintTaskQueue(LinkedQueue *Q, int no, char *text)
{     
	Task *p;
	p = (Task*)malloc(sizeof(Task));
	p->text = (char*)malloc(strlen(text)*sizeof(char)+1);
	/*开辟空间存放打印的内容*/
	strcpy(p->text, text);
	p->no = no;
	p->next = NULL;
	/*新结点入队, 修改队尾指针*/
	Q->rear->next = p;				
	Q->rear = p;
}

/*---------------------------------------------------------*/
/* 出队操作                			 	   				   */
/* 将打印任务标识号no和要打印的内容text出队			   	   */
/*---------------------------------------------------------*/
int DePrintTaskQueue(LinkedQueue *Q)	
{     
	Task *p;
	if (Q->front == Q->rear)	/* 队列中没有元素不能出队 */
		return FAILURE;
	p = Q->front->next;
	if(Q->rear == p)
		Q->rear = Q->front;		/* 当队列中只有一个元素出队时修改尾指针 */
	Q->front->next = p->next;	/* 将p结点出队 */
	printf("当前打印任务序号: %d\n",  p->no);
	printf("当前打印内容: %s\n",  p->text);
	free(p);
	return SUCCESS;
}

/*---------------------------------------------------------*/
/* 主程序                                   			   */
/*---------------------------------------------------------*/
void main()										
{   
	LinkedQueue Q; int m, no; char str[MAXSIZE];
	InitQueue(&Q);		/* 初始化队列 */
	while (1)
	{  
		printf("\n*** 添加打印任务:1 *** \n");/* 打印菜单 */
		printf("*** 执行打印任务:2 *** \n");
		printf("*** 结束：0 ***\n");
		printf("\n请选择任务：");
		scanf("%d",  &m);
		if(m==0) 
			break;
		if (m==1)
		{ 
			printf("请输入：编号和文本内容（使用,间隔，文本长度小于100）\n");
			scanf("%d, %s",  &no,  str);
			EnPrintTaskQueue(&Q,  no,  str);    /* 作业入队 */
			OutputPrintTask(Q); 				/* 输出当前队列全部作业 */
		}
		else
		{
			/* 作业入队出 列全部作业 */  
			DePrintTaskQueue(&Q);              
		}
	}
}
