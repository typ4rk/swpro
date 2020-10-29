// a0043.cpp 
//

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 8
std::vector<int> last_card;

#ifdef _USE_FILE
std::string GetInputFileName()
{
	char path[MAX_PATH] = { 0 };
	GetModuleFileNameA(NULL, path, _countof(path));
	std::string::size_type pos = std::string(path).find_last_of("\\/");
	std::string filename = std::string(path).substr(0, pos) + "\\input.txt";
	return filename;
}
#endif

int calc(vector<int> &v, const vector<vector<int>> &score) {
	int sum = 0;

	for (int i = 0; i < v.size(); i++) {
		sum += score[i][v[i]];
	}
	return sum;
}

bool Read()
{
#ifdef _USE_FILE
	FILE *stream;
	std::string filename = GetInputFileName();
	freopen_s(&stream, filename.c_str(), "r", stdin);
#endif

	int T;
	scanf("%d", &T);

	int N;

	bool list[4 * MAX + 1];

	int T_index = 1;

	while (T--) {
		scanf("%d", &N);
		
		vector<vector<int>> card(N);
		memset(list, NULL, sizeof(list));

		int num;		
		int player = 0;
		while (player < 3) {
			int round = 0;
			while (round < N) {
				scanf("%d", &num);
				card[round++].emplace_back(num);
				list[num] = true;
			}
			player++;
		}

		for (int i = 1; i <= 4*N; i++) {
			if (list[i] == false) {
				last_card.emplace_back(i);
			}
		}

		vector<vector<int>> score(N);

		for (int round = 0; round <N ; round++){
			std::sort(card[round].begin(), card[round].end());

			for (auto mycard : last_card) {
				int select = -1;
				for (auto item : card[round]) {					
					if (item > mycard) {
						break;
					}
					select = item;
				}
				
				if (select == -1) {
					select = card[round][2];
				}
				score[round].emplace_back(select);
			}
		}
		
		vector<int> v;
		for (int i = 0; i < N; i++) {
			v.emplace_back(i);
		}

		//오름차순
		int sum = 0;
		int max = 0;

		do {
			sum = calc(v, score);
			if (max < sum) {
				max = sum;
			}
		} while (next_permutation(v.begin(), v.end()));

		std::cout << "#" << T_index++ << " " << max << std::endl;

		last_card.clear();
		card.clear();
		score.clear();
		v.clear();
	}

#ifdef _USE_FILE
	fclose(stream);
#endif
	return true;
}

int main()
{
	Read();
	return 0;
}
