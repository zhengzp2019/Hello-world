#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    char s[100];
    char ch = getchar();
    scanf("%s", s);
    while (sscanf(s, "%c", &ch))
    {
        printf("%c\n", ch);
    }
    return 0;
}