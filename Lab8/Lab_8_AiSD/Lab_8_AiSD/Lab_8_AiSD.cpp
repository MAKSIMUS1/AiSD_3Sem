#include <iostream>
#include <algorithm>
using namespace std;
const int N = 4;
const int maxCapacity = 14;

void main() {
	setlocale(LC_ALL, "RU");
	int weights[100] = { 7, 3, 4, 2 };
	int cost[100] = { 25, 15, 13, 8 };
	string name[] = { "Арбуз", "Морковка", "Орех" , "Помидор" };
	int arr[N + 1][maxCapacity + 1];
	for (int g = 0; g < N; g++)
		cout << "Имя товара: " << name[g] << "\t\t" << "Стоимость: " << cost[g] << "\t\t" << "Вес: " << weights[g] << endl;
	//algrorithm
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= maxCapacity; j++)
		{
			if (i == 0 || j == 0)
				arr[i][j] = 0;
			else
			{
				if (weights[i - 1] > j)
					arr[i][j] = arr[i - 1][j];
				else
				{
					int prev = arr[i - 1][j];
					int byFormula = cost[i - 1] + arr[i - 1][j - weights[i - 1]];
					arr[i][j] = max(prev, byFormula);
				}
			}
		}
	}
	cout << "\n________________________________________________________________________________________________________\n";
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= maxCapacity; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	int i = N;
	int j = maxCapacity;

	cout << "\________________________________________________________________________________________________________\n";
	cout << "\n\nИмена товаров: ";
	while (i != 0) 
	{
		if (arr[i][j] == arr[i - 1][j])
			i--;
		else 
		{
			j = j - weights[i];
			cout << name[i - 1] << " ";
			i--;
		}
	}
	cout << "\nМаксимальная стоимость: " << arr[N][maxCapacity];


}