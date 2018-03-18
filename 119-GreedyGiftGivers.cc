#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int n;
  int f;
  int money;
  char s[13];
  map<string, int> m;
  string name[10];
  int i, j;
  int flag;
  flag = 0;

  while (scanf("%d\n", &n) != EOF) {
    if (flag)
      printf("\n");
    m.clear();
    for (i = 0; i < n; i++) {
      scanf("%s", s);
      name[i] = s;
      m.insert(make_pair(name[i], 0));
    }
    for (i = 0; i < n; i++) {
      scanf("%s %d %d", s, &money, &f);
      if (f) {
        m[s] -= static_cast<int>(money / f) * f;
      }
      for (j = 0; j < f; j++) {
        scanf("%s", s);
        m[s] += money / f;
      }
    }
    for (i = 0; i < n; i++) 
      printf("%s %d\n", name[i].c_str(), m[name[i]]);
    flag = 1;
  }
  return 0;
}
