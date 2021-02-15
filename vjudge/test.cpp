#include <iostream>
using namespace std;

int main()
{
    // char c, b;
    // cin >> c >> b;
    cin.peek();
    cout << cin.get() - '0' << ' ' << cin.get() << endl;
    // cout << c << b;
    float f;
    cin >> f;
    cout << f << endl;
    return 0;
}