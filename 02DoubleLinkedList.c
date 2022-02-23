#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef int ElemType;		/* ElemTyp类型根据实际情况而定，这里假设为int */

typedef struct DoubleLinkedNode		/* 线性表的双向链表存储结构 */
{
	ElemType data;					/*结点的数据域*/
	struct DoubleLinkedNode *prev;	/*结点的前驱指针域*/
	struct DoubleLinkedNode *next;	/*结点的后继指针域*/
	
}DoubleLinkedNode,*DLinkedList;


/* --------------------------------------------------- */
/* 初始化双向链表                                      */
/* 参数：空											   */
/* 返回值：DLinkedList 已初始化的双向链表              */
/* ----------------------------------------------------*/
DLinkedList InitList(void)
{ 
	/* 产生空的双向循环链表L 使用一个DoubleLinkedNode结点作为链表的头 */
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
/* 求双向链表长度                                                */
/* 参数：DLinkedList *L求长度的双向链表                       */
/* 返回值：int 双向链表长度                               		*/
/* ----------------------------------------------------*/
int ListLength(DLinkedList L)
{ 
	int i=0;
	DLinkedList p=L->next;		/* p指向第一个结点 */
	while(p!=NULL)				/* p没到表头 */
	{
		i++;
		p=p->next;
	}
	return i;
}

/* --------------------------------------------------- */
/* 判断双向链表是否为空                                          */
/* 参数：DLinkedList *L双向链表                       		*/
/* 返回值：int  双向链表是否为空                                */
/* ----------------------------------------------------*/
int IsListEmpty(DLinkedList L)
{ 
	if(L->next == NULL && L->prev == NULL)
		return SUCCESS;
	else
		return FAILURE;
	
}


/* --------------------------------------------------- */
/* 在双向链表L中返回第i个元素的地址。                          */
/* 参数：DLinkedList *L双向链表                           	 */
/* i为0，返回头结点的地址。                                     */
/* 若第i个元素不存在，则返回NULL                               */
/* ----------------------------------------------------*/
DoubleLinkedNode* GetEleAdd(DLinkedList L,int i) 
{ 
	int j;
	DoubleLinkedNode *p=L; 			/* p指向头结点 */
	if(i<0 || i>ListLength(L) ) 	/* i值不合法 */
		return NULL;
	for(j=1;j<=i;j++)
		p=p->next;
	return p;
}


/* --------------------------------------------------- */
/* 在有头结点的双向链循环线性表L中第i个位置之前插入元素e       */
/* i的合法值为1≤i≤表长+1                                      */
/* 参数：DLinkedList *L双向链表                                 */
/* ElemType e 需要插入的元素                                   */
/* 返回值：int 是否插入成功                                      */
/* ----------------------------------------------------*/
int ListInsert(DLinkedList L,int i,ElemType e)
{ 
	DoubleLinkedNode *p;
	DLinkedList s;
	if(i<1 || i>ListLength(L)+1) 	/* i值不合法 */
		return FAILURE;

	p=GetEleAdd(L,i-1); 			/* 在L中确定第i个元素前驱的位置指针p */
	if(!p) 							/* p=NULL,即第i个元素的前驱不存在 */
		return FAILURE;

	s=(DLinkedList)malloc(sizeof(DoubleLinkedNode));
	if(!s){
		printf("init node error!");
		return FAILURE;
	}

	s->data=e;
	s->prev=p; 		/* 在第i-1个元素之后插入 */
	s->next=p->next;
	if(p->next !=NULL){
		p->next->prev=s;
	}
	p->next=s;
	
	return SUCCESS;
}

/* --------------------------------------------------- */
/*删除带头结点的双链循环线性表L的第i个元素                     */
/* i的合法值为1≤i≤表长+1                                     */
/* 参数：DLinkedList *L双向链表                                */
/* int i 需要删除的元素下标                                     */
/* 返回值：int 是否删除成功                                      */
/* ----------------------------------------------------*/
int ListDel(DLinkedList L,int i)
{ 
	DoubleLinkedNode *p;
	if(i<1) /* i值不合法 */
		return FAILURE;
	p=GetEleAdd(L,i);	/* 在L中确定第i个元素的位置指针p */
	if(!p) 				/* p=NULL,即第i个元素不存在 */
		return FAILURE;
	p->prev->next=p->next;
	p->next->prev=p->prev;
	free(p);
	return SUCCESS;
}

/* --------------------------------------------------- */
/* 销毁双向链表                                                  */
/* 参数：DLinkedList *L 需要销毁的双向链表                     */
/* 返回值：空                                                    */
/* ----------------------------------------------------*/
void DestroyList(DLinkedList L)
{ /* 操作结果：销毁双向循环链表L */
	DoubleLinkedNode *q, *p=L->next; /* p指向第一个结点 */
	while(p!=NULL) /* p没到表头 */
	{
		q=p->next;
		free(p);
		p=q;
	}
	free(L);
	L=NULL;
}


/* ---------------------------------------------------*/
/* 主程序，用于测试所有实现的基本操作函数			  */
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
