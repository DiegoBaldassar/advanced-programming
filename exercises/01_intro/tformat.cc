#include <iostream>
#include <string>

using namespace std;

const int LINE_LENGTH {20};

int main() {
  int i;
  string line;
  
  while (getline(cin,line))
    for (i=LINE_LENGTH; ;i--)                                   // Loop until the line is exhausted, preparing
    {                                                           //   to scan over each character on the line
      if (line.length() <= LINE_LENGTH)                         // If line is short enough, print it out
      {
        cout << line << endl;
        break;
      }
      if (i<0)                                                  // If the search failed, brutally crop line
      {                                                         //   and loop around
        i = line.length()-LINE_LENGTH;
        cout << line.substr(0,LINE_LENGTH) << endl;
        line = line.substr(LINE_LENGTH,i);
        continue;
      }
      if (line.at(i) == ' ' || line.at(i) == '\t')              // If a space is found, cut the line at the
      {                                                         //   corresponding position and loop around
        cout << line.substr(0,i) << endl;
        line = line.substr(i+1,line.length()-i-1);
        continue;
      }
    }
}
