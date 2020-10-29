#include <cstdio> 
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 3

//int score[MAX][MAX] = { {1, 11, 2}, {6, 5, 2}, {8, 11, 10} };
int score[MAX][MAX] = { {1, 6, 8}, {11, 5, 11}, {2, 2, 10} };

int calc(vector<int> &v) {
	int sum = 0;

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
		sum += score[i][v[i]];
	}
	cout << "sum = " << sum;
	cout << "\n";
	return sum;
}

int main() {
	int a[3] = { 0, 1, 2 };	
	int sum = 0;
	int max = 0;
	vector<int> v;
	for (int i = 0; i < 3; i++)v.push_back(a[i]);

	//오름차순
	do {
		sum = calc(v);	
		if (max < sum) {
			max = sum;
		}
	} while (next_permutation(v.begin(), v.end()));


	cout << "max = " << max;

	

	//cout << "-------------" << '\n';
	//v.clear();
	//for (int i = 2; i >= 0; i--)v.push_back(a[i]);
	////3, 2, 1부터 내림차순으로 순열을 뽑습니다.  
	//do {
	//	printV(v);
	//} while (prev_permutation(v.begin(), v.end()));
	return 0;
}
