#include <iostream>;
#include <set>;
using namespace std;
int main()
{
	int n, num;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		s.insert(num);
	}
	cout << s.size();
	return 0;
}