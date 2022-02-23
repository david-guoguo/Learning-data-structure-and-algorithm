#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 9			/* ���嶥���� */
#define QueueMax 10

struct Node					/* ����ͼ�ζ���ṹ */
{
	int	Vertex;		        /* �ڽӶ������� */
	struct	Node *Next;		/* ��һ���ڽӶ��� */
};

typedef	struct Node *Graph;	/* ����ͼ�νṹ */
struct Node Head[MAXSIZE];	/* �������� */

int	Queue[QueueMax];
int	Front = -1;
int	Rear = -1;

int	Visited[MAXSIZE];	      /* ���Ҽ�¼ */

/* --------------------------------------------------- */
/* ���еĴ���                                          */
/* --------------------------------------------------- */
int Enqueue(int Vertex)
{
	if ( Rear >= QueueMax )		/* �������� */
		return -1;
	else
	{
		Rear++;					/* ����β��ָ����� */
		Queue[Rear] = Vertex;	/* ��ֵ��������� */
		return 1;
	}
}

/* --------------------------------------------------- */
/* ���е�ȡ��                                          */
/* --------------------------------------------------- */
int Dequeue()
{
	if ( Front == Rear )		/* �����ѿ� */
		return -1;
	else
	{
		Front++;	            /* ��ͷָ����� */
		return Queue[Front];
	}
}

/* --------------------------------------------------- */
/* �������������                                      */
/* --------------------------------------------------- */
void BFS(int Vertex)
{
	Graph	Pointer;			/* �ڵ����� */

	Enqueue(Vertex);			/* ��������� */
	Visited[Vertex] = 1;		/* �Ѳ��� */
	printf("[%d]==>",Vertex);

	while (	Front != Rear )		/* ����Ϊ��ʱ������ѭ�� */
	{
		Vertex = Dequeue();
		Pointer = Head[Vertex].Next;
		while ( Pointer != NULL )	/* �����ڽ��б����ж��� */
		{
			if ( Visited[Pointer->Vertex] == 0)
			{
				Enqueue(Pointer->Vertex);		/* ��������� */
				Visited[Pointer->Vertex] = 1;	/* �Ѳ��ҹ��Ķ��� */
				printf("[%d]==>",Pointer->Vertex);
			}
			Pointer = Pointer->Next;			/* ��һ���ڽӵ� */
		}
	}
}

/* --------------------------------------------------- */
/* �����ڽӶ������ڽ��б���                            */
/* --------------------------------------------------- */
void Create_L_Graph(int Vertex1,int Vertex2)
{
	Graph	Pointer;							/* �ڵ����� */
	Graph	New;								/* �¶������� */

	New = (Graph) malloc(sizeof(struct Node));	/* �����ڴ� */
	if ( New != NULL )							/* ���óɹ� */
	{
		New->Vertex = Vertex2;	/* �ڽ����� */
		New->Next = NULL;		/* ��һ���ڽӶ���ָ�� */

		/* Pointerָ����Ϊ��������֮�׽ڵ� */
		Pointer = &(Head[Vertex1]);

		while ( Pointer->Next != NULL )
			Pointer = Pointer->Next;		/* ����һ���ڵ� */

		Pointer->Next = New;				/* ����������β�� */
	}
}

/* --------------------------------------------------- */
/* ����ڽ��б�������                                  */
/* --------------------------------------------------- */
void Print_L_Graph(struct Node *Head)
{
	Graph	Pointer;				/* �ڵ����� */

	Pointer = Head->Next;			/* Pointerָ����Ϊ�׽ڵ� */
	while (	Pointer != NULL )		/* ���ڵ�ΪNULL����ѭ�� */
	{
		printf("[%d]",Pointer->Vertex);
		Pointer = Pointer->Next;	/* ����һ���ڵ� */
	}
	printf("\n");
}

/* --------------------------------------------------- */
/* ������                                              */
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
		Print_L_Graph(&Head[i]);	/* ��������ڽ��б����� */
	}
	printf("BFS : \n");
	printf("[BEGIN]==>");
	BFS(4);
	printf("[END]\n");
}
