#include <iostream>
using namespace std;
//单链表的类定义和基本操作
//单链表的结点采用 结构体类型定义
typedef int ElemType;//ElemType代表数据元素的类型
struct Node
{
    /* data */
    ElemType data;
    Node *next;
};

class LinkList
{
private:
    /* data */
    Node *Head;

public:
    LinkList(/* args */);//构造一个空的线性表L
    ~LinkList();//销毁线性表L
    void CreateList1(int n);//头插法创建具有n个数据元素的线性链表
    void CreateList2(int n);//尾插法创建具有n个数据元素的线性链表
    void ListInsert(int i, int e);//在表中第i个位置插入数据元素
    int ListDelete(int i);//删除表中第i个位置上的数据元素
    int GetElem(int i);//获取第i个数据的元素
    int LocateElem(int e);//在链表中查找是否存在数据元素e。
    int ListLength();//计算表长
};

LinkList::LinkList(/* args */)
{
}

LinkList::~LinkList()
{
}

