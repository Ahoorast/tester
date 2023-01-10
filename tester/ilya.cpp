#include <bits/stdc++.h>
using namespace std;

const long long maxn = 3e5 + 10, maxp = 110, inf = 1e17;
int n, k, p;
long long a[maxn], dp[maxn][maxp];
deque <pair<long long, int>> fmx;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][0] = -inf;
    }
    dp[1][0] = a[1];
    for (int j = 1; j <= p; j++, fmx.clear())
        for (int i = 1; i <= n; i++) {
            dp[i][j] = -inf;
            if (fmx.empty()) {
                fmx.push_back({dp[i][j - 1], i});
                continue;
            }
            dp[i][j] = fmx.front().first + a[i];
            if (fmx.front().second == i - k)
                fmx.pop_front();
            while (!fmx.empty() && fmx.back().first < dp[i][j - 1])
                fmx.pop_back();
            fmx.push_back({dp[i][j - 1], i});
        }
    cout << dp[n][p] << endl;
    return 0;
}
