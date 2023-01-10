#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 5, maxp = 102, inf = -1e18;
struct deq{
	pair<long long, int> data[2 * maxn];
	int s = maxn, e = maxn + 1;
	void init() {
		s = maxn, e = maxn + 1;
	}
	bool empty() {
		if (s + 1 ==  e)
			return 1;
		else
			return 0;
	}
	void pop_front() {
		s++;
	}
	void pop_back() {
		e--;	
	}
	void push_front(pair<long long, int> x) {
		data[s] = x;
		s--;
	}
	void push_back(pair<long long, int> x) {
		data[e] = x;
		e++;
	}
	pair<long long, int> front() {
		return data[s + 1];
	}
	void clear() {
		init();
	}
	pair<long long, int> back() {
		return data[e - 1];
	}
}; 
int n, p, k, ar[maxn];
long long dp[maxn][maxp];
deq st;
int main() {
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

