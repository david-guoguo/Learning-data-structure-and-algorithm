#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define Stack_Init_Size 100

typedef int elemttype;		/*elemttype���͸���ʵ������������������Ϊint*/

typedef struct
{     
	elemttype elemt[Stack_Init_Size];    	/*�������ջ��Ԫ�ص�һά����*/
	int top;                        	/*�������ջ��Ԫ�ص��±�*/
}
SeqStack; 

/* --------------------------------------------------- */
/* ��ʼ��ջ                                                       */
/* ������SeqStack *S  ��Ҫ��ʼ����ջS                          */
/* ����ֵ��int �Ƿ��ʼ���ɹ�                                    */
/* ----------------------------------------------------*/
SeqStack * InitStack()
{ 
	/* �����ڴ� */
	int i;
	SeqStack * S = (SeqStack *)malloc(sizeof(SeqStack));
	if(!S)
	{
		return NULL;
	}

	/* ��ʼ���ڴ� */
	S->top = 0;
	for(i=0; i<Stack_Init_Size; i++){
		S->elemt[i] = 0;
	}
	
	return S; 
}


/* --------------------------------------------------- */
/* ��Sջ�в���Ԫ��e���ɹ������棬ʧ�ܷ��ؼ�                     */
/* ������SeqStack *S  ��Ҫ������ջS                            */
/* elemttype e  ��Ҫ��ջ��Ԫ��                                   */
/* ����ֵ��int �Ƿ�ɹ�                                          */
/* ----------------------------------------------------*/
int PushStack(SeqStack *S, elemttype *e)
{  
	if(S->top >= Stack_Init_Size)  
		return FAILURE;			/* ջ�����ܲ���Ԫ�أ����ؼ� */

	S->elemt[S->top] = *e;
	S->top++;
	return SUCCESS;				/* �ɹ���Ԫ����ջ�������� */
}



/* --------------------------------------------------- */
/* ջS��ջ����ջ����ջԪ�ش��e��                              */
/* ������SeqStack *S  ��Ҫ������ջS                            */
/* elemttype e  ��ջԪ��                                        */
/* ����ֵ��int �Ƿ�ɹ�                                          */
/* ----------------------------------------------------*/
int PopStack(SeqStack *S, elemttype *e)
{  
	if(S->top == 0) return FAILURE; 	/*ջΪ�գ����ؼ�ֵ*/
	else
	{  
		S->top--;                 			/*�޸�ջ��ָ��*/
		*e= S->elemt[S->top];
		return SUCCESS;                	/*�ɹ���ջ��������ֵ*/
	}
}


/* --------------------------------------------------- */
/* ȡ��ջS��ջ��Ԫ�ش��e��                                    */
/* ������SeqStack *S  ��Ҫ������ջS                            */
/* elemttype e  ȡ����ջ��Ԫ��                                  */
/* ����ֵ��int �Ƿ�ɹ�                                          */
/* ----------------------------------------------------*/
int GetTop(SeqStack *S, elemttype *e)	
{  
	if(S->top==0) return FAILURE;    		 
	else 
	{
		*e = S->elemt[S->top-1];    		/*ȡջ�����ݣ������e��*/
		return SUCCESS;
	}
}


/* --------------------------------------------------- */
/*����ջ�е�ǰԪ�صĸ���                                          */
/* ������SeqStack *S  ��Ҫ������ջS                            */
/* ����ֵ��int Ԫ�ظ���                                          */
/* ----------------------------------------------------*/
int Stacklength(SeqStack *S)          	
{  
	return S->top;
}


/* ---------------------------------------------------*/
/* ���������ڲ�������ʵ�ֵĻ�����������             */
/* ---------------------------------------------------*/
void main ()
{
	elemttype e1,e2;
	SeqStack *S = InitStack();
	
	e1=111;
	PushStack(S, &e1);
	printf("%d\n", Stacklength(S));
	
	
	GetTop(S,&e2);
	printf("%d\n", e2);
	printf("%d\n", Stacklength(S));
	
	PopStack(S,&e2);
	printf("%d\n", e2);
	printf("%d\n", Stacklength(S));	

}