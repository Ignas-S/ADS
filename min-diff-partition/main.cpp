#include <climits>
#include <iostream>
#include <vector>
#include <fstream>
#include "min_diff_partition.h"

void partitionRecurse(unsigned int i, long &diffcurrent, long sum1, long sum2);
void partitionMinDiff(std::vector<int> &res1, std::vector<int> &res2, std::vector<int> m_array, long &difference);
void outputVector(std::vector<int> x);
void Input(std::vector<int> &Array);

using namespace std;

int main()
{
    vector<int> ArrayMain;
    vector<int> R1, R2;
    long difference=LONG_MAX;

    Input(ArrayMain);
    partitionMinDiff(R1, R2, ArrayMain, difference);

    cout<<"Partition 1: ";
    outputVector(R1);
    cout<<"Partition 2: ";
    outputVector(R2);
    cout<<"Minimum sum difference: "<<difference<<endl;


}

void Input(vector<int> &Array) {
    string filename;
    int temp;
    cout<<"Input file name (file stores a set of numbers which will be partitioned into two with min difference):"<<endl;
    cin>>filename;

    ifstream fd(filename);

    if(!fd.is_open()) {
        cout<<"Problem opening the file"<<endl;
        exit(EXIT_FAILURE);
    }

    while (fd.good())
    {
        fd>>temp;
        Array.push_back(temp);
    }

    fd.close();
}



void outputVector(vector<int> x) {

    long s=0;
    for(int i=0; i < x.size(); i++) {
        cout<<x[i];
        if(i != x.size()-1) cout<<",";
        cout<<" ";
        s += (long) x[i];
    }
    cout<<" = "<<s<<endl;
}
