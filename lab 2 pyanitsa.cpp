#include<iostream>
#include<deque>
using namespace std;

void task(deque<int> deq1, deque<int> deq2)
{
	int count = 0;
	while (!deq1.empty() && !deq2.empty())
	{
		int num1 = deq1.front();
		deq1.pop_front();
		int num2 = deq2.front();
		deq2.pop_front();

		if (num1 == 0 && num2 == 9)
		{
			deq1.push_back(num1);
			deq1.push_back(num2);
		}

		else if (num1 == 9 && num2 == 0)
		{
			deq2.push_back(num1);
			deq2.push_back(num2);
		}

		else if (num1 > num2)
		{
			deq1.push_back(num1);
			deq1.push_back(num2);
		}

		else if (num1 < num2)
		{
			deq2.push_back(num1);
			deq2.push_back(num2);
		}
		count++;
	}

	if (count == 1000000)
		cout << "botva";
	else if (deq1.empty())
		cout << "second " << count;
	else
		cout << "first " << count;
}

int main()
{
	deque<int> deq1;
	deque<int> deq2;

	for (int i = 1; i <= 5; i++)
	{
		int num;
		cin >> num;
		deq1.push_back(num);
	}

	for (int i = 1; i <= 5; i++)
	{
		int num;
		cin >> num;
		deq2.push_back(num);
	}
	task(deq1, deq2);
	return 0;
}