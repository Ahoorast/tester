// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 300000 + 100;
const int maxp = 100 + 10;

int n, k, p;
int a[maxn];
ll dp[maxp][maxn];
int q[maxn], hd, tl;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k >> p;
	assert(1 <= n && n <= 300000);
	assert(1 <= k && k <= n-1);
	assert(1 <= p && p <= 100);
	assert(p * k >= n-1);
	rep(i, n) cin >> a[i], assert(-1e9-1 <= a[i] && a[i] <= 1e9+1);
//	rep(i, n) a[i] = i*(ll)i % (int)2e9 - 1e9;

	memset(dp, -50, sizeof dp);

	dp[0][0] = a[0];
	fer(z, 1, p+1) {
		hd = tl = 0;
		q[tl++] = 0;

		fer(i, 1, n) {
			while(q[hd] < i-k) hd++;
			dp[z][i] = dp[z-1][q[hd]] + a[i];
			while(hd < tl && dp[z-1][q[tl-1]] <= dp[z-1][i]) tl--;
			q[tl++] = i;
		}
	}
	cout << dp[p][n-1] << endl;

	{ return 0; }
}

