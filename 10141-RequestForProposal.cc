#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{

  int nr, np;
  int flag = 0;
  char s[81];
  int jump;
  char c;
  double price, max_price;
  int i;
  int req, max_req;
  char target[81];
  int n = 1;

  while (1) {
    scanf("%d %d\n", &nr, &np);
    if (!nr)
      break;
    if (flag)
      printf("\n");
    flag = 1;
    max_req = 0;

    jump = 0;
    while (1) { // jump parts
      c = getchar();
      if (c == '\n') 
        jump++;
      if (jump == nr)
        break;
    }

    while (np--) {
      i = 0;
      while ((c = getchar()) != '\n')
        s[i++] = c;
      s[i] = '\0';
      scanf("%lf %d\n", &price, &req);
      if (req > max_req || (req == max_req && price < max_price )) {
        max_req = req;
        max_price = price; // price of max_req
        for (i = 0; i < 81; i++)
          target[i] = s[i];
      } else
        ;

      jump = 0;
      while (1) {
        c = getchar();
        if (c == '\n')
          jump++;
        if (jump == req)
          break;
      }
    }
    printf("RFP #%d\n", n++);
    printf("%s\n", target);
  }
  return 0;
}
