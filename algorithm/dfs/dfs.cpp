// dfs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define MAX 5
using namespace std;

int Arr[MAX];
bool Select[MAX];

void Print()
{
	for (int i = 0; i < MAX; i++)
	{
		if (Select[i] == true)
		{
			cout << Arr[i] << " ";
		}
	}
	cout << endl;

}

void Permutation(int Idx, int Cnt)
{
	if (Cnt == 3)
	{
		Print();
		return;
	}

	for (int i = Idx; i < MAX; i++)
	{
		if (Select[i] == true) continue;

		Select[i] = true;
		Permutation(i, Cnt + 1);
		Select[i] = false;
	}
}

#include "test.h"

int main(void)
{
	// DFS
	//make_connection();
	//dfs(1);

	// ¼ø¿­
	Arr[0] = 1;
	Arr[1] = 2;
	Arr[2] = 3;
	Arr[3] = 4;
	Arr[4] = 5;
	Permutation(0, 0);

	return 0;
}