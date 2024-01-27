#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<conio.h>

using namespace std;


void display(int block[4][4]);
void each_move(int& first_row, int& first_col, int block[4][4]);
void inp(int block[4][4], char& move);

int main()
{
	int block[4][4];
	char move;	
	int m;

	srand(time(NULL));

	int first_row, first_col;

	first_row = rand() % 4;

	first_col = rand() % 4;

	block[first_row][first_col] = 1;

	int sec_row, sec_col;

	sec_row = rand() % 4;

	sec_col = rand() % 4;

	block[sec_row][sec_col] = 1;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((i == first_row && j == first_col) || (i == sec_row && j == sec_col))
			{

			}

			else
			{
				block[i][j] = 0;
			}
		}
	}


	display(block);

	int i=0, j=0;

	while (block[i][j] != 1024)
	{
		inp(block, move);

		each_move(first_row, first_col, block);
	}
}

void display(int block[4][4])
{
	for (int i = 0; i < 4; i++)
	{	
		cout << "\t";

		for (int j = 0; j < 4; j++)
		{
			if (block[i][j] == 0)
			{
				cout << "-";
			}

			else
			{
				cout << block[i][j];
			}

			if (j >= 0 && j < 4)
			{
				cout << "\t";
			}
		}
		cout << endl; cout << endl;
	}

}

void each_move(int& first_row, int& first_col, int block[4][4])	
{
	system("cls");
	
		while (true)
		{
			first_row = rand() % 4;

			first_col = rand() % 4;

			if (block[first_row][first_col] == 0)
			{
				block[first_row][first_col] = 1;

				break;
			}
			else 
			{

			}
		}

	for (int i = 0; i < 4; i++)
	{
		cout << "\t";

		for (int j = 0; j < 4; j++)
		{

			if (block[i][j] == 0)
			{
				cout << "-";
			}

			else
			{
				cout << block[i][j];
			}

			if (j >= 0 && j < 4)
			{
				cout << "\t";
			}
		}
		cout << endl; cout << endl;
	}
}

void inp(int block[4][4], char& move)
{
	int i = 0, j = 0;
	int m, k;
	
	//while (block[i][j]!=1024 )
	//{
		move = _getch();
		system("cls");

		if (move == 'w' || move == 'W')
		{
			for (j = 0; j < 4; j++)
			{
				m = 0;
				k = j;

				for (i = 1; i < 4; i++)
				{
					if (block[i][j] > 0)
					{
						if ((block[i - 1][j] == block[i][j] || (block[i - 1][j] == 0)) && (block[m][k] == block[i][j]))
						{
							block[m][k] = block[i][j] + block[m][k];

							block[i][j] = 0;
						}

						else if ((block[i - 1][j] == block[i][j] || block[i - 1][j] == 0) && (block[m][k] == 0))
						{
							block[m][k] = block[i][j];

							block[i][j] = 0;
						}

						else if ((block[i - 1][j] == block[i][j] || (block[i - 1][j] == 0)) && (block[m][k] > 0))
						{
							m = m + 1;

							block[m][k] = block[i][j];

							block[i][j] = 0;
						}

						else
						{
							m++;
						}
					}

				}
			}
		}


		else if (move == 'a' || move == 'A')
		{
			for (i = 0; i < 4; i++)
			{
				m = i;
				k = 0;

				for (j = 1; j < 4; j++)
				{
					if (block[i][j] > 0)
					{
						if ((block[i][j - 1] == block[i][j] || block[i][j - 1] == 0) && block[m][k] == block[i][j])
						{
							block[m][k] = block[i][j] + block[m][k];
							block[i][j] = 0;
						}

						else if ((block[i][j - 1] == block[i][j] || block[i][j - 1] == 0) && block[m][k] == 0)
						{
							block[m][k] = block[i][j];
							block[i][j] = 0;
						}
						else if ((block[i][j - 1] == block[i][j] || block[i][j - 1] == 0) && block[m][k] > 0)
						{
							k = k + 1;
							block[m][k] = block[i][j];
							block[i][j] = 0;
						}
						else
						{
							k++;
						}
					}
				}
			}

		}

		else if (move == 's' || move == 'S')
		{
			for (j = 0; j < 4; j++)
			{
				m = 3;
				k = j;

				for (i = 2; i >=0; i--)
				{
					if (block[i][j] > 0)
					{
						if ((block[i + 1][j] == block[i][j] || (block[i + 1][j] == 0)) && (block[m][k] == block[i][j]))
						{
							block[m][k] = block[i][j] + block[m][k];

							block[i][j] = 0;
						}

						else if ((block[i + 1][j] == block[i][j] || block[i + 1][j] == 0) && (block[m][k] == 0))
						{
							block[m][k] = block[i][j];

							block[i][j] = 0;
						}

						else if ((block[i + 1][j] == block[i][j] || (block[i + 1][j] == 0)) && (block[m][k] > 0))
						{
							m = m - 1;

							block[m][k] = block[i][j];

							block[i][j] = 0;
						}

						else
						{
							m--;
						}
					}

				}
			}


		}

		else if (move == 'd' || move == 'D')
		{
			for (i = 0; i < 4; i++)
			{
				m = i;
				k = 3;

				for (j = 2; j >=0; j--)
				{
					if (block[i][j] > 0)
					{
						if ((block[i][j + 1] == block[i][j] || block[i][j + 1] == 0) && block[m][k] == block[i][j])
						{
							block[m][k] = block[i][j] + block[m][k];
							block[i][j] = 0;
						}
						
						else if ((block[i][j + 1] == block[i][j] || block[i][j + 1] == 0) && block[m][k] == 0)
						{
							block[m][k] = block[i][j];
							block[i][j] = 0;
						}
						else if ((block[i][j + 1] == block[i][j] || block[i][j + 1] == 0) && block[m][k] > 0)
						{
							k = k - 1;
							block[m][k] = block[i][j];
							block[i][j] = 0;
						}
						else
						{
							k--;
						}
					}
				}
			}

		}

		else
		{
			cout << "Invalid input.";
			
		}
}