#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x: a)
        cin >> x;
    vector<long long> pr(n + 1);
    for (long long i = 1; i <= n; i++) 
        pr[i] = pr[i - 1] + a[i - 1];
    long long Q;
    cin >> Q;
    while (Q--) {
        long long l, r;
        cin >> l >> r;
        cout << pr[r] - pr[l - 1] << '\n';
    }
    return 0;
}
