#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef int ElemType;	/* ElemTyp类型根据实际情况而定，这里设为int */

typedef struct Node
{	
	ElemType data;     	/*结点的数据域*/
	struct Node *next;  /*结点的指针域*/
} Node;	


typedef struct
{
	struct Node *head;	/*单链表的头指针*/
	int count;			/*单链表中结点的个数*/
} LinkedList;


/* --------------------------------------------------- */
/* 初始化单链表                                                   */
/* 参数： 无							                        */
/* 返回值：LinkedList* 初始化的单链表                              */
/* ----------------------------------------------------*/
LinkedList * InitList(void)
{ 
	LinkedList *L = (LinkedList *)malloc(sizeof(LinkedList));
	if(L == NULL){
		printf("init list error!");
		return NULL;
	}
	else{
		L->head = NULL;
		L->count = 0;
		
		return L; 
	}
}


/* --------------------------------------------------- */
/* 求单链表的长度                                                 */
/* 参数：LinkedList *L  单链表L                               */
/* 返回值：int 单链表的长度                                      */
/* ----------------------------------------------------*/
int ListLength(LinkedList *L)
{
	return L->count;
}


/* --------------------------------------------------- */
/* 判断单链表是否为空                                             */
/* 参数：LinkedList *L 单链表L                          		 */
/* 返回值：int  是否为空                                         */
/* ----------------------------------------------------*/
int IsListEmpty(LinkedList *L)
{
	if((L->head == NULL) && (L->count == 0))
		return SUCCESS;
	else
		return FAILURE;
	
}

/* --------------------------------------------------- */
/* 在单链表末端添加一个新元素                                     */
/* 参数：LinkedList *L  单链表L                           	 */
/* ElemType item  需要添加的新元素                             */
/* 返回值：int 是否添加成功                                      */
/* ----------------------------------------------------*/
int AppendList(LinkedList *L, ElemType item)
{ 
    struct Node *p;
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    q->data = item;
    q->next = NULL;
    
    if(L->head == NULL)  /*单链表为空*/ 
    {
        L->head = q;
        ++L->count;
        return SUCCESS;
    }
	
    /*查找尾部结点*/
    p = L->head;
    while ((p!=NULL) && (p->next != NULL))
    {
        p = p->next;
    }
	
    /*添加结点*/
    p->next = q;
	
    /*表长加1*/
    L->count++;
	
    return SUCCESS;
}

/* --------------------------------------------------- */
/* 在单链表指定位置插入一个新元素                             */
/* 参数：LinkedList *L  单链表L                           	 */
/* ElemType item  需要添加的新元素                             */
/* int pos  新元素插入的位置                                    */
/* 返回值：int 是否插入成功                                      */
/* ----------------------------------------------------*/
int ListInsert(LinkedList *L, ElemType item, int pos)
{
    Node *q = (Node *)malloc(sizeof(Node));
    Node *p;
    int i = 0;
	q->data = item;
    q->next = NULL;

    /* 插入的位置不正确，
       pos小于1表示在第1个位置之前插入，
       pos大于lastIndex+1表示在最后一个结点后面的第2个结点前面插入*/
    if((pos<1) || (pos>L->count+1))
    {
        printf("Position is error!");
        return FAILURE;
    }

    if(L->head == NULL)  /*单链表为空*/
    {
        L->head = q;
        L->count++;
        return SUCCESS;
    }

    /*在其他位置插入新结点*/
    p = L->head;
    i  = NULL= 1;

    while ((p != NULL) && (p->next != NULL) &&	(i < pos-1 ))	
	/* 定位插入点 */
    {
        p = p->next;
        i++;
    }

    /*插入结点*/
    q->next = p->next;
    p->next = q;

    /*表长加1*/
    L->count++;

    return SUCCESS;
}

