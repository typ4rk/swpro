// p0038.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <functional>

#define DLOG(...)	printf(__VA_ARGS__)

struct Quest {
	int start;
	int end;
	int cutline;
};

bool compare(int a, int b)
{
	return a > b;
}
  
//std::set<int, std::function<bool(int, int)> > s(compare);
std::map<int, std::vector<int>, std::function<bool(int, int)> > m(compare);

void MakeTree(const std::vector<int> &numbers)
{
	int index = 1;
	if (!m.empty()) {
		m.clear();
	}

	for (const auto &num : numbers) {
		auto it = m.find(num);
		if (it != m.end()) {
			it->second.emplace_back(index++);
			continue;
		}

		std::vector<int> index_list;
		index_list.emplace_back(index++);

		m.insert(std::pair<int, std::vector<int>>(num, index_list));
		//index++;
	}
}

int Solve(const std::vector<int> &numbers, const Quest &question)
{
	//PRINT
	//std::cout << std::endl;
	//for (std::map<int, std::vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
	//	std::cout << it->first << ": ";
	//	for (const auto &index : it->second) {
	//		std::cout << index << ", ";
	//	}
	//	std::cout << std::endl;
	//}

	int total = 0;
	for (std::map<int, std::vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
		if (it->first <= question.cutline) {
			break;
		}

		int sum = 0;
		std::for_each(it->second.begin(), it->second.end(), [&question, &sum](const int index) {
			if (index >= question.start && index <= question.end) {
				sum += 1;
			}
		});

		total += sum;

		//PRINT
		//std::cout << "===============" << std::endl;
		//std::cout << it->first << ": " << sum << std::endl;
	}

	//PRINT
	//std::cout << "Total: " << total << std::endl;
	return total;
}

bool Read()
{
	freopen("sample_input.txt", "r", stdin);
	
	int T;
	scanf("%d", &T);

	int N, Q;

	std::vector<int> numbers;
	std::vector<Quest> questions;

	int T_index = 1;

	while (T--) {
		scanf("%d %d", &N, &Q);

		numbers.reserve(N);

		int num;
		while (N--) {
			scanf("%d", &num);
			numbers.emplace_back(num);
		}

		MakeTree(numbers);
		
		std::cout << "#" << T_index++;

		Quest q;
		while (Q--) {
			scanf("%d %d %d", &q.start, &q.end, &q.cutline);
			std::cout << " " << Solve(numbers, q);
		}

		std::cout << std::endl;		
		
		numbers.clear();
		questions.clear();
	}

	return true;
}

int main()
{
	Read();
}

