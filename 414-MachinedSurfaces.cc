#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  vector<int> vc;
  vector<int>::iterator it;
  int n;
  int ns, i;
  char y[27];
  int min;
  int ans;

  while (scanf("%d\n", &n) && n) {
    vc.clear();
    ans = 0;
    while (n--) {
      ns = 0;
      scanf("%[^\n]\n", y);
      for (i = 0; i < 25; i++) {
        if (y[i] == ' ') 
          ns++;
      }
      vc.push_back(ns);
    }
    min = vc[0];
    for (it = vc.begin(); it != vc.end(); it++) {
      if (*it < min)
        min = *it;
    }
    for (it = vc.begin(); it != vc.end(); it++) 
      ans += *it - min;
    printf("%d\n", ans);
  }
  return 0;
}
