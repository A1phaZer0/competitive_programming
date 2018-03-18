#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  int N, K;
  vector<int> v;
  vector<int> tmp;
  int num;
  int a;
  enum {UNKNW, CMPED, FALSE, TRUE};
  int i, j;
  char c;
  int ans;
  int flag = 0;

  scanf("%d\n", &tc);
  while (tc--) {
    if (flag)
      printf("\n");
    flag = 1;
    v.clear();
    scanf("%d %d\n", &N, &K);
    for (i = 0; i < N; i++) 
      v.push_back(UNKNW); // initialize ALL to UNKNW;
    for (i = 0; i < K; i++) {
      tmp.clear();
      scanf("%d", &num);
      for (j = 0; j < num * 2; j++) {
        scanf("%d", &a);
        tmp.push_back(a);
      }
      scanf("\n%c", &c);
      if (c == '<') {
        for (j = 0; j < num * 2; j++) {
          if (v[tmp[j] - 1] == UNKNW) 
            v[tmp[j] - 1] = CMPED;
        }
      } else if (c == '>') {
        for (j = 0; j < num * 2; j++) {
          if (v[tmp[j] - 1] == UNKNW)
            v[tmp[j] - 1] = CMPED;
        }
      } else {
        for (j = 0; j < num * 2; j++) {
          v[tmp[j] - 1] = TRUE;
        }
      }
    }
    ans = -1;
    for (i = 0; i < N; i++) {
      if (v[i] == CMPED) {
        if (ans == -1)
          ans = i + 1;
        else {
          printf("0\n");
          ans = -2;
          break;
        }
      } 
    }

    if (ans == -1) {
      for (i = 0; i < N; i++) {
        if (v[i] == UNKNW) {
          if (ans == -1)
            ans = i + 1;
          else {
            printf("0\n");
            ans = -2;
            break;
          }
        }
      }
    }
    if (ans != -2) {
      printf("%d\n", ans);
    }
  }
  return 0;
}
