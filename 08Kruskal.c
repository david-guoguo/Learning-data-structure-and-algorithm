#include <stdio.h>
#include <stdlib.h>

#define Max 10
#define VertexNum 5

struct	List	                     /* �ڵ�ṹ���� */
{
	int		Vertex1;
	int		Vertex2;
	int		Weight;
	struct	List *Next;
};
typedef	struct	List	Node;
typedef	Node	*Edge;				/* �����ڽӱߵĽڵ� */

int Edges[10][3] =	                /* �������� */
{
	{1,2,7}, {1,3,6}, {1,4,5}, {1,5,12}, {2,3,14},
	{2,4,8}, {2,5,8}, {3,4,3}, {3,5,9}, {4,5,2} 
};

int Visited[VertexNum];	           /* ���Ҽ�¼ */

/* --------------------------------------------------- */
/* Kruskal�㷨                                         */
/* ������Edge Head ͷָ��		   					   */
/* ����ֵ����                                          */
/* --------------------------------------------------- */
void Kruskal(Edge Head)
{
	Edge	Pointer;				/* �ڵ����� */
	int	EdgeNum = 0;				/* ������ߵ���Ŀ */
	int	Weight = 0;
	
	Pointer = Head;
	
	/* ���ߵ���ĿΪ�������Ŀ��1ʱ������ѭ�� */
	while ( EdgeNum != ( VertexNum - 1 )  )	
	{
		/* ��һ���㲻����������ʱ */
		if ( Visited[Pointer->Vertex1] == 0
			|| Visited[Pointer->Vertex2] == 0 ) 
		{
			
			printf("==>[%d,%d]",Pointer->Vertex1,Pointer->Vertex2);
			printf("(%d)",Pointer->Weight);
			Weight += Pointer->Weight;
			EdgeNum++;	/* ������1 */
			Visited[Pointer->Vertex1] = 1;	/* ��Ϊ�Ѳ��� */
			Visited[Pointer->Vertex2] = 1;  /* ��Ϊ�Ѳ���  */
		}
		Pointer = Pointer->Next;			/* ����һ���ڵ� */
		
		if ( Pointer == NULL )				/* ���ޱ�ʱ */
		{
			printf("No Spanning Tree \n");
			break;
		}
	}
	printf("\nTotal weight = %d\n",Weight);	/* �����Ȩֵ�ܺ� */
}

/* --------------------------------------------------- */
/* �ͷ�����                                            */
/* ������Edge Head ͷָ��		   					   */
/* ����ֵ����                                          */
/* --------------------------------------------------- */
void FreeEdge(Edge Head)
{
	Edge	Pointer;				/* �ڵ����� */
	
	while (	Head != NULL )			/* ���ڵ�ΪNULL����ѭ�� */
	{
		Pointer = Head;
		Head = Head->Next;			/* ����һ���ڵ� */
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
	Edge	Pointer;				/* �ڵ����� */
	Pointer = Head;					/* Pointerָ����Ϊ�׽ڵ� */
	while (	Pointer != NULL )		/* ���ڵ�ΪNULL����ѭ�� */
	{
		printf("[%d,%d]",Pointer->Vertex1,Pointer->Vertex2);
		printf("(%d)",Pointer->Weight); /* �����Ȩֵ */
		Pointer = Pointer->Next;	/* ����һ���ڵ� */
	}
	printf("\n");
}

/* --------------------------------------------------- */
/* ���������ڽӱ���������                              */
/* ������Edge Head ����ǰ��ͷָ��		   			   */
/* ����ֵ��Edge ������ɺ��ͷָ��                     */
/* --------------------------------------------------- */
Edge InsertEdge(Edge Head,Edge New)
{
	Edge	Pointer;				/* �ڵ����� */
	
	Pointer = Head;			        /* Pointerָ����Ϊ�׽ڵ� */
	
	while ( 1 )
	{
		if ( New->Weight < Head->Weight ) /* �µļ�Ȩֵ���׽ڵ�С */
		{
			New->Next = Head;		/* �������׽ڵ�֮ǰ */
			Head = New;
			break;
		}
		
		
		if( Pointer->Next==NULL )
		{
			break;
		}
		
		/* �����������м��β�� */
		if ( New->Weight >= Pointer->Weight
			&& New->Weight < Pointer->Next->Weight) 
		{
			New->Next = Pointer->Next;
			Pointer->Next = New;
			break;
		}
		Pointer = Pointer->Next;	/* ����һ���ڵ� */
	}
	return Head;
}


/* --------------------------------------------------- */
/* ��������                                            */
/* ������Edge Head ͷָ��		   					   */
/* ����ֵ��Edge ������ɺ��ͷָ��                     */
/* --------------------------------------------------- */
Edge CreateEdge(Edge Head)
{
	Edge	New;			                /* �ڵ����� */
	//	Edge	Pointer;		            /* �ڵ����� */
	int	i;
	
	Head = (Edge) malloc(sizeof(Node));		/* �ڴ����� */
	
	if ( Head == NULL )
		printf("Memory allocate Failure!!\n");	/* �ڴ�����ʧ�� */
	
	else
	{
		Head->Vertex1 = Edges[0][0];
		Head->Vertex2 = Edges[0][1];
		Head->Weight = Edges[0][2];			/* ����ڵ��Ȩֵ */
		Head->Next = NULL;
		
		for ( i=1;i<10;i++ )
		{
			New = (Edge) malloc(sizeof(Node));
			
			if ( New != NULL )
			{
				New->Vertex1 = Edges[i][0];
				New->Vertex2 = Edges[i][1];
				New->Weight = Edges[i][2];	/* ����ڵ��Ȩֵ */
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
	Edge	Head;					/* �ڵ����� */
	int	i;			
	
	for ( i=0;i<VertexNum;i++ )		/* ������Ҽ�¼ */
		Visited[i] = 0;
	
	Head = CreateEdge(Head);		/* ���ý������� */
	
	if ( Head != NULL )
	{
		printf("Kruskal  Algorithm : \n");
		printf("First Step : Sorting \n");
		PrintEdge(Head);
		printf("Second Step : Find Minimal Spanning Tree. \n");
		
		Kruskal(Head); 		/* ����kruskal�㷨 */
		
		FreeEdge(Head);	/* �����ͷ����� */
	}
}
