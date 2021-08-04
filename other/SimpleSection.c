//SimpleSection.c
//通过与此代码的相关实践来学习objdump的使用
//详见《程序员的自我修养—链接、装载与库》(潘爱民，俞甲子，石凡 著)3.3节

int printf(const char* format, ...);

int global_init_var = 84;
int global_uninit_var;

void func1(int i) {
    printf("%d\n", i);
}

int main(void)
{
    static int static_var = 85;
    static int static_var2;
    int a = 1;
    int b;

    func1(static_var + static_var2 + a + b);
    return a;
}