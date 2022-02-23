#include <stdlib.h>
#include <stdio.h>

#define Max 10
#define VertexNum 5

struct	List			/* �ڵ�ṹ���� */
{
	int		Marked;		/* ���ұ�� */
	int		Vertex1;	/* �������� */
	int		Vertex2;	/* �������� */
	int		Weight;		/* ��Ȩֵ */
	struct	List	*Next;
};
typedef	struct	List	Node;
typedef	Node	*Edge;	/* �����ڽӱߵĽڵ� */

int Edges[10][3] =		/* �������� */
{
	{1,2,7}, {1,3,6}, {1,4,5}, {1,5,12}, {2,3,14},
	{2,4,8}, {2,5,8}, {3,4,3}, {3,5,9}, {4,5,2} 
};

int Visited[VertexNum+1];	/* ���Ҽ�¼ */

/* --------------------------------------------------- */
/* Prims�㷨                                           */
/* ������Edge Head ͷָ��		   					   */
/* int index ��ʼλ��						   		   */
/* ����ֵ����                                          */
/* --------------------------------------------------- */
void Prims(Edge Head, int index)
{
	Edge	Pointer;		/* �ڵ����� */
	Edge	MinEdge=(Edge)malloc(sizeof(Edge));
	int		EdgeNum = 0;	/* ������ߵ���Ŀ */
	int		Weight = 0;		/* �ۼƼ�Ȩֵ */
	int		i;
	
	Visited[index] = 1;		/* �����Ѳ��ҹ� */
	
	/* ���ߵ���ĿΪ�������Ŀ��1ʱ������ѭ�� */
	while ( EdgeNum != ( VertexNum - 1 )  )
	{
		MinEdge->Weight = 999;			/* ����С�ߵļ�Ȩֵ�赽��� */
		
		for ( i=1;i<=VertexNum;i++ )	/* �ж�δ�������ڽӶ��� */
			
		{
			Pointer = Head;
			if ( Visited[i] == 1 )		/* �Ѵ������������ϵĶ��� */
			{
				/* ����һ��δ�������ڽӱ� */
				while ( Pointer->Marked == 1 )	
					Pointer = Pointer->Next;
				if ( MinEdge->Weight > Pointer->Weight )
					MinEdge = Pointer;	/* �ҳ���Ȩֵ��С���ڽӱ� */
				
				while (	Pointer != NULL )
				{
					/* ���������Դ��������������У���ʾ���Ѳ��ҹ��ı� */
					if ( Visited[Pointer->Vertex1] == 1
						&& Visited[Pointer->Vertex2] == 1 )
						Pointer->Marked = 1;
					/* �ҳ���Ȩֵ��С���ڽӱ� */
					if ( MinEdge->Weight > Pointer->Weight
						&& Pointer->Marked == 0
						&& ( Pointer->Vertex1 == i
						|| Pointer->Vertex2 == i ) )
						MinEdge = Pointer;
					Pointer = Pointer->Next;
				}
			}
		}
		Visited[MinEdge->Vertex1] = 1;	/* ������1��Ϊ���������������� */
		
		Visited[MinEdge->Vertex2] = 1;	/* ������2��Ϊ���������������� */
		
		EdgeNum++;						/* �������ı�����1 */
		Weight += MinEdge->Weight;		/* �ۼƼ�Ȩֵ */
		printf("[%d,%d]",MinEdge->Vertex1,MinEdge->Vertex2);
		printf("(%d)",MinEdge->Weight);
	}
	printf("\nTotal weight = %d\n",Weight);/* �����Ȩֵ�ܺ� */
}

/* --------------------------------------------------- */
/* �ͷ�����											   */
/* ������Edge Head ͷָ��		   					   */
/* ����ֵ����                                          */
/* --------------------------------------------------- */
void FreeEdge(Edge Head)
{
	Edge	Pointer;			/* �ڵ����� */
	
	while (	Head != NULL )		/* ���ڵ�ΪNULL����ѭ�� */
	{
		Pointer = Head;
		Head = Head->Next;		/* ����һ���ڵ� */
		free(Pointer);
	}
}

/* --------------------------------------------------- */
/* �����������                                        */
/* ������Edge Head ͷָ��		   					   */
/* ����ֵ����                                          */
/* --------------------------------------------------- */
void PrintEdge(Edge Head)
{
	Edge Pointer;				/* �ڵ����� */
	
	Pointer = Head;				/* Pointerָ����Ϊ�׽ڵ� */
	while (	Pointer != NULL )	/* ���ڵ�ΪNULL����ѭ�� */
	{
		printf("[%d,%d]",Pointer->Vertex1,Pointer->Vertex2);
		printf("(%d)",Pointer->Weight);	/* �����Ȩֵ */
		Pointer = Pointer->Next;		/* ����һ���ڵ� */
	}
	printf("\n");
}

/* --------------------------------------------------- */
/* �����ڽӱ���������                                  */
/* ������Edge Head ����ǰ��ͷָ��		   			   */
/* ����ֵ��Edge ������ɺ��ͷָ��                     */
/* --------------------------------------------------- */
Edge InsertEdge(Edge Head,Edge New)
{
	Edge Pointer;				/* �ڵ����� */
	
	Pointer = Head;				/* Pointerָ����Ϊ�׽ڵ� */
	
	while ( Pointer->Next != NULL )	/* ����������β�� */
		Pointer = Pointer->Next;
	Pointer->Next = New;
	
	return Head;
}

/* --------------------------------------------------- */
/* ��������											   */
/* ������Edge Head ͷָ��		   					   */
/* ����ֵ��Edge ������ɺ��ͷָ��                     */
/* --------------------------------------------------- */
Edge CreateEdge(Edge Head)
{
	Edge New;							/* �ڵ����� */
	int	i;
	
	Head = (Edge) malloc(sizeof(Node));	/* �ڴ����� */
	
	if ( Head == NULL )
		printf("Memory allocate Failure!!\n");	/* �ڴ�����ʧ�� */
	
	else
	{
		Head->Marked = 0;
		Head->Vertex1 = Edges[0][0];
		Head->Vertex2 = Edges[0][1];
		Head->Weight = Edges[0][2];		/* ����ڵ��Ȩֵ */
		Head->Next = NULL;
		
		for ( i=1;i<10;i++ )
		{
			New = (Edge) malloc(sizeof(Node));
			
			if ( New != NULL )
			{
				New->Marked = 0;
				New->Vertex1 = Edges[i][0];
				New->Vertex2 = Edges[i][1];
				New->Weight = Edges[i][2];		/* ����ڵ��Ȩֵ */
				New->Next = NULL;
				
				Head = InsertEdge(Head,New);	/* ������½ڵ� */
			}
		}
	}
	return Head;
}
/* --------------------------------------------------- */
/* ������                                              */
/* --------------------------------------------------- */
void main ()
{
	Edge Head=NULL;					/* �ڵ����� */
	int	i;
	
	for ( i=1;i<=VertexNum;i++ )	/* ������Ҽ�¼ */
		Visited[i] = 0;
	
	Head = CreateEdge(Head);		/* ���ý������� */
	PrintEdge(Head);
	
	if ( Head != NULL )
	{
		printf("Prims Algorithm : \n");
		printf("Start from Vertex 1.\n");
		printf("Find Minimal Spanning Tree.\n");
		
		Prims(Head,1); 		/* ����Prims�㷨 */
		free(Head);			/* �����ͷ����� */
	}
}
