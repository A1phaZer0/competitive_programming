#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{

  vector<pair<string, string> > v; // Author/Title,Author include "by"
  vector<pair<string, string> >::iterator it;
  vector<int> borrowed;
  char title[81];
  char author[81];
  char c;
  char command[7];
  
  string t, a, cs;
  int quotes;
  int titlegot;
  int count;
  unsigned int i;
  int j;

  while (1) {
    a.clear();
    t.clear();
    quotes = 0;
    titlegot = 0;
    count = 4;
    i = 0;

    while ((c = getchar()) != EOF && c != '\n') {
      if ((title[i++] = c) == '\"') {
        quotes++;
        if (quotes == 2) { // how many quotes we meet
          title[i] = '\0';
          titlegot = 1;
          break;
        }
      } 
    }

    if (title[0] == 'E')
      break;

    i = 0;
    while (titlegot && (author[i++] = getchar()) != '\n') 
      ;
    author[i-1] = '\0';


    a.append(author);
    t.append(title);
    v.push_back(make_pair(a, t));
    borrowed.push_back(0);
  }

  sort(v.begin(), v.end());

  while (1) {
    scanf("%s", command);
    cs = command;
    if ("SHELVE" != cs && "END" != cs) {
      scanf(" %[^\n]", title);
      t = title;

      for (i = 0; i < v.size(); i++) {
        if (v[i].second == t) {
          if (cs == "BORROW") {
            borrowed[i] = -1;
          } else if (cs == "RETURN") {
            borrowed[i] = 1;
          }
        }
      }
    }

    if ("SHELVE" == cs) {
      j = -1;
      for (i = 0; i < v.size(); i++) {
        if (j == -1 && borrowed[i] == 1) {
          printf("Put %s first\n", v[i].second.c_str());
          borrowed[i] = 0;
        } else {
          if (borrowed[i] == 1)  {
            printf("Put %s after %s\n", v[i].second.c_str(), v[j].second.c_str());
            borrowed[i] = 0;
          }
        }
        if (borrowed[i] >= 0)
          j = i;
      }
      printf("END\n");
    }

    if ("END" == cs) {
      break;
    }
  }
  return 0;
}
