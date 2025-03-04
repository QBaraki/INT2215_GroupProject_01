#include <iostream>
#include <vector>

const int kInf = (int)1e9 + 123;

void DFS(const std::vector<std::string>& grid, const int& n, std::vector<std::vector<int>>& dist, int x, int y, int current) {
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
  DFS(grid, n, dist, x + 1, y, current + 1);
  DFS(grid, n, dist, x - 1, y, current + 1);
  DFS(grid, n, dist, x, y + 1, current + 1);
  DFS(grid, n, dist, x, y - 1, current + 1);
  return;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::string> grid(n);
  std::vector<std::vector<int>> dist(n, std::vector<int>(n, kInf));
  for (int i = 0; i < n; ++i) {
    std::cin >> grid[i];
  }
  DFS(grid, n, dist, 0, 0, 0);
  if (dist[n - 1][n - 1] == kInf) {
    std::cout << "IMPOSSIBLE!\n";
  } else {
    std::cout << dist[n - 1][n - 1] << '\n';
  }
  return 0;
}