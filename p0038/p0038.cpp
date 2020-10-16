// p0038.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <iostream>
#include <sstream>
#include <fstream>
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

struct Number {
	int index;
	int value;
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

	for (const auto &num : numbers) {
		auto iter = m.find(num);
		if (iter != m.end()) {
			iter->second.emplace_back(index);
			continue;
		}

		std::vector<int> index_list;
		index_list.emplace_back(index);

		m.insert(std::pair<int, std::vector<int>>(num, index_list));
		index++;
	}
}

int Solve(const std::vector<int> &numbers, const std::vector<Quest> &questions)
{
	MakeTree(numbers);

	for (std::map<int, std::vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << ": ";
		for (const auto &index : it->second) {
			std::cout << index <<", ";
		}
		std::cout << std::endl;
	}
	return 0;
}

bool Read(const std::string &filename)
{
	FILE *stream;
	freopen_s(&stream, filename.c_str(), "r", stdin);
	
	int T;
	scanf_s("%d", &T);

	int N, Q;

	std::vector<int> numbers;
	std::vector<Quest> questions;

	while (T--) {
		scanf_s("%d %d", &N, &Q);

		numbers.reserve(N);

		int num;
		while (N--) {
			scanf_s("%d", &num);
			numbers.emplace_back(num);
		}

		questions.reserve(Q);

		Quest q;
		while (Q--) {
			scanf_s("%d %d %d", &q.start, &q.end, &q.cutline);
			questions.emplace_back(q);
		}

		Solve(numbers, questions);
		
		numbers.clear();
		questions.clear();
	}

	fclose(stream);
	return true;
}

bool Write(const std::string &filename, const bool is_append)
{
	unsigned int mode = std::ios::out;
	if (is_append) {
		mode |= std::ios::app;
	}

	std::string test = "abc haha\nABC HAHA";

	std::ofstream stream;
	stream.open(filename.c_str(), mode);

	stream.write(test.c_str(), test.length());
	stream << std::endl;

	stream.close();
	return true;
}

std::string GetInputFileName()
{
	char path[MAX_PATH] = { 0 };
	GetModuleFileNameA(NULL, path, _countof(path));
	std::string::size_type pos = std::string(path).find_last_of("\\/");
	std::string filename = std::string(path).substr(0, pos) + "\\input.txt";
	return filename;
}

int main()
{
	std::string filename = GetInputFileName();

	//Write(filename, true);
	Read(filename);
}

