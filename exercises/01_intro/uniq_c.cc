#include <iostream>
#include <string>

using namespace std;


int main() {
  int count = 1;
  string line, oldline;

  if (getline(cin,oldline))
  {
    while (getline(cin,line))
    {
      if (oldline != line)
      {
        cout << count << " " << oldline << endl;
        oldline = line;
        count = 1;
      }
      else count++;
    }
    cout << count << " " << oldline << endl;
  }
  return 0;
}
