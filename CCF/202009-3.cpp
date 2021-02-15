// http://118.190.20.162/view.page?gpid=T111
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct FUNC
{
    string func;
    int num;     //标记输入的数目
    string in_1; //输入1的名字
    string in_2; //输入2的名字若器件为NOT则不使用2号输入
    bool out;
    int pos;   //器件标号
    bool flag; //标记器件的输出有没有求出来
};

//计算除NOT操作外其他器件的结果
bool compute(string func, bool in_1, bool in_2)
{
    if (func == "AND")
        return in_1 & in_2;
    else if (func == "OR")
        return in_1 | in_2;
    else if (func == "XOR")
        return in_1 ^ in_2;
    else if (func == "NAND")
        return ~(in_1 & in_2);
    else if (func == "NOR")
        return ~(in_1 | in_2);
    return false;
}

int main()
{
    // Q为问题数目
    // M为输入数目
    // N为器件数目
    int M, N, Q;
    cin >> Q;
    while (Q--)
    {
        cin >> M >> N;
        vector<FUNC> opt;
        //读入电路描述信息
        for (int i = 1; i <= N; i++)
        {
            opt[i].flag = false;
            opt[i].pos = i;
            cin >> opt[i].func >> opt[i].num;
            if (opt[i].num == 1)
                cin >> opt[i].in_1;
            else
                cin >> opt[i].in_1 >> opt[i].in_2;
        }
        int S; //电路需要运行S次
        cin >> S;
        bool inputs[550][220] = {false}; //存储每组输入情况
        //对于每组输入求输出
        for (int i = 0; i < S; i++)
        {
            for (int j = 1; j <= M; j++)
                cin >> inputs[i][j];
        }
        //读入需要输出的器件号
        for (int i = 0; i < S; i++)
        {
            int output[110] = {0}; //存储需要输出的器件标号
            int s_i;               //需要输出的器件数目
            cin >> s_i;
            for (int j = 0; j < s_i; j++)
                cin >> output[j];
            for (int ii = 0; ii < S; i++)
            { //对于第i组输入
                for (int jj = 0; output[jj] != 0; jj++)
                {
                    int label = output[jj];
                    if(opt[label].flag)
                        cout << opt[label].out << " ";
                    else
                    {

                    }
                }
                cout << endl;
                //清空所有器件的输出
            }
        }
    }
}