#include <iostream>
#include <string>
using namespace std;

// 宏定义：顺序表最大容量
#define MAXSIZE 100

// 数据元素类型定义：存储字符串（姓名）
struct ElemType
{
    string name; // 数据域：存储姓名
};

// 顺序表结构定义
struct SqList
{
    ElemType *elem; // 指向存储数据元素的动态数组(程序运行时申请空间)
    int length;     // 顺序表当前实际长度（有效元素个数）
};

// 全局顺序表对象（也可在main中定义局部对象）
SqList L;

// 初始化顺序表
bool InitList(SqList &L) // 用引用&，这样函数里修改的是外面的L
{
    // 1.程序运行时，根据需要申请一块连续的内存，大小是 MAXSIZE 个 ElemType元素
    L.elem = new ElemType[MAXSIZE];

    // 申请成功后，电脑会返回这块空间的「起始地址」（比如 0x0012FF30，一串十六进制数字）；
    // L.elem = 起始地址：把这个地址存到 elem 指针里 —— 从此，L.elem 就 “指向” 了这个动态数组。

    // 2. 检查内存是否分配成功（防止内存不足的情况）
    if (L.elem == nullptr) // 如果分配失败，指针会是空
    {
        cout << "内存分配失败，顺序表初始化失败！" << endl;
        return false; // 返回false表示初始化失败
    }

    // 3. 初始化顺序表的当前长度为0（因为刚开始里面没有元素）
    L.length = 0;

    cout << "顺序表初始化成功！" << endl;
    return true; // 返回true表示初始化成功
}

int main()
{
    // 调用初始化函数
    InitList(L);

    // 可以查看一下初始化后的长度（应该是0）
    cout << "顺序表当前长度：" << L.length << endl;

    return 0;
}
