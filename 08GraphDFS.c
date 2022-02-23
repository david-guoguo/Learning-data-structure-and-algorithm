
#include <stdlib.h>
#include <stdio.h>
	
#define MAXSIZE 9		        /* 定义顶点数 */

struct Node						/* 声明图形顶点结构 */
{
	int	adjvex;					/* 邻接顶点数据 */
	struct Node *Next;			/* 下一个邻接顶点 */
};

typedef	struct	Node *Graph;    /* 定义图形结构 */
struct	Node Head[MAXSIZE];		/* 顶点数组 */

int	Visited[MAXSIZE];	        /* 记录 */

/* --------------------------------------------------- */
/* 深度优先遍历算法                                    */
/* --------------------------------------------------- */
void DFS(int adjvex)
{
	Graph	Pointer;					/* 节点声明 */

	Visited[adjvex] = 1;	            /* 已查找 */
	printf("[%d]==>",adjvex);
	Pointer = Head[adjvex].Next;

	while (	Pointer != NULL )
	{
		if ( Visited[Pointer->adjvex] == 0)
			DFS(Pointer->adjvex);	    /* 递归调用 */
		Pointer = Pointer->Next;	    /* 下一个邻接点 */
	}
}

/* --------------------------------------------------- */
/* 建立邻接顶点至邻接列表内                            */
/* --------------------------------------------------- */
void CreateLGraph(int adjvex1,int adjvex2)
{
	Graph	Pointer;							/* 节点声明 */
	Graph	New;								/* 新顶点声明 */

	New = (Graph) malloc(sizeof(struct Node));	/* 配置内存 */
	if ( New != NULL )	/* 配置成功 */
	{
		New->adjvex = adjvex2;            		/* 邻近顶点 */
		New->Next = NULL;						/* 下一个邻接顶点指针 */
		/* Pointer指针设为顶点数组之首节点 */
		Pointer = &(Head[adjvex1]);

		while ( Pointer->Next != NULL )
			Pointer = Pointer->Next;			/* 往下一个节点 */

		Pointer->Next = New;	                /* 串连在链接尾端 */
	}
}

/* --------------------------------------------------- */
/* 输出邻接列表内数据                                  */
/* --------------------------------------------------- */
void PrintLGraph(struct Node *Head)
{
	Graph	Pointer;					/* 节点声明 */

	Pointer = Head->Next;		/* Pointer指针设为首节点 */
	while (	Pointer != NULL )	/* 当节点为NULL结束循环 */
	{
		printf("[%d]",Pointer->adjvex);
		Pointer = Pointer->Next;		/* 往下一个节点 */
	}
	printf("\n");
}

/* --------------------------------------------------- */
/* 主程序                                              */
/* --------------------------------------------------- */
void main ()
{
	int	i;
	int  Node[20][2] = { {1,2}, {2,1}, {1,3}, {3,1}, {2,4},
		{4,2}, {2,5}, {5,2}, {3,6}, {6,3},
		{3,7}, {7,3}, {4,8}, {8,4}, {5,8},
		{8,5}, {6,8}, {8,6}, {7,8}, {8,7} };

	for ( i=0;i<MAXSIZE;i++ )
	{
		Head[i].adjvex = i;
		Head[i].Next = NULL;
	}

	for ( i=0;i<MAXSIZE;i++ )
		Visited[i] = 0;

	for ( i=0;i<20;i++ )
		CreateLGraph(Node[i][0],Node[i][1]);

	printf("##Graph##\n");
	for ( i=1;i<MAXSIZE;i++)
	{
		printf("adjvex[%d] : ",i);
		PrintLGraph(&Head[i]);      /* 调用输出邻接列表数据 */
	}
	printf("DFS : \n");
	printf("[BEGIN]==>");
	DFS(1);
	printf("[END]\n");
}
