// programers_heap_DiskController.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(vector<int>&a, vector<int>&b) {
	if (a[0] == b[0])
		return a[1] < b[1];
	return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int jSize = jobs.size();
	multimap<int, int> mjobs;
	//sort(Tjobs.begin(), Tjobs.end(), Tcmp);
	sort(jobs.begin(), jobs.end(), cmp);

	int iCulTime = 0; int iSpentime = 0;
	int iAllSpTime = 0;

	iCulTime = jobs[0][0] + jobs[0][1];
	iAllSpTime = jobs[0][1];
	int count = 1;
	while (true)
	{
		while (true) {
			if (count >= jSize)
				break;
			if (jobs[count][0] <= iCulTime) {
				mjobs.emplace(make_pair(jobs[count][1], jobs[count][0]));
				count++;
			}
			else break;
		}
		if (mjobs.empty()) {
			if (count >= jSize)
				break;
			iCulTime = jobs[count][0] + jobs[count][1];
			iAllSpTime += jobs[count][1];
			count++;

		}
		else {
			auto itor = mjobs.begin();
			iCulTime += itor->first;
			iSpentime = iCulTime - itor->second;
			iAllSpTime += iSpentime;
			mjobs.erase(itor);
		}
	}
	answer = (double)iAllSpTime / jSize;
	return answer;
}

int main()
{
	vector<vector<int>> jobs;
	vector<int> temp;
	temp.push_back(0);
	temp.push_back(3);
	jobs.push_back(temp);
	temp.clear();
	temp.push_back(0);
	temp.push_back(4);
	jobs.push_back(temp);
	temp.clear();
	temp.push_back(10);
	temp.push_back(6);
	jobs.push_back(temp);
	temp.clear();
	solution(jobs);
	return 0;
}

