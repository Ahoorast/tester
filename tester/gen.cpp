#include<bits/stdc++.h>
using namespace std;

const int N = 3 * 1000 * 100;
const int kooft = 1e9 + 1;

int main() { 
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	int n = rnd() % N + 1;
	int p = rnd() % min(n - 1, 100) + 1;
	int lim = (n + p - 1) / p;
	int k = rnd() % (n - lim) + lim;
	cout << n << ' ' << k << ' ' << p << '\n';
	for (int i = 0; i < n; i++) {
		int x = rnd() % kooft;
		int coin = rnd() % 2;
		if (coin == 0)
			x *= -1;
		cout << x << ' ';
	}
	cout << '\n';
	return 0;
}
