#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    
    ifstream fin;
    fin.open(argv[1]);
    int foo;
    fin >> foo;
    fin.close();

    cout << foo;

    return 0;
}