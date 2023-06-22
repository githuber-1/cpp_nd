#include <iostream>
using namespace std;

int main() {
    int a = 5;
    
    // -- reference -- //
    int& c = a; // & on left side during variable definition indicates a reference
                // c is an alias for a
    
    cout << "value of a: " << a << endl;
    cout << "value of c: " << c << endl;

    c = 10;

    cout << "value of a after modifying c: " << a << endl;
    cout << "value of c: " << c << endl;

    return 0;
}