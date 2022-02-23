#include <stdlib.h>
#include <stdio.h>

#define Max 999		                    /* ��������� */
#define VertexNum 7	                    /* ���嶥���� */
#define EdgeNum 9						/* �����ڽӱ��� */

int	Graph[VertexNum][VertexNum];		/* ͼ���ڽ�����	*/
int	Edge[EdgeNum][3] =					/* �������� */
		{ {1,2,6}, {1,3,3}, {2,4,5},
		  {3,2,2}, {3,4,3}, {3,5,4},
		  {4,6,3}, {5,4,2}, {5,6,5} };
int	Visited[VertexNum];	                /* ���Ҽ�¼ */
int Distance[VertexNum];	            /* �����ܺ� */

/* --------------------------------------------------- */
/* Dijkstra�㷨                                        */
/* ������int begin ��ʼ����					   		   */
/* ����ֵ����                                          */
/* --------------------------------------------------- */
void Dijkstra(int begin)
{
	int	MinEdge;		/* ��С�� */
	int	Vertex;			/* ��С�ߵĶ��� */
	int	i,j;
	int	Edges;			/* ���� */

	Edges = 1;			/* ��ʼ���� */
	Visited[begin] = 1;	/* ��ʼ���� */

	for ( i=1;i<VertexNum;i++ )	
		Distance[i] = Graph[begin][i];	/* ��ʼ�����ܺ� */

	Distance[begin] = 0;				/* ��ʼ��ľ���Ϊ0 */
	printf("Vertice");	
	for ( i=1;i<VertexNum;i++ )
		printf("%5d",i);				/* ����������� */
	printf("\n");
	printf("Step %d :",Edges);
	for ( i=1;i<VertexNum;i++ )	
		printf("%5d",Distance[i]);      /* ��������ܺ����� */
	printf("\n");
	while ( Edges < ( VertexNum - 1 ) )	/* ���������ڶ�����ʱִ�� */
	{
		Edges++;
		MinEdge = Max;	                /* ����С���赽���ֵ */
		for ( j=1;j<VertexNum;j++ )		/* �ж�δ�������ڽӶ��� */
		{
			/* ����δ���ҹ�����С�߼�Ȩֵ�Ⱦ����ܺʹ� */
			if ( Visited[j] == 0 && MinEdge > Distance[j] )
			{
				Vertex = j;				/* �ҳ���С�ߵĶ��� */
				MinEdge = Distance[j];	/* �ҳ���С�ߵľ����ܺ� 
*/
			}
		}
		Visited[Vertex] = 1;			/* ����С�ߵĶ�����Ϊ�Ѳ��� */
		printf("Step %d :",Edges);
		for ( j=1;j<VertexNum;j++ )
		{
			/* �ҳ�δ���Ҷ������С�����ܺ� */
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
/* ����ڽ���������                                    */
/* ��������								   			   */
/* ����ֵ����                                          */
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
/* ���ڽ����齨��ͼ��                                  */
/* ������int Vertice1,int Vertice2, �����յ�		   */
/* int Weight Ȩֵ						   			   */
/* ����ֵ����                                          */
/* --------------------------------------------------- */
void Create_M_Graph(int Vertice1,int Vertice2,int Weight)
{

	Graph[Vertice1][Vertice2] = Weight;	
}

/* --------------------------------------------------- */
/* ������                                              */
/* --------------------------------------------------- */
void main ()
{
	int	beginVertex = 1;		/*  ��ʼ���� */
	int	i,j;

	for ( i=0;i<VertexNum;i++ )	/* ������Ҽ�¼ */
		Visited[i] = 0;

	for ( i=0;i<VertexNum;i++ )	/* ����������� */
		for ( j=0;j<VertexNum;j++)
			Graph[i][j] = Max;

	for ( i=0;i<EdgeNum;i++)	/* ���ý����ڽ����� */
		Create_M_Graph(Edge[i][0],Edge[i][1],Edge[i][2]);

	printf("##Graph##\n");
	Print_M_Graph();			/* ��������ڽ��������� */

	printf("\n");
	printf("Dijkstra Algorithm : \n");
	Dijkstra(beginVertex);		/* ����Dijkstra�㷨 */
}
