#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> st;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (!st.empty() && st.top() == '(' && s[i] == ')')
			st.pop();
		else if (!st.empty() && st.top() == '[' && s[i] == ']')
			st.pop();
		else if (!st.empty() && st.top() == '{' && s[i] == '}')
			st.pop();
		else
			st.push(s[i]);
	}

	if (st.empty())
		cout << "yes";
	else
		cout << "no";
	return 0;
}