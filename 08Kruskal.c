#include <stdio.h>
#include <stdlib.h>

#define Max 10
#define VertexNum 5

struct	List	                     /* 节点结构声明 */
{
	int		Vertex1;
	int		Vertex2;
	int		Weight;
	struct	List *Next;
};
typedef	struct	List	Node;
typedef	Node	*Edge;				/* 定义邻接边的节点 */

int Edges[10][3] =	                /* 输入数据 */
{
	{1,2,7}, {1,3,6}, {1,4,5}, {1,5,12}, {2,3,14},
	{2,4,8}, {2,5,8}, {3,4,3}, {3,5,9}, {4,5,2} 
};

int Visited[VertexNum];	           /* 查找记录 */

/* --------------------------------------------------- */
/* Kruskal算法                                         */
/* 参数：Edge Head 头指针		   					   */
/* 返回值：空                                          */
/* --------------------------------------------------- */
void Kruskal(Edge Head)
{
	Edge	Pointer;				/* 节点声明 */
	int	EdgeNum = 0;				/* 已连结边的数目 */
	int	Weight = 0;
	
	Pointer = Head;
	
	/* 当边的数目为顶点的数目减1时，结束循环 */
	while ( EdgeNum != ( VertexNum - 1 )  )	
	{
		/* 有一顶点不在生成树中时 */
		if ( Visited[Pointer->Vertex1] == 0
			|| Visited[Pointer->Vertex2] == 0 ) 
		{
			
			printf("==>[%d,%d]",Pointer->Vertex1,Pointer->Vertex2);
			printf("(%d)",Pointer->Weight);
			Weight += Pointer->Weight;
			EdgeNum++;	/* 边数加1 */
			Visited[Pointer->Vertex1] = 1;	/* 设为已查找 */
			Visited[Pointer->Vertex2] = 1;  /* 设为已查找  */
		}
		Pointer = Pointer->Next;			/* 往下一个节点 */
		
		if ( Pointer == NULL )				/* 已无边时 */
		{
			printf("No Spanning Tree \n");
			break;
		}
	}
	printf("\nTotal weight = %d\n",Weight);	/* 输出加权值总和 */
}

/* --------------------------------------------------- */
/* 释放链表                                            */
/* 参数：Edge Head 头指针		   					   */
/* 返回值：空                                          */
/* --------------------------------------------------- */
void FreeEdge(Edge Head)
{
	Edge	Pointer;				/* 节点声明 */
	
	while (	Head != NULL )			/* 当节点为NULL结束循环 */
	{
		Pointer = Head;
		Head = Head->Next;			/* 往下一个节点 */
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
	Edge	Pointer;				/* 节点声明 */
	Pointer = Head;					/* Pointer指针设为首节点 */
	while (	Pointer != NULL )		/* 当节点为NULL结束循环 */
	{
		printf("[%d,%d]",Pointer->Vertex1,Pointer->Vertex2);
		printf("(%d)",Pointer->Weight); /* 输出加权值 */
		Pointer = Pointer->Next;	/* 往下一个节点 */
	}
	printf("\n");
}

/* --------------------------------------------------- */
/* 递增插入邻接边至链表内                              */
/* 参数：Edge Head 插入前的头指针		   			   */
/* 返回值：Edge 插入完成后的头指针                     */
/* --------------------------------------------------- */
Edge InsertEdge(Edge Head,Edge New)
{
	Edge	Pointer;				/* 节点声明 */
	
	Pointer = Head;			        /* Pointer指针设为首节点 */
	
	while ( 1 )
	{
		if ( New->Weight < Head->Weight ) /* 新的加权值比首节点小 */
		{
			New->Next = Head;		/* 插入在首节点之前 */
			Head = New;
			break;
		}
		
		
		if( Pointer->Next==NULL )
		{
			break;
		}
		
		/* 插入在链表中间或尾端 */
		if ( New->Weight >= Pointer->Weight
			&& New->Weight < Pointer->Next->Weight) 
		{
			New->Next = Pointer->Next;
			Pointer->Next = New;
			break;
		}
		Pointer = Pointer->Next;	/* 往下一个节点 */
	}
	return Head;
}


/* --------------------------------------------------- */
/* 建立链表                                            */
/* 参数：Edge Head 头指针		   					   */
/* 返回值：Edge 创建完成后的头指针                     */
/* --------------------------------------------------- */
Edge CreateEdge(Edge Head)
{
	Edge	New;			                /* 节点声明 */
	//	Edge	Pointer;		            /* 节点声明 */
	int	i;
	
	Head = (Edge) malloc(sizeof(Node));		/* 内存配置 */
	
	if ( Head == NULL )
		printf("Memory allocate Failure!!\n");	/* 内存配置失败 */
	
	else
	{
		Head->Vertex1 = Edges[0][0];
		Head->Vertex2 = Edges[0][1];
		Head->Weight = Edges[0][2];			/* 定义节点加权值 */
		Head->Next = NULL;
		
		for ( i=1;i<10;i++ )
		{
			New = (Edge) malloc(sizeof(Node));
			
			if ( New != NULL )
			{
				New->Vertex1 = Edges[i][0];
				New->Vertex2 = Edges[i][1];
				New->Weight = Edges[i][2];	/* 定义节点加权值 */
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
	Edge	Head;					/* 节点声明 */
	int	i;			
	
	for ( i=0;i<VertexNum;i++ )		/* 清除查找记录 */
		Visited[i] = 0;
	
	Head = CreateEdge(Head);		/* 调用建立链表 */
	
	if ( Head != NULL )
	{
		printf("Kruskal  Algorithm : \n");
		printf("First Step : Sorting \n");
		PrintEdge(Head);
		printf("Second Step : Find Minimal Spanning Tree. \n");
		
		Kruskal(Head); 		/* 调用kruskal算法 */
		
		FreeEdge(Head);	/* 调用释放链表 */
	}
}
