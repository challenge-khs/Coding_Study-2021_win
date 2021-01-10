#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str, temp = "";
	int answer = 0, minus = 0;
	cin >> str;

	for (int i = 0; i <= str.length(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
		{
			if (minus == 1)
				answer -= stoi(temp);
			else
				answer += stoi(temp);
			temp = "";
			if (str[i] == '-')
				minus = 1;
		}
		else
			temp += str[i];
	}
	cout << answer;
}
