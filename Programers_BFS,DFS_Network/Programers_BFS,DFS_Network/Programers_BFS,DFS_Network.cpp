// Programers_BFS,DFS_Network.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;
int check[200] = { 0, };
int Allcheck(int n) {
	for (int i = 0; i < n; i++)
		if (check[i] == 0)
			return i;
	return 0;
}
void dfs(int x, int n,int &component, vector < vector <int> > &v)
{
	if (check[x] != 0)
		return;
	check[x] = component;
	for (int i = 0; i < n; i++)
	{
		if (v[x][i]||v[i][x])
		{
			if (check[i] == 0)
				dfs(i,n, component,v);
		}
	}	
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 1;
	int node = 1;
	dfs(0, n, answer, computers);
	while (true) {
		node = Allcheck(n);
		if (node == 0)
			break;
		dfs(node, n, ++answer, computers);

	}
	return answer;
}

int main()
{
	vector<vector<int>> computers = { {1,1,1,0},{1,1,0,0},{1,0,1,1},{ 0,0,1,1 } };
	solution(4, computers);
    return 0;
}

