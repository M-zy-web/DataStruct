#include <iostream>
#include <new>
using namespace std;

#define SUCCESS 1
#define UNSUCCESS 0
#define OVERFLOW -1
#define OK 1
#define ERROR -1
#define MAXNUM 9999 // ���ڳ�ʼ����ϣ��ļ�¼ key

typedef int Status;
typedef int KeyType;

//��ϣ���еļ�¼����
struct RcdType
{
    KeyType key;
};

struct HashTable
{
    RcdType *rcd;
    int size;  //����
    int count; //��ǰ����Ԫ�ظ���
    int *tag;  //����Ԫ�ش洢��ַ
};

//��ϣ��ÿ���ؽ���Ĵ�С
int hashsize[] = {11, 31, 61, 127, 251, 503};
int index = 0;

//��ʼ����ϣ��
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

//��ϣ����������������
int Hash(KeyType key, int m)
{
    return (3 * key) % m;
}

//�����ϣ��ͻ:����̽��
void collision(int &p, int m)
{
    p = (p + 1) % m;
}

Status SearchHash(HashTable H, KeyType key, int &p, int &c)
{
    p = Hash(key, H.size - 2); //pΪ����ؼ��ֵĹ�ϣ��ַ
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