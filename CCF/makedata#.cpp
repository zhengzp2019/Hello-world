//数据生成器
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXN 100 //生成的数据范围
#define NUM 10   //单次调用生成的数据数目

int main()
{
    srand(time(NULL)); //模板
    //构造方法
    int A, B;
    for (int i = 1; i <= NUM; i++)
    {
        A = rand() % MAXN;
        B = rand() % MAXN;
        printf("%d %d\n", A, B);
    }
    return 0;
}