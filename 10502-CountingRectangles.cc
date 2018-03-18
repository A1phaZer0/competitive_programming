#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int row, col;
  char **mat;
  int i, j, k, l, p, q;
  int flag;
  int count;

  while (scanf("%d\n", &row) == 1 && row) {
    scanf("%d\n", &col);
    mat = (char **)malloc(sizeof(*mat) * row);
    for (i = 0; i < row; i++) 
      mat[i] = (char *)malloc((sizeof(char) + 1) * col);
    for (i = 0; i < row; i++) 
      scanf("%s\n", mat[i]);

    count = 0;

    for (i = 0; i < row; i++) { // up-left point
      for (j = 0; j < col; j++) {
        for (k = 1; k <= row - i; k++) { //length
          for (l = 1; l <= col - j; l++) { //height
            flag = 1;
            for (p = i; p < i+k; p++) {
              for (q = j; q < j+l; q++) {
                if (mat[p][q] == '0')
                  flag = 0;
              }
            }
            if (flag)
              count++;
          }
        }
      }
    }
    printf("%d\n", count);
  }
  return 0;
}
