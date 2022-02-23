#include <stdlib.h>
#include <stdio.h>

#define Max 10
#define VertexNum 5

struct	List			/* 节点结构声明 */
{
	int		Marked;		/* 查找标记 */
	int		Vertex1;	/* 顶点声明 */
	int		Vertex2;	/* 顶点声明 */
	int		Weight;		/* 加权值 */
	struct	List	*Next;
};
typedef	struct	List	Node;
typedef	Node	*Edge;	/* 定义邻接边的节点 */

int Edges[10][3] =		/* 输入数据 */
{
	{1,2,7}, {1,3,6}, {1,4,5}, {1,5,12}, {2,3,14},
	{2,4,8}, {2,5,8}, {3,4,3}, {3,5,9}, {4,5,2} 
};

int Visited[VertexNum+1];	/* 查找记录 */

/* --------------------------------------------------- */
/* Prims算法                                           */
/* 参数：Edge Head 头指针		   					   */
/* int index 起始位置						   		   */
/* 返回值：空                                          */
/* --------------------------------------------------- */
void Prims(Edge Head, int index)
{
	Edge	Pointer;		/* 节点声明 */
	Edge	MinEdge=(Edge)malloc(sizeof(Edge));
	int		EdgeNum = 0;	/* 已连结边的数目 */
	int		Weight = 0;		/* 累计加权值 */
	int		i;
	
	Visited[index] = 1;		/* 设置已查找过 */
	
	/* 当边的数目为顶点的数目减1时，结束循环 */
	while ( EdgeNum != ( VertexNum - 1 )  )
	{
		MinEdge->Weight = 999;			/* 将最小边的加权值设到最大 */
		
		for ( i=1;i<=VertexNum;i++ )	/* 判断未建立的邻接顶点 */
			
		{
			Pointer = Head;
			if ( Visited[i] == 1 )		/* 已存在生成树集合的顶点 */
			{
				/* 往下一个未建立的邻接边 */
				while ( Pointer->Marked == 1 )	
					Pointer = Pointer->Next;
				if ( MinEdge->Weight > Pointer->Weight )
					MinEdge = Pointer;	/* 找出加权值最小的邻接边 */
				
				while (	Pointer != NULL )
				{
					/* 如果两顶点皆存在生成树集合中，表示是已查找过的边 */
					if ( Visited[Pointer->Vertex1] == 1
						&& Visited[Pointer->Vertex2] == 1 )
						Pointer->Marked = 1;
					/* 找出加权值最小的邻接边 */
					if ( MinEdge->Weight > Pointer->Weight
						&& Pointer->Marked == 0
						&& ( Pointer->Vertex1 == i
						|| Pointer->Vertex2 == i ) )
						MinEdge = Pointer;
					Pointer = Pointer->Next;
				}
			}
		}
		Visited[MinEdge->Vertex1] = 1;	/* 将顶点1设为存在生成树集合中 */
		
		Visited[MinEdge->Vertex2] = 1;	/* 将顶点2设为存在生成树集合中 */
		
		EdgeNum++;						/* 生成树的边数加1 */
		Weight += MinEdge->Weight;		/* 累计加权值 */
		printf("[%d,%d]",MinEdge->Vertex1,MinEdge->Vertex2);
		printf("(%d)",MinEdge->Weight);
	}
	printf("\nTotal weight = %d\n",Weight);/* 输出加权值总和 */
}

/* --------------------------------------------------- */
/* 释放链表											   */
/* 参数：Edge Head 头指针		   					   */
/* 返回值：空                                          */
/* --------------------------------------------------- */
void FreeEdge(Edge Head)
{
	Edge	Pointer;			/* 节点声明 */
	
	while (	Head != NULL )		/* 当节点为NULL结束循环 */
	{
		Pointer = Head;
		Head = Head->Next;		/* 往下一个节点 */
		free(Pointer);
	}
}

/* --------------------------------------------------- */
/* 输出链表数据                                        */
/* 参数：Edge Head 头指针		   					   */
/* 返回值：空                                          */
/* --------------------------------------------------- */
void PrintEdge(Edge Head)
{
	Edge Pointer;				/* 节点声明 */
	
	Pointer = Head;				/* Pointer指针设为首节点 */
	while (	Pointer != NULL )	/* 当节点为NULL结束循环 */
	{
		printf("[%d,%d]",Pointer->Vertex1,Pointer->Vertex2);
		printf("(%d)",Pointer->Weight);	/* 输出加权值 */
		Pointer = Pointer->Next;		/* 往下一个节点 */
	}
	printf("\n");
}

/* --------------------------------------------------- */
/* 插入邻接边至链表中                                  */
/* 参数：Edge Head 插入前的头指针		   			   */
/* 返回值：Edge 插入完成后的头指针                     */
/* --------------------------------------------------- */
Edge InsertEdge(Edge Head,Edge New)
{
	Edge Pointer;				/* 节点声明 */
	
	Pointer = Head;				/* Pointer指针设为首节点 */
	
	while ( Pointer->Next != NULL )	/* 插入在链表尾端 */
		Pointer = Pointer->Next;
	Pointer->Next = New;
	
	return Head;
}

/* --------------------------------------------------- */
/* 建立链表											   */
/* 参数：Edge Head 头指针		   					   */
/* 返回值：Edge 创建完成后的头指针                     */
/* --------------------------------------------------- */
Edge CreateEdge(Edge Head)
{
	Edge New;							/* 节点声明 */
	int	i;
	
	Head = (Edge) malloc(sizeof(Node));	/* 内存配置 */
	
	if ( Head == NULL )
		printf("Memory allocate Failure!!\n");	/* 内存配置失败 */
	
	else
	{
		Head->Marked = 0;
		Head->Vertex1 = Edges[0][0];
		Head->Vertex2 = Edges[0][1];
		Head->Weight = Edges[0][2];		/* 定义节点加权值 */
		Head->Next = NULL;
		
		for ( i=1;i<10;i++ )
		{
			New = (Edge) malloc(sizeof(Node));
			
			if ( New != NULL )
			{
				New->Marked = 0;
				New->Vertex1 = Edges[i][0];
				New->Vertex2 = Edges[i][1];
				New->Weight = Edges[i][2];		/* 定义节点加权值 */
				New->Next = NULL;
				
				Head = InsertEdge(Head,New);	/* 则插入新节点 */
			}
		}
	}
	return Head;
}
/* --------------------------------------------------- */
/* 主程序                                              */
/* --------------------------------------------------- */
void main ()
{
	Edge Head=NULL;					/* 节点声明 */
	int	i;
	
	for ( i=1;i<=VertexNum;i++ )	/* 清除查找记录 */
		Visited[i] = 0;
	
	Head = CreateEdge(Head);		/* 调用建立链表 */
	PrintEdge(Head);
	
	if ( Head != NULL )
	{
		printf("Prims Algorithm : \n");
		printf("Start from Vertex 1.\n");
		printf("Find Minimal Spanning Tree.\n");
		
		Prims(Head,1); 		/* 调用Prims算法 */
		free(Head);			/* 调用释放链表 */
	}
}
