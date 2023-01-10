#include <deque>
#include <iostream>

using namespace std;

struct Element { long long value; int index; };

const int MAX_N = 3e5;
const long long MIN_VAL = (long long) 3e5 * -1e9;

void optimize_IO () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main () {
	optimize_IO();
	int n, k, p, a[MAX_N + 1];
	cin >> n >> k >> p;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	deque<Element> candidates[100 + 1];
	candidates[0] = { {a[1], 1} };
	for (int p = 1; p <= 100; ++p)
		candidates[p] = { {MIN_VAL - 1, 1} };
	for (int i = 2; i <= n; ++i) {
		for (int p = 100; p >= 1; --p) {
			while (candidates[p - 1].back().index < i - k)
				candidates[p - 1].pop_back();
			while (not candidates[p].empty() and candidates[p].front().value <= candidates[p - 1].back().value + a[i])
				candidates[p].pop_front();
			candidates[p].push_front({candidates[p - 1].back().value + a[i], i});
		}
		while (not candidates[0].empty() and candidates[0].front().value <= MIN_VAL - 1)
			candidates[0].pop_front();
		candidates[0].push_front( {MIN_VAL - 1, i} );
	}

	while (candidates[p].back().index < n)
		candidates[p].pop_back();
	cout << candidates[p].back().value << '\n';
}

