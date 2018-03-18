#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vii> graph;

enum {UNVISITED = -1, VISITED = 1};
vi bfs_num;


void bfs(graph &G, int u)
{
  queue<ii> q;
  ii v;
  int i;

  while (1) {
    if (bfs_num[u] == UNVISITED) {
      bfs_num[u] = VISITED;
      printf("%d ", u);
      for (i = 0; i < (int)G[u].size(); i++) {
        v = G[u][i];
        if (bfs_num[v.first] == UNVISITED)
          q.push(v);
      }
    }
    if (q.empty()) 
      break;
    v = q.front();
    q.pop();
    u = v.first;
  }
}

int main(int argc, char *argv[])
{
  int n;
  int i, j;
  int m;
  int a, b;
  graph G;

  scanf("%d %d\n", &n, &m);
  bfs_num.resize(n);
  G.resize(n);
  for (i = 0; i < n; i++)
    bfs_num[i] = UNVISITED;
  for (i = 0; i < m; i++) {
    scanf("%d %d\n", &a, &b);
    G[a].push_back(make_pair(b, 0));
    G[b].push_back(make_pair(a, 0));
  }
  for (i = 0; i < n; i++) {
    printf("%d: ", i);
    for (j = 0; j < (int)G[i].size(); j++)
      printf("%d ", G[i][j].first);
    printf("\n");
  }

  printf("BFS:\n");
  bfs(G, 0);
  printf("\n");
  bfs(G, 6);
  printf("\n");
  bfs(G, 5);
  printf("\n");
  return 0;
}
