#include<iostream>
#include<cstdlib>
#include<new>
using namespace std;
//˳����൱�����飬��һ��ͷָ�룬�Ϳ�����ͷָ��[]��ʽ�����ʽڵ������
//5����������
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

//���Գ��򳤶ȶ���
#define LONGTH 5

typedef int ElemType;
typedef int Status;

struct SqList
{
    ElemType *elem;//�洢�ռ��ַ
	int length;
	int size;
	int increment;//����
};

//��ʼ��
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

//����˳���(����ַָ��ҿ�)
Status Destory_SqList(SqList &L)
{
    delete L.elem;
    L.elem = NULL;
    return OK;
}

//��˳������
Status Clear_SqList(SqList &L)
{
    if(L.length != 0)
        L.length = 0;
    return OK;
}

//�ж�˳����Ƿ�Ϊ�ձ�
Status Is_SqList_Empty(SqList &L)
{
    if(L.length == 0)
        return true;
    return false;
}

//���ص�i��Ԫ��
Status Return_i(SqList L, int i, ElemType &e)
{
    e = L.elem[i];
    return OK;
}

//��˳����в���Ԫ��e��һ�γ��ֵ�λ��
int Search_e(SqList L, ElemType e)
{
    int i = 0;
    while(L.elem[i] != e && i < L.length)
        i++;
    if(i < L.length)
        return i;
    return OVERFLOW;
}

//��������
Status visit(ElemType e)
{
    cout<< e <<" ";
    return OK;
}

//����˳�����ÿ��Ԫ��ʹ��һ��visit
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

//��˳����i��Ԫ�ظ�ֵΪe
Status PutElem_Sq(SqList &L, int i, ElemType e)
{
    if(i > L.length)
        return ERROR;
    e = L.elem[--i];
    return OK;
}

//��˳���L��β���Ԫ��e
Status Append_Sq(SqList &L, ElemType e)
{
    if(L.length >= L.size)
        return ERROR;
    L.elem[L.length] = e;
    L.length++;
    return OK;
}

//ɾ��˳���L�ı�βԪ�أ����ò���e������ֵ
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

    cout<<"---��˳���---\n";
    cout<<"��L��sizeΪ"<<size<<" ��L��incrementΪ��"<<increment<<endl;
    cout<<"����Ԫ�أ�";
    for(i = 0;i < LONGTH; i++)
    {
        cout<<eArray[i];
    }
    cout<<endl;

    //��ʼ��˳���
    if(!Ini_SqList(L, size, increment))
    {
        cout<<"��ʼ������ʧ��!";
        exit(0);
    }
    cout<<"��ʼ������ɹ���\n";

    system("pause");
    return 0;
}