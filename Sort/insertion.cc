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
  int n;
  int tmp;

  scanf("%d\n", &n);
  vi.resize(n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    printf("%d ", a);
    vi[i] = a;
  }
  printf("\n");

  for (i = 1; i < n; i++) {
    tmp = vi[i];
    for (j = i - 1; j >= 0; j--) {
      if (tmp < vi[j])
        vi[j+1] = vi[j];
      else
        break;;
    }
    vi[j+1] = tmp;
  }


  for (i = 0; i < n; i++)
    printf("%d ", vi[i]);
  printf("\n");

  return 0;
}
