#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  int D, Q;
  int i, j;
  string s;
  char sc[21];
  int low, high, p;
  int flag, tmp;
  int flagout;
  vector<pair<string, pair<int, int> > > v;

  scanf("%d\n", &tc);
  flagout = 0;
  while (tc--) {
    if (flagout++) 
      printf("\n");
    scanf("%d\n", &D);
    v.clear();
    for (i = 0; i < D; i++) {
      scanf("%s", sc);
      s = sc;
      scanf("%d %d\n", &low, &high);
      v.push_back(make_pair(s, make_pair(low, high)));
    }
    scanf("%d\n", &Q);
    for (i = 0; i < Q; i++) {
      scanf("%d\n", &p);
      flag = 0;
      for (j = 0; j < (int)v.size(); j++) {
        if (p >= v[j].second.first && p <= v[j].second.second) {
          flag++;
          tmp = j;
        }
      }
      if (flag == 1) {
        printf("%s\n", v[tmp].first.c_str());
      } else {
        printf("UNDETERMINED\n");
      }
    }
  }
  return 0;
}
