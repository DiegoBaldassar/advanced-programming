#include <iostream>

using namespace std;

void generate_primes(unsigned int* &primes_vec, int &primes_n, unsigned int max_num);

int main() {
  int primes_n;
  unsigned int* primes_vec;
  
  generate_primes(primes_vec, primes_n, 100);
  for (int i=0; i<primes_n; i++)
    cout << primes_vec[i] << endl;
  return 0;
}

void generate_primes(unsigned int* &primes_vec, int &primes_n, unsigned int max_num) {
  unsigned int temp_primes[max_num/3+2];        // Allocation on stack, only suitable if max_num is moderate
                                                // There will always be enough space for primes, but there are more refined alternatives
  int i, j;
  unsigned int num, div;
  bool isprime;

  if (max_num < 2) {                            // Special case for small max_num
    primes_n = 0;                               // return an empty vector
    primes_vec = new unsigned int[0];
    return;
  }
  
  temp_primes[0]=2;
  i = 1;
  for (num = 3; num <= max_num; num += 2) {
    isprime = true;
    for (j = 0; ; j++) {
      div = temp_primes[j];
      if (div * div > num)                      // Stop the check when reaching sqrt(num)
        break;
      if (num % div == 0) {
        isprime = false;
        break;
      }
    }
    if (isprime)
      temp_primes[i++] = num;
  }
  primes_n = i;
  primes_vec = new unsigned int[primes_n];      // Allocate on stack and copy
  for (i = primes_n - 1; i >= 0; i--)
    primes_vec[i] = temp_primes[i];
}
