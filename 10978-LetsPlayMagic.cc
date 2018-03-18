#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int n;
  string c, w;
  char card[3];
  char words[21];
  vector<string> vs;
  vector<int> vi;
  int i;
  int j, k;

  while (scanf("%d\n", &n) && n) {
    vs.clear();
    vi.clear();
    vs.reserve(n);
    vi.reserve(n);

    for (i = 0; i < n; i++)
      vi[i] = 0; // initialize
    j = -1;
    for (i = 0; i < n; i++) {
      scanf("%s", card);
      scanf("%s\n", words);
      c = card;
      w = words;
      for (k = 0; k < w.length();) {
        j = (j + 1) % n;
        if (!vi[j])
          k++;
      }
      vs[j] = c;
      vi[j] = 1;
    }
    for (i = 0; i < n - 1; i++) 
      printf("%s ", vs[i].c_str());
    printf("%s", vs[i].c_str());
    printf("\n");
  }
  return 0;
}
