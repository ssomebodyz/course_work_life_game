#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<locale.h> 
#include<iostream> 
#include <Windows.h> 
#pragma warning (disable:4996); 
char **Field = {};
char **DopField = {};
char **DopField1 = {};
int check = 0;
bool checker = false;
#define SizeForMemory 1000
using namespace std;
void copyField1(int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			DopField1[i][j] = Field[i][j];
		}
	}
}
void copyField(int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			Field[i][j] = DopField[i][j];
		}
	}
}
int FindDoubleVerticalValue(int i, int j, int size)// Vert$$
{
	int flag = -1;
	if (Field[i][1] == '$')
	{
		return (size - 1);
	}
	else
	{
		while (Field[i][j] != '$')
		{
			flag++;
			j++;
		}
		flag += 2;
		j += 2;
		while (Field[i][j] != '$')
		{
			flag++;
			j++;
		}

		return (flag);
	}
}
int VertValue(int i, int  j, int size)
{
	int pos = 1;
	while (Field[i][j - 1] != '$')
	{
		i++; pos++;
	}

	return (pos + 1);
}
int FindVerticalValue(int i, int j, int size)//Vert$
{
	int Pos = 1;
	while (Field[i][j] != '$')
	{
		Pos++; j++;
	}

	return Pos;
}
int FindDoubleGhorizontalValue(int i, int j, int size)//Find $$
{
	int flag = -1;
	if (Field[i][1] == '%')
	{
		return (size - 1);
	}
	else
	{
		while (Field[i][j] != '%')
		{
			flag++;
			j++;
		}
		flag++;
		while (Field[i][j] != '%')
		{
			flag++;
			j++;
		}
		return (flag - 1);
	}
}
int FindGhorizontalValue(int i, int j, int size)//Find$
{
	int Pos = 1;
	while (Field[i][j] != '%')
	{
		Pos++; j++;
	}
	return Pos - 1;
}
int countNeighbours(int i, int j)// countN
{
	int count = 0;
	if (Field[i][j + 1] == '*')
	{
		count++;
	}
	if (Field[i][j - 1] == '*')
	{
		count++;
	}
	if (Field[i - 1][j] == '*')
	{
		count++;
	}
	if (Field[i - 1][j - 1] == '*')
	{
		count++;
	}
	if (Field[i - 1][j + 1] == '*')
	{
		count++;
	}
	if (Field[i + 1][j - 1] == '*')
	{
		count++;
	}
	if (Field[i + 1][j] == '*')
	{
		count++;
	}
	if (Field[i + 1][j + 1] == '*')
	{
		count++;
	}
	return count;
}
int check_the_end_of_the_game(int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Field[i][j] == DopField[i][j])
			{
				count++;
			}

		}
	}
	if (count == size * size)
	{
		return 1;
	}
	else return 0;
}
int check_the_end_of_the_game1(int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (DopField[i][j] == DopField1[i][j])
			{
				count++;
			}
		}
	}
	if (count == size * size)
	{
		return 1;
	}
	else return 0;
}
void SetFirstFieldValues(int size)
{
	int counter = 0;
	printf("Choose the coordinates!:\nInput 'end' if you want to stop input\n");
    twice:printf("Press 1 to set GLAIDER, Press 2 for self-input \n");
	char choice[2];
	scanf("%s", &choice);
	if ((choice[0] != '1' && choice[0] != '2') || strlen(choice)!=1)
	{
		memset(choice, 0, sizeof(char));
		printf("Error! Stop try to break our programm please!\n"); goto twice;
	}
	if (choice[0] == '1')
	{
		Field[5][18] = '*'; Field[6][19] = '*'; Field[7][19] = '*'; Field[7][18] = '*'; Field[7][17] = '*';
		printf("GLIDER IS READY!\n");
		counter++;
		repeat :char chooser[2];
		printf("1- Continue inputing\n2-Exit\n");
		scanf("%s", &chooser);
		printf("\n");
		if (chooser[0] =='2' && strlen(chooser)==1)
		{
			return;
		}

		if (chooser[0] == '1' && strlen(chooser)==1)
		{
			goto twice;
		}
		else goto repeat;
	}
	while (1)
	{
	    agai:char xcor[4];
		char ycor[4];
		bool xcheck = false;
		bool ycheck = true;
		char symbols[9] = { '1','2','3','4','5','6','7','8','9' };
		int count1 = 0,count2 = 0, count3 = 0, count4 = 0;
		printf("\nInput y coordinate:");
		getchar();
		scanf("%s", &xcor);
		for (int i = 0; i < 9; i++)
		{
			if (xcor[0] == symbols[i])
			{
				count1++;
			}
			if (xcor[1] == symbols[i])
			{
				count2++;
			}

		}
		if (xcor[0] == 'e' && xcor[1] == 'n' && xcor[2] == 'd' && strlen(xcor)==3)
		{
			return;
		}
		if ((count1 <1 && count2 <1) || (strlen(xcor)>2))
		{
			printf("ERROR ON THE SCREEN!\n");
			memset(xcor, 0, sizeof(char));
			goto agai;
		}
		int x, y;
		printf("\n");
		x = atof(xcor);
		if (x > 25)
		{
			printf("Too big value\n");
			goto agai;
		}
		printf("\nInput x coordinate:");
		getchar();
		scanf("%s", &ycor);
		for (int i = 0; i < 9; i++)
		{
			if (ycor[0] == symbols[i])
			{
				count3++;
			}
			if (ycor[1] == symbols[i])
			{
				count4++;
			}

		}
		if (ycor[0] == 'e' && ycor[1] == 'n' && ycor[2] == 'd' && strlen(ycor)==3)
		{
			return;
		}
		if ((count4 <1 && count4 <1) || strlen(ycor)>2)
		{
			printf("ERROR ON THE SCREEN!\n");
			memset(ycor, 0, sizeof(char));
			goto agai;
		}
		y = atof(ycor);
		if (y > 25)
		{
			printf("\nToo big value\n");
			goto agai;
		}
		Field[x][y] = '*';
		printf("-------------------------------------------------------\n");
	}

}

