#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef struct commodity
{
    int id;
    int score;
    struct commodity *next;
} commodity;

int n, m, op, OPnum, OPask, type;
commodity co = {0, 0, NULL};
vector<commodity> a;
fstream in("201909-4_in.txt");
fstream out("201909-4_out.txt");
void Op1(vector<commodity> &a);       //insert
void Op2(vector<commodity> &a);       //delete
void Op3(const vector<commodity> &a); //print information

int main()
{
    in >> m >> n;
    for (int i = 0; i < m; i++)
    {
        a.push_back(co);
    }
    while (n--)
    {
        commodity *c = (commodity *)malloc(sizeof(commodity));
        in >> c->id >> c->score;
        for (int i = 0; i < m; i++)
        {
            c->next = a[i].next;
            a[i].next = c;
        }
    }
    in >> OPnum;
    while (OPnum--)
    {
        in >> op;
        switch (op)
        {
        case 1:
            Op1(a);
            break;
        case 2:
            Op2(a);
            break;
        case 3:
            Op3(a);
            break;
        default:
            break;
        }
    }
    return 0;
}

void Op1(vector<commodity> &a)
{
    commodity *cc = (commodity *)malloc(sizeof(commodity));
    in >> type >> cc->id >> cc->score;
    cc->next = a[type].next;
    a[type].next = cc;
}

void Op2(vector<commodity> &a)
{
    in >> type >> co.id;
}

void Op3(const vector<commodity> &a)
{
    int K;
    vector<int> opt(m);
    in >> K;
    for (int i = 0; i < m; i++)
    {
        in >> opt[i];
    }
}