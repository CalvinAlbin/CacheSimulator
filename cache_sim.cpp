#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){

    int numEntries = atoi(argv[1]);
    int associativity = atoi(argv[2]);

    cout << numEntries + 1 << endl;
    cout << associativity + 1 << endl;
    
    ifstream fin;
    fin.open(argv[3]);
    int foo;
    fin >> foo;
    fin.close();

    cout << foo;

    return 0;
}