int InvalidFunction(int i, int j, int size)// то,что надо переделать
{
	if (Field[i][j + 1] == '$')
	{
		return 1;
	}
	if (Field[i][j - 1] == '$')
	{
		return 1;
	}
	if (Field[i + 1][j] == '$')
	{
		return 2;
	}
	if (Field[i - 1][j] == '$')
	{
		return 2;
	}

	if (Field[i + 1][j + 1] == '$')
	{
		return 2;
	}
	if (Field[i - 1][j + 1] == '$')
	{
		return 2;
	}
	if (Field[i - 1][j - 1] == '$')
	{
		return 2;
	}
	if (Field[i + 1][j - 1] == '$')
	{
		return 2;
	}
	return-1;
}
void put(int i, int j, int count, bool life)
{
	if (count == 3 && life == false)
	{
		DopField[i][j] = '*';
		count = 0;
	}
	if ((count == 2 || count == 3) && life == true)
	{
		DopField[i][j] = '*';
		count = 0;
	}
	else if (count >= 4 && life == true)
	{
		DopField[i][j] = ' ';
		count = 0;
	}
	else if (count < 2 && life == true)
	{
		DopField[i][j] = ' ';
		count = 0;
	}
}
void check_is_alive(int size)
{
	int Pos2;
	bool check = false;
	int count = 0;
	bool life = true;
	for (int i = 2; i < size - 2; i++)
	{
		//21 3 21 26
		for (int j = 1; j < size - 2; j++)
		{
			count = 0;
			check = false;
			life = true;
			if (Field[i][j] != '*')
			{
				life = false;
			}
			Pos2 = i;
			count = countNeighbours(i, j);
			if (InvalidFunction(i, j, size - 1)>0)
			{
				if (Field[i][j + 1] == '$')
				{
					if (Field[i + 1][j] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i + 1][j + 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i + 1][j - 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					Pos2 = i + 1;
					int Pos = FindVerticalValue(Pos2, 0, size - 1);
					Pos -= 2;
					if (Field[Pos2][Pos] == '*')
					{
						count++;
					}
					count += countNeighbours(Pos2, Pos);
					put(i, j, count, life);
					continue;

				}
				if (Field[i][j + 2] == '$' &&Field[i + 1][j] == '$')
				{
					if (Field[i + 1][j] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i + 1][j + 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i + 1][j - 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					int Pos = FindVerticalValue(Pos2, 0, size - 1);
					if (Field[i + 1][j] == '$')
					{
						Pos2 = i + 1;
					}
					else if (Field[i - 1][j] == '$')
					{
						Pos2 = i - 1;
					}

					Pos++;
					if (Field[Pos2][Pos] == '*')
					{
						count++;
					}
					count += countNeighbours(Pos2, Pos);
					put(i, j, count, life);
					continue;
				}
				if (Field[i][j + 2] == '$' &&Field[i + 1][j] == '$')
				{
					if (Field[i + 1][j] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i + 1][j + 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i + 1][j - 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					int Pos = FindVerticalValue(Pos2, 0, size - 1);
					if (Field[i - 1][j] == '$')
					{
						Pos2 = i + 1;
					}
					else
					{
						Pos2 = i - 1;
					}

					Pos++;
					if (Field[Pos2][Pos] == '*')
					{
						count++;
					}
					count += countNeighbours(Pos2, Pos);
					put(i, j, count, life);
					continue;
				}
				if (Field[i][j - 1] == '$')
				{
					if (Field[i + 1][j] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i + 1][j + 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i + 1][j - 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i - 1][j] == '$')
					{
						Pos2 = i + 1;
					}
					else
					{
						Pos2 = i - 1;
					}
					int Pos = FindDoubleVerticalValue(Pos2, 0, size - 1);
					Pos += 2;
					if (Field[Pos2][Pos] == '*')
					{
						count++;
					}
					count += countNeighbours(Pos2, Pos);
					put(i, j, count, life);
					continue;
				}
				if (Field[i][j - 2] == '$')
				{
					if (Field[i + 1][j] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i + 1][j + 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i + 1][j - 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}

					int Pos = FindDoubleVerticalValue(i, 0, size - 1);
					if (Field[i - 1][j] == '$')
					{
						Pos2 = i + 1;
					}
					else
					{
						Pos2 = i - 1;
					}
					Pos--;
					if (Field[Pos2][Pos] == '*')
					{
						count++;
					}
					count += countNeighbours(Pos2, Pos);
					put(i, j, count, life);
					continue;
				}
				if (Field[i + 1][j + 1] == '$')
				{
					if (Field[i + 1][j] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i + 1][j + 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i + 1][j - 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					Pos2 = i + 1;
					int Pos = FindVerticalValue(Pos2, 0, size - 1);
					count += countNeighbours(Pos2, Pos);
					put(i, j, count, life);
					continue;
				}
				if (Field[i - 1][j + 1] == '$')
				{

					if (Field[i - 1][j] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i - 1][j + 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i - 1][j - 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					Pos2 = i - 1;
					int Pos = FindVerticalValue(Pos2, 0, size - 1);
					count += countNeighbours(Pos2, Pos);
					put(i, j, count, life);
					continue;
				}
				if (Field[i + 1][j - 1] == '$')
				{
					Pos2 = i + 1;
					if (Field[i + 1][j] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i + 1][j + 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i + 1][j - 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					int Pos = FindDoubleVerticalValue(Pos2, 0, size - 1);
					count += countNeighbours(Pos2, Pos);
					put(i, j, count, life);
					continue;
				}
				if (Field[i - 1][j - 1] == '$')
				{
					Pos2 = i - 1;
					if (Field[i - 1][j] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i - 1][j + 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					if (Field[i - 1][j - 1] == '*')
					{
						put(i, j, count, life);
						continue;
					}
					int Pos = FindDoubleVerticalValue(Pos2, 0, size - 1);
					count += countNeighbours(Pos2, Pos);
					put(i, j, count, life);
					continue;
				}
			}
			if (InvalidFunction(i, j, size - 1) == -1)
			{
				if (Field[i][j + 1] == '%')
				{
					int Pos = FindGhorizontalValue(i, 0, size - 1);

					if (Field[i][Pos] == '*')
					{
						count++;
					}
					count += countNeighbours(i, Pos);
					put(i, j, count, life);
				}
				else if (Field[i][j - 1] == '%')
				{
					int Pos = FindDoubleGhorizontalValue(i, 0, size - 1);
					if (Field[i][Pos] == '*')
					{
						count++;
					}
					count += countNeighbours(i, Pos);
					put(i, j, count, life);
				}

			}
			put(i, j, count, life);
		}

	}
}

void play(int size)
{
	for (int i = 2; i < size - 2; i++)
	{
		for (int j = 1; j < size - 1; j++)
		{
			int num = rand() + 5;
			if (num % 2 == 0)
			{
				Field[i][j] = '*';
			}
			else
			{
				Field[i][j] = ' ';
			}
		}
	}
}

void ReadTheGameOverFile()
{
	char symbol;
	FILE* file = fopen("1.txt", "r");
	symbol = fgetc(file);
	while (symbol != EOF)
	{
		symbol = fgetc(file);
		if (symbol == EOF)
		{
			symbol = ' ';
			break;
		}
		printf("%c", symbol);
	}
}
void PrintTheGameOverImage()
{
	ReadTheGameOverFile();
}
void printField(int size)
{
	system("cls");
	int k = 2;
	int e = 0;
	int l = size / 2, r = size / 2;
	int i = 0;
	k = 0; int t = size / 2;
	while (t > 0)
	{
		Field[i][l - k] = '$';
		Field[i][r + k] = '$';
		Field[size - i - 1][l - k] = '$';
		Field[size - i - 1][r + k] = '$';
		DopField[i][l - k] = '$';
		DopField[i][r + k] = '$';
		DopField[size - i - 1][l - k] = '$';
		DopField[size - i - 1][r + k] = '$';
		i++; k += 2;
		t--;
	}
	for (int i = size / 4; i < size - (size / 4); i++)
	{
		Field[i][1] = '%';
		Field[i][size - 2] = '%';
		DopField[i][1] = '%';
		DopField[i][size - 2] = '%';
		k += 2;
	}

	for (int i = 1; i < size - 1; i++)
	{
		int j = 0;
		while (Field[i][j] != '%'&&Field[i][j] != '$')
		{
			Field[i][j] = ' ';
			DopField[i][j] = ' ';
			j++;
		}
		int y = size - 1;
		while (Field[i][y] != '%'&&Field[i][y] != '$')
		{
			Field[i][y] = ' ';
			DopField[i][y] = ' ';
			y--;
		}
	}
	Field[0][(size / 2)] = '$';
	Field[size - 1][(size / 2)] = '$';
	for (int i = 0; i < size; i++)
	{
		printf(" ");
		for (int j = 1; j < size - 1; j++)
		{
			printf("%c ", Field[i][j]);
		}
		printf("\n");
	}
}
void setMemory(int size)
{
	Field = (char **)malloc(size * sizeof(char *));
	DopField = (char **)malloc(size * sizeof(char *));
	DopField1 = (char **)malloc(size * sizeof(char *));
	for (int i = 0; i < size; i++)
	{
		Field[i] = (char *)malloc(SizeForMemory * sizeof(char));
		DopField[i] = (char *)malloc(SizeForMemory * sizeof(char));
		DopField1[i] = (char *)malloc(SizeForMemory * sizeof(char));
		memset(Field[i], 0, SizeForMemory * sizeof(char));
		memset(DopField[i], 0, SizeForMemory * sizeof(char));
		memset(DopField1[i], 0, SizeForMemory * sizeof(char));
	}
}
void ListMenu()
{
	int count;
	setlocale(LC_ALL, "Rus");
	printf("Insert the size of the field:\n");
	while (true)
	{
		repeat:char SizeOftheField[2];
		int count1 = 0;
		int count2 = 0;
		char symbols[9] = { '1','2','3','4','5','6','7','8','9' };
	    scanf("%s", &SizeOftheField);
		for (int i = 0; i < 9; i++)
		{
			if (SizeOftheField[0] == symbols[i])
			{
				count1++;
				continue;
			}
			if (SizeOftheField[1] == symbols[i])
			{
				count2++;
			}
			
		}
		if (count1!=1  || strlen(SizeOftheField)>2 )
		{
			printf("ERROR!\n");
			for (int i = 0; i < strlen(SizeOftheField); i++)
			{
				SizeOftheField[i] = 0;
			}
			goto repeat;
		}
		int SizeOftheField1 = atof(SizeOftheField);
		if (SizeOftheField1 <= 4 || SizeOftheField1 >= 25)
		{
			printf("This size is very small or very big!\n");
			continue;
		}
		SizeOftheField1 = SizeOftheField1 * 2;
		SizeOftheField1++;
		setMemory(SizeOftheField1);
		printf("Выбeрите :\n1-Random input\n2-Input yourself\n");
		enum menu { SetValuesByRand = 1, SetValuesByMyself = 2 };
		check :char choose[2];
		scanf("%s", &choose);
		
		if (choose[0] != '1' && choose[0] != '2' && strlen(choose)>1)
		{
			printf("ERROR!\n");
			goto check;
		}
		int krock = atof(choose);
		switch (krock)
		{
		case SetValuesByRand:
		{
			play(SizeOftheField1);
			break;
		}
		case SetValuesByMyself:
		{
			SetFirstFieldValues(SizeOftheField1);
			break;
		}
		}
		printField(SizeOftheField1);
		copyField1(SizeOftheField1);
		check = 1;
		while (1)
		{
			Sleep(50);
			printField(SizeOftheField1);
			//system("pause");
			check_is_alive(SizeOftheField1);
			if (check_the_end_of_the_game(SizeOftheField1) == 1)
			{
				system("pause");
				system("cls");
				PrintTheGameOverImage();
				system("pause>>NULL");
				exit(0);
			}
			if (check % 3 == 0)
			{

				if (check_the_end_of_the_game1(SizeOftheField1) == 1)
				{
					system("pause");
					system("cls");
					PrintTheGameOverImage();
					system("pause>>NULL");
					exit(0);
				}
				copyField1(SizeOftheField1);
			}
			copyField(SizeOftheField1);
			check++;
			checker = false;
			//check_is_dead(kek); 
			// printField(kek); 
			//system("pause");
		}
	}
	system("pause");
}
void StartOurGame()
{
	cout << "\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::" << endl;
	cout << "\t\t\t\t\t\t\t\t::::::::WELCOME TO THE GAME OF LIFE:::::::" << endl;
	cout << "\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::\n" << endl;
}
int main()
{
	StartOurGame();
	ListMenu();
	return 0;
}