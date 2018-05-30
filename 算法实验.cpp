
#include<iostream>
#include<algorithm>
#include <fstream>
using namespace std;
int Partition(int a[], int start, int end)
{
	int middle = (start + end )/ 2;
	int pvi = a[end];
	int left = start;
	int right = end-1;
	if (start == end)
		return start;
	while (left!=right)
	{
		while ((a[left] <pvi)&&(left<right))left++;
		while (a[right] >= pvi&&(right>left))right--;
		if (left != right) swap(a[left], a[right]);
	}
	swap(a[left+1], a[end]);
	return left+1;
}
int main()
{
	int a[15000];
	int n;
	fstream fin;
	fin.open("D:\\算法实验\\input.txt");
	fin >> n;
	int x; int y;
	int count = 0;
	for (int i = n; i > 0; i--)
	{
		fin>> x;
		fin >> y;
		a[count++] = y;
	}
	fin.clear();
	fin.close();
	int target;

	if(count%2==0)
		target = (n / 2)-1;
	else target = ((n+1) / 2)-1;
	int temp = Partition(a, 0, count-1);
	while (temp!=target)
	{
		if (temp > target)
			temp = Partition(a, 0, temp - 1);
		else temp = Partition(a, temp + 1,count-1);

	}

	//cout.clear();
	//cout << temp;
	int sum = 0;
	for (int i = 0; i < count; i++)
		a[i] > a[temp] ? sum += a[i] - a[temp] : sum += a[temp] - a[i];

	cout << sum;
	system("pause");
}
/*
#include <iostream>
#include<fstream>
using namespace std;
int n;
int a[200];
int b[200];
int C[200][200];
int max;
int min;
fstream fin;
int main()
{
	fin.open("d:\\算法实验\\lab2\\input.txt");
	while (fin >> n)
	{
		if (n == 0)
			break;
		for (int i = 0; i < 200; i++)
			a[i] = b[i] = 0;
		for (int i = 0; i < 200; i++)
			for (int j = 0; j < 200; j++)
				C[i][j] = 0;


		int temp;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			fin >> temp;
			a[n + i] = a[i] = temp;
			sum += temp;
			b[i] = sum;
		}
		for (int i = 0; i < n; i++)
		{
			b[n + i] = b[n + i - 1] + a[i];
		}


		for (int i = 0; i < 2 * n; i++)
			for (int j = i; j < 2 * n; j++)
			{
				if ((j - i) == j)
				{
					C[j - i][j] = 0;
					continue;
				}
				min = 99999;
				for (int k = j - i; k < j; k++)
				{
					if (((C[j - i][k] + C[k + 1][j]) + (b[j] - b[j - i - 1])) <min)
						min = (C[j - i][k] + C[k + 1][j]) + (b[j] - b[j - i - 1]);
				}
				C[j - i][j] = min;
			}
		min = 999999;
		for (int i = n; i < 2 * n; i++)
		{
			if (C[i - n][i - 1] < min)
				min = C[i - n][i - 1];
		}
		cout << min << endl;
	


//==============================================================



		for (int i = 0; i < 200; i++)
			for (int j = 0; j < 200; j++)
				C[i][j] = 0;


		for (int i = 0; i < 2 * n; i++)
			for (int j = i; j < 2 * n; j++)
			{
				if ((j - i) == j)
				{
					C[j - i][j] = 0;
					continue;
				}
				max = -99999;
				for (int k = j - i; k < j; k++)
				{
					if (((C[j - i][k] + C[k + 1][j]) + (b[j] - b[j - i - 1])) > max)
						max = (C[j - i][k] + C[k + 1][j]) + (b[j] - b[j - i - 1]);
				}
				C[j - i][j] = max;
			}


		max = -999999;
		for (int i = n; i < 2 * n; i++)
		{
			if (C[i - n][i - 1] > max)
				max = C[i - n][i - 1];
		}
		cout << max<<endl;

		system("pause");
	}
}*/