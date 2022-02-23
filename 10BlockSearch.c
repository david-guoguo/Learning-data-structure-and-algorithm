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
/* �ֿ�����㷨                                        */
/* ������sqlist   r  ����		   					   */
/* indextype   index ������		   					   */
/* int   block ����		   							   */
/* int   key Ҫ���ҵĹؼ���		   					   */				
/* ����ֵ��int ���ҵ��Ĺؼ����±�                      */
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
/* ������                                              */
/* --------------------------------------------------- */
main() 
{ 
	int   i,j,key; 
	sqlist   table; 
	indextype   index; 

	printf( "����������(0-%d):\n",MAXSIZE); 
	for(i=0;i <=MAXSIZE;i++) 
    { 
		scanf( "%d",&j); 
		table[i].key=j; 
	} 
	
	printf( "������%d���ֿ���ʼλ��\n",BLOCK); 
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
	printf( "������%d���ֿ��е����ؼ���\n",BLOCK); 
	for(i=0;i <=BLOCK-1;i++) 
    { 
		scanf( "%d",&j); 
		index[i].key=j; 
	} 
	printf( "������Ҫ���ҵĹؼ���\n"); 
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
			printf( "���ҵ��Ĺؼ����±�Ϊ��%d\n ",j); 
	} 
}