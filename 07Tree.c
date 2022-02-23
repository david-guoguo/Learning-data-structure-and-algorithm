#include <stdio.h>
#include <stdlib.h>

#define dep 3			/* 定义树的度 */
#define STACKMAXSIZE 10	/* 定义在建立树的存储结构时的栈空间大小 */
#define QUEUEMAXSIZE 10	/* 定义在树的按层遍历算法中的队列空间大小 */

typedef char ElemtType;	/* ElemtType类型根据实际情况而定，这里假设为char */

struct GTreeNode{
    ElemtType data;
    struct GTreeNode *t[dep];
    struct GTreeNode *parent;
};

/* --------------------------------------------------- */
/* 创建树										   	   */
/* 参数：struct GTreeNode* *gt 树指针				   */
/* char *a 树广义表字符串							   */
/* 返回值：空                                          */
/* ----------------------------------------------------*/
void CreateTree(struct GTreeNode* *gt, char *a)
{
	/* 数组s作为存储树中结点指针的栈使用 */    
    struct GTreeNode *s[STACKMAXSIZE];	

	/* 数组d作为存储孩子结点链接到双亲结点指针域的序号栈使用 */
    int d[STACKMAXSIZE];	
    int top = -1;		/* top作为两个栈的栈顶指针，初值为-1表示栈空 */
    struct GTreeNode *p;/* 定义p为指向树结点的指针 */
    int i = 0, j;		/* i指示扫描字符串a中的当前字符位置 */
    *gt = NULL;			/* 初始将树根指针置空 */
    
    while(a[i] != '\0'){  /* 每次循环处理一个字符，直到字符串结束为止 */
        switch(a[i]){
            /* 对空格不作处理 */
		case ' ':    
			break;

            /* 处理左括号时，让p指针进s栈，０进d栈，表明待扫描的孩子
			结点将被链接到s栈顶元素所指结点的第一个指针域*/
		case '(':
			top++;
			s[top] = p;
			d[top] = 0;
			break;

            /* 处理右括号时，让s和d退栈 */
		case ')':
			top--;
			break;

			/* 处理逗号时，让待读入的孩子的结点链接到s栈顶元素所指结点
			的下一个指针域*/
		case ',':
			d[top]++;
			break;

            /* 处理字符元素 */
		default:
			/* 根据a[i]字符生成新结点 */
			p = malloc(sizeof(struct GTreeNode));
			p->data = a[i];
			for(j = 0; j < dep; j++)
			{/* 用dep表示树的深度 */
				p->t[j] = NULL;        
			}
			
			if(NULL == *gt   )
			{
				*gt = p;        /* 使结点p成为树根 */
			}
			else
			{
				s[top]->t[d[top]] = p;/* 链接到双亲结点对应的指针域 */ 
			}
			break;
		}    
		i++;	/* 准备处理下一个字符 */
	}
    return;
}

/* --------------------------------------------------- */
/* 从树中查找值为x的结点元素						   */
/* 参数：struct GTreeNode *gt 树根结点指针             */
/* ElemtType x 需要查找的元素值						   */
/* 返回值：ElemtType *								   */
/* 若存在则返回元素存储地址，否则返回NULL			   */
/* ----------------------------------------------------*/
ElemtType *findTree(struct GTreeNode *gt, ElemtType x)
{
    /* 若树空则返回NULL */
    if(gt == NULL){
        return NULL;
	}else{
		ElemtType *p;
        int i;
        /* 若查找成功返回结点值域的地址 */
        if(gt->data == x){
            return &(gt->data);
		}
        /* 向每棵子树继续查找，返回得到的值域地址 */
        for(i = 0; i < dep; i++){
            if(p = findTree(gt->t[i], x)){
                return p;
			}
		}
        return NULL;        /* 查找不成功返回NULL */
	}
}

/* --------------------------------------------------- */
/* 求树的深度									   	   */
/* 参数：struct GTreeNode *gt 树根结点指针             */
/* 返回值：int 树深度                              	   */
/* ----------------------------------------------------*/
int TreeDepth(struct GTreeNode *gt)
{
    int i, max;
    /* 空树的深度为0 */
    if(gt == NULL){
        return 0;
	}
    /* 求非空树的深度，max的初值为0 */
	max = 0;
    for(i = 0; i < dep; i++){
        int d = TreeDepth(gt->t[i]);/* 计算出一棵子树的深度并赋值给d */
        if(d > max){
			max = d;
		}
	}
    return max + 1;        /* 返回非空树的深度，它等于各子树的最大深度加1 */
}

