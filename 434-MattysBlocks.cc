#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char * argv[])
{
  int tc;
  int gs; //grid size
  vector<vector<int> > vvi;
  vector<int> front;
  vector<int> right;
  int i, j;
  int a;
  int max, min;
  int minx;
  int idx;

  scanf("%d\n", &tc);
  while (tc--) {
    vvi.clear();
    front.clear();
    right.clear();
    min = max = 0;
    scanf("%d\n", &gs);
    vvi.resize(gs, vector<int>(gs, 0)); //initialize 2d array
    for (i = 0; i < gs; i++) {
      scanf("%d", &a);
      front.push_back(a);
    }
    for (i = 0; i < gs; i++) { 
      scanf("%d", &a);
      right.push_back(a);
    }

    for (i = 0; i < gs; i++) {
      for (j = 0; j < gs; j++) {
        max += std::min(front[i], right[j]);
      }
    }

    for (i = 0; i < gs; i++) {
      minx = 8;
      idx = -1;
      for (j = 0; j < gs; j++) {
        if (right[j] - front[i] < minx && right[j] - front[i] >= 0) {
          minx = right[j] - front[i];
          idx = j;
        }
        if (right[j] == front[i]) {
          vvi[i][j] = front[i];
          break;
        }
      }
      if (idx >= 0)
        vvi[i][idx] = front[i]; 
    }

    for (j = 0; j < gs; j++) {
      minx = 8;
      idx = -1;
      for (i = 0; i < gs; i++) {
        if (front[i] - right[j] < minx && front[i] - right[j] >= 0) {
          minx = front[i] - right[j];
          idx = i;
        }
        if (front[i] == right[j]) {
          vvi[i][j] = right[j];
          break;
        }
      }
      if (idx >= 0)
        vvi[idx][j] = right[j];
    }

    for (i = 0; i < gs; i++) {
      for (j = 0; j < gs; j++) {
        min += vvi[i][j];
        printf("%d ", vvi[i][j]);
      }
      printf("\n");
    }
    printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", min, max - min);
  }
  return 0;
}
