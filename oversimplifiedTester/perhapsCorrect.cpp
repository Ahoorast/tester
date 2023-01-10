#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a)
        cin >> x;
    vector<int> pr(n + 1);
    for (int i = 1; i <= n; i++) 
        pr[i] = pr[i - 1] + a[i - 1];
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << pr[r] - pr[l - 1] << '\n';
    }
    return 0;
}
