// programers BinarySearch 징검다리.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	rocks.push_back(distance);
	sort(rocks.begin(), rocks.end());
	int iSizeRocks = rocks.size();
	unsigned long long left = 0, mid, right = distance;
	int popRocks = 0, curRock;
	unsigned long long dist, min_dist;
	while (left <= right)
	{
		mid = (left + right) / 2;
		popRocks = 0;
		curRock = 0;
		min_dist = distance;
		for (int i = 0; i < iSizeRocks; i++) {
			dist = abs(rocks[i] - curRock);
			if (dist < mid) { 
				popRocks++;
			}
			else {
				curRock = rocks[i];
				min_dist = min(min_dist, dist);
			}
		}
		if (popRocks > n)
			right = mid - 1;
		else {
			left = mid + 1;
			answer = min_dist;
		}
	}
	//answer = mid;
	return answer;
}

int main()
{
	vector<int> rocks = { 2, 14, 11, 21, 17 };
	solution(25, rocks, 2);
    return 0;
}

