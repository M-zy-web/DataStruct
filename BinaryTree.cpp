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

//节点结构
typedef struct BiTNode
{
    TElemType date;
    BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//初始化一个空树
void InitBiTree(BiTree &T)
{
    T = NULL;
}

//构建二叉树
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

//访问节点
Status visit(TElemType e)
{
    cout << e << " ";
    return OK;
}

//对二叉树求叶子节点数
int Leaves(BiTree T)
{
    int l = 0;
    int r = 0;
    if (T == NULL)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)
        return 1;

    //递归求叶子
    l = Leaves(T->lchild);
    r = Leaves(T->rchild);

    return l + r;
}

//求二叉树的深度，deep应为全局变量
int deepTraverse(BiTree T)
{
    if (T == NULL)
        return ERROR;
    deep = (deepTraverse(T->rchild) > deepTraverse(T->rchild)) ? deepTraverse(T->lchild) : deepTraverse(T->rchild);

    return deep + 1;
}

//高度遍历，提供一个缺省值，当要输入其他树节点时，在重新修改即可
void levTraverse(BiTree T, Status (*visit)(TElemType e), int lev = 1)
{
    if (NULL == T)
        return;
    visit(T->date);
    cout << "所在层次是：" << lev << endl;

    levTraverse(T->lchild, visit, ++lev);
    levTraverse(T->rchild, visit, lev);
}

//中序遍历，num是一个全局变量
int InOrderTraverse(BiTree T, Status (*visit)(TElemType e), int &num)
{
    if (NULL == T)
        return 0;
    if (NULL == T->lchild && NULL == T->rchild)
    {
        cout << "叶子节点是：" << T->date;
        num++;
        cout << "\n";
    }
    else
        cout << "不是叶子节点";
    InOrderTraverse(T->lchild, visit, num);
    InOrderTraverse(T->rchild, visit, num);
}

//二叉树树空判定
Status BiTreeEmpty(BiTree T)
{
    if (NULL == T)
        return true;
    return false;
}

//打断二叉树：置空二叉树的左右子树
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

//替换左子树
Status ReplaceLeft(BiTree &T, BiTree &LT)
{
    BiTree temp;
    if (NULL == T)
        return ERROR;
    temp = T->lchild;
    T->lchild = LT; //将建立好的左子树节点赋值给T的左孩子指针(即使左孩子指针指向左节点)
    LT = temp;      //原建立的左子树节点被架空

    return OK;
}

Status ReplaceRight(BiTree &T, BiTree &RT)
{
    BiTree temp;
    if (NULL == T)
        return ERROR;
    temp = T->rchild;
    T->rchild = RT; //将建立好的右子树节点赋值给T的右孩子指针(即使右孩子指针指向右节点)
    RT = temp;      //原建立的右子树节点被架空

    return OK;
}

//合并二叉树
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
        cout << "初始化T为空" << endl;
    else
        cout << "初始化T不为空" << endl;

    T = MakeBiTree(date[i++], NULL, NULL);

    Ttemp = T;
    UnionBiTree(Ttemp);

    Ttemp = T->lchild;
    UnionBiTree(Ttemp);

    Status (*visit1)(TElemType); //函数指针
    visit1 = visit;              //将visit1指向visit
    int num = 0;
    InOrderTraverse(T, visit1, num);
    cout << "叶子节点有" << num;

    cout << "\n";

    cout << "叶子节点是" << Leaves(T);

    cout << "\n";
    int lev = 1;
    levTraverse(T, visit1, lev);

    cout << "高度是" << deepTraverse(T);

    system("pause");
    return 0;
}