#include <iostream>
#include <string>

using namespace std;

int solution(string s)
{
	int answer = 1, len = s.size();

	while (len >= 2)
	{
		for (int i = 0; i <= s.size() - len; i++)
		{
			int left = i;
			int right = len - i - 1;
			bool flag = true;
			while (left <= right)
			{
				if (s[left] != s[right])
				{
					flag = false;
					break;
				}
				left++;
				right--;
			}
			if (flag)
				return len;
		}
		len--;
	}
	return answer;
}

int main()
{
	string s;
	cin >> s;
	int k = solution(s);
	cout << k;
	return 0;
}