/* --------------------------------------------------- */
/* 删除单链表指定位置的一个元素                                   */
/* 参数：LinkedList *L  单链表L                             	 */
/* int pos  删除元素的位置                                      */
/* 返回值：ElemType 删除的元素                                  */
/* ----------------------------------------------------*/
ElemType ListDel(LinkedList *L, int pos)
{
    struct Node *q;
    struct Node *p;
    int i = 0;
	
    if ((L->head == NULL) ||(pos < 1)||(pos > L->count))	
	/*单链表为空或者删除的位置不对*/
    {
        printf("Link is empty or Position is error!");
        return FAILURE;
    }
	
    /*删除第1个结点*/
    if (pos == 1)
    {
        q = L->head;
        L->head = L->head->next;
        L->count--;
        return q->data;
    }
	
    /*删除的不是第1个结点*/
    p = L->head;
    i = 1;
	
    /*查找第pos个结点*/
    while ((p != NULL) && (p->next != NULL) && (i < pos))
    {     
        ++pos;
        q = p;
        p = p->next;               
    }
	
    /*删除第pos个结点*/
    q->next = p->next;
	
    /*表长减1*/
    L->count--;
	
    return p->data;
}

/* --------------------------------------------------- */
/* 获得单链表指定位置的一个元素                                   */
/* 参数：LinkedList *L  单链表L                            	 */
/* int pos  获取元素的位置                                      */
/* 返回值：ElemType 获取的元素                                  */
/* ----------------------------------------------------*/
ElemType GetEle(LinkedList *L, int pos)
{
    struct Node *p;
    int i = 0;
	
	if ((L->head == NULL) || (pos < 1) || (pos > L->count))
		/* 表为空或位置下标不对 */
    {
        printf("List is empty or Position is error!");
        return FAILURE;
    }
	
    /*查找第pos个结点*/
    p = L->head;
    i = 1;
	
    while ((p != NULL) && (p->next != NULL)&& (i < pos))
    {     
		++i;
		p = p->next;               
    }
	
    return p->data;
}

/* --------------------------------------------------- */
/* 查找指定值的一个元素                                           */
/* 参数：LinkedList *L  单链表L                           	 */
/* ElemType value  需要查找的元值                              */
/* 返回值：int 查找到的值的位置                                  */
/* ----------------------------------------------------*/
int FindInList(LinkedList *L, ElemType value)
{ 
    struct Node *p;
    int i = 0;
	
    if(L->head == NULL) /*表为空*/
    {
        printf("list is Empty");
        return 0;
    }
	
    /*查找值为value的结点*/
    p = L->head;
    i = 1;
    while ((p != NULL) && (p->data != value) && (p->next != NULL))
    {
        p = p->next;
        ++i;
    } 
	
    if(p == NULL)
    {
        i = 0;
    }
	
    return i;         
}  

/* ---------------------------------------------------*/
/* 销毁链表												*/
/* 参数：LinkedList *L 需要销毁的单链表                   	*/
/* 返回值：空                                          			*/
/* ---------------------------------------------------*/
void DestroyList(LinkedList *L)
{
	Node *tmp;			/* 临时结点声明 */
	
	/* 释放所有结点 */
	while (	L->head != NULL )		/* 当头结点为NULL时结束循环 */
	{
		tmp = L->head;
		L->head = L->head->next;	/* 下一个结点 */
		free(tmp);
	}

	/* 释放表 */
	free(L);
}


/* ---------------------------------------------------*/
/* 主程序，用于测试所有实现的基本操作函数             */
/* ---------------------------------------------------*/
void main3(void)
{
	
	LinkedList* L=InitList();
	ElemType e;
			
	printf("%d\n", ListLength(L));
	printf("%d\n", IsListEmpty(L));

	ListInsert(L, 111, 1);
	ListInsert(L, 222, 2);
	AppendList(L, 333);
	ListInsert(L, 444, 2);
	printf("%d\n", ListLength(L));
	printf("%d\n", IsListEmpty(L));

	e = GetEle(L,2);
	printf("%d\n", e);

	ListDel(L,1);
	printf("%d\n", ListLength(L));
	printf("%d\n", IsListEmpty(L));

	DestroyList(L);

}
