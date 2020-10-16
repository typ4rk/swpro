// basic_file.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

std::string GetInputFileName()
{
	char path[MAX_PATH] = { 0 };
	GetModuleFileNameA(NULL, path, _countof(path));
	std::string::size_type pos = std::string(path).find_last_of("\\/");
	std::string filename = std::string(path).substr(0, pos) + "\\input.txt";
	return filename;
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

		//Solve(numbers, questions);

		numbers.clear();
		questions.clear();
	}

	fclose(stream);
	return true;
}


int main()
{
	std::string filename = GetInputFileName();
	Read(filename);
}

//bool Read(const std::string &filename)
//{
//	std::ifstream stream;
//	stream.open(filename.c_str(), std::ios::in);
//
//	if (!stream.is_open()) {
//		DLOG("Open file is failed");
//		return false;
//	}
//
//	std::string line;
//	std::string readbuf;
//
//	while (std::getline(stream, line)) {
//		readbuf.append(line + "\n");
//	}
//
//	std::cout << readbuf.c_str() << std::endl;
//
//	stream.close();
//	return true;
//}
//
//bool Write(const std::string &filename, const bool is_append)
//{
//	unsigned int mode = std::ios::out;
//	if (is_append) {
//		mode |= std::ios::app;
//	}
//
//	std::string test = "abc haha\nABC HAHA";
//
//	std::ofstream stream;
//	stream.open(filename.c_str(), mode);
//
//	stream.write(test.c_str(), test.length());
//	stream << std::endl;
//
//	stream.close();
//	return true;
//}