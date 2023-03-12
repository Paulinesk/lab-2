#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int> > a(n + 1);
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	vector<pair<int, int> > ans;
	if (n == 1) {
		return 0;
	}

	if (n == 2) {
		while (!a[1].empty() && a[1].back() == 2) 
		{
			ans.push_back(make_pair(1, 2));
			a[1].pop_back();
			a[2].push_back(2);
		}
		while (!a[2].empty() && a[2].back() == 1) 
		{
			ans.push_back(make_pair(2, 1));
			a[2].pop_back();
			a[1].push_back(1);
		}

		for (int i = 0; i < a[1].size(); ++i) 
		{
			if (a[1][i] == 2) 
			{
				cout << "0\n";
				return 0;
			}
		}

		for (int i = 0; i < a[2].size(); ++i) 
		{
			if (a[2][i] == 1) 
			{
				cout << "0\n";
				return 0;
			}
		}

		for (int i = 0; i < ans.size(); ++i) 
		{
			cout << ans[i].first << " " << ans[i].second << "\n";
		}
		return 0;
	}

	while (!a[1].empty()) 
	{ 
		ans.push_back(make_pair(1, 2));
		a[2].push_back(a[1].back());
		a[1].pop_back();
	}

	for (int i = 2; i <= n; ++i) 
	{
		while (!a[i].empty())
		{
			int x = a[i].back();
			a[i].pop_back();
			if (x == 1) 
			{
				a[1].push_back(1);
				ans.push_back(make_pair(i, 1));
			}
			else 
			{
				if (i == 2) 
				{
					ans.push_back(make_pair(2, 3));
					a[3].push_back(x);
				}
				else 
				{
					ans.push_back(make_pair(i, 2));
					a[2].push_back(x);
				}
			}
		}
	}

	while (!a[2].empty()) 
	{
		ans.push_back(make_pair(2, 1));
		a[1].push_back(a[2].back());
		a[2].pop_back();
	}

	while (!a[1].empty() && a[1].back() != 1) 
	{
		int x = a[1].back();
		a[1].pop_back();
		a[x].push_back(x);
		ans.push_back(make_pair(1, x));
	}

	for (int i = 0; i < ans.size(); ++i) 
	{
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}