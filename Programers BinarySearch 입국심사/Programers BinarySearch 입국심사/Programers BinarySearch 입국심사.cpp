// Programers BinarySearch 입국심사.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	unsigned long long answer = 0;
	sort(times.begin(), times.end());

	unsigned long long low = 1;
	unsigned long long high = times[times.size() - 1] * n;

	while (low <= high) {
		unsigned long long mid = (low + high) / 2;
		unsigned long long cnt = 0;

		for (int i = 0; i < times.size(); i++) {
			cnt += mid / times[i];
		}

		if (cnt >= n) {
			if (answer == 0)
				answer = mid;
			else
				answer = min(answer, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return answer;
}

int main()
{
    return 0;
}

