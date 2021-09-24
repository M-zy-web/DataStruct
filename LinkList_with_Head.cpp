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
    LNode *p, *q; //p是用来指向当前节点的指针，q是用来指向新节点的指针
    //L开始只是一个指向节点的指针，没有指向任何地址
    int i = 0;

    if (n < 0)
        return ERROR;
    p = L = NULL; //L是头结点

    q = new (nothrow) LNode;
    if (q == NULL)
        return ERROR;
    q->next = NULL;
    p = L = q; //q是第一个节点

    for (i = 0; i < n; i++)
    {
        LNode *q = new (nothrow) LNode; //(nothrow)保证能够提供内存

        if (q == NULL)
            return OVERFLOW;
        q->date = date[i];
        q->next = NULL;
        p->next = q;
        p = q;
    }

    return OK;
}

//e节点尾部插入链表
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

//取出链表首节点到e
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

//访问节点数据
Status visit(ElemType e)
{
    cout << e << " ";
    return OK;
}

//遍历链表
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

    //测试显示值
    cout << "【链表测试】" << endl;
    cout << "测试值：";
    for (i = 0; i < LONGTH; i++)
    {
        cout << date[i] << "\t";
    }
    cout << endl;

    cout << "创建链表：";
    if (ERROR == Create(L, date, 5))
        cout << "链表创建失败!" << endl;
    else
        cout << "链表创建成功" << endl;
    cout << endl;

    //遍历单链表
    cout << "链表中的元素为：";
    ListTravel(L, visit);
    cout << endl;

    system("pause");
    return 0;
}