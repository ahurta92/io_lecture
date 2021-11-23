#include "std_lib_facilities.h"

int main() {
  string inFile = "landSeaTempC.txt";
  ifstream ifs(inFile);
  string line;
  // Here we read in line by line
  for (int i = 0; i < 4; i++) {
      // we can read line by line using getline
    getline(ifs, line);
    cout << line<<"\n";
  }
  // Start Reading in temperatures and converting
}
