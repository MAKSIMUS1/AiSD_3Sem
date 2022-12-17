#include <iostream>

using namespace std;
#define V 8

int G[V][V] = {
			{0,			2,			INT_MAX,	8,			2,			INT_MAX,	INT_MAX,	INT_MAX},//		1

			{2,			0,			3,			10,			5,			INT_MAX,	INT_MAX,	INT_MAX},//		2

			{INT_MAX,	3,			0,			INT_MAX,	12,			INT_MAX,	INT_MAX,	8},		 //		3

			{8,			10,			INT_MAX,	0,			14,			3,			1,			INT_MAX},//		4

			{2,			5,			12,			14,			0,			11,			4,			8},		 //		5

			{INT_MAX,	INT_MAX,	INT_MAX,	3,			11,			0,			6,			INT_MAX},//		6

			{INT_MAX,	INT_MAX,	INT_MAX,	1,			4,			6,			0,			9},		 //		7

			{INT_MAX,	INT_MAX,	7,			INT_MAX,	8,			INT_MAX,	9,			0},		 //		8
			//1			2			3			4			5			6			7			8
};

int main()
{
    int min = INT_MAX, amount_edge = 0, row = 0, col = 0;
    int selected[V];

    for (int i = 0; i < V; i++)
        selected[i] = false;

    selected[0] = true;

    while (amount_edge < V - 1) {
        min = INT_MAX;
        for (int i = 0; i < V; i++)
            if (selected[i])
                for (int j = 0; j < V; j++)
                    if (!selected[j] && G[i][j])
                        if (min > G[i][j]) {
                            min = G[i][j];
                            row = i;
                            col = j;
                        }
        cout << (row + 1) << " - " << col + 1 << " :  " << G[row][col] << endl;
        selected[col] = true;
        amount_edge++;
    }
}