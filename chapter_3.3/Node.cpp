//原书中本文件采用的是C语言风格实现的，这里我改为用C++风格实现。
#include <string>
#include <vector>
#include <iostream>

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

int main(int argc, char const *argv[])
{
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
