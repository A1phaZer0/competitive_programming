#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  char name[100][101];
  int n, i, j;
  int times[100];
  char song[16][10] = {
                          "Happy",
                          "birthday",
                          "to",
                          "you",
                          "Happy",
                          "birthday",
                          "to",
                          "you",
                          "Happy",
                          "birthday",
                          "to",
                          "Rujia",
                          "Happy",
                          "birthday",
                          "to",
                          "you"
                        };

  scanf("%d\n", &n);
  for (i = 0; i < n; i++) 
    scanf("%s\n", name[i]);
  for (i = 0; i < n; i++)
    times[i] = 0;

  for (j = 0, i = 0; j < 16 && i < n; j = (j + 1) % 16, i = (i + 1) % n) {
    printf("%s: %s\n", name[i], song[j]);
    if (j == 15 && times[n-1] > 0)
      break;
    times[i]++;
  }


  return 0;
}
