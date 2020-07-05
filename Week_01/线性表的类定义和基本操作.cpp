#include <iostream>
using namespace std;
//顺序表的类定义1
const int MaxSize = 100;//应根据实际问题设置其大小
typedef int ElemType;//ElemType代表数据元素的类型
class SqList_s{ //顺序表类SqList_s
private:
    /* data */
    ElemType elem_array[MaxSize];//一维数组的容量， MaxSize为可存放的数据元素的最大个数，ElemType数据元素的类型
    int length;//线性表的长度，表中数据元素的实际个数， 应小于或等于MaxSize
public:
    //12个基本操作对应的成员函数  
};

//顺序表的类定义2
const int LISTINCEREMENT = 10;//顺序表存储空间的分配增量
typedef int ElemType;//ElemType代表数据元素的类型
class SqList_d{ //顺序表类SqList_d
private:
    /* data */
    ElemType *elem; //指针elem指向一维数组的第一个元素
    int length; //线性表的长度，表中数据元素的实际个数
    int MaxSize; //一维数组的容量，即动态分配存储空间时申请的空间所能存储的数据元素的最大个数
public:
    SqList_d(int);
    ~SqList_d();
    void SqListInsert (int, int);
    int SqListDelete (int);
    int LocateElem (int);
    int GetElem(int);
};

//顺序表的基本操作
//(1)初试化顺序表
SqList_d::SqList_d(int n)
{
    //创建一长度为0，容量为n的空表
    elem = (int*)malloc (n * sizeof(int));  //申请表空间
    length = 0;//空表长为0
    MaxSize = n;//初试容量为n
}
//算法的时间复杂度和空间复杂度均为O(1)

//(2)销毁顺序表

SqList_d::~SqList_d()//析构函数
{
    //释放表空间
    delete [] elem;
    length = 0;
    MaxSize = 0;
}
//算法的时间复杂度和空间复杂度均为O(1)

//(3)顺序表插入数据元素
//插入数据元素操作步骤如下：
//Step1：如果表满，则重新申请空间。
//Step2：如果插入位置i不合理，抛出“位置”异常。
//Step3：将最后一个元素an至第i个数据元素aj，共n-i+1个数据元素，一次后移一个数据元素位置。
//Step4：将数据元素值e插入到位置i处。
//Step5：表长增加1。
void SqList_d::SqListInsert (int i, int e){
    if (length >= MaxSize){
        elem = (int*)realloc(elem, (MaxSize*LISTINCEREMENT) * sizeof(int));
        MaxSize += LISTINCEREMENT;
    }
    if (i < 1 || i > length + 1){
        cout << "插入位置异常";
        return ;
    }
    for (int j = length; j >= i; j--) {
        elem[j] = elem[j - 1];
    }
    elem[i - 1] = e;
    length++;
}
//算法的平均时间复杂度为O(n)。

//顺序表删除数据元素
//顺序表删除数据元素的操作步骤如下：
//Step1：如果表空，抛出"下溢"异常
//Step2：如果删除位置i不合理，抛出"位置"异常。
//Step3：取出被删除数据元素。
//Step4：将最后一个数据元素an至第i个元素ai，共n-i+1个数据元素，依次后移一个数据元素位置。
//Step5：将第i+1个数据元素ai+1至最后一个数据元素an，共n-i个数据元素，依次前移一个数据元素位置。
//Step6：表长减1。
int SqList_d::SqListDelete (int i) {
    //删除表中第i个位置数据元素
    int e;
    if (length == 0){
        cout << "下溢";
        return -1;
    }
    if (i < 1 || i > length + 1){
        cout << "删除位置异常";
        return -1;
    }
    e = elem[i - 1];
    for (int j = i; j < length; j++){
        elem[j - 1] = elem[j];
    }
    length--;
    return e;
}
//算法性能分析：
//当i = n时，这是最好的情况，直接在表尾删除数据元素，不需要移动其他数据元素；
//当i = 1时，这是最差的情况，需要将表中剩余的n-1个数据元素均前移一位。
//算法的平均时间复杂度O(n)。

//(5)顺序表返回数据元素的位置i(按值查找)
//在顺序表中查找是否存在值为e的数据元素，最简单的方法是把线性表中的各个数据元素值依次与e比较。
int SqList_d::LocateElem (int e) {
    //数据元素定位，若找到，返回该数据元素在表中的位序；未找到，返回0.
    for (int i = 0; i < length; i++) {
        if (elem[i] == e) {
            return i + 1;
        }
    }
    return 0;
}
//算法性能分析：
//算法的平均时间复杂度为O(n)。

//(5)顺序表返回第i个数据元素的值(按位查找)
//顺序表的按位查找即在顺序表中查找第i个位置的数据元素的值并返回。
int SqList_d::GetElem(int i) {
    //获取第i个元素的值
    int e;
    if (i < 1 || i > length) {
        cout << "位置不合法";
        return -1;
    }
    e = elem[i - 1];
    return 0;
}
//算法性能分析：
//顺序表可以随机存取，因此按位查找的平均时间复杂度为O(1).



