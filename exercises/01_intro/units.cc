#include <iostream>
#include <string>

using namespace std;

const string units_table[] = {"mm","cm","m","km","mg","g","kg","t","s","m²","ha","km²","mL","cm³","L","m³","m/s","km/h","kg/m³","N","Pa","kPa","W","kW","kJ","MJ","kW·h","A","ft","floz","gal","in","mi","mi/h","oz","lbf","lb","lbf/in²","qt","ft²","mi²","yd"};

const float ratios_table[] = {0.001,0.01,1,1000,0.000001,0.001,1,1000,1,1,10000,1000000,0.001,0.000001,1,1,1,0.2777777778,1,1,1,0.001,1,0.001,0.001,0.000001,3600000,1,0.3048,0.0957353,3.785411784,0.0254,1609.344,0.44704,0.02834952,4.448222,0.45359237,6894.757,0.946352946,0.09290304,2589988,0.9144};

const string endunits_table[] = {"m","m","m","m","kg","kg","kg","kg","s","m²","m²","m²","L","m³","L","m³","m/s","m/s","kg/m³","N","Pa","Pa","W","W","J","J","J","A","m","L","L","m","m","m/s","kg","N","kg","Pa","L","m²","m²","m"};

const int NUM_OF_UNITS { sizeof(ratios_table)/sizeof(ratios_table[0]) };

int main() {
  int i;
  float val;
  string unit;
  
  cin >> val >> unit;
  
  for (i=unit.length()-1;i>0;i--)                               // RTrim
    if (unit.at(i) != ' ')
    {
      unit = unit.substr(0,i+1);
      break;
    }
  for (i=0;i<unit.length()-1;i--)                               // LTrim
    if (unit.at(i) != ' ')
    {
      unit = unit.substr(i,unit.length()-i);
      break;
    }

  for (i=0;i<NUM_OF_UNITS;i++)
    if (!unit.compare(units_table[i]))
    {
      cout << val*ratios_table[i] << " " << endunits_table[i] << endl;
      return 0;
    }
  cout << "Unrecognized expression." << endl;
  return 1;
}
