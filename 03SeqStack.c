#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define Stack_Init_Size 100

typedef int elemttype;		/*elemttype类型根据实际情况而定，这里假设为int*/

typedef struct
{     
	elemttype elemt[Stack_Init_Size];    	/*用来存放栈中元素的一维数组*/
	int top;                        	/*用来存放栈顶元素的下标*/
}
SeqStack; 

/* --------------------------------------------------- */
/* 初始化栈                                                       */
/* 参数：SeqStack *S  需要初始化的栈S                          */
/* 返回值：int 是否初始化成功                                    */
/* ----------------------------------------------------*/
SeqStack * InitStack()
{ 
	/* 分配内存 */
	int i;
	SeqStack * S = (SeqStack *)malloc(sizeof(SeqStack));
	if(!S)
	{
		return NULL;
	}

	/* 初始化内存 */
	S->top = 0;
	for(i=0; i<Stack_Init_Size; i++){
		S->elemt[i] = 0;
	}
	
	return S; 
}


/* --------------------------------------------------- */
/* 在S栈中插入元素e，成功返回真，失败返回假                     */
/* 参数：SeqStack *S  需要操作的栈S                            */
/* elemttype e  需要进栈的元素                                   */
/* 返回值：int 是否成功                                          */
/* ----------------------------------------------------*/
int PushStack(SeqStack *S, elemttype *e)
{  
	if(S->top >= Stack_Init_Size)  
		return FAILURE;			/* 栈满不能插入元素，返回假 */

	S->elemt[S->top] = *e;
	S->top++;
	return SUCCESS;				/* 成功将元素入栈，返回真 */
}



/* --------------------------------------------------- */
/* 栈S的栈顶出栈，出栈元素存放e中                              */
/* 参数：SeqStack *S  需要操作的栈S                            */
/* elemttype e  出栈元素                                        */
/* 返回值：int 是否成功                                          */
/* ----------------------------------------------------*/
int PopStack(SeqStack *S, elemttype *e)
{  
	if(S->top == 0) return FAILURE; 	/*栈为空，返回假值*/
	else
	{  
		S->top--;                 			/*修改栈顶指针*/
		*e= S->elemt[S->top];
		return SUCCESS;                	/*成功出栈，返回真值*/
	}
}


/* --------------------------------------------------- */
/* 取出栈S的栈顶元素存放e中                                    */
/* 参数：SeqStack *S  需要操作的栈S                            */
/* elemttype e  取出的栈顶元素                                  */
/* 返回值：int 是否成功                                          */
/* ----------------------------------------------------*/
int GetTop(SeqStack *S, elemttype *e)	
{  
	if(S->top==0) return FAILURE;    		 
	else 
	{
		*e = S->elemt[S->top-1];    		/*取栈顶数据，存放在e中*/
		return SUCCESS;
	}
}


/* --------------------------------------------------- */
/*返回栈中当前元素的个数                                          */
/* 参数：SeqStack *S  需要操作的栈S                            */
/* 返回值：int 元素个数                                          */
/* ----------------------------------------------------*/
int Stacklength(SeqStack *S)          	
{  
	return S->top;
}


/* ---------------------------------------------------*/
/* 主程序，用于测试所有实现的基本操作函数             */
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