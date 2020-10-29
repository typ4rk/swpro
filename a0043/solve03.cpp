#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		// √ ±‚»≠
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

	return 0;
}
