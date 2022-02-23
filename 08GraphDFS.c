
#include <stdlib.h>
#include <stdio.h>
	
#define MAXSIZE 9		        /* ���嶥���� */

struct Node						/* ����ͼ�ζ���ṹ */
{
	int	adjvex;					/* �ڽӶ������� */
	struct Node *Next;			/* ��һ���ڽӶ��� */
};

typedef	struct	Node *Graph;    /* ����ͼ�νṹ */
struct	Node Head[MAXSIZE];		/* �������� */

int	Visited[MAXSIZE];	        /* ��¼ */

/* --------------------------------------------------- */
/* ������ȱ����㷨                                    */
/* --------------------------------------------------- */
void DFS(int adjvex)
{
	Graph	Pointer;					/* �ڵ����� */

	Visited[adjvex] = 1;	            /* �Ѳ��� */
	printf("[%d]==>",adjvex);
	Pointer = Head[adjvex].Next;

	while (	Pointer != NULL )
	{
		if ( Visited[Pointer->adjvex] == 0)
			DFS(Pointer->adjvex);	    /* �ݹ���� */
		Pointer = Pointer->Next;	    /* ��һ���ڽӵ� */
	}
}

/* --------------------------------------------------- */
/* �����ڽӶ������ڽ��б���                            */
/* --------------------------------------------------- */
void CreateLGraph(int adjvex1,int adjvex2)
{
	Graph	Pointer;							/* �ڵ����� */
	Graph	New;								/* �¶������� */

	New = (Graph) malloc(sizeof(struct Node));	/* �����ڴ� */
	if ( New != NULL )	/* ���óɹ� */
	{
		New->adjvex = adjvex2;            		/* �ڽ����� */
		New->Next = NULL;						/* ��һ���ڽӶ���ָ�� */
		/* Pointerָ����Ϊ��������֮�׽ڵ� */
		Pointer = &(Head[adjvex1]);

		while ( Pointer->Next != NULL )
			Pointer = Pointer->Next;			/* ����һ���ڵ� */

		Pointer->Next = New;	                /* ����������β�� */
	}
}

/* --------------------------------------------------- */
/* ����ڽ��б�������                                  */
/* --------------------------------------------------- */
void PrintLGraph(struct Node *Head)
{
	Graph	Pointer;					/* �ڵ����� */

	Pointer = Head->Next;		/* Pointerָ����Ϊ�׽ڵ� */
	while (	Pointer != NULL )	/* ���ڵ�ΪNULL����ѭ�� */
	{
		printf("[%d]",Pointer->adjvex);
		Pointer = Pointer->Next;		/* ����һ���ڵ� */
	}
	printf("\n");
}

/* --------------------------------------------------- */
/* ������                                              */
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
		PrintLGraph(&Head[i]);      /* ��������ڽ��б����� */
	}
	printf("DFS : \n");
	printf("[BEGIN]==>");
	DFS(1);
	printf("[END]\n");
}
