#include "test.h"

using namespace std;

int number = 7;
int c[7];
vector<int> a[8];

// ���� ȿ��
void dfs(int x) {
	if (c[x]) return;

	c[x] = true;
	cout << x << ' ';

	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
	}
}

void make_connection() {
	a[1].push_back(2);
	a[1].push_back(3);

	a[2].push_back(1);
	a[2].push_back(3);
	a[2].push_back(4);
	a[2].push_back(5);

	a[3].push_back(1);	
	a[3].push_back(2);
	a[3].push_back(6);
	a[3].push_back(7);

	a[4].push_back(2);
	a[4].push_back(5);
	
	a[5].push_back(2);
	a[5].push_back(4);
	
	a[6].push_back(3);
	a[6].push_back(7);
	
	a[7].push_back(3);
	a[7].push_back(6);
}