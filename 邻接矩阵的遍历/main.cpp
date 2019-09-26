#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;
bool visit[MAX];
int Graph[MAX][MAX];
queue <int> Q;
int n, m;

void BFS(int cur) {
	cout << cur << " ";
	visit[cur] = true;
	Q.push(cur);
	while (!Q.empty()) {
		for (int i = 1; i <= n; i++) {
			if (!visit[i] && Graph[i][cur] != 0) {
				cout << i << " ";
				visit[i] = true;
				Q.push(i);
			}
		}
		cur = Q.front();
		Q.pop();
	}
}

void DFS(int cur) {
	visit[cur] = true;
	cout << cur << " ";
	for (int i = 1; i <= n; i++) {
		if (!visit[i] && Graph[i][cur] != 0) {
			DFS(i);
		}
	}
}

void Init() {
	cin >> n >> m;
	memset(visit, false, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			Graph[i][j] = Graph[j][i] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int row, col, value;
		cin >> row >> col >> value;
		Graph[row][col] = Graph[col][row] = value;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << Graph[i][j] << " ";
		}
		putchar(10);
	}
}

int main() {
	Init();
	cout << "广度优先搜索:" << endl;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) BFS(i);
	}
	putchar(10);
	memset(visit, false, n);
	cout << "深度优先搜索" << endl;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) DFS(i);
	}
	return 0;
}
/*
7 7
1 2 1
1 5 1
2 3 1
2 6 1
3 5 1
5 4 1
5 6 1
*/