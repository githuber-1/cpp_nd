#include <iostream>

using namespace std;

/*
Animal is a an abstract class because it has a Pure Virtual Function, which is denoted
by the syntax const = 0; This function must be overriden.

Abstract Classes cannot be instantiated, but instead are meant to spawn derived classes.
*/
class Animal {
	virtual void Talk() const = 0; 

    public: 
        void foo() {
            cout << "foo";
        }
};

class Human : public Animal {
	public:
        void Talk() const {
		    cout << "Hello!\n";
	    }
};

int main() {
    Human human;
    human.Talk();
    return 0;
}