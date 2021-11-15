#include "std_lib_facilities.h"

int main() {

  // create vectors to hold the temps
  vector<int> hours;
  vector<double> temps;

  // string holds the file name
  string file_name = "temp.txt";
  // input file stream open with "temps.txt"
  ifstream ist{file_name};

  int hour;
  double temperature;

  while (ist >> hour >> temperature) { // read
    if (hour < 0 || 23 < hour)
      error("hour out of range"); // check
    hours.push_back(hour);
    temps.push_back(temperature);
  }
  // Print to screen
  for (int i = 0; i < hours.size(); i++) {
    cout << hours[i] << " " << temps[i] << "\n";
  }
}
