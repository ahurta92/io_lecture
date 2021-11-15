#include "std_lib_facilities.h"

int main(){

    cout<<"Please enter name of output file: " ;
    string o_name;
    cin>>o_name;

    ofstream ofs{o_name}; // ofstream is an "output stream from a file"
    // defining an ofstream with a name string and
    // opens the file with that name for writing

    if (!ofs) error("can't open output file",o_name);




}
