#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0
#define MAXSIZE	8
#define HashMax 5

/* ���ҵ��������� */
int Data[MAXSIZE] = { 1, 13, 20, 5, 12, 32, 59, 92};

struct List						/* �����б�ṹ */
{
	int		Key;				/* ��ֵ */
	struct  List	*Next;		/* ��һ���ڵ� */
};
typedef struct List Node;
typedef Node *LinkNode;

Node	HashTab[HashMax];		/* ��ϣ�� */
int 	Counter = 1;			/* ���Ҵ��������� */

/* ---------------------------------------------------*/
/* ��ϣ���������в��ó���������                       */
/* ������int key �ؼ���		   		  				  */				
/* ����ֵ��int ��ֵ���Թ�ϣ���Сȡ����               */
/* ---------------------------------------------------*/
int HashMod(int Key)
{
	return Key % HashMax ;	
}

/* ---------------------------------------------------*/
/* ���ؼ��ֲ����ϣ��                                 */
/* ������int key �ؼ���		   		  				  */				
/* ����ֵ����										  */
/* ---------------------------------------------------*/
void InsertHash(int Key)
{
	LinkNode Pointer;					/* �б�ָ�� */
	LinkNode New;						/* ���б�ָ�� */
	int	Index;							/* ��ϣ���� */
	
	New = ( LinkNode ) malloc(sizeof(Node));/* �ڴ���� */
	New->Key = Key;						
	New->Next = NULL;					/* ָ�����ָ�� */
	
	Index = HashMod(Key);				/* ȡ������λ�� */
	Pointer = HashTab[Index].Next;		/* ��ϣ����ʼָ�� */
	if ( Pointer != NULL )				/* ָ��ûָ�����ָ��ʱ */
	{
		New->Next = Pointer;			/* ָ����һ��ָ�� */
		HashTab[Index].Next = New;		/* ��ϣ��ָ��ָ�����ָ�� */
	}
	else
	{
		HashTab[Index].Next = New;		/* ��ϣ��ָ��ָ�����ָ�� */
	}
}

/* ---------------------------------------------------*/
/* ��ϣ���ҷ�                                         */
/* ������int key �ؼ���		   		  				  */				
/* ����ֵ��int �Ƿ���ҳɹ�							  */
/* ---------------------------------------------------*/
int HashSearch(int Key)
{
	LinkNode Pointer;				/* �б�ָ�� */
	int	Index;						/* ��ϣ���� */
	
	Counter = 0;
	Index = HashMod(Key);			/* ȡ������λ�� */
	Pointer = HashTab[Index].Next;	/* ��ϣ����ʼָ�� */
	printf("Data[%d] : ",Index);
	
	while ( Pointer != NULL )		/* ָ��ָ�����ָ��ʱ��ֹѭ�� */
	{
		Counter++;
		printf("[%d]",Pointer->Key);
		if ( Pointer->Key == Key )	/* ���ҵ����� */
			return SUCCESS;
		else						/* ����һ��ָ����� */
			Pointer = Pointer->Next;/* ָ����һ��ָ�� */
	}
	return FAILURE;
}

/* ---------------------------------------------------*/
/* ������                                             */
/* ---------------------------------------------------*/
void main ()
{
	int		KeyValue;				/* ���������ݱ��� */
	int		Index;					/* ������������ */
	LinkNode    Pointer;
	int i;
	
	Index = 0;
	
	printf("���ҵ��������� : ");		
	for ( i=0;i<MAXSIZE;i++ )
		printf("[%d]",Data[i]);
	printf("\n");
	
	while ( Index < MAXSIZE )		/* ������ϣ�� */
	{
		InsertHash(Data[Index]);
		Index++;
	}
	
	for ( i=0;i<HashMax;i++ )		/* �����ϣ������ */
	{
		printf("HashTab[%d] : ",i);
		Pointer = HashTab[i].Next;
		while ( Pointer != NULL )
		{
			if ( Pointer->Key > 0 )
				printf("[%d]",Pointer->Key);
			Pointer = Pointer->Next;
		}
		printf("\n");
	}
	
	while ( KeyValue != -1 )		/* ����-1�������� */
	{
		printf("��������Ҫ���ҵ�ֵ : ");
		scanf("%d",&KeyValue);
		
		if ( HashSearch(KeyValue) )
			printf("\n���Ҵ��� = %d\n",Counter);/* ������Ҵ��� */
		else
			printf("\nNo Found!!\n");	/* ���û���ҵ����� */
	}
}
