#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	string input;
	int flag = 0, size;

	while (1)
	{
		stack<char> s;
		getline(cin, input);
		if (input == ".")
			break;
		size = input.length();
		for (int i = 0; i < size; i++)
		{
			flag = 0;
			if (input[i] == '[' || input[i] == '(')
				s.push(input[i]);
			else if (input[i] == ')')
			{
				if (!s.empty() && s.top() == '(')
					s.pop();
				else
				{
					flag = 1;
					break;
				}
			}
			else if (input[i] == ']')
			{
				if (!s.empty() && s.top() == '[')
					s.pop();
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0 && s.empty())
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
