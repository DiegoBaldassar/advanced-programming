#include <iostream>

using namespace std;

template <typename numtype>
numtype* alloc_array (int dim) {
  numtype* vec = new numtype[dim];
  for (int i=dim-1; i>=0; i--)
    vec[i] = 0;
  return vec;
}

template <typename numtype>
void reverse_print (numtype vec[], int dim) {
  for (int i=dim-1; i>0; i--)
    cout << vec[i] << " ";
  if (dim > 0)
    cout << vec[0] << endl;
  return;
}

int main() {
  int i, dim;
  
  cout << "Please insert the size of the int array followed by the array elements" << endl;
  cin >> dim;
  int* vec = alloc_array<int>(dim);
  for (i=0; i<dim; i++)
    cin >> vec[i];
  reverse_print(vec, dim);
  delete[] vec;
  
  cout << "Please insert the size of the float array followed by the array elements" << endl;
  cin >> dim;
  float* vec2 = alloc_array<float>(dim);
  for (i=0; i<dim; i++)
    cin >> vec2[i];
  reverse_print(vec2, dim);
  delete[] vec2;
  
  return 0;
}
