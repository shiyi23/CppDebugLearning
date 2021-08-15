//这是原书的会员管理系统用C语言风格代码来开发的版本
#include <malloc.h>
#include <string>
#include <vector>
#include <thread>

int count = 0;
void do_work(void* arg) {
    printf("线程函数开始工作...\n");
    int local_data = count;
    count ++;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    printf("线程函数结束工作！\n");
}
int start_threads(int thread_num) {
    std::vector<std::thread> threadsVector;
    //启动十个线程
    for (size_t i = 0; i < count; i++)
    {
        threadsVector.emplace_back(std::thread(do_work, &i));
        printf("启动新线程:%d\n", i);
    }
    //等待所有线程结束
    for (auto& t: threadsVector)
    {
        if (t.joinable()) {
            t.join();
        }
    }
    
    
}

struct Node0
{
    int ID;
    char name[40];
    int age;
    Node0* prev;
    Node0* next;
};

struct Node0* node_head = NULL;
int member_id = 0;

void add_member() {
    struct Node0* new_node = (Node0*)malloc(sizeof(Node0));
    new_node->next = NULL;;
    Node0* prev_node = node_head->prev;
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
    printf("请输入会员姓名，然后按回车键\n");
    scanf("%s", new_node->name);
    printf("请输入会员年龄，然后按回车键\n");
    scanf("%d", &new_node->age);

    printf("成功添加新会员！\n") ;
}

int main(int argc, char const *argv[])
{
    start_threads(10);
    node_head = (struct Node0*)malloc(sizeof(Node0));
    node_head->next = node_head->prev = NULL;
    printf("会员管理系统\n1:录入会员信息\nq:退出\n");
    while (true)
    {
        switch(getchar()) {
            case '1':
                    add_member();
                    break;
            case 'q':
                    return 0;
            default:
                    break;
        }
    }
    return 0;
}
