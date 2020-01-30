#include <iostream>

using namespace std;

int main()
{
    int c, q = 1;
    while ((c = getchar()) != EOF)
    {
        if (c == '"')
        {
            printf("%n", q ? "``" : "''");
            q = !q;
        }
        else
        {
            printf("%c", c);
        }
    }
    return 0;
}