#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int bisearch(vector<int> *vi, char c, int lastindex)
{
  vector<int>::iterator it;

  if (c >= 'a') {
    it = lower_bound(vi[c-'a'].begin(), vi[c-'a'].end(), lastindex);
    if (it != vi[c-'a'].end()) 
      lastindex = *it;
    else
      lastindex = -1;
  } else {
    it = lower_bound(vi[c-'A'+26].begin(), vi[c-'A'+26].end(), lastindex);
    if (it != vi[c-'A'+26].end())
      lastindex = *it;
    else
      lastindex = -1;
  }

  return lastindex;
}

int main(int argc, char *argv[])
{
  int Q;
  vector<int> vi[52]; // for a..z A..Z
  int i;
  char c;
  int lastindex;
  int start, end;
  int flag;

  i = 0;
  while ((c = getchar()) != '\n') {
    if (c >= 'a')
      vi[c-'a'].push_back(i++);
    else
      vi[c-'A'+26].push_back(i++);
  }
  scanf("%d\n", &Q);
  while (Q--) {
    lastindex = -1;
    start = -1;
    end = -1;
    flag = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
      lastindex = bisearch(vi, c, lastindex+1);
      if (lastindex == -1)
        flag = 1;
      if (start == -1)
        start = lastindex;
      if (lastindex > end)
        end = lastindex;
    }
    if (flag)
      printf("Not matched\n");
    else
      printf("Matched %d %d\n", start, end);
  }
  return 0;
}
