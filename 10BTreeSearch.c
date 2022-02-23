#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0
#define MAXSIZE	10

/* �������� */
int	Data[MAXSIZE] = {
	16,  1, 13,  5,  17,
	25, 37,  7,  3,  99};   
int Counter;			/* ������ */

/* ������״�ṹ */
struct Tree			               
{
	int		Key;				/* ���ݱ��� */
	struct	Tree	*Left;		/* ������ָ�� */
	struct	Tree	*Right;		/* ������ָ�� */
};
typedef struct Tree TreeNode;
typedef TreeNode *BTree;

BTree   Root = NULL;			/* �������ڵ� */

/* ---------------------------------------------------*/
/* �������������                                     */
/* ������int Data ���ڴ���������������		   		  */				
/* ����ֵ����                            			  */
/* ---------------------------------------------------*/
void CreateBTree(int *Data)
{
	BTree   New;		             /* ��ָ����� */
	BTree	Current;	             /* Ŀǰָ�� */
	BTree	Father;		             /* ���ڵ�ָ�� */
	int	  	i;

	for ( i=0;i<MAXSIZE;i++ )
	{
		New = (BTree) malloc(sizeof(TreeNode));	/* �ڴ����� */
		New->Key = Data[i];	/* ��ָ��Ϊ��������� */
		New->Left = NULL;	/* �������ڵ� */
		New->Right = NULL;	/* �������ڵ� */
		if ( Root == NULL )	/* �����ڵ�δ�����κ�����ʱ */
			Root = New;		/* ���ڵ�Ϊ�½ڵ� */
		else
		{
			Current = Root;				/* Ŀǰ��λ���ڸ��ڵ� */
			while ( Current != NULL )	/* ��Ŀǰ�Ľڵ�Ϊ��׶������ѭ�� */
			{
				Father = Current;				/* ��¼���ڵ� */

				/* Ŀǰ�ڵ����ݴ��ڻ������������ */
				if ( Current->Key >= Data[i] ) 	
					Current = Current->Left; 	/* �������� */
				else	/* Ŀǰ�ڵ�����С���������� */
					Current = Current->Right;	/* �������� */
			}
			if ( Father->Key > Data[i] )		/* ���������ӽڵ� */
				Father->Left = New;
			else
				Father->Right = New;
		}
	}
}

/* ---------------------------------------------------*/
/* ���������                                         */
/* ������int key ��Ҫ���ҵ�keyֵ		   			  */				
/* ����ֵ��int �����Ƿ�ɹ�                           */
/* ---------------------------------------------------*/
int BTreeSearch(int Key)
{
	BTree	Pointer;
	Pointer = Root;		/* ���ҽڵ�Ϊ���ڵ� */
	Counter = 0;

	while ( Pointer != NULL )
	{
		Counter++;
		/* ���ҽڵ������С������������ */
		if ( Pointer->Key < Key )	
			Pointer = Pointer->Right;	/* �������� */
		/* ���ҽڵ�����ݴ������������� */
		else if ( Pointer->Key > Key )
			Pointer = Pointer->Left;	/* �������� */
		/* ���ҽڵ�����ݵ������������� */
		else if ( Pointer->Key == Key )
			return SUCCESS;				/* �ҵ����� */
	}

	return FAILURE;	/* δ�ܲ��ҵ����� */
}

/* ---------------------------------------------------*/
/* ������                                             */
/* ---------------------------------------------------*/
void main ()
{
	int KeyValue;						/* ���������ݱ��� */
	int i;

	printf("Search Data : ");	          
	for ( i=0;i<MAXSIZE;i++ )
		printf("[%d]",Data[i]);
	printf("\n");

	Root = NULL;
	CreateBTree(Data);					/* ���ý������������ */

	while ( KeyValue != -1 )			/* ����-1�������� */
	{
	printf("Please enter your key value : ");
	scanf("%d",&KeyValue);

	if ( BTreeSearch(KeyValue) )
		printf("Search Time = %d\n",Counter);	/* ������Ҵ��� */
	else
		printf("Data No Found!!\n");	/* ���û���ҵ����� */
	}
}
