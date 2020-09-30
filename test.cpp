#include<stdio.h>
#define maxSize 100
typedef int ElemType;
typedef struct LNode
{
    /* data */
    int data[maxSize]; //存储线性表数组
    int length; //定义线性表当前长度
}LNode;

void Init_Sqlist(LNode *L)
{
    L -> length = 0;
}

int Insert_Sqlist(LNode *L,int i,ElemType e) //向表L的i位置插入数据e
{
    //判断插入位置是否合理
    if(L -> length >= i - 1 && i > 0){
        int k;
        //依次向后挪位
        for(k = L -> length; k >= i; k --){
            L -> data[k] = L -> data[k - 1];
        }
        L -> data[k] = e;  //将e插入L
        L -> length ++; //线性表长度+1
        return 1;
    }
    else return 0; //已达最大长度，不能插入
}

int sqListDelete(LNode *L, int i, ElemType e){
    if(L -> length >= i && i > 0){
        int k;
        for(k = i; k <= L -> length; ++ k){
            L -> data[i - 1] = L -> data[i];
        }
        e = L -> data[i];
        L -> length --; //长度减一
        return 1;
    }
    else return 0; //i值不合法
}

int Locate_SqList(LNode *L, ElemType e)
{
    int i = 0;
    for(i;i < L -> length; ++i){
        if(L -> data[i] == e)
            break;
        i ++;

    }
    //判断是否存在
    if( i < L -> length)
    {
        return i + 1; //存在
    }
    else return 0; //不存在
}

void Display_SqList(LNode L) //显示线性表的元素
{
    int i;
    for(i = 0; i < L.length - 1;i ++){
        printf("%d  ", L.data[i]);
    }
    printf("%d\n", L.data[i]);
}
int main(){
    LNode  L,La,Lb,Lc;
    Init_Sqlist(&L);
    printf("List.....\n");
    printf("---------------\n");
    printf("Such as List: \n");
    Insert_Sqlist(&L,1,1);
    Insert_Sqlist(&L,2,2);
    Insert_Sqlist(&L,3,5);
    Insert_Sqlist(&L,4,3);
    Insert_Sqlist(&L,5,4);
    Display_SqList(L);
    printf("\n");
    printf("Please insert a element: \n");
    Insert_Sqlist(&L,3,21);
    Display_SqList(L);
    printf("\n");
    return 0;
}
