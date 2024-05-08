#include <queue>
#include <vector>
#include <iostream>
 
class MyClass {
public:
    int value;
 
    MyClass(int v) : value(v) {}
 
    // 重载比较运算符，用于 priority_queue 比较
    bool operator<(const MyClass &other) const {
        return value > other.value; // 小值优先，即value较小的对象优先级更高
    }
};
 
// 自定义比较函数
struct MyClassCompare {
    bool operator()(const MyClass &lhs, const MyClass &rhs) const {
        return lhs.value < rhs.value; // 小值优先
    }
};
 
int main() {
    // 使用默认比较函数
    std::priority_queue<MyClass> defaultQueue;
 
    // 使用自定义比较函数
    std::priority_queue<MyClass, std::vector<MyClass>, MyClassCompare> customQueue;
 
    // 添加元素
    defaultQueue.push(MyClass(30));
    defaultQueue.push(MyClass(10));
    customQueue.push(MyClass(30));
    customQueue.push(MyClass(10));
 
    // 输出
    std::cout << "Default queue top: " << defaultQueue.top().value << std::endl;
    std::cout << "Custom queue top: " << customQueue.top().value << std::endl;
 
    return 0;
}