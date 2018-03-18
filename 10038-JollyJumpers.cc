#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  vector<int> vi;
  vector<int> v;
  unsigned int i;
  int n;
  int inp;
  int flag;

  while (scanf("%d", &n) && n != EOF) {
    flag = 1;
    vi.clear();
    v.clear();
    while (n--) {
      scanf("%d ", &inp);
      vi.push_back(inp);
      v.push_back(0);
    }
    if (vi.size() == 1) {
      printf("Jolly\n");
      continue;
    }
    for (i = 1; i < vi.size(); i++) {
      v[abs(vi[i]-vi[i-1])] = 1;
    }
    for (i = 1; i < vi.size(); i++) {
      flag &= v[i];
    }
    if (flag) {
      printf("Jolly\n");
    } else {
      printf("Not jolly\n");
    }
  }
  return 0;
}
