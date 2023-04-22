#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
//Declaring initial variables
    int numEntries = atoi(argv[1]);
    int associativity = atoi(argv[2]);
    if (associativity == 1)
        associativity = numEntries;
    int blockSpace = numEntries / associativity;


//Opening Input File
    ifstream fin;
    fin.open(argv[3]);


//Opening Output File
    ofstream fout;
    fout.open("cache_sim_output");


//Initializing Cache Vector and blockIndex vector
    vector<int> cache;
    for (int j = 0; j < numEntries; j++){
        cache.push_back(-1);
    }
    vector<int> blockIndex;
    for (int j = 0; j < associativity; j++){
        blockIndex.push_back(0);
    }


//Itterating through entries
    int entry;
    int section, sectionStartIndex;
    int counter;
    bool found;
    while (fin >> entry){
        section = entry % associativity;
        counter = section * blockSpace;
        sectionStartIndex = counter;
        found = false;
        while (!found && counter < blockSpace * (section + 1)){
            if (cache[counter] == entry){
                found = true;
                fout << entry << ": HIT" << endl;
            }
            counter++;
        }
        if (found == false){
            cache[blockIndex[section] + sectionStartIndex] = entry;
            blockIndex[section] = (blockIndex[section] + 1) % blockSpace;
            fout << entry << ": MISS" << endl;
        }
    }


//Close files and end program
    fin.close();
    fout.close();
    return 0;
}