#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){

    int numEntries = atoi(argv[1]);
    int associativity = atoi(argv[2]);
    
    ifstream fin;
    fin.open(argv[3]);
 /*   int foo;
    fin >> foo;

    int foo2;
    fin >> foo2;

    cout << foo << " " << foo2;
*/
    int i;
    while (fin >> i){
        cout << i << endl;
    }


    
    fin.close();
    return 0;
}