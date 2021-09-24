#include<iostream>
#include<new>
#include<cstdlib>
#include<malloc.h>
using namespace std;

//5����������
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

//���Գ��򳤶ȶ���
#define LONGTH 5

//���Ͷ���
typedef int Status;
typedef int ElemType;

struct SqStack
{
    ElemType *base;//��ַָ��

    int top;      //ָ��ջ��
    int size;
    int increment;
};

//��ʼ��˳��ջ
Status InitStack(SqStack &s, int size, int inc){
    s.base = new(nothrow) ElemType[size];//����һ������size��С��ָ�����飬���ڴ�����ݵ�ַ
    if(s.base == NULL)
        return OVERFLOW;
    s.top = 0;
    s.size = size;
    s.increment = inc;
    return OK;
}

//����˳��ջ(��˳�����ͬ���ѻ�ַָ��ҿռ���)
Status DestoryStack(SqStack &s){
    delete s.base;
    s.base = NULL;
    return OK;
}

//�ж�ջ�Ƿ�Ϊ��
Status IsEmpty(SqStack s){
    if(s.top == 0)
        return true;
    else
        return false;
}

//���ջ
void ClearStack(SqStack &s){
    if(s.top == 0)
        return;
    s.size = 0;
    s.top = 0;
}

//��Ԫ��eѹ��ջs�������ջ�ڴ治����������ʱ����Ҫ�¿���һ��size��ԭ������ڴ棬�����µ�Ԫ�ز���
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

//ջs��ջ��Ԫ�س�ջ������e����
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

    cout<<"--��˳��ջ��--\n";
    cout<<"ջs��sizeΪ��"<<size<<"\nջs��incrementΪ��"<<incremnt<<endl;
    cout<<"����Ԫ��Ϊ��";
    for(i = 0; i < LONGTH; i++)
    {
        cout<<eArray[i]<<" ";
    }

    cout<<endl;

    //��ʼ��˳��ջ
    if(!InitStack(s, size, incremnt)){
        cout<<"ջ��ʼ��ʧ�ܣ�\n";
        exit(0);
    }
    cout<<"ջ��ʼ���ɹ���\n";

    //��ջ
    for(i = 0; i < LONGTH; i++)
    {
        if(!Push_back(s,eArray[i])){
            cout<<eArray[i]<<"��ջʧ��!\n";
            exit(0);
        }
    }
    cout<<"��ȫ����ջ��";

    //�ж�ջ�Ƿ�Ϊ��
    if(IsEmpty(s))
        cout<<"ջΪ�գ�\n";
    else
        cout<<"ջ��Ϊ�գ�\n";

    cout<<"ջ��Ԫ��Ϊ��";
    for(i = 0 , e = 0;i < s.size ; i++)
    {
        cout<< Pop(s, e);
        cout<<" ";
    }

    system("pause");
    return 0;
    
}