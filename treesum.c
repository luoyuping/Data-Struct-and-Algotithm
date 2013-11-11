#include<stdio.h>    
#include<stdlib.h>    
#include<malloc.h>   
  
#define MaxSize 100   //该定义服务于创建循环队列  
typedef int TElemType;  
TElemType Nil=0; // 整型以0为空  
  
typedef struct BiTNode  
{  
    TElemType data;  
    BiTNode *lchild,*rchild; // 左右孩子指针  
}BiTNode,*BiTree;  
  
// 按先序次序输入二叉树中结点的值（可为字符型或整型，在主程中  
// 定义），构造二叉链表表示的二叉树T。变量Nil表示空（子）树。  
void CreateBiTree(BiTree &T)  
{   
   TElemType ch;  
   scanf("%d",&ch);  
   if(ch==Nil) // 空  
      T=NULL;  
   else  
   {  
      T=(BiTree)malloc(sizeof(BiTNode));  
      T->data=ch; // 生成根结点  
      CreateBiTree(T->lchild); // 构造左子树  
      CreateBiTree(T->rchild); // 构造右子树  
   }  
}  
  
// 初始条件: 二叉树T存在,Visit是对结点操作的应用函数。  
// 操作结果: 先序递归遍历T,对每个结点调用函数Visit一次且仅一次  
void PreOrderTraverse(BiTree T,void(*Visit)(TElemType))  
{  
    if(T) // T不空  
    {  
        Visit(T->data); // 先访问根结点  
        PreOrderTraverse(T->lchild,Visit); // 再先序遍历左子树  
        PreOrderTraverse(T->rchild,Visit); // 最后先序遍历右子树  
    }  
}  
  
// 初始条件: 二叉树T存在,Visit是对结点操作的应用函数  
// 操作结果: 中序递归遍历T,对每个结点调用函数Visit一次且仅一次  
void InOrderTraverse(BiTree T,void(*Visit)(TElemType))  
{     
    if(T)  
    {  
        InOrderTraverse(T->lchild,Visit); // 先中序遍历左子树  
        Visit(T->data); // 再访问根结点  
        InOrderTraverse(T->rchild,Visit); // 最后中序遍历右子树  
    }  
}  
  
/*PreOrderTraverse调用的visit函数*/  
void visit(TElemType c)  
{  
    printf("%d ",c);  
}  
  
/*1.统计二叉树总节点的个数*/  
/* 参数：T：二叉树根结点指针，n：传入的整数记录总结点个数*/  
void getAllNum(BiTree T, int &n)  
{  
    if(T!=NULL)   //如果树不为空  
    {  
        n=n+1;  
        getAllNum(T->lchild,n);     //左子树结点个数  
        getAllNum(T->rchild,n);     //右子树结点个数  
    }  
    else  
    {  
        return;  
    }     
}  
  
/*2.统计二叉树度为1节点个数*/  
/* 参数：T：二叉树根结点指针，n：传入的整数记录度为1结点个数*/  
void OneDegree(BiTree T, int &n)  
{  
    if (!T) return;  
    else if (T->lchild && !T->rchild)   //如果有左子树，没有右子树  
    {  
        n++;                            //个数加1  
        OneDegree(T->lchild,n);         //递归左子树  
    }  
    else if (!T->lchild && T->rchild)   //如果没有左子树，有右子树  
    {  
        n++;                            //个数加1  
        OneDegree(T->rchild,n);         //递归右子树  
    }  
    else  //(T->lchild && T->rchild) || (!T->lchild && !T->rchild)  
    {  
        //如果左右都有子树或左右都无子树，则左右都递归;  
        OneDegree(T->lchild,n);   
        OneDegree(T->rchild,n);  
    }     
      
}  
  
/*3.统计二叉树度为2节点个数*/  
/* 参数：T：二叉树根结点指针，n：传入的整数记录度为2结点个数*/  
void TwoDegree(BiTree T, int &n)  
{  
    if(!T) return;  
    //如果结点左右子树都有，则记录加1，并且递归左右子树  
    else if(T->lchild && T->rchild)     
    {  
        n++;  
        TwoDegree(T->lchild,n);  
        TwoDegree(T->rchild,n);  
    }  
    //否则不加1，但也递归左右子树  
    else  
    {  
        TwoDegree(T->lchild,n);  
        TwoDegree(T->rchild,n);  
    }  
}  
  
/*4.统计二叉树度为0（叶子节点）节点个数*/  
/* 参数：T：二叉树根结点指针，n：传入的整数记录度为0结点个数*/  
void ZeroDegree(BiTree T, int &n)  
{  
    if(!T) return;  
    //如果结点无左右子树，则记录加1，并递归左右子树  
    else if(!T->lchild && !T->rchild)  
    {  
        n++;  
        ZeroDegree(T->lchild,n);  
        ZeroDegree(T->rchild,n);  
    }  
    //否则不加1，但也递归左右子树  
    else  
    {  
        ZeroDegree(T->lchild,n);  
        ZeroDegree(T->rchild,n);  
    }  
  
}  
  
