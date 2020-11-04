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

#ifndef _USE_FILE
#include <windows.h>
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

int T;
int N;
int card[8][3];
int visited[33];
vector<int> target;
vector<int> pick;
vector<int> ans;

void backTracking(int idx, int cnt) {
	if (cnt == N) {
		int temp = 0;

		for (int i = 0; i < N; i++) {
			if (pick[i] < card[i][0]) {
				temp += card[i][2];
			}
			else {
				for (int j = 2; j >= 0; j--) {
					if (pick[i] > card[i][j]) {
						temp += card[i][j];
						break;
					}
				}
			}
		}

		ans.push_back(temp);
		return;
	}
	else {
		//for (int n = idx; n < N; n++) {
		for (int i = 0; i < N; i++) {
			if (visited[target[i]] == 1) continue;

			visited[target[i]]++;
			pick.push_back(target[i]);
			backTracking(idx + 1, cnt + 1);
			pick.pop_back();
			visited[target[i]]--;
		}
		//}

	}
}

void solve03()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	FILE* stream;
	std::string filename = GetInputFileName();
	freopen_s(&stream, filename.c_str(), "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		// 초기화
		ans.clear();
		pick.clear();
		target.clear();
		fill_n(visited, 33, 0);

		for (int i = 0; i < 3; i++) {
			for (int n = 0; n < N; n++) {
				cin >> card[n][i];
				visited[card[n][i]]++;
			}
		}

		for (int n = 0; n < N; n++) {
			sort(card[n], card[n] + 3);
		}

		for (int i = 1; i <= 4 * N; i++) {
			if (visited[i] == 0) {
				target.push_back(i);
			}
		}

		backTracking(0, 0);
		sort(ans.begin(), ans.end());

		cout << "#" << t << " " << ans[ans.size() - 1] << "\n";
	}

	fclose(stream);
}
int main()
{
	//Read();
	solve03();
	return 0;
}
