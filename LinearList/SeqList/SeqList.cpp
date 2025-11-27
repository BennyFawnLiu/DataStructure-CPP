#include <iostream>
#define MAXSIZE 100 // 顺序表最大容量

// 定义顺序表结构体（C++中可直接用struct，也可封装为类）
struct SeqList
{
    int elem[MAXSIZE]; // 存储元素的数组
    int last;          // 记录最后一个元素的位置

    // 构造函数：初始化空表
    SeqList() : last(-1) {}

    // 1. 判断顺序表是否为空
    bool isEmpty() const
    {
        return last == -1;
    }

    // 2. 插入元素：在位置pos插入值为value的元素
    bool insert(int pos, int value)
    {
        // 检查顺序表是否已满
        if (last == MAXSIZE - 1)
        {
            std::cerr << "顺序表已满，无法插入！" << std::endl;
            return false;
        }
        // 检查插入位置是否合法
        if (pos < 0 || pos > last + 1)
        {
            std::cerr << "插入位置不合法！" << std::endl;
            return false;
        }
        // 元素后移，腾出插入位置
        for (int i = last; i >= pos; --i)
        {
            elem[i + 1] = elem[i];
        }
        // 插入元素
        elem[pos] = value;
        ++last;
        return true;
    }

    // 3. 删除指定位置pos的元素
    bool remove(int pos)
    {
        // 检查顺序表是否为空
        if (isEmpty())
        {
            std::cerr << "顺序表为空，无法删除！" << std::endl;
            return false;
        }
        // 检查删除位置是否合法
        if (pos < 0 || pos > last)
        {
            std::cerr << "删除位置不合法！" << std::endl;
            return false;
        }
        // 元素前移，覆盖被删除元素
        for (int i = pos; i < last; ++i)
        {
            elem[i] = elem[i + 1];
        }
        --last;
        return true;
    }

    // 4. 查找值为value的元素，返回其位置（-1表示未找到）
    int search(int value) const
    {
        for (int i = 0; i <= last; ++i)
        {
            if (elem[i] == value)
            {
                return i;
            }
        }
        return -1;
    }

    // 5. 遍历顺序表
    void traverse() const
    {
        if (isEmpty())
        {
            std::cout << "顺序表为空！" << std::endl;
            return;
        }
        std::cout << "顺序表元素：";
        for (int i = 0; i <= last; ++i)
        {
            std::cout << elem[i] << " ";
        }
        std::cout << std::endl;
    }
};

// 主函数测试
int main()
{
    SeqList L; // 自动调用构造函数初始化（last=-1）

    // 测试插入
    L.insert(0, 10);
    L.insert(1, 20);
    L.insert(1, 15);
    L.traverse(); // 输出：10 15 20

    // 测试查找
    int pos = L.search(15);
    std::cout << "元素15的位置:" << pos << std::endl; // 输出：1

    // 测试删除
    L.remove(1);
    L.traverse(); // 输出：10 20

    return 0;
}
