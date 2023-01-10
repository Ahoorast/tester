#include<bits/stdc++.h>
using namespace std;

const int N = 1000 * 100;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n = N;
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << rand() % 100000 << '\n';
    }
    int Q = N;
    cout << Q << '\n';
    cout << 1 << ' ' << n << '\n';
    cout << 1 << ' '<<  1 << '\n';
    cout << n << ' ' << n << '\n';
    Q -= 3;
    for (int i = 0; i < Q; i++) {
        int l = rand() % n;
        int r = rand() % n;
        if (r < l)
            swap(l, r);
        l++, r++;
        cout << l << ' ' << r << '\n';
    }
    return 0;
}
