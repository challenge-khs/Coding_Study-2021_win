#include <iostream>
#include <deque>

using namespace std;

int main()
{
	int n, m, del, index, count = 0;
	deque<int> d;
	
	cin >> n >> m;	// 큐의크기 n, 뽑아내려는 수의 개수 m
	
	for (int i = 1; i <= n; i++)	// 큐에 1~n까지 값을 넣기
	{
		d.push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> del; // 뽑아내려는 값 입력

		for (int i = 0; i < d.size(); i++)
		{
			if (d[i] == del)	// 뽑아내려는 값의 위치 찾아 index에 저장
			{
				index = i;
				break;
			}
		}
		if (index < d.size() - index)	// 뽑아내려는 값의 위치가 앞에서 도는 경우가 더 빠르다면
		{
			while (1)	// 뽑아내려는 값이 나올 때까지 앞의 값을 뒤로 저장하며 count 증가
			{
				if (d.front() == del)
				{
					d.pop_front();
					break;
				}
				++count;
				d.push_back(d.front());
				d.pop_front();
			}
		}
		else	// 뽑아내려는 값의 위치가 뒤에서 도는 경우가 더 빠르다면
		{
			while (1)	// 뽑아내려는 값이 나올때까지 뒤의 값을 앞으로 저장하며 count 증가
			{
				if (d.front() == del)
				{
					d.pop_front();
					break;
				}
				++count;
				d.push_front(d.back());
				d.pop_back();
			}
		}
	}

	cout << count << endl;

	return 0;
}