/*5求二叉树高度*/  
/*思路就是左子树的高度和右子树的高度相比，大的那一项加1*/  
  
//比较两数大小函数，输出大数  
int max(int m, int n)  
{  
    return m>n ? m:n;  
}  
  
int TreeHeigh(BiTree T)  
{  
    if(!T)   
    {  
        return 0;  
      
    }  
    else  
    {  
        /*经过递归得到左右子树高度相比更高的数加1*/  
        return 1 + max(TreeHeigh(T->lchild),TreeHeigh(T->rchild));  
    }  
}  
  
/*6.交换左右子树*/  
/*交换左右子树意思是每个结点的左右子树交换*/  
/*思路：如果结点无左右子树不交换，否则交换。然后利用递归访问结点的左子树或右子树*/  
void exchange(BiTree T)  
{  
    BiTree temp;  
    if(!T->lchild && !T->rchild)   //结点无左右子树  
    {  
        return;  
      
    }  
    else              //否则只要有一个子树，则左右交换  
    {  
        temp = T->lchild;  
        T->lchild = T->rchild;  
        T->rchild = temp;  
    }  
  
    if(T->lchild)   //有左子树时递归左子树  
    {  
        exchange(T->lchild);  
    }  
    if(T->rchild)   //有右子树时递归右子树  
    {  
        exchange(T->rchild); 
     }  
}  
  
/*7.复制一颗二叉树*/  
/*复制一颗于原二叉树完全相同的树*/  
BiTree CopyTree(BiTree T)  
{     
    if(!T) return NULL;  //当结点为空时返回  
    else  
    {  
        /*首先申请一个结点，值为原树对应结点的值*/  
        BiTNode* newNode = (BiTNode*)malloc(sizeof(BiTNode));  
        newNode->data = T->data;  
        /*然后新结点的左子树继续递归复制原树对应结点的左子树*/  
        newNode->lchild = CopyTree(T->lchild);  
        /*然后新结点的右子树继续递归复制原树对应结点的右子树*/  
        newNode->rchild = CopyTree(T->rchild);  
  
        return newNode;  
    }  
}  
  
/*8判断两二叉树是否相等*/  
/*二叉树相等的概念是对应的左右子树相同，且结点内值相同*/  
/*经过一系列递归就可以判断两二叉树是否相等*/  
bool EqualTree(BiTree Tree1, BiTree Tree2)  
{  
    bool flag = true;  
    /*结点都为空时则相同*/  
    if(!Tree1&&!Tree2)  
    {  
        return flag;  
    }  
    /*一个结点为空，一个结点不为空这不相同*/  
    else if(!Tree1||!Tree2)  
    {  
        return !flag;  
    }  
    else  
    {  
        /*结点值相同时*/  
        if(Tree1->data == Tree2->data)  
        {  
            flag = true;  
        }  
        else  
        {  
            flag = false;  
        }  
  
        /*一对结点判断则需要递归判断两个结点的左子树，右子树是否相等*/  
        flag = EqualTree(Tree1->lchild,Tree2->lchild);  
        flag = EqualTree(Tree1->rchild,Tree2->rchild);  
  
        return flag;  
    }  
}  
  
/*9判断两二叉树是否相似*/  
/*与相等类似，则不需要判断结点内部值是否相等*/  
bool isSimilar(BiTree Tree1, BiTree Tree2)  
{  
    bool flag = true;  
    if(!Tree1&&!Tree2)  
    {  
        return flag;  
    }  
    else if(!Tree1||!Tree2)  
    {  
        return !flag;  
    }  
    else  
    {     
        flag = isSimilar(Tree1->lchild,Tree2->lchild);  
        flag = isSimilar(Tree1->rchild,Tree2->rchild);  
  
        return flag;  
    }  
}  
  
/*10.在二叉树中查找X*/  
/*同样采用递归，先判断左子树是否有，在判断右子树是否有*/  
/*递归终止条件就是找到一个结点内的值等于X*/  
BiTNode* Select(BiTree T,TElemType x)  
{     
    BiTNode* p;  
    if(T) // T不空  
    {  
        if(T->data == x)  
        {  
            return T;  
        }  
  
        if(T->lchild)  
        {  
            p = Select(T->lchild,x);   
        }  
  
        if(T->rchild)  
        {  
            p = Select(T->rchild,x);   
        }  
    }  
  
    return NULL;  
}  
  
/*11.按层次结构输出二叉树*/  
/*按层次结构输出二叉树需要用到循环队列。*/  
void LevelOrder(BiTree T)  
{  
    BiTNode *p;  
    BiTNode *qu[MaxSize];   //定义循环队列存放结点指针  
  
    int front, rear;   //定义队列头尾标示  
  
    front = rear = -1; //置队列为空  
  
    rear++;  
    qu[rear] = T;  //根结点入队  
  
    while(front!=rear)   //如果队列不空  
    {  
        front = (front+1)%MaxSize;  //front移动  
        p = qu[front];              //取出该位置的结点指针  
        printf("%d ",p->data);  
  
        if(p->lchild)  
        {  
            rear = (rear+1)%MaxSize;  
            qu[rear] = p->lchild;  
        }  
  
        if(p->rchild)  
        {  
            rear = (rear+1)%MaxSize;  
            qu[rear] = p->rchild;  
        }  
    }  
  
    printf("\n");  
}  
  