/* --------------------------------------------------- */
/* 清除树中所有结点，使之变为一棵空树  				   */
/* 参数：struct GTreeNode* *gt 树根结点指针            */
/* 返回值：空										   */
/* ----------------------------------------------------*/
void clearTree(struct GTreeNode* *gt)
{
    if(*gt != NULL){
        int i;
        for(i = 0; i < dep; i++){
			clearTree(&((*gt)->t[i]));
		}
		free(*gt);
        *gt = NULL;
	}
    return;
}

/* --------------------------------------------------- */
/* 先根遍历树	  								   	   */
/* 参数：struct GTreeNode *gt 树根结点指针             */
/* 返回值：空										   */
/* ----------------------------------------------------*/
void preRoot(struct GTreeNode *gt)
{
    int i;
    if(gt != NULL){
		printf("%c ", gt->data);	/* 访问根结点 */
        for(i = 0; i < dep; i++){
			preRoot(gt->t[i]);		/* 递归遍历每一棵子树 */
		}
	}
    return;
}

/* --------------------------------------------------- */
/* 后根遍历树	  								   	   */
/* 参数：struct GTreeNode *gt 树根结点指针             */
/* 返回值：空										   */
/* ----------------------------------------------------*/
void postRoot(struct GTreeNode *gt)
{
    int i;
    if(gt != NULL){
        for(i = 0; i < dep; i++){
			postRoot(gt->t[i]);	/* 递归遍历每一棵子树 */
		}
		printf("%c ", gt->data);	/* 访问根结点 */
	}
	
}

/* --------------------------------------------------- */
/* 层序遍历树	  								  	   */
/* 参数：struct GTreeNode *gt 树根结点指针             */
/* 返回值：空										   */
/* ----------------------------------------------------*/
void levelOrder(struct GTreeNode *gt)
{
    struct GTreeNode *p;
    int i;
    struct GTreeNode *q[QUEUEMAXSIZE];    /* 队列用的数组q，存放根结点 */
    int front = 0, rear = 0;
    /* 将整棵树的树根指针入队 */
    if(gt != NULL){
		rear = (rear + 1 % QUEUEMAXSIZE);
		q[rear] = gt;
	}
    /* 当队列非空时执行循环 */
    while(front != rear){
		front = (front + 1) % QUEUEMAXSIZE;        /*  */
        /* 删除队首元素，输出队首元素所指结点的值 */
		p = q[front];
		printf("%c ", p->data);
        /* 非空的孩子结点的指针依次进队 */
        for(i = 0; i < dep; i++){
            if(p->t[i] != NULL){
				rear = (rear + 1) % QUEUEMAXSIZE;
				q[rear] = p->t[i];
			}
		}
	}
    return;
}

/* --------------------------------------------------- */
/* 打印树的内容  							   		   */
/* 参数：struct GTreeNode *gt 树根结点             	   */
/* 返回值：空										   */
/* ----------------------------------------------------*/
void printTree(struct GTreeNode *gt)
{
    if(gt != NULL){
        int i;
		printf("%c", gt->data);
        /* 判断gt结点是否有孩子 */
        for(i = 0; i < dep; i++){
            if(gt->t[i] != NULL){
                break;
			}
		}
        /* 有孩子时才执行条件语句体的向下递归调用 */
        if(i < dep){
			printf("(");
			printTree(gt->t[0]);        /* 输出第一棵子树 */
            /* 输出其余各个子树 */
            for(i = 1; i < dep; i++){
				printf(",");
				printTree(gt->t[i]);
			}
			printf(")");
		}
	}
    return;
}

/* ---------------------------------------------------*/
/* 主程序，用于测试实现的基本操作函数			      */
/* ---------------------------------------------------*/
int main()
{
    char ch;
    struct GTreeNode *gt = NULL;
    char b[50];	/* 用于存入k叉树广义表的字符数组 */
	
	printf("输入一棵%d叉树的广义表字符串： ", dep);
	scanf("%s", b); /* 例如 a (b,c (d,e,f)) */
	
	CreateTree(&gt, b);
	printf("先根遍历：");
	preRoot(gt);
	printf(" ");

	printf("后根遍历：");
	postRoot(gt);
	printf(" ");

	printf("按层遍历：");
	levelOrder(gt);
	printf(" ");

	printf("按广义表的形式输出：");
	printTree(gt);
	printf(" ");

	printf("树的深度为：%d ", TreeDepth(gt));
	printf("输入待查找的字符：");
	scanf(" %c", &ch);

    if(findTree(gt, ch)){
		printf("查找成功！ ");
	}else{
		printf("查找失败！ ");
	}

	clearTree(&gt);
    return 0;
}
