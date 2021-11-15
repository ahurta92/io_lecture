#include "std_lib_facilities.h"

int main(){

    vector<int> time;
    // I want a 24 hour period from 0 to 23
    for(int i=0;i<24;i++){
        time.push_back(i);
    }
    // temp initialized to zero with size of temp
    vector<double> temp(time.size());

    double n=temp.size();
    // the temp stars at 44 and increases 15*sin(i *pi/n) n number of
    for(int i=0;i<temp.size();++i){
        temp[i]=44.0+15*sin(i*M_PI/n);
        // we print to screen the values
        cout<<time[i]<<" "<<temp[i]<<"\n";
    }
    cout<<endl;
    // Now let's write the output to a file
    ofstream temp_file{"temp.txt"};
    for(int i=0;i<temp.size();++i){
       // Now we are writing to the temp_file stream
        temp_file<<time[i]<<" "<<temp[i]<<"\n";
    }


}

