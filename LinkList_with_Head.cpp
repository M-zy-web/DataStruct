#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;
typedef int ElemType;

#define LONGTH 5

typedef struct LNode
{
    ElemType date;
    LNode *next;
} LNode, *LinkList;

Status Create(LinkList &L, ElemType *date, int n)
{
    LNode *p, *q; //p������ָ��ǰ�ڵ��ָ�룬q������ָ���½ڵ��ָ��
    //L��ʼֻ��һ��ָ��ڵ��ָ�룬û��ָ���κε�ַ
    int i = 0;

    if (n < 0)
        return ERROR;
    p = L = NULL; //L��ͷ���

    q = new (nothrow) LNode;
    if (q == NULL)
        return ERROR;
    q->next = NULL;
    p = L = q; //q�ǵ�һ���ڵ�

    for (i = 0; i < n; i++)
    {
        LNode *q = new (nothrow) LNode; //(nothrow)��֤�ܹ��ṩ�ڴ�

        if (q == NULL)
            return OVERFLOW;
        q->date = date[i];
        q->next = NULL;
        p->next = q;
        p = q;
    }

    return OK;
}

//e�ڵ�β����������
Status Insert_rear(ElemType &e, LinkList &L)
{
    LinkList p, q;

    if (NULL == (q = new (nothrow) LNode))
        return OVERFLOW;
    q->date = e;
    q->next = NULL;
    if (L == NULL)
    {
        L = new (nothrow) LNode;
        if (L == NULL)
            return OVERFLOW;
        L->next = q;
    }
    else
    {
        p = L;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = q;
    }
    return OK;
}

//ȡ�������׽ڵ㵽e
Status Del_front(LinkList &L, ElemType &e)
{
    if (L == NULL || L->next == NULL)
        return ERROR;
    LinkList p;
    p = L->next;
    e = p->date;
    L->next = p->next;
    delete (p);
    return OK;
}

//���ʽڵ�����
Status visit(ElemType e)
{
    cout << e << " ";
    return OK;
}

//��������
Status ListTravel(LinkList &L, Status (*visit)(ElemType e))
{
    if (L == NULL)
        return ERROR;
    else
    {
        for (LinkList p = L->next; p != NULL; p = p->next)
        {
            visit(p->date);
        }
    }
}
int main()
{
    LinkList L;

    int i;
    ElemType date[LONGTH] = {1, 2, 3, 4, 5};

    //������ʾֵ
    cout << "��������ԡ�" << endl;
    cout << "����ֵ��";
    for (i = 0; i < LONGTH; i++)
    {
        cout << date[i] << "\t";
    }
    cout << endl;

    cout << "��������";
    if (ERROR == Create(L, date, 5))
        cout << "������ʧ��!" << endl;
    else
        cout << "�������ɹ�" << endl;
    cout << endl;

    //����������
    cout << "�����е�Ԫ��Ϊ��";
    ListTravel(L, visit);
    cout << endl;

    system("pause");
    return 0;
}