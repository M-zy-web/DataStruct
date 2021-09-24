#include <iostream>
#include <new>
using namespace std;

#define SUCCESS 1
#define UNSUCCESS 0
#define OVERFLOW -1
#define OK 1
#define ERROR -1
#define MAXNUM 9999 // 用于初始化哈希表的记录 key

typedef int Status;
typedef int KeyType;

//哈希表中的记录类型
struct RcdType
{
    KeyType key;
};

struct HashTable
{
    RcdType *rcd;
    int size;  //容量
    int count; //当前数据元素个数
    int *tag;  //数据元素存储基址
};

//哈希表每次重建后的大小
int hashsize[] = {11, 31, 61, 127, 251, 503};
int index = 0;

//初始化哈希表
Status InitHashTable(HashTable &H, int size)
{
    int i;
    H.rcd = new (nothrow) RcdType[size];
    H.tag = new (nothrow) int[size];
    if (NULL == H.tag || NULL == H.tag)
        return OVERFLOW;
    KeyType maxNum = MAXNUM;
    for (int i = 0; i < size; i++)
    {
        H.tag[i] = 0;
        H.rcd[i].key = maxNum;
    }

    H.size = size;
    H.count = 0;
    return OK;
}

//哈希函数：除留余数法
int Hash(KeyType key, int m)
{
    return (3 * key) % m;
}

//处理哈希冲突:线性探测
void collision(int &p, int m)
{
    p = (p + 1) % m;
}

Status SearchHash(HashTable H, KeyType key, int &p, int &c)
{
    p = Hash(key, H.size - 2); //p为所存关键字的哈希地址
    int h = p;
    c = 0;
    while ((1 == H.tag[p] && H.rcd[p].key != key) || -1 == H.tag[p])
    {
        collision(p, H.size);
        c++;
    }

    if (1 == H.tag[p] && key == H.rcd[p].key)
        return SUCCESS;
    else
        return UNSUCCESS;
}
int main()
{
}