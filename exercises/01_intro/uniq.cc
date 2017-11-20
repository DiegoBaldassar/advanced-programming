#include <iostream>
#include <string>

using namespace std;


int main() {
  string line, oldline;

  if (getline(cin,oldline))
  {
    while (getline(cin,line))
      if (oldline != line)
      {
        cout << oldline << endl;
        oldline = line;
      }
    cout << oldline << endl;
  }
  return 0;
}
