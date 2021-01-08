#include <bits/stdc++.h>

using namespace std;
/*
struct person
{
	char s;
	int a, b;
};

int main() {
	int n, cnt = 1, m = 0;
	struct person p[5000];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p[i].s >> p[i].a >> p[i].b;
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (p[i].s != p[j].s)
			{
				if (p[i].a >= p[j].a && p[i].a <= p[j].b)
					cnt++;
				else if (p[i].b >= p[j].a && p[i].b <= p[j].b)
					cnt++;
			}
			else if ((p[i].s == p[j].s) && (cnt >= 2)) // 2명에 동성이 추가될 때
			{
				if (p[i].a >= p[j].a && p[i].a <= p[j].b)
					cnt++;
				else if (p[i].b >= p[j].a && p[i].b <= p[j].b)
					cnt++;
			}
		}


		if (cnt >= m) {
			m = cnt;
			cnt = 1;
		}
	}
	cout << m << "\n";
}*/


typedef struct {
	char s;
	int a;
	int b;
}Member;

int main()
{
	int num, i;
	int male[366] = { 0 };
	int female[366] = { 0 };
	int day[366] = { 0 };
	Member* list;
	cin >> num;

	list = (Member*)malloc(sizeof(Member) * num);
	for (i = 0; i < num; i++)
		cin >> list[i].s >> list[i].a >> list[i].b;

	for (i = 0; i < num; i++)
	{
		for (int j = list[i].a - 1; j < list[i].b; j++)
		{
			if (list[i].s == 'M')
			{
				male[j]++;
				if (male[j] < female[j])
					day[j] = male[j];
				else
					day[j] = female[j];
			}
			else
			{
				female[j]++;
				if (male[j] < female[j])
					day[j] = male[j];
				else
					day[j] = female[j];
			}
		}
	}

	int max = 0;
	for (i = 0; i < 366; i++)
	{
		if (max < day[i])
			max = day[i];
	}
	cout << "\n";
	cout << max * 2;

}
