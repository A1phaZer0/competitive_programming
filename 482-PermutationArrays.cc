#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  vector<int> p;
  vector<string> vs;
  char c;
  char s[100];
  int b;
  int tc;
  unsigned int i;
  int flag = 0;

  scanf("%d\n", &tc);
  while (tc--) {
    if (flag) 
      printf("\n");
    p.clear();
    vs.clear();
    while (1) {
      scanf("%d", &b);
      p.push_back(b);
      if ((c = getchar()) == '\n')
        break;
    }
    vs.reserve(p.size());
    i = 0;
    while (1) {
      scanf("%s", s);
      vs[p[i] - 1] = s;
      if ((c = getchar()) == '\n')
        break;
      i++;
    }
    for (i = 0; i < p.size(); i++)
      printf("%s\n", vs[i].c_str());
    flag = 1;
  }
  return 0;
}
