#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vii> graph;

enum {UNVISITED = -1, VISITED = 1};
vi dfs_num;



void dfs_recursive(graph &G,int u)
{
  int i;
  ii v;
  if (dfs_num[u] == UNVISITED) {
    dfs_num[u] = VISITED;
    printf("%d ", u);
  }
  for (i = 0; i < (int)G[u].size(); i++) {
    v = G[u][i];
    if (dfs_num[v.first] == UNVISITED)
      dfs_recursive(G, v.first);
  }
}


void dfs_iterative(graph &G, int u)
{
  stack<ii> stk;
  ii v;
  int i;

  while (1) {
    if (dfs_num[u] == UNVISITED) {
      dfs_num[u] = VISITED;
      printf("%d ", u);
      for (i = 0; i < (int)G[u].size(); i++) {
        v = G[u][i];
        if (dfs_num[v.first] == UNVISITED)
          stk.push(v);
      }
    }
    if (stk.empty()) 
      break;
    v = stk.top();
    stk.pop();
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
  dfs_num.resize(n);
  G.resize(n);
  for (i = 0; i < n; i++)
    dfs_num[i] = UNVISITED;
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
  printf("DFS Recursive:\n");
  dfs_recursive(G, 0);
  printf("\n");
  dfs_recursive(G, 6);
  printf("\n");
  dfs_recursive(G, 5);
  printf("\n");

  for (i = 0; i < n; i++)
    dfs_num[i] = UNVISITED;

  printf("DFS Iterative:\n");
  dfs_iterative(G, 0);
  printf("\n");
  dfs_iterative(G, 6);
  printf("\n");
  dfs_iterative(G, 5);
  printf("\n");
  return 0;
}
