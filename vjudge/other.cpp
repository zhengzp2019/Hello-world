#include <iostream>
using namespace std;
typedef long long ll;

ll f[50];

void solve(){
	f[0] = 1;
	f[1] = 2;
	f[2] = 3;
	for (int i = 3; i < 50; i++){
		f[i] = f[i - 1] + f[i - 2];
	}

}

int main()
{
	int n;
	cin >> n;
	solve();
	while (n--){
		int a, b;
		cin >> a >> b;
		int t = b - a-1;
		cout << f[t] << endl;
	}
	return 0;
}