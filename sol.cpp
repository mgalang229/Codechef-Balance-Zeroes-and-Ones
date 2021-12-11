#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		// count the frequency of 1's, 0's, and questions marks
		int o = 0;
		int z = 0;
		int q = 0;
		for (int i = 0; i < n; i++) {
			o += (s[i] == '1');
			z += (s[i] == '0');
			q += (s[i] == '?');
		}
		// find the difference of 1's and 0's (if they're not equal)
		int diff = abs(o - z);
		if (o != z) {
			diff = min(diff, q);
			q -= diff;
		}
		// fill the question marks with the needed 1's or 0's to make them equal
		for (int i = 0; i < n; i++) {
			if (diff > 0 && s[i] == '?') {
				s[i] = (o < z ? '1' : '0');
				diff--;
			}
		}
		// once they're equal, divide the remaining question marks equally (if possible)
		o = q / 2;
		z = q / 2;
		// however if it's not possible, then simply add 1 to either 1's or 0's (it's the same)
		if (q & 1) {
			o++;
		}
		// change the value of the remaining question marks with 1's and 0's
		for (int i = 0; i < n; i++) {
			if (s[i] == '?') {
				if (o > 0) {
					s[i] = '1';
					o--;
				} else {
					s[i] = '0';
					z--;
				}
			}
		}
		cout << s << '\n';
	}
	return 0;
}
