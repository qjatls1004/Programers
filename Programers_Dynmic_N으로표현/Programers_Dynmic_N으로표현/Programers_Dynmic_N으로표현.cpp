// Programers_Dynmic_N으로표현.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


#include <string>
#include <vector>

using namespace std;

#include <unordered_set>
int solution(int N, int number) 
{
	int answer = -1;
	int sum=0;
	unordered_set<int> dp[8];
	for (int i = 0; i < 8; i++) {
		sum = sum * 10 + N;
		dp[i].emplace(sum);
	}
	for (int i = 1; i < 8; ++i) {
		for (int j = 0; j < i; ++j) {
			for (auto itori = dp[j].begin(); itori != dp[j].end(); itori++) {
				for (auto itorj = dp[i - j - 1].begin(); itorj != dp[i - j - 1].end(); itorj++) {
					dp[i].emplace(*itori + *itorj);
					dp[i].emplace(*itori - *itorj);
					dp[i].emplace(*itori * *itorj);
					if (*itorj != 0)
						dp[i].emplace(*itori / *itorj);
				}
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		if (dp[i].find(number) != dp[i].end())
			return i + 1;
	}
	return answer;
}

int main()
{
	solution(5, 12);
    return 0;
}

