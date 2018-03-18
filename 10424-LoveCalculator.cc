#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int name[2];
  int ans[2];
  int k;
  char c;
  int tmp;

  k = 0;
  while (1) {
    name[k] = 0;

    while ((c = getchar()) != '\n' && c != EOF) {
      if (c <= 'z' && c >= 'a')
        name[k] += c - 'a' + 1;
      if (c <= 'Z' && c >= 'A')
        name[k] += c - 'A' + 1;
    }
    if (c == EOF)
      break;
    while (1) {
      ans[k] = 0;
      while (name[k]) {
        ans[k] += name[k] - name[k]/10*10;
        name[k] /= 10;
      }
      name[k] = ans[k];
      if (!(ans[k]/10))
        break;
    }

    k = (k + 1) % 2;
    if (k == 0) { // after a pair of name got;
      if (ans[0] > ans[1]) {
        tmp = ans[0];
        ans[0] = ans[1];
        ans[1] = tmp;
      }
      if (ans[1])
        printf("%.2lf %%\n", (double)ans[0]/(double)ans[1] * 100);
      else
        printf("\n");
    }
  }

  return 0;
}
