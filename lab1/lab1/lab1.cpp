#include <iostream>

using namespace std;
int Correct_Input_Integer();

void hanoi(int i, int k, int n)
{
    if (n == 1) 
        printf("Переместить диск 1 с %d на %d стержень\n", i, k);
    else {
        int tmp = 6 - i - k; 			
        hanoi(i, tmp, n - 1);
        printf("Переместить диск %d с %d на %d стержень\n", n, i, k);
        hanoi(tmp, k, n - 1);
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int N, k = 1;
    printf("Введите кол-во дисков: ");
	N = Correct_Input_Integer();
    printf("Ввод конечного стержня: ");
	while (k <=1 || k > 3)
	{
		k = Correct_Input_Integer();
		if (k <= 1 || k > 3)
			printf("Неверный ввод стержня.\n");
	}
    hanoi(1, k, N);
    return 0;
}

int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[20];

	while (proverka != 1) 
	{
		cin.ignore(cin.rdbuf()->in_avail());
		proverka_2 = 0;
		gets_s(ch);
		if (ch[0] == '-')
			proverka_na_minus = 1;
		else
			if (ch[0] >= '0' && ch[0] <= '9')
				proverka_na_minus = 2;
			else
				proverka_2 = 1;
		if (proverka_na_minus == 1)
			for (int i = 1; i < strlen(ch); i++)
				if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' && ch[i] != '4' && ch[i] != '5' && ch[i] != '6' && ch[i] != '7' && ch[i] != '8' && ch[i] != '9') {
					proverka_2 = 1;
					break;
				}
		if (proverka_na_minus == 2)
			for (int i = 0; i < strlen(ch); i++)
				if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' && ch[i] != '4' && ch[i] != '5' && ch[i] != '6' && ch[i] != '7' && ch[i] != '8' && ch[i] != '9') {
					proverka_2 = 1;
					break;
				}
		cin.clear();
		proverka_na_minus = 0;
		if (proverka_2 == 1)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (proverka_2 == 0)
			proverka = 1;
	}
	value = atoi(ch);
	return value;
}

