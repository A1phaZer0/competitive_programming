#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int m;
  char c;
  int i, j;
  int amin, amax;

  while (scanf("%d\n", &m) != EOF) {
    vector<pair<int, int> > v1;
    vector<pair<int, int> > v3;
    for (i = 0; i < m; i++) {
      j = 0;
      while ((c = getchar()) != '\n' && c != EOF) {
        if (c == '1') 
          v1.push_back(make_pair(i, j));
        if (c == '3')
          v3.push_back(make_pair(i, j));
        if (c == '1' || c == '2' || c == '3')
          j++;
      }
    }
    amax = 0;
    for (i = 0; i < (int)v1.size(); i++) {
      amin = 32767;
      for (j = 0; j < (int)v3.size(); j++) {
        if (abs(v3[j].first - v1[i].first) + abs(v3[j].second - v1[i].second) < amin)
          amin = abs(v3[j].first - v1[i].first) + abs(v3[j].second - v1[i].second);
      }
      if (amin > amax)
        amax = amin;
    } 
    printf("%d\n", amax);
  }
  return 0;
}
