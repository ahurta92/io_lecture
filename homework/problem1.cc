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
   // create vectors to hold the temps
  vector<int> years;
  vector<double> relativeTemps;


  int year;
  double temp1;
  double temp2;

  while (ifs >> year >> temp1>>temp2) { // read
      //std::cout << year << " " << temp1 <<" "<<temp2<< std::endl;
      years.push_back(year);
      relativeTemps.push_back(temp1);
  }

  for (int i = 0; i < years.size(); i++) {
      std::cout << years[i] << " " << relativeTemps[i]+12.8 << std::endl; 
  } 


  for (int i = 0; i < years.size(); i++) {
      std::cout << years[i] << " " << relativeTemps[i]+12.8 << std::endl; 
  } 

  string outFile = "absoluteTempC.txt";
  ofstream ofs(outFile);

  for (int i = 0; i < years.size(); i++) {
      ofs<< years[i] << " " << relativeTemps[i]+12.8 << std::endl; 
  } 
}

