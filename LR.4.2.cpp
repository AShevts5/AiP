#include <iostream>
using namespace std;
int main()
{
	int i, K;
	const int N = 10;
	int A[N];
	for (i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	cin >> K;
	for (i = 0; i < N; i++)
	{
		if (A[i] == 0 and K != 0)
		{
			A[i] = K;
		}
	}
	for (i = 0; i < N; i++)
	{
		cout << "A[" << i << "] = " << A[i] << endl;
	}
	return 0;
}