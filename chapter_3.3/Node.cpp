//原书中本文件采用的是C语言风格实现的，这里我改为用C++风格实现。
//用来学习core cump文件分析而使用的.
/**
#include <string>
#include <vector>
#include <iostream>

class Test_1
{
private:
    
public:
    Test_1(){};
    virtual ~Test_1(){};
    virtual void test_fun() {
        printf("class Test_1's test_fun()\n");
    }
};

class Test_2 : public Test_1
{
private:
    
public:
    Test_2(){};
    virtual ~Test_2(){};
    virtual void test_fun() {
        printf("class Test_2's test_fun()\n");
    }
};

class Node
{
    int ID;
    std::string name;
    int age;
public:
    int member_id = 0;
    Node* prev;
    Node* next;
    Node* node_head;
    Node() {
        this->prev = nullptr;
        this->node_head = nullptr;
    }
    void add_member() {
        Node* new_node = new Node();
        new_node->next = nullptr;
        Node* prev_node = node_head->prev;
        if (prev_node) {
            prev_node->next = new_node;
            new_node->prev = prev_node;
            node_head->prev = new_node;
        }
        else {
            node_head->next = new_node;
            new_node->prev = node_head;
            node_head->prev = new_node;
        }
        new_node->ID = member_id++;
        std::cout << "请输入会员姓名，然后按回车键\n";
        std::cin >> new_node->name;
        std::cout << "请输入会员年龄，然后按回车键\n";
        std::cin >> new_node->age;
        std::cout << "成功添加新会员！\n";
    }

};

void test_fun(int a) {
    printf("a = %d\n", a);
}

// void test_fun(std::string str) {
//     printf("str is : %s\n", str);
// }

void test_loop() {
    for (int i = 0; i < 1000; i++)
    {
        printf("i = %d\n", i);
    }
}

int main(int argc, char const *argv[])
{   
    //test_loop();//测试为条件表达式设置断点
    test_fun(6);
    // test_fun("hello");
    Test_1 test_1;
    test_1.test_fun();
    std::cout << "传入的参数信息为\n";
    for (int i = 0; i < argc; i++)
    {
        printf("参数: %d=%s\n", i, argv[i]);
    }
    
    Node* node_head = new Node();
    node_head->next = node_head->prev = nullptr;
    printf("会员管理系统\n1:录入会员信息\nq:退出\n");
    while (true)
    {
        switch(getchar()) {
            case '1':
                    node_head->add_member();
                    break;
            case 'q':
                    return 0;
            default:
                    break;
        }
    }
    
    return 0;
}

**/