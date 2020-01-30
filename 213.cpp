#include <cstring>
#include <cstdio>

int readchar();      //跨行读取二进制数
int readint(int c);  //读取c为二进制数并转化为十进制数
int readcodes();     //读取编码头，并编码
//void printcodes();   //输出编码头的编码
int code[8][1 << 8]; //每一行存储对应长度的二进制数，eg:0——存在第一行，00——存在第二行

int main()
{
    while (readcodes())
    {
        //printcodes();
        while (1)
        {
            int len = readint(3);
            //printf("len=%d\n", len);
            if (len == 0)
            {
                break;
            }
            while (1)
            {
                int v = readint(len);
                if (v == (1 << len) - 1)
                {
                    break;
                }
                //printf("v=%d\n", v);
                putchar(code[len][v]);
            }
        }
        getchar();
        putchar('\n');
    }
    return 0;
}

int readcodes()
{
    memset(code, 0, sizeof(code));
    char ch = getchar();
    if (ch == EOF)
    {
        return 0;
    }
    else
    {
        for (int len = 1; len <= 7; len++)
        {
            for (int i = 0; i < (1 << len) - 1; i++)
            {
                if (ch == '\n' || ch == '\r')
                    return 1;
                code[len][i] = ch;
                ch = getchar();
            }
        }
    }
    return 1;
}

int readchar()
{
    while (1)
    {
        int ch = getchar();
        if (ch != '\n')
        {
            return ch;
        }
    }
}

int readint(int c)
{
    int v = 0;
    while (c--)
    {
        v = v * 2 + readchar() - '0';
    }
    return v;
}

/*
void printcodes()
{
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 0; code[i][j] != 0; j++)
        {
            printf("%d %d->%c\n", i, j, code[i][j]);
        }
    }
}
*/