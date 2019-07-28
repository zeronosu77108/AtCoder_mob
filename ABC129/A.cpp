#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	int p, q, r;
	int ans = 999;
	cin >> p >> q >> r;

	ans = min(ans, p + q);
	ans = min(ans, q + r);
	ans = min(ans, r + p);

	cout << ans << endl;
}
