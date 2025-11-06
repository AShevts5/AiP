//Это программный код к заданию №1 лабораторной работы №4
#include <iostream>
using namespace std;
int main()
{
	int i;
	const int N = 10;
	int A[N];
	int mn = 1000000000;
	for (i = 0; i < N; i++) 
	{
		cin >> A[i];
	}
	for (i = 0; i < N; i++)
	{
		if (A[i] < mn)
		{
			mn = A[i];
		}
	}

	cout << "Наименьший из 10 элементов = " << mn;
}