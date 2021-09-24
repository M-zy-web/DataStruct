#include<iostream>
#include<cstdlib>
#include<new>
using namespace std;
//顺序表相当于数组，有一个头指针，就可以用头指针[]方式来访问节点或内容
//5个常量定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

//测试程序长度定义
#define LONGTH 5

typedef int ElemType;
typedef int Status;

struct SqList
{
    ElemType *elem;//存储空间基址
	int length;
	int size;
	int increment;//增加
};

//初始化
Status Ini_SqList(SqList &L, int size, int inc)
{
    L.elem = new (nothrow) ElemType;
    if(L.elem == NULL)
        return OVERFLOW;
    L.length = 0;
    L.size = size;
    L.increment = inc;
    return OK;
}

//销毁顺序表(将基址指针挂空)
Status Destory_SqList(SqList &L)
{
    delete L.elem;
    L.elem = NULL;
    return OK;
}

//将顺序表清空
Status Clear_SqList(SqList &L)
{
    if(L.length != 0)
        L.length = 0;
    return OK;
}

//判断顺序表是否为空表
Status Is_SqList_Empty(SqList &L)
{
    if(L.length == 0)
        return true;
    return false;
}

//返回第i个元素
Status Return_i(SqList L, int i, ElemType &e)
{
    e = L.elem[i];
    return OK;
}

//在顺序表中查找元素e第一次出现的位置
int Search_e(SqList L, ElemType e)
{
    int i = 0;
    while(L.elem[i] != e && i < L.length)
        i++;
    if(i < L.length)
        return i;
    return OVERFLOW;
}

//遍历调用
Status visit(ElemType e)
{
    cout<< e <<" ";
    return OK;
}

//遍历顺序表，对每个元素使用一次visit
Status Travel_SqList(SqList L, Status(*visit)(ElemType e))
{
    if(L.length == 0)
        return OVERFLOW;
    for(int i = 0; i < L.length; i++)
    {
        visit(L.elem[i]);
    }
    return OK;
}

//将顺序表第i个元素赋值为e
Status PutElem_Sq(SqList &L, int i, ElemType e)
{
    if(i > L.length)
        return ERROR;
    e = L.elem[--i];
    return OK;
}

//在顺序表L表尾添加元素e
Status Append_Sq(SqList &L, ElemType e)
{
    if(L.length >= L.size)
        return ERROR;
    L.elem[L.length] = e;
    L.length++;
    return OK;
}

//删除顺序表L的表尾元素，并用参数e返回其值
Status DeleteLast_Sq(SqList &L, ElemType e)
{
    if(L.length == 0)
        return ERROR;
    e = L.elem[L.length-1];
    L.length--;
    return OK;
}

int main()
{
    SqList L;

    int size, increment, i;

    size = LONGTH;
    increment = LONGTH;
    ElemType e, eArray[LONGTH] = {1,2,3,4,5};

    cout<<"---【顺序表】---\n";
    cout<<"表L的size为"<<size<<" 表L的increment为："<<increment<<endl;
    cout<<"待测元素：";
    for(i = 0;i < LONGTH; i++)
    {
        cout<<eArray[i];
    }
    cout<<endl;

    //初始化顺序表
    if(!Ini_SqList(L, size, increment))
    {
        cout<<"初始化链表失败!";
        exit(0);
    }
    cout<<"初始化链表成功！\n";

    system("pause");
    return 0;
}