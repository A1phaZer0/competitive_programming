#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int b[3];
  int g[3];
  int c[3];
  int min;
  int i;

  int ans[6];// BCG BGC CBG CGB GBC GCB
  string s[6] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };

  while (scanf("%d %d %d %d %d %d %d %d %d\n", 
        b, b+1, b+2, g, g+1, g+2, c, c+1, c+2) != EOF) {
    ans[0] = b[1] + b[2] + g[0] + g[1] + c[0] + c[2];
    min = ans[0];
    ans[1] = b[1] + b[2] + g[0] + g[2] + c[0] + c[1];
    ans[2] = b[0] + b[1] + g[1] + g[2] + c[0] + c[2];
    ans[3] = b[0] + b[1] + g[0] + g[2] + c[1] + c[2];
    ans[4] = b[0] + b[2] + g[1] + g[2] + c[0] + c[1];
    ans[5] = b[0] + b[2] + g[0] + g[1] + c[1] + c[2];

    for (i = 1; i < 6; i++) {
      if (ans[i] < min)
        min = ans[i];
    }

    for (i = 0; i < 6; i++) {
      if (ans[i] == min)
        break;
    }
    printf("%s %d\n", s[i].c_str(), ans[i]);
  }
  return 0;
}
