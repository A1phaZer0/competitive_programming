#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int a;
  vector<int> vi;
  int i;
  int j;
  int tmp;
  int n;

  scanf("%d\n", &n);
  vi.resize(n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    printf("%d ", a);
    vi[i] = a;
  }
  printf("\n");

  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j > i; j--) {
      if (vi[j] < vi[j-1]) {
        tmp = vi[j];
        vi[j] = vi[j-1];
        vi[j-1] = tmp;
      }
    }
  }

  for (i = 0; i < n; i++)
    printf("%d ", vi[i]);
  printf("\n");

  return 0;
}
