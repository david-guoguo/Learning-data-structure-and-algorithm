#include <stdlib.h>
#include <stdio.h>

#define Max 999		                    /* 定义最大数 */
#define VertexNum 7	                    /* 定义顶点数 */
#define EdgeNum 9						/* 定义邻接边数 */

int	Graph[VertexNum][VertexNum];		/* 图形邻接数组	*/
int	Edge[EdgeNum][3] =					/* 输入数据 */
		{ {1,2,6}, {1,3,3}, {2,4,5},
		  {3,2,2}, {3,4,3}, {3,5,4},
		  {4,6,3}, {5,4,2}, {5,6,5} };
int	Visited[VertexNum];	                /* 查找记录 */
int Distance[VertexNum];	            /* 距离总和 */

/* --------------------------------------------------- */
/* Dijkstra算法                                        */
/* 参数：int begin 初始顶点					   		   */
/* 返回值：空                                          */
/* --------------------------------------------------- */
void Dijkstra(int begin)
{
	int	MinEdge;		/* 最小边 */
	int	Vertex;			/* 最小边的顶点 */
	int	i,j;
	int	Edges;			/* 边数 */

	Edges = 1;			/* 初始边数 */
	Visited[begin] = 1;	/* 初始顶点 */

	for ( i=1;i<VertexNum;i++ )	
		Distance[i] = Graph[begin][i];	/* 初始距离总和 */

	Distance[begin] = 0;				/* 起始点的距离为0 */
	printf("Vertice");	
	for ( i=1;i<VertexNum;i++ )
		printf("%5d",i);				/* 输出顶点数据 */
	printf("\n");
	printf("Step %d :",Edges);
	for ( i=1;i<VertexNum;i++ )	
		printf("%5d",Distance[i]);      /* 输出距离总和数据 */
	printf("\n");
	while ( Edges < ( VertexNum - 1 ) )	/* 当边数少于顶点数时执行 */
	{
		Edges++;
		MinEdge = Max;	                /* 将最小边设到最大值 */
		for ( j=1;j<VertexNum;j++ )		/* 判断未建立的邻接顶点 */
		{
			/* 顶点未查找过且最小边加权值比距离总和大 */
			if ( Visited[j] == 0 && MinEdge > Distance[j] )
			{
				Vertex = j;				/* 找出最小边的顶点 */
				MinEdge = Distance[j];	/* 找出最小边的距离总和 
*/
			}
		}
		Visited[Vertex] = 1;			/* 将最小边的顶点设为已查找 */
		printf("Step %d :",Edges);
		for ( j=1;j<VertexNum;j++ )
		{
			/* 找出未查找顶点的最小距离总和 */
			if ( Visited[j] == 0 &&
			 Distance[Vertex] + Graph[Vertex][j] < Distance[j] )
			 {
				Distance[j] =
				 Distance[Vertex] + Graph[Vertex][j];
			 }
			printf("%5d",Distance[j]);
		}
		printf("\n");
	}
}

/* --------------------------------------------------- */
/* 输出邻接数组数据                                    */
/* 参数：空								   			   */
/* 返回值：空                                          */
/* --------------------------------------------------- */
void Print_M_Graph()
{
	int	i,j;

	printf("Vertice");
	for ( i=1;i<VertexNum;i++)
		printf("%5d",i);
	printf("\n");
	for ( i=1;i<VertexNum;i++)
	{
		printf("%5d   ",i);
		for ( j=1;j<VertexNum;j++ )
			printf("%5d",Graph[i][j]);
		printf("\n");
	}
}

/* --------------------------------------------------- */
/* 以邻接数组建立图形                                  */
/* 参数：int Vertice1,int Vertice2, 起点和终点		   */
/* int Weight 权值						   			   */
/* 返回值：空                                          */
/* --------------------------------------------------- */
void Create_M_Graph(int Vertice1,int Vertice2,int Weight)
{

	Graph[Vertice1][Vertice2] = Weight;	
}

/* --------------------------------------------------- */
/* 主程序                                              */
/* --------------------------------------------------- */
void main ()
{
	int	beginVertex = 1;		/*  起始顶点 */
	int	i,j;

	for ( i=0;i<VertexNum;i++ )	/* 清除查找记录 */
		Visited[i] = 0;

	for ( i=0;i<VertexNum;i++ )	/* 清除数组数据 */
		for ( j=0;j<VertexNum;j++)
			Graph[i][j] = Max;

	for ( i=0;i<EdgeNum;i++)	/* 调用建立邻接数组 */
		Create_M_Graph(Edge[i][0],Edge[i][1],Edge[i][2]);

	printf("##Graph##\n");
	Print_M_Graph();			/* 调用输出邻接数组数据 */

	printf("\n");
	printf("Dijkstra Algorithm : \n");
	Dijkstra(beginVertex);		/* 调用Dijkstra算法 */
}
