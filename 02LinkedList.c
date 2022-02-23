#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef int ElemType;	/* ElemTyp���͸���ʵ�����������������Ϊint */

typedef struct Node
{	
	ElemType data;     	/*����������*/
	struct Node *next;  /*����ָ����*/
} Node;	


typedef struct
{
	struct Node *head;	/*�������ͷָ��*/
	int count;			/*�������н��ĸ���*/
} LinkedList;


/* --------------------------------------------------- */
/* ��ʼ��������                                                   */
/* ������ ��							                        */
/* ����ֵ��LinkedList* ��ʼ���ĵ�����                              */
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
/* ������ĳ���                                                 */
/* ������LinkedList *L  ������L                               */
/* ����ֵ��int ������ĳ���                                      */
/* ----------------------------------------------------*/
int ListLength(LinkedList *L)
{
	return L->count;
}


/* --------------------------------------------------- */
/* �жϵ������Ƿ�Ϊ��                                             */
/* ������LinkedList *L ������L                          		 */
/* ����ֵ��int  �Ƿ�Ϊ��                                         */
/* ----------------------------------------------------*/
int IsListEmpty(LinkedList *L)
{
	if((L->head == NULL) && (L->count == 0))
		return SUCCESS;
	else
		return FAILURE;
	
}

/* --------------------------------------------------- */
/* �ڵ�����ĩ�����һ����Ԫ��                                     */
/* ������LinkedList *L  ������L                           	 */
/* ElemType item  ��Ҫ��ӵ���Ԫ��                             */
/* ����ֵ��int �Ƿ���ӳɹ�                                      */
/* ----------------------------------------------------*/
int AppendList(LinkedList *L, ElemType item)
{ 
    struct Node *p;
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    q->data = item;
    q->next = NULL;
    
    if(L->head == NULL)  /*������Ϊ��*/ 
    {
        L->head = q;
        ++L->count;
        return SUCCESS;
    }
	
    /*����β�����*/
    p = L->head;
    while ((p!=NULL) && (p->next != NULL))
    {
        p = p->next;
    }
	
    /*��ӽ��*/
    p->next = q;
	
    /*����1*/
    L->count++;
	
    return SUCCESS;
}

/* --------------------------------------------------- */
/* �ڵ�����ָ��λ�ò���һ����Ԫ��                             */
/* ������LinkedList *L  ������L                           	 */
/* ElemType item  ��Ҫ��ӵ���Ԫ��                             */
/* int pos  ��Ԫ�ز����λ��                                    */
/* ����ֵ��int �Ƿ����ɹ�                                      */
/* ----------------------------------------------------*/
int ListInsert(LinkedList *L, ElemType item, int pos)
{
    Node *q = (Node *)malloc(sizeof(Node));
    Node *p;
    int i = 0;
	q->data = item;
    q->next = NULL;

    /* �����λ�ò���ȷ��
       posС��1��ʾ�ڵ�1��λ��֮ǰ���룬
       pos����lastIndex+1��ʾ�����һ��������ĵ�2�����ǰ�����*/
    if((pos<1) || (pos>L->count+1))
    {
        printf("Position is error!");
        return FAILURE;
    }

    if(L->head == NULL)  /*������Ϊ��*/
    {
        L->head = q;
        L->count++;
        return SUCCESS;
    }

    /*������λ�ò����½��*/
    p = L->head;
    i  = NULL= 1;

    while ((p != NULL) && (p->next != NULL) &&	(i < pos-1 ))	
	/* ��λ����� */
    {
        p = p->next;
        i++;
    }

    /*������*/
    q->next = p->next;
    p->next = q;

    /*����1*/
    L->count++;

    return SUCCESS;
}

/* --------------------------------------------------- */
/* ɾ��������ָ��λ�õ�һ��Ԫ��                                   */
/* ������LinkedList *L  ������L                             	 */
/* int pos  ɾ��Ԫ�ص�λ��                                      */
/* ����ֵ��ElemType ɾ����Ԫ��                                  */
/* ----------------------------------------------------*/
ElemType ListDel(LinkedList *L, int pos)
{
    struct Node *q;
    struct Node *p;
    int i = 0;
	
    if ((L->head == NULL) ||(pos < 1)||(pos > L->count))	
	/*������Ϊ�ջ���ɾ����λ�ò���*/
    {
        printf("Link is empty or Position is error!");
        return FAILURE;
    }
	
    /*ɾ����1�����*/
    if (pos == 1)
    {
        q = L->head;
        L->head = L->head->next;
        L->count--;
        return q->data;
    }
	
    /*ɾ���Ĳ��ǵ�1�����*/
    p = L->head;
    i = 1;
	
    /*���ҵ�pos�����*/
    while ((p != NULL) && (p->next != NULL) && (i < pos))
    {     
        ++pos;
        q = p;
        p = p->next;               
    }
	
    /*ɾ����pos�����*/
    q->next = p->next;
	
    /*����1*/
    L->count--;
	
    return p->data;
}

/* --------------------------------------------------- */
/* ��õ�����ָ��λ�õ�һ��Ԫ��                                   */
/* ������LinkedList *L  ������L                            	 */
/* int pos  ��ȡԪ�ص�λ��                                      */
/* ����ֵ��ElemType ��ȡ��Ԫ��                                  */
/* ----------------------------------------------------*/
ElemType GetEle(LinkedList *L, int pos)
{
    struct Node *p;
    int i = 0;
	
	if ((L->head == NULL) || (pos < 1) || (pos > L->count))
		/* ��Ϊ�ջ�λ���±겻�� */
    {
        printf("List is empty or Position is error!");
        return FAILURE;
    }
	
    /*���ҵ�pos�����*/
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
/* ����ָ��ֵ��һ��Ԫ��                                           */
/* ������LinkedList *L  ������L                           	 */
/* ElemType value  ��Ҫ���ҵ�Ԫֵ                              */
/* ����ֵ��int ���ҵ���ֵ��λ��                                  */
/* ----------------------------------------------------*/
int FindInList(LinkedList *L, ElemType value)
{ 
    struct Node *p;
    int i = 0;
	
    if(L->head == NULL) /*��Ϊ��*/
    {
        printf("list is Empty");
        return 0;
    }
	
    /*����ֵΪvalue�Ľ��*/
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
/* ��������												*/
/* ������LinkedList *L ��Ҫ���ٵĵ�����                   	*/
/* ����ֵ����                                          			*/
/* ---------------------------------------------------*/
void DestroyList(LinkedList *L)
{
	Node *tmp;			/* ��ʱ������� */
	
	/* �ͷ����н�� */
	while (	L->head != NULL )		/* ��ͷ���ΪNULLʱ����ѭ�� */
	{
		tmp = L->head;
		L->head = L->head->next;	/* ��һ����� */
		free(tmp);
	}

	/* �ͷű� */
	free(L);
}


/* ---------------------------------------------------*/
/* ���������ڲ�������ʵ�ֵĻ�����������             */
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
