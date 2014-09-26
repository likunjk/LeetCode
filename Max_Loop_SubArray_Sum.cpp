#include<iostream>
#include<cstdio>
using namespace std;

int data[100009];

int helper(int data[], int n)
{
	int ans = 0;
	int tmp = 0;
	for(int i=0; i<n; ++i)
	{
		if(tmp > 0)
			tmp += data[i];
		else
			tmp = data[i];
		ans = tmp > ans ? tmp : ans;
	}

	return ans;
}

//测试链接: http://ac.jobdu.com/problem.php?pid=1527
int main(void)
{
	int i,n;
	while(scanf("%d",&n)!=EOF)
	{
		int sum = 0;
		for(i=0; i<n; ++i)
		{
			scanf("%d", &data[i]);
			sum += data[i];
		}

		int ans1 = helper(data, n);

		for(i=0; i<n; ++i)
			data[i] = -data[i];
		int ans2 = helper(data, n);

		int ans = max(ans1, sum+ans2);
		printf("%d\n", ans);
	}

	return 0;
}

