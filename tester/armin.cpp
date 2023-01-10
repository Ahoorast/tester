#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<pair <int, pair <int, int>>, null_type,less<pair <int, pair <int, int>>>, rb_tree_tag,tree_order_statistics_node_update> 
 
const int MAXN = 3e5 + 20, MAXM = 1e2 + 5, MOD = 1e9 + 7;
const long long INF = 1e18 + 10;
deque <int> q[MAXM];
long long a[MAXN], dp[MAXN][MAXM];

void solve() {
	int n, k, p;
	cin >> n >> k >> p;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= p; j++)
			dp[i][j] = -INF;	
	
	dp[1][0] = a[1];
	for (int j = 0; j <= p; j++) {
		for (int i = 1; i <= n; i++) {	
			if (q[j].size())
				dp[i][j + 1] = a[i] + dp[q[j].front()][j];
			else
				dp[i][j + 1] = -INF;
			
			while (q[j].size() && dp[q[j].back()][j] <= dp[i][j])
				q[j].pop_back();
				
			q[j].push_back(i);
			while (q[j].size() && q[j].front() <= i - k)
				q[j].pop_front();
		}
		q[j].clear();
	}
	
//	for (int j = 0; j <= p; j++) {
//		for (int i = 1; i <= n; i++)
//			cout << i << " " << j << " " << dp[i][j] << endl;
//	}
	
	cout << dp[n][p] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q = 1;
//	cin >> q;
	
	while (q--) {
		solve();
	}
}
