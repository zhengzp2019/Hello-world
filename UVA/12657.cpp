#include <cstdio>
#define MAXN 100000+100
using namespace std;
FILE *fp_out = fopen("output.txt", "w");
FILE *fp_in = fopen("input.txt", "r");
int left[MAXN], right[MAXN];
void swap(int L, int R); //交换R和L的位置
void Link(int L, int R); //连接R和L，R在L的右边

int main()
{
    int kase = 1, n, m;
    int cmd;
    while (fscanf(fp_in, "%d %d", &n, &m) == 2)
    {
        //链表初始化，用两个数组构建一个双向链表
        for (int i = 1; i <= n; i++)
        {
            left[i] = i - 1;
            right[i] = (i + 1) % (n + 1);
        }
        left[0] = n;
        right[0] = 1;
        int inv = 1; //0表示翻转，1表示未反转

        //输入命令，并处理
        while (m--)
        {
            fscanf(fp_in, "%d", &cmd);
            if (cmd == 4) //转置整条链
                inv = !inv;
            else
            {
                int X, Y;
                fscanf(fp_in, "%d %d", &X, &Y);
                if (cmd == 3) //交换X和Y
                    swap(X, Y);
                if (!inv)
                    cmd = 3 - cmd;
                int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
                if (cmd == 1) //X放在Y左边
                {
                    if (left[Y] == X)
                        continue;
                    Link(LX, RX);
                    Link(LY, X);
                    Link(X, Y);
                }
                if (cmd == 2) //X放在y右边
                {
                    if (right[Y] == X)
                        continue;
                    Link(LX, RX);
                    Link(X, RY);
                    Link(Y, X);
                }
            }
        }

        //求和
        long long sum = 0;
        if (inv) //正向
        {
            int R = right[0];
            for (int i = 1; i <= n; i++)
            {
                if (i % 2 == 1)
                    sum += R;
                R = right[R];
            }
        }
        else //反向
        {
            int L = left[0];
            for (int i = 1; i <= n; i++)
            {
                if (i % 2 == 1)
                    sum += L;
                L = left[L];
            }
        }
        fprintf(fp_out, "Case %d: %lld\n", kase++, sum);
    }
    return 0;
}

void swap(int L, int R)
{
    int LL = left[L], RR = right[R], LR = right[L], RL = left[R];
    if (left[R] == L)
    {
        Link(LL, R);
        Link(L, RR);
        right[R] = L;
        left[L] = R;
    }
    else
    {
        if (right[R] == L)
        {
            Link(RL, L);
            Link(R, LR);
            right[L] = R;
            left[R] = L;
        }
        else
        {
            Link(LL, R);
            Link(L, RR);
            Link(R, LR);
            Link(RL, L);
        }
    }
}

void Link(int L, int R)
{
    right[L] = R;
    left[R] = L;
}