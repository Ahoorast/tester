#include<bits/stdc++.h>
using namespace std;

const int N = 3 * 1000 * 100 + 10;
const long long inf = 1LL << 60;
int n, p, k, a[N];
long long dp[N][2];

int main() { 
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> p >> k;
	swap(p, k);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 2; j++)
			dp[i][j] = -inf;
	dp[1][0] = a[1];
	deque<int> dq;
	for (int j = 1; j <= p; j++) {
		dq.clear();
		bool b = j & 1;
		for (int i = 1; i <= n; i++)
			dp[i][b] = -inf;
		for (int i = 2; i <= n; i++) {
			while (dq.size() && dp[dq.back()][!b] < dp[i - 1][!b])
				dq.pop_back();
			dq.push_back(i - 1);
			if (dq.size() && dq.front() == i - k - 1)
				dq.pop_front();
			dp[i][b] = a[i] + dp[dq.front()][!b];
		}
	}
	cout << dp[n][p & 1] << '\n';
	return 0;
}
