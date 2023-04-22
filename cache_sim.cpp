#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
//Declaring initial variables
    int numEntries = atoi(argv[1]);
    int associativity = atoi(argv[2]);
    int blockSpace = numEntries % associativity;

    const int numE {numEntries};

//Opening file
    ifstream fin;
    fin.open(argv[3]);


//Initializing Cache Vector and initializing each index to -1
    vector<int> cache;
    for (int j = 0; j < numEntries; j++)
        cache.push_back(-1);


//Itterating through entries
    int entry;
    while (fin >> entry){
        int section = entry % associativity;
    }



    fin.close();
    return 0;
}