/*12.求二叉树宽度*/  
int getWidth(BiTree T)  
{  
    BiTree q[MaxSize];  
    int front=-1,rear=-1; //初始化一个队列  
    int flag=0,count=0,p;  
    /* p用于指向树中层的最右边的结点，标志flag记录层中结点数的最大值。*/  
    if(T!=NULL)  
    {  
        rear++;  
        q[rear]=T;    //根节点入队  
        flag=1;  
        p=rear;  
    }  
    while(front<p)  
    {  
        front++;  
        T=q[front];  
        if(T->lchild!=NULL)  
        {  
            rear++;  
            q[rear]=T->lchild;   //左子节点入队  
            count++;  
        }  
        if(T->rchild!=NULL)  
        {  
            rear++;  
            q[rear]=T->rchild;   //右子节点入队  
            count++;  
        }  
        if(front==p)  
        /* 当前层已遍历完毕*/  
        {  
            if(flag<count)  
            flag=count;  
            count=0;  
            p=rear;              /*p指向下一层最右边的结点*/    
        }  
    }  
    /* endwhile*/  
    return flag;  
}  
  
  
void main()  
{  
    int allNum = 0;              //总结的个数  
    int oneDegree = 0;           //度为1结点个数  
    int twoDegree = 0;           //度为2结点个数  
    int zeroDegree = 0;          //度为0结点个数  
    //声明两个二叉树  
    BiTree t, m, s;  
    //按先序分别输入二叉树t,m中的值，构建二叉树  
    printf("按先序次序输入二叉树T中结点的值,空指针用0表示\n");  
    CreateBiTree(t);  
    printf("按先序次序输入二叉树M中结点的值,空指针用0表示\n");  
    CreateBiTree(m);  
  
    printf("按先序次序输出二叉树 T\n");  
    PreOrderTraverse(t,visit);        //先序输出  
    printf("\n");  
  
    printf("按先序次序输出二叉树 M\n");  
    PreOrderTraverse(m,visit);        //先序输出  
    printf("\n");  
  
    //总结点个数  
    getAllNum(t,allNum);  
    printf("二叉树T，总节点个数 = %d \n",allNum);  
  
    //度为1结点个数  
    OneDegree(t,oneDegree);  
    printf("二叉树T，度为1节点个数 = %d \n",oneDegree);  
  
    //度为2结点个数  
    TwoDegree(t,twoDegree);  
    printf("二叉树T，度为2节点个数 = %d \n",twoDegree);  
  
    //度为0结点个数  
    ZeroDegree(t,zeroDegree);  
    printf("二叉树T，度为2节点个数 = %d \n",zeroDegree);  
  
    //二叉树t的高度  
    int heigh = TreeHeigh(t);  
    printf("二叉树T的高度为:%d \n",heigh);  
  
    //交换左右子树，此时原二叉树t改变  
    exchange(t);  
    printf("交换左右子树后，按先序次序输出二叉树T'\n");  
    PreOrderTraverse(t,visit);  
    printf("\n\n");  
  
    //复制一个二叉树t，此时复制的二叉树为左右子树交换后的二叉树t'  
    s = CopyTree(t);  
    printf("按先序次序输出二叉树S \n");  
    PreOrderTraverse(s,visit);  
    printf("\n\n");  
  
    //判断二叉树t,m是否相等，  
    if(EqualTree(t,m))  
    {  
        printf("T, M两二叉树相等\n");  
    }  
    else  
    {  
        printf("T, M两二叉树不相等\n");  
    }  
    printf("\n");  
  
    //判断两二叉树t,s是否相似，由于s为t交换后复制过来的二叉树，则与t相似  
    if(isSimilar(t,s))  
    {  
        printf("T, S两二叉树相似\n");  
    }  
    else  
    {  
        printf("T, S两二叉树不相似\n");  
    }  
    printf("\n");  
  
    //查找二叉树t中X结点,参数8为要找的值  
    BiTNode* p = Select(t,8);  
    //如果找到的话，p就不为空  
    if(p!=NULL)  
    {  
        printf("从二叉树T中查找8成功\n");  
    }  
    else  
    {  
        printf("从二叉树T中查找8失败\n");  
    }  
    printf("\n");  
  
    //按层次序列输出二叉树M  
    printf("按层次结构输出二叉树M\n");  
    LevelOrder(m);  
    printf("\n");  
  
    //打印二叉树M的宽度  
    printf("二叉树宽度M的宽度为:%d \n",getWidth(m));  
  
}  