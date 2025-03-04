#include <iostream>
#include <vector>
using namespace std;

const int kInf = (int)1e9 + 123;

void BFS(const vector<string>& grid, const int& n, vector<vector<int>>& dist, int x, int y, int current) {
	if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == '#') {
		return;
	}
	if (current >= dist[x][y]) {
		return;
	}
	if (current < dist[x][y]) {
		dist[x][y] = current;
	}
	if (x == n - 1 && y == n - 1) {
		return;
	}
	BFS(grid, n, dist, x + 1, y, current + 1);
	BFS(grid, n, dist, x - 1, y, current + 1);
	BFS(grid, n, dist, x, y + 1, current + 1);
	BFS(grid, n, dist, x, y - 1, current + 1);
	return;
}

int main() {
	int n;
	cin >> n;
	vector<string> grid(n);
	vector<vector<int>> dist(n, vector<int>(n, kInf));
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
	}
	BFS(grid, n, dist, 0, 0, 0);
	if (dist[n - 1][n - 1] == kInf) {
		cout << "IMPOSSIBLE!\n";
	}
	else {
		cout << dist[n - 1][n - 1] << '\n';
	}
	return 0;
}