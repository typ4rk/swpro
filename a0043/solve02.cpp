#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

int T, N;

int Man1[9];
int Man2[9];
int Man3[9];
int MaxScore;
vector<int> Me;


void CopyDec(vector<int> *src, vector<int> *dest, int except)
{
	for (int i = 0; i < src->size(); i++)
	{
		int card = src->at(i);
		if (except != card)
		{
			dest->push_back(card);
		}
	}
}

void Search(vector<int> *src, int round, int total)
{
	for (int i = 0; i < src->size(); i++)
	{
		int card = src->at(i);

		int card1 = Man1[round];
		int card2 = Man2[round];
		int card3 = Man3[round];

		int min = 0;
		int max = 0;
		int score = 0;

		if (card1 < card)
			min = card1;
		else
			max = card1;

		if (card2 < card && min < card2)
			min = card2;
		else if (card2 > card && max < card2)
			max = card2;

		if (card3 < card && min < card3)
			min = card3;
		else if (card3 > card && max < card3)
			max = card3;

		if (min == 0)
			score = max;
		else
			score = min;

		//printf ("%d(%d) : %d, ", card, round, score + total);

		if (src->size() > 1)
		{
			vector<int> next;

			CopyDec(src, &next, card);

			int next_rount = round + 1;

			Search(&next, next_rount, score + total);
		}
		else
		{
			if (MaxScore < score + total)
				MaxScore = score + total;
		}
	}
}


int main()
{
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N;

		MaxScore = 0;
		memset(Man1, 0, sizeof(Man1));
		memset(Man1, 0, sizeof(Man2));
		memset(Man1, 0, sizeof(Man3));

		Me.clear();

		for (int i = 1; i <= 4 * N; i++)
		{
			Me.push_back(i);
		}

		for (int i = 0; i < 3; i++)
		{
			for (int n = 1; n <= N; n++)
			{
				int card;
				cin >> card;

				vector<int>::iterator it;
				for (it = Me.begin(); it != Me.end(); it++)
				{
					if (*it == card)
					{
						Me.erase(it);
						break;
					}
				}

				if (i == 0)
					Man1[n] = card;
				else if (i == 1)
					Man2[n] = card;
				else
					Man3[n] = card;
			}
		}

		Search(&Me, 1, 0);

		cout << "#" << t << " " << MaxScore;
		cout << "\n";
	}

	return 0;
}
