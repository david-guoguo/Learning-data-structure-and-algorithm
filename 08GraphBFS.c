#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 9			/* 定义顶点数 */
#define QueueMax 10

struct Node					/* 声明图形顶点结构 */
{
	int	Vertex;		        /* 邻接顶点数据 */
	struct	Node *Next;		/* 下一个邻接顶点 */
};

typedef	struct Node *Graph;	/* 定义图形结构 */
struct Node Head[MAXSIZE];	/* 顶点数组 */

int	Queue[QueueMax];
int	Front = -1;
int	Rear = -1;

int	Visited[MAXSIZE];	      /* 查找记录 */

/* --------------------------------------------------- */
/* 队列的存入                                          */
/* --------------------------------------------------- */
int Enqueue(int Vertex)
{
	if ( Rear >= QueueMax )		/* 队列已满 */
		return -1;
	else
	{
		Rear++;					/* 队列尾端指针后移 */
		Queue[Rear] = Vertex;	/* 将值存入队列中 */
		return 1;
	}
}

/* --------------------------------------------------- */
/* 队列的取出                                          */
/* --------------------------------------------------- */
int Dequeue()
{
	if ( Front == Rear )		/* 队列已空 */
		return -1;
	else
	{
		Front++;	            /* 队头指针后移 */
		return Queue[Front];
	}
}

/* --------------------------------------------------- */
/* 广度优先搜索法                                      */
/* --------------------------------------------------- */
void BFS(int Vertex)
{
	Graph	Pointer;			/* 节点声明 */

	Enqueue(Vertex);			/* 存入队列中 */
	Visited[Vertex] = 1;		/* 已查找 */
	printf("[%d]==>",Vertex);

	while (	Front != Rear )		/* 队列为空时，结束循环 */
	{
		Vertex = Dequeue();
		Pointer = Head[Vertex].Next;
		while ( Pointer != NULL )	/* 读入邻接列表所有顶点 */
		{
			if ( Visited[Pointer->Vertex] == 0)
			{
				Enqueue(Pointer->Vertex);		/* 存入队列中 */
				Visited[Pointer->Vertex] = 1;	/* 已查找过的顶点 */
				printf("[%d]==>",Pointer->Vertex);
			}
			Pointer = Pointer->Next;			/* 下一个邻接点 */
		}
	}
}

/* --------------------------------------------------- */
/* 建立邻接顶点至邻接列表内                            */
/* --------------------------------------------------- */
void Create_L_Graph(int Vertex1,int Vertex2)
{
	Graph	Pointer;							/* 节点声明 */
	Graph	New;								/* 新顶点声明 */

	New = (Graph) malloc(sizeof(struct Node));	/* 配置内存 */
	if ( New != NULL )							/* 配置成功 */
	{
		New->Vertex = Vertex2;	/* 邻近顶点 */
		New->Next = NULL;		/* 下一个邻接顶点指针 */

		/* Pointer指针设为顶点数组之首节点 */
		Pointer = &(Head[Vertex1]);

		while ( Pointer->Next != NULL )
			Pointer = Pointer->Next;		/* 往下一个节点 */

		Pointer->Next = New;				/* 串连在链接尾端 */
	}
}

/* --------------------------------------------------- */
/* 输出邻接列表内数据                                  */
/* --------------------------------------------------- */
void Print_L_Graph(struct Node *Head)
{
	Graph	Pointer;				/* 节点声明 */

	Pointer = Head->Next;			/* Pointer指针设为首节点 */
	while (	Pointer != NULL )		/* 当节点为NULL结束循环 */
	{
		printf("[%d]",Pointer->Vertex);
		Pointer = Pointer->Next;	/* 往下一个节点 */
	}
	printf("\n");
}

/* --------------------------------------------------- */
/* 主程序                                              */
/* --------------------------------------------------- */
void main ()
{
	int	i;
	int	Node[20][2] = { {1,2}, {2,1}, {1,3}, {3,1}, {2,4},
						{4,2}, {2,5}, {5,2}, {3,6}, {6,3},
						{3,7}, {7,3}, {4,8}, {8,4}, {5,8},
						{8,5}, {6,8}, {8,6}, {7,8}, {8,7} };

	for ( i=0;i<MAXSIZE;i++ )
	{
		Head[i].Vertex = i;
		Head[i].Next = NULL;
	}

	for ( i=0;i<MAXSIZE;i++ )
		Visited[i] = 0;

	for ( i=0;i<20;i++ )
		Create_L_Graph(Node[i][0],Node[i][1]);

	printf("##Graph##\n");
	for ( i=1;i<MAXSIZE;i++)
	{
		printf("Vertex[%d] : ",i);
		Print_L_Graph(&Head[i]);	/* 调用输出邻接列表数据 */
	}
	printf("BFS : \n");
	printf("[BEGIN]==>");
	BFS(4);
	printf("[END]\n");
}
