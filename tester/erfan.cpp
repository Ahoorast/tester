//In the name of Allah.
#include <bits/stdc++.h>
using namespace std;

const long long N = 3e5 + 5, P = 1e2 + 3, INF = 1ll << 60;
long long n, k, p, a[N], dp[N][P];
deque <int> d[P];

int main() {
    scanf("%lld%lld%lld", &n, &k, &p);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    d[0].push_back(n - 1);
    dp[n - 1][0] = a[n - 1];
    for (int i = n - 2; ~i; i--)
        for (int j = 1; j <= p; j++) {
            while (d[j - 1].size() && d[j - 1].back() > i + k)
                d[j - 1].pop_back();
            dp[i][j] = (d[j - 1].size()? dp[d[j - 1].back()][j - 1] + a[i]: -INF);
            if (j > 1) {
                while (d[j - 1].size() && dp[d[j - 1].front()][j - 1] <= dp[i][j - 1])
                    d[j - 1].pop_front();
                d[j - 1].push_front(i);
            }
        }
    printf("%lld\n", dp[0][p]);
}
