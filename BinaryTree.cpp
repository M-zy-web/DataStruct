#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define SUCCESS 1
#define UNSUCCESS 0
#define dataNum 5
int i = 0;
int deep = 0;
char date[dataNum] = {'A', 'B', 'C', 'D', 'E'};

typedef int Status;
typedef char TElemType;

//�ڵ�ṹ
typedef struct BiTNode
{
    TElemType date;
    BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//��ʼ��һ������
void InitBiTree(BiTree &T)
{
    T = NULL;
}

//����������
BiTree MakeBiTree(TElemType e, BiTree L, BiTree R)
{
    BiTree T = new (nothrow) BiTNode;
    if (T == NULL)
        return NULL;
    T->date = e;
    T->lchild = L;
    T->rchild = R;
    return T;
}

//���ʽڵ�
Status visit(TElemType e)
{
    cout << e << " ";
    return OK;
}

//�Զ�������Ҷ�ӽڵ���
int Leaves(BiTree T)
{
    int l = 0;
    int r = 0;
    if (T == NULL)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)
        return 1;

    //�ݹ���Ҷ��
    l = Leaves(T->lchild);
    r = Leaves(T->rchild);

    return l + r;
}

//�����������ȣ�deepӦΪȫ�ֱ���
int deepTraverse(BiTree T)
{
    if (T == NULL)
        return ERROR;
    deep = (deepTraverse(T->rchild) > deepTraverse(T->rchild)) ? deepTraverse(T->lchild) : deepTraverse(T->rchild);

    return deep + 1;
}

//�߶ȱ������ṩһ��ȱʡֵ����Ҫ�����������ڵ�ʱ���������޸ļ���
void levTraverse(BiTree T, Status (*visit)(TElemType e), int lev = 1)
{
    if (NULL == T)
        return;
    visit(T->date);
    cout << "���ڲ���ǣ�" << lev << endl;

    levTraverse(T->lchild, visit, ++lev);
    levTraverse(T->rchild, visit, lev);
}

//���������num��һ��ȫ�ֱ���
int InOrderTraverse(BiTree T, Status (*visit)(TElemType e), int &num)
{
    if (NULL == T)
        return 0;
    if (NULL == T->lchild && NULL == T->rchild)
    {
        cout << "Ҷ�ӽڵ��ǣ�" << T->date;
        num++;
        cout << "\n";
    }
    else
        cout << "����Ҷ�ӽڵ�";
    InOrderTraverse(T->lchild, visit, num);
    InOrderTraverse(T->rchild, visit, num);
}

//�����������ж�
Status BiTreeEmpty(BiTree T)
{
    if (NULL == T)
        return true;
    return false;
}

//��϶��������ÿն���������������
Status BreakBiTree(BiTree &T, BiTree &L, BiTree &R)
{
    if (NULL == T)
        return ERROR;
    L = T->lchild;
    R = T->rchild;
    T->lchild = NULL;
    T->rchild = NULL;
    return OK;
}

//�滻������
Status ReplaceLeft(BiTree &T, BiTree &LT)
{
    BiTree temp;
    if (NULL == T)
        return ERROR;
    temp = T->lchild;
    T->lchild = LT; //�������õ��������ڵ㸳ֵ��T������ָ��(��ʹ����ָ��ָ����ڵ�)
    LT = temp;      //ԭ�������������ڵ㱻�ܿ�

    return OK;
}

Status ReplaceRight(BiTree &T, BiTree &RT)
{
    BiTree temp;
    if (NULL == T)
        return ERROR;
    temp = T->rchild;
    T->rchild = RT; //�������õ��������ڵ㸳ֵ��T���Һ���ָ��(��ʹ�Һ���ָ��ָ���ҽڵ�)
    RT = temp;      //ԭ�������������ڵ㱻�ܿ�

    return OK;
}

//�ϲ�������
void UnionBiTree(BiTree &Ttemp)
{
    BiTree L = NULL, R = NULL;
    L = MakeBiTree(date[i++], NULL, NULL);
    R = MakeBiTree(date[i++], NULL, NULL);

    ReplaceLeft(Ttemp, L);
    ReplaceRight(Ttemp, R);
}

int main()
{
    BiTree T = NULL, Ttemp = NULL;

    InitBiTree(T);
    if (TRUE == BiTreeEmpty(T))
        cout << "��ʼ��TΪ��" << endl;
    else
        cout << "��ʼ��T��Ϊ��" << endl;

    T = MakeBiTree(date[i++], NULL, NULL);

    Ttemp = T;
    UnionBiTree(Ttemp);

    Ttemp = T->lchild;
    UnionBiTree(Ttemp);

    Status (*visit1)(TElemType); //����ָ��
    visit1 = visit;              //��visit1ָ��visit
    int num = 0;
    InOrderTraverse(T, visit1, num);
    cout << "Ҷ�ӽڵ���" << num;

    cout << "\n";

    cout << "Ҷ�ӽڵ���" << Leaves(T);

    cout << "\n";
    int lev = 1;
    levTraverse(T, visit1, lev);

    cout << "�߶���" << deepTraverse(T);

    system("pause");
    return 0;
}