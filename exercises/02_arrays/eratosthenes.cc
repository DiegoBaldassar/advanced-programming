#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
  unsigned int i, j, max_num;

  if (argc != 2) {
    cout << "This program requires exactly one command line argument" << endl;
    return 1;
  }

  max_num = atoi(argv[1]);
  bool sieve[max_num - 1];                      // Here sieve[i] represents whether or not i+2 is prime
  const unsigned int max_i = sqrt(max_num) - 2;

  for (i = 0; i < max_num - 1; i++)             // Init sieve
    sieve[i] = true;

  for (i = 0; i < max_i; i++)                   // Actual sifting
    if (sieve[i])
      for (j = max_num / (i + 2); j > 1; j--)
        sieve[(i + 2) * j - 2] = false;

  for (i = 0; i < max_num - 1; i++)             // Print out
    if (sieve[i])
      cout << i + 2 << endl;

  return 0;
}
