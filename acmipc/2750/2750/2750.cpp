// 2750.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "stdio.h"
#include <iostream>
#include <algorithm>

int number, data[1000001];

void quickSort(int* data, int start, int end) {
    if (start >= end) {
        return;
    }
    int key = start;
    int i = start + 1, j = end, temp;
    while (i <= j) {
        while (data[i] <= data[key]) {
            i++;
        }
        while (data[j] >= data[key] && j > start) {
            j--;
        }
        if (i > j) {
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        }
        else {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}

int main()
{
    int i, j, min, index, temp;
    scanf("%d", &number);
    for (i = 0; i < number; i++) {
        scanf("%d", &data[i]);
    }
    //quickSort(data, 0, number - 1);   
    std::sort(data, data + number);

    for (i = 0; i < number; i++) {
        printf("%d\n", data[i]);
    }
}

