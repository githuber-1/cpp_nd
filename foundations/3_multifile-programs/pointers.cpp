#include <iostream>
#include <vector>
using namespace std;

int main() {

    // -- pointer -- //
    int a = 5; // normal var
    int* b = &a; // b is a pointer to memory address of a. & on right side gets var address

    cout << "address of a from &: " << &a << endl;
    cout << "address of a from pointer: " << b << endl;
    cout << "value after dereferencing pointer: " << *b << endl; //deref because used with already declared var


    // Note to dereference a ptr to a vector, use (*ptr_v)
    vector<int> v = {1, 2, 3};
    vector<int>* ptr_v = &v;

    cout << (*ptr_v)[0] << endl;

    return 0;
}