#include <cstdio>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int k, c;
  int ct, cm;
  char s[5];
  int i;
  int j;
  int chosen;
  int unpassed;
  set<string> ss;

  while (scanf("%d %d\n", &k, &c) && k) {
    ss.clear();
    unpassed = 0;
    for (i = 0; i < k; i++) {
      scanf("%s", s);
      ss.insert(s);
    }
    for (i = 0; i < c; i++) {
      chosen = 0;
      scanf("%d %d", &ct, &cm); // category total/ category must be chosen
      for (j = 0; j < ct; j++) {
        scanf("%s", s);
        if (ss.find(s) != ss.end())
          chosen++;
      }
      if (chosen < cm)
        unpassed++;
    }
    if (unpassed)
      printf("no\n");
    else
      printf("yes\n");
  }
  return 0;
}
