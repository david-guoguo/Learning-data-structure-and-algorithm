#include <stdio.h>

#define   MAXSIZE   15 
#define   BLOCK   4 

typedef   struct
{
	int   key; 
	int   link; 
}indexelement; 

typedef   struct
{
	int   key; 
	float   info; 
}element; 
typedef   indexelement   indextype[BLOCK]; 
typedef   element   sqlist[MAXSIZE]; 

/* --------------------------------------------------- */
/* 分块查找算法                                        */
/* 参数：sqlist   r  主表		   					   */
/* indextype   index 索引表		   					   */
/* int   block 块数		   							   */
/* int   key 要查找的关键字		   					   */				
/* 返回值：int 查找到的关键字下标                      */
/* ----------------------------------------------------*/
int BlockingSearch(sqlist   r, indextype   index,int   block, int   key) 
{ 
	int   i; 
	i=index[block].link; 

	while(key!=r[i].key&&key <=index[block].key)   
		i++; 
	if(key!=r[i].key)   
		i=0; 
	return i ; 
} 

/* --------------------------------------------------- */
/* 主程序                                              */
/* --------------------------------------------------- */
main() 
{ 
	int   i,j,key; 
	sqlist   table; 
	indextype   index; 

	printf( "请输入数据(0-%d):\n",MAXSIZE); 
	for(i=0;i <=MAXSIZE;i++) 
    { 
		scanf( "%d",&j); 
		table[i].key=j; 
	} 
	
	printf( "请输入%d个分块起始位置\n",BLOCK); 
	for(i=0;i <=BLOCK-1;i++) 
    { 
		scanf( "%d",&j); 
		if(j <0 || j> MAXSIZE) 
		{ 
            printf( "block ERRORS! "); 
            exit(0); 
		} 
        index[i].link=j; 
	} 
	printf( "请输入%d个分块中的最大关键字\n",BLOCK); 
	for(i=0;i <=BLOCK-1;i++) 
    { 
		scanf( "%d",&j); 
		index[i].key=j; 
	} 
	printf( "请输入要查找的关键字\n"); 
	scanf( "%d",&key); 

	i=0; 
	while(key> index[i].key&&i <BLOCK-1)   
		i++; 

	if(i>= BLOCK)   
		printf( "not   fount\n"); 
	else 
	{ 
		j=BlockingSearch(table,index,i,key); 
		if(j==0)
			printf( "not   fount\n"); 
		else
			printf( "查找到的关键字下标为：%d\n ",j); 
	} 
}