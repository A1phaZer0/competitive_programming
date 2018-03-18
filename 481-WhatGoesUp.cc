#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vi;
vector<int> mono;
vector<int> L;

/* 
 * bi-search the first one which's larger than or equal tgt
 */
int bisearch(int l, int r, int tgt)
{
  while (l < r) {
    int m = (r-l)/2+l;
    
    if (vi[mono[m]] < tgt)
      l = m + 1;
    else
      r = m;
  }
  if (vi[mono[r]] < tgt)
    r++;
  return r;
}

/*
 * recursivly print results
 */
void print(int idx)
{
  if (idx >= 0) {
    print(L[idx]);
    printf("%d\n", vi[idx]);
  }
}

int main(int argc, char *argv[])
{
  int inp;
  int max = -1;
  int last;

  vi.clear();
  while (scanf("%d", &inp) != EOF) {
    vi.push_back(inp);
    L.push_back(-1);
  }
  mono.push_back(0);

  for (int i = 0; i < (int)vi.size(); i++) {
    int k = bisearch(0, (int)mono.size() - 1, vi[i]);
    if (k == (int)mono.size())
      mono.push_back(i);
    else
      mono[k] = i;
    if (k + 1 >= max) { // current longest sequence
      max = k + 1;
      last = i;
    }
    if (k) 
      L[i] = mono[k-1];
  }
  printf("%d\n-\n",max);
  print(last);

  return 0;
}
