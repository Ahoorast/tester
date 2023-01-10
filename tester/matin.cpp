#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 5, maxp = 102, inf = -1e18;
int n, p, k, ar[maxn];
long long dp[maxn][maxp];
deque<pair<long long, int>> st;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        dp[i][0] = inf;
    }
    dp[1][0] = ar[1];
    for (int j = 1; j <= p; j++) {
        for (int i = 1; i <= n; i++) {
            if (st.empty())
                dp[i][j] = inf;
            else 
                dp[i][j] = st.front().first + ar[i];
            if (!st.empty() && st.front().second == i - k)
                st.pop_front();
            while (!st.empty() && st.back().first < dp[i][j - 1])
                st.pop_back();
            st.push_back({dp[i][j - 1], i});
        }
        st.clear();
    }
    cout << dp[n][p] << endl;
}
