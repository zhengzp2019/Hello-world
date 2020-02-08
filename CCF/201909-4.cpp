#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct commodity
{
    int id;
    int score;
    struct commodity *next;
} commodity;

//m类商品，每类商品有n个种类，cmd为命令，OPnum为op数目，查询操作用OPask个
int n, m, cmd, OPnum, OPask, type;
commodity co = {0, 0, NULL};
vector<commodity> a(m);
void Op1(vector<commodity> &a); //insert
void Op2(vector<commodity> &a); //delete
void Op3(vector<commodity> &a); //print information

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        a.push_back(co);
    }
    for (int i = 0; i < n; i++)
    {
        commodity *c = (commodity *)malloc(sizeof(commodity));
        cin >> c->id >> c->score;
        c->next = NULL;
        for (int i = 0; i < m; i++)
        {
            commodity *ci = (commodity *)malloc(sizeof(commodity));
            *ci = *c;
            commodity *p, *q; //p指向最小的score比c->score大的商品
                              //q指向最大的score比c->score小的商品
            p = &a[i];
            q = a[i].next;
            while (q != NULL && q->score >= c->score)
            {
                p = q;
                q = q->next;
            }
            p->next = ci;
            ci->next = q;
        }
    }
    cin >> OPnum;
    while (OPnum--)
    {
        cin >> cmd;
        switch (cmd)
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
    cin >> type >> cc->id >> cc->score;
    commodity *p, *q; //p指向最小的score比c->score大的商品
                      //q指向最大的score比c->score小的商品
    p = &a[type];
    q = a[type].next;
    while (q != NULL && q->score >= cc->score)
    {
        p = q;
        q = q->next;
    }
    cc->next = q;
    p->next = cc;
}

void Op2(vector<commodity> &a)
{
    int id;
    cin >> type >> id;
    commodity *p = &a[type], *q; //p指向编号为id的前一个商品，q指向编号为id的商品
    q = p->next;
    while (q != NULL && q->id != id)
    {
        p = q;
        q = q->next;
    }
    p->next = q->next;
    free(q);
}

void Op3(vector<commodity> &a)
{
    int K;
    vector<int> opt(m);
    vector<commodity> M(m);
    cin >> K;
    for (int i = 0; i < m; i++)
        cin >> opt[i];
    for (int i = 0; i < m; i++)
    {
        if (K == 0)
        {
            cout << "-1\n";
            break;
        }
        vector<int> id;
        commodity *p = a[i].next;
        for (int j = 0; j < opt[i] && K; K--, j++)
        {
            id.push_back(p->id);
            p = p->next;
        }
        sort(id.begin(), id.end());
        bool first = true;
        for (auto p = id.begin(); p != id.end(); p++)
        {
            if (first)
            {
                cout << *p;
                first = !first;
            }
            else
            {
                cout << " " << *p;
            }
        }
        cout << endl;
    }
}