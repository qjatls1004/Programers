// Programers_Dynmic_정수삼각형.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	vector<vector<int>> add;
	vector<int> temp;
	int sum;
	int height = triangle.size();
	for (int i = 0; i < height; i++) 
	{
		temp.push_back(0);
		add.push_back(temp);
	}
	add[0][0] = triangle[0][0];
	for (int i = 1; i < height; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				add[i][j] = add[i - 1][j] + triangle[i][j];
			else if (j == i)
				add[i][j] = add[i - 1][j-1] + triangle[i][j];
			else {
				add[i][j] = __max(add[i - 1][j], add[i - 1][j-1])+ triangle[i][j];
			}
		}
	}
	
	for (int i = 0; i < height; i++)
	{
		//if (answer < add[height - 1][i])
			answer = __max(add[height - 1][i],answer);
	}
	return answer;
}

int main()
{
	vector<vector<int>> triangle = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
	solution(triangle);
    return 0;
}

