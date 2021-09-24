#include<iostream>
#include<new>
#include<cstdlib>
#include<malloc.h>
using namespace std;

//5个常量定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

//测试程序长度定义
#define LONGTH 5

//类型定义
typedef int Status;
typedef int ElemType;

struct SqStack
{
    ElemType *base;//基址指针

    int top;      //指向栈顶
    int size;
    int increment;
};

//初始化顺序栈
Status InitStack(SqStack &s, int size, int inc){
    s.base = new(nothrow) ElemType[size];//开辟一个具有size大小的指针数组，用于存放数据地址
    if(s.base == NULL)
        return OVERFLOW;
    s.top = 0;
    s.size = size;
    s.increment = inc;
    return OK;
}

//销毁顺序栈(与顺序表相同，把基址指针挂空即可)
Status DestoryStack(SqStack &s){
    delete s.base;
    s.base = NULL;
    return OK;
}

//判断栈是否为空
Status IsEmpty(SqStack s){
    if(s.top == 0)
        return true;
    else
        return false;
}

//清空栈
void ClearStack(SqStack &s){
    if(s.top == 0)
        return;
    s.size = 0;
    s.top = 0;
}

//将元素e压入栈s，会出现栈内存不足的情况，此时就需要新开辟一个size比原来大的内存，供给新的元素插入
Status Push_back(SqStack &s, ElemType e){
    ElemType *newbase;
    if(s.top >= s.size)
    {
        newbase = (ElemType *)realloc(s.base,(s.size+s.increment)*sizeof(ElemType));
        if(newbase == NULL)
            return OVERFLOW;
        s.base = newbase;
        s.size += s.increment;
    }

    s.base[s.top++] = e;

    return OK;
}

//栈s的栈顶元素出栈，并用e返回
Status Pop(SqStack &s, ElemType &e){
    if(s.size < s.top)
        return OVERFLOW;
    e = s.base[--s.top];
    return e;
}

int main(){
    SqStack s;

    int size, incremnt, i;

    size = LONGTH;
    incremnt = LONGTH;
    ElemType e, eArray[LONGTH] = {1,2,3,4,5};

    cout<<"--【顺序栈】--\n";
    cout<<"栈s的size为："<<size<<"\n栈s的increment为："<<incremnt<<endl;
    cout<<"待测元素为：";
    for(i = 0; i < LONGTH; i++)
    {
        cout<<eArray[i]<<" ";
    }

    cout<<endl;

    //初始化顺序栈
    if(!InitStack(s, size, incremnt)){
        cout<<"栈初始化失败！\n";
        exit(0);
    }
    cout<<"栈初始化成功！\n";

    //入栈
    for(i = 0; i < LONGTH; i++)
    {
        if(!Push_back(s,eArray[i])){
            cout<<eArray[i]<<"入栈失败!\n";
            exit(0);
        }
    }
    cout<<"已全部入栈！";

    //判断栈是否为空
    if(IsEmpty(s))
        cout<<"栈为空！\n";
    else
        cout<<"栈不为空！\n";

    cout<<"栈内元素为：";
    for(i = 0 , e = 0;i < s.size ; i++)
    {
        cout<< Pop(s, e);
        cout<<" ";
    }

    system("pause");
    return 0;
    
}