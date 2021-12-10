# Solutions

Again find all the solutions on [Github](https://github.com/ahurta92/io_lecture)

This assignment is all about file input and output.  File input
and output is very similar to the regular input and output stream
using `<iostream` library.  For those who want to follow
a tutorial on file input and output you can read the following link

[Input/Output Tutorial](https://www.cplusplus.com/doc/tutorial/files/)

## Problem 1

In this problem we are reading global yearly temperature data from a 
txt file called `landSeaTempC.txt`. below you can see an example of
the contents of the file.  

```console
Land-Ocean Temperature Index (C)
--------------------------------
Year No_Smoothing  Lowess(5)
----------------------------
1880     -0.16     -0.09
1881     -0.08     -0.12
1882     -0.10     -0.16
1883     -0.17     -0.20
```

The file contains 4 lines which serve as
header files.  The first column is the year.  The second and 
third columns give the relative temperature with respect to the average
temperature between 1880 and 1950. We only need the 2nd column for this 
problem.

Your task is to: 

 1. read the year and the temperature data from the file into `vector<double>`s. We only want the 2nd column of temperature data.
    1. Question: Why vector of doubles?
 2. Then convert the vector of relative temperature into an absolute temperature by adding the average temperature to each.
 3. Last write the year and absolute temperature to a text file named "absoluteTempC.txt"

### Solution

Here is the first part of the solution.  
```cpp
#include "std_lib_facilities.h"// This header file includes <iostream> and <fstream>
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
  ....
```

First we include the header file that includes all the library headers files that we
need for this problem.  For input and output as well as file input and output we need 
to include the header files 

   1. `#include <iostream>`
   2. `#include <vector>` 
   3. `#include <fstream>`


To read from a file we need to create a `ifstream` object.  This is done as follows

```cpp
  string inFile = "landSeaTempC.txt";
  ifstream ifs(inFile);
```

We first create a string which holds the name of the file we are reading from. 
We then create a `ifstream` object by initializing the object  `ifs` with the 
previously defined file name.

The next step is to read the first 4 lines.  We do not need that data but we
need to read it in so we can start reading the data we need.  This is done as follows
```cpp
  string line;
  // Here we read in line by line
  for (int i = 0; i < 4; i++) {
      // we can read line by line using getline
    getline(ifs, line);
    cout << line<<"\n";
  }
````

First we create a string that will hold each line that we read in. 
Then using a for loop we read 4 lines into the `string line`. This
is done using `getline(ifs,line)`.  This is saying read a line into
`line` from the `ifstream` object  named `ifs`.  

The next step is to read the data we want from the file.  We
want the data the years to be a vector of `ints` and the 
temperature to be a vector of `doubles`.  Each of the lines that 
we want to read contain 1 `int` and 2 `doubles` therefore we 
need to create variables that will hold our data. 

```cpp
  vector<int> years;// hold the years
  vector<double> relativeTemps;// hold the temps
  int year;// read in year
  double temp1;// read first temp
  double temp2;// read second temp
```

Then we need to read the data in using a while loop.

```cpp
  while (ifs >> year >> temp1>>temp2) { // read
      //std::cout << year << " " << temp1 <<" "<<temp2<< std::endl;
      years.push_back(year);
      relativeTemps.push_back(temp1);
  }
```

We push back the year and the temp into the appropriate vectors.  

The last step is to print our vectors into a new file.  This can be
done by first creating an output stream object with the name of
our output file.  We then write the data from our vector using a 
for loop 

```cpp 
  string outFile = "absoluteTempC.txt";
  ofstream ofs(outFile);

  for (int i = 0; i < years.size(); i++) {
      ofs<< years[i] << " " << relativeTemps[i]+12.8 << std::endl; 
  } 
```




Here is the complete solution

```cpp
#include "std_lib_facilities.h"// This header file includes <iostream> and <fstream>

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

```

After we run the code we should have a new text file with the data.
This code will work properly if you can set your working directory to 
the file directory.  You can also set the absolute paths 
of your input or output files.  

Here is an example of the output file

```console
1880 12.64
1881 12.72
1882 12.7
1883 12.63
1884 12.52
1885 12.47
1886 12.49
1887 12.44
1888 12.63
1889 12.7
1890 12.45
1891 12.58
1892 12.53
1893 12.49
1894 12.5
1895 12.57
1896 12.69
```

## Problem 2

In problem 2 we need to read the data from the file we generated in problem 1 and
write a set of functions that help us write a report about the temperatures.  

Here are the list of the files we need to create

- Write a function that returns the index of the warmest year
- Write a function that returns the index of the coldest year
- Write a function that returns the average temperature between the temperature range
- Write a function that returns the temperature change per year
  - delta(C)= C(current year)-C(previous)
  - There will be n-1 temperature changes

### Solution

The first step is the read in the temperature data from your text file 
this is done in a similar way to the first problem.  Now we do not 
have 4 extra lines at the top and only two columns of data.  
Therefore the main function begins with 


```cpp
int main() {
    string inFile = "absoluteTempC.txt";
    ifstream ifs(inFile);
    vector<int> years;
    vector<double> tempC;
    int year;
    double temp1;
    // notice that temp2 is not here in this problem

    // Now we only read in two columns of data
    while (ifs >> year >> temp1) { // read
        years.push_back(year);
        tempC.push_back(temp1);
    }
```

The next step is to declare the functions we will be writing
before the main function.  

```cpp
// Here are all my function declarations
int warmest_index(const vector<double> & temps);
int coldest_index(const vector<double> & temps);
double average_temp(const vector<double> & temps);
vector<double> temperature_change(const vector<double> & temps);
int main() {
    // 
    // rest of main
    //
}
```

For every function we are passing in a vector of temperatures.  We pass
in the vectors by const reference because we know that our functions
will not modify the vectors, and we do not want to needlessly copy a large vector.
For the first two functions we need to write the return type is an `int` because 
we are looking for the index of the warmest and coldest year.  

After we declare our functions we can call our functions from the main scope.  

```cpp
    int warmest_i= warmest_index(tempC);
    int coldest_i= coldest_index(tempC);
    double average_C= average_temp(tempC);
    vector<double> delta_C= temperature_change(tempC);
```

As you see I am directly initializing our variables using the functions we 
have created.  

Next we should define our functions.  We can define them anywhere outside 
the main function but only **once**.  It's best practice defining them
outside the main function.


Here are definitions defined below the main function.
What I want you to notice that each of these functions is equivalent 
to finding the max, the min, the average value, and the delta 
of a vector

```cpp

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
```

Notice that each function has the same pattern.
1. define the variable you will return
2. read the elements of the vector and do something
3. return the data.

The last step is to write the report to a file 

The entire solution looks is 

```cpp
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
```

## Problem 3

For problem 3 all you need to do is use the same function 
as in problem 2 but just convert your Celsius temperature 
to Fahrenheit before you call the functions.  

```cpp
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


```

