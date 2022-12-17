#include <iostream>

using namespace std;

void main()
{
	srand(time(NULL));
	int N;
	cin >> N;
	int* A = new int[N];
	int* D = new int[N];
	int* prev = new int[N];
	for (int i = 0; i < N; i++)
	{
		A[i] = (rand() % 100) + 1;
		D[i] = 1;
		prev[i] = -1;
	}
	//for (int i = 0; i < N; i++)
		//cin >> A[i];
	cout << "A: \t";
	for (int i = 0; i < N; i++)
		cout << A[i] << "\t|";
	cout << endl;
	for (int i = 1; i < N; i++)
		for (int j = 0; j < i; j++)
			if (A[i] > A[j])
				if (D[i] <= D[j])
				{
					D[i] = D[j] + 1;
					prev[i] = j;
				}
	cout << "D: \t";
	for (int i = 0; i < N; i++)
		cout << D[i] << "\t|";
	cout << endl;
	cout << "prev: \t";
	for (int i = 0; i < N; i++)
		cout << prev[i] << "\t|";
	cout << endl;
	int max = 0, maxPos = 0, maxPosPrev = 0;
	for (int i = 0; i < N; i++)
		if (D[i] >= max)
		{
			max = D[i];
			maxPos = i;
		}
	int ForAnsw[100];
	for (int i = max; i >= 0; i--)
	{
		ForAnsw[i] = A[maxPos];
		maxPos = prev[maxPos];
	}
	cout << max << endl;
	for (int i = 1; i < max + 1; i++)
		cout << ForAnsw[i] << " ";
}