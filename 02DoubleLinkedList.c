#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef int ElemType;		/* ElemTyp���͸���ʵ������������������Ϊint */

typedef struct DoubleLinkedNode		/* ���Ա��˫������洢�ṹ */
{
	ElemType data;					/*����������*/
	struct DoubleLinkedNode *prev;	/*����ǰ��ָ����*/
	struct DoubleLinkedNode *next;	/*���ĺ��ָ����*/
	
}DoubleLinkedNode,*DLinkedList;


/* --------------------------------------------------- */
/* ��ʼ��˫������                                      */
/* ��������											   */
/* ����ֵ��DLinkedList �ѳ�ʼ����˫������              */
/* ----------------------------------------------------*/
DLinkedList InitList(void)
{ 
	/* �����յ�˫��ѭ������L ʹ��һ��DoubleLinkedNode�����Ϊ�����ͷ */
	DLinkedList L=(DLinkedList)malloc(sizeof(DoubleLinkedNode));
	if(L!=NULL){
		L->next=L->prev=NULL;
		return L;
	}
	else{
		printf("init list error!");
		exit(1);
	}
}

/* --------------------------------------------------- */
/* ��˫��������                                                */
/* ������DLinkedList *L�󳤶ȵ�˫������                       */
/* ����ֵ��int ˫��������                               		*/
/* ----------------------------------------------------*/
int ListLength(DLinkedList L)
{ 
	int i=0;
	DLinkedList p=L->next;		/* pָ���һ����� */
	while(p!=NULL)				/* pû����ͷ */
	{
		i++;
		p=p->next;
	}
	return i;
}

/* --------------------------------------------------- */
/* �ж�˫�������Ƿ�Ϊ��                                          */
/* ������DLinkedList *L˫������                       		*/
/* ����ֵ��int  ˫�������Ƿ�Ϊ��                                */
/* ----------------------------------------------------*/
int IsListEmpty(DLinkedList L)
{ 
	if(L->next == NULL && L->prev == NULL)
		return SUCCESS;
	else
		return FAILURE;
	
}


/* --------------------------------------------------- */
/* ��˫������L�з��ص�i��Ԫ�صĵ�ַ��                          */
/* ������DLinkedList *L˫������                           	 */
/* iΪ0������ͷ���ĵ�ַ��                                     */
/* ����i��Ԫ�ز����ڣ��򷵻�NULL                               */
/* ----------------------------------------------------*/
DoubleLinkedNode* GetEleAdd(DLinkedList L,int i) 
{ 
	int j;
	DoubleLinkedNode *p=L; 			/* pָ��ͷ��� */
	if(i<0 || i>ListLength(L) ) 	/* iֵ���Ϸ� */
		return NULL;
	for(j=1;j<=i;j++)
		p=p->next;
	return p;
}


/* --------------------------------------------------- */
/* ����ͷ����˫����ѭ�����Ա�L�е�i��λ��֮ǰ����Ԫ��e       */
/* i�ĺϷ�ֵΪ1��i�ܱ�+1                                      */
/* ������DLinkedList *L˫������                                 */
/* ElemType e ��Ҫ�����Ԫ��                                   */
/* ����ֵ��int �Ƿ����ɹ�                                      */
/* ----------------------------------------------------*/
int ListInsert(DLinkedList L,int i,ElemType e)
{ 
	DoubleLinkedNode *p;
	DLinkedList s;
	if(i<1 || i>ListLength(L)+1) 	/* iֵ���Ϸ� */
		return FAILURE;

	p=GetEleAdd(L,i-1); 			/* ��L��ȷ����i��Ԫ��ǰ����λ��ָ��p */
	if(!p) 							/* p=NULL,����i��Ԫ�ص�ǰ�������� */
		return FAILURE;

	s=(DLinkedList)malloc(sizeof(DoubleLinkedNode));
	if(!s){
		printf("init node error!");
		return FAILURE;
	}

	s->data=e;
	s->prev=p; 		/* �ڵ�i-1��Ԫ��֮����� */
	s->next=p->next;
	if(p->next !=NULL){
		p->next->prev=s;
	}
	p->next=s;
	
	return SUCCESS;
}

/* --------------------------------------------------- */
/*ɾ����ͷ����˫��ѭ�����Ա�L�ĵ�i��Ԫ��                     */
/* i�ĺϷ�ֵΪ1��i�ܱ�+1                                     */
/* ������DLinkedList *L˫������                                */
/* int i ��Ҫɾ����Ԫ���±�                                     */
/* ����ֵ��int �Ƿ�ɾ���ɹ�                                      */
/* ----------------------------------------------------*/
int ListDel(DLinkedList L,int i)
{ 
	DoubleLinkedNode *p;
	if(i<1) /* iֵ���Ϸ� */
		return FAILURE;
	p=GetEleAdd(L,i);	/* ��L��ȷ����i��Ԫ�ص�λ��ָ��p */
	if(!p) 				/* p=NULL,����i��Ԫ�ز����� */
		return FAILURE;
	p->prev->next=p->next;
	p->next->prev=p->prev;
	free(p);
	return SUCCESS;
}

/* --------------------------------------------------- */
/* ����˫������                                                  */
/* ������DLinkedList *L ��Ҫ���ٵ�˫������                     */
/* ����ֵ����                                                    */
/* ----------------------------------------------------*/
void DestroyList(DLinkedList L)
{ /* �������������˫��ѭ������L */
	DoubleLinkedNode *q, *p=L->next; /* pָ���һ����� */
	while(p!=NULL) /* pû����ͷ */
	{
		q=p->next;
		free(p);
		p=q;
	}
	free(L);
	L=NULL;
}


/* ---------------------------------------------------*/
/* ���������ڲ�������ʵ�ֵĻ�����������			  */
/* ---------------------------------------------------*/
int main ()
{
	DLinkedList L= InitList();
	DoubleLinkedNode *node;
		
	printf("%d\n", ListLength(L));
	printf("%d\n", IsListEmpty(L));

	ListInsert(L, 1, 111);
	ListInsert(L, 2, 333);
	ListInsert(L, 2, 222);
    ListInsert(L, 2, 234567);

	GetEleAdd(L,1);
	node = GetEleAdd(L,1);
	printf("%d\n", node->data);

	ListDel(L,1);
	printf("%d\n", ListLength(L));
	printf("%d\n", IsListEmpty(L));

	DestroyList(L);
    
    return 0;
}
