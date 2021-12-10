#include "std_lib_facilities.h"

// Here are all my function declarations
int warmest_index(const vector<double> & temps);
int coldest_index(const vector<double> & temps);
double average_temp(const vector<double> & temps);
vector<double> temperature_change(const vector<double> & temps);


int main() {
    string inFile = "absoluteTempC.txt";
    ifstream ifs(inFile);
    vector<int> years;
    vector<double> tempF;
    int year;
    double temp1;
    // notice that temp2 is not here in this problem

    // Now we only read in two columns of data
    while (ifs >> year >> temp1) { // read
        years.push_back(year);
        tempF.push_back((temp1*9/5)+32);// i convert directly in here
    }
    //H

    int warmest_i= warmest_index(tempF);
    int coldest_i= coldest_index(tempF);
    double average_F= average_temp(tempF);
    vector<double> delta_F= temperature_change(tempF);

    double average_deltaF= average_temp(delta_F);

    ofstream datafile{"reportF.txt"};

    datafile<<"The warmest year was "<<years[warmest_i]<< " with a temperature of "<< tempF[warmest_i]<<" F."<<endl;
    datafile<<"The coldest year was "<<years[coldest_i]<< " with a temperature of "<< tempF[coldest_i]<<" F."<<endl;
    datafile<<"The average temperature across all years is "<<average_F<<" F."<<endl;
    datafile<<"The average temperature change across all years is "<<average_deltaF<<" F."<<endl;


}

// Function definitions
int warmest_index(const vector<double> & temps){
    int warm_i=0;
    for(int i=1;i<temps.size();i++) {
        if (temps[i] > temps[warm_i])//is temp[i] greater than temps[warm_i]
        {
            warm_i=i;// them warm_i is i
        }
    }
    return warm_i;// return the warmest
}
// notice this is the same as above except we its less than.
int coldest_index(const vector<double> & temps){
    int coldest=0;
    for(int i=1;i<temps.size();i++) {
        if (temps[i] < temps[coldest])//is temp[i] less than temps[warm_i]
        {
            coldest=i;//
        }
    }
    return coldest;// return the warmest
}
double average_temp(const vector<double> & temps){
    double total=0;
    for(int i=0;i<temps.size();i++) {
        total+=temps[i];// them warm_i is i
    }
    return total/static_cast<double>(temps.size());
}
vector<double> temperature_change(const vector<double> & temps){
    vector<double> deltaT;
    for(int i=1;i<temps.size();i++) {
        deltaT.push_back(temps[i]-temps[i-1]);
    }
    return deltaT;
}

