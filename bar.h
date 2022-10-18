// bar.h
// Seyfal Sultanov 
// UIC CS 251 Fall 2020 
// Professor: Adam Koehler

#include <iostream> 
#include <string> 
#include "myrandom.h" // used in graders, do not remove
using namespace std;

//
// Bar
//
class Bar {
 private:
    // Private member variables for a Bar object

    string name; // name of the bar 
    int value; // value of the bar
    string category;  // category of the bar

 public:

    // default constructor:
    Bar() {
        
        name = ""; // set name to empty string
        value = 0; // set value to 0
        category = ""; // set category to empty string

    }

    // second constructor:
    Bar(string name, int value, string category) {
        
        this->name = name; // set name
        this->value = value; // set value
        this->category = category; // set category
        
    }

    // destructor:
    virtual ~Bar() {
    
        // TODO - nothing to do here, but you need to have a virtual destructor
        
    }

    // getName:
	string getName() {
        return name; // return name
    }

    // getValue:
	int getValue() { 
        return value; // return value
    }

    // getCategory:
	string getCategory() {
        return category; // return category
    }

	// operators
    // TO DO:  Write these operators.  This allows you to compare two Bar
    // objects.  Comparison should be based on the Bar's value.  For example:
	bool operator<(const Bar &other) const {
        return value < other.value; // return true if value is less than other value
    }

    bool operator>(const Bar &other) const {
        return value > other.value; // return true if value is greater than other value
    }

    bool operator<=(const Bar &other) const {
        return value <= other.value; // return true if value is less than or equal to other value
    }   

    bool operator>=(const Bar &other) const {
        return value >= other.value; // return true if value is greater than or equal to other value
    }


/*     bool operator==(const Bar &other) const {
        return value == other.value;
    }

    bool operator!=(const Bar &other) const {
        return value != other.value;
    }

    // This allows you to print a Bar object
    // to an output stream.  For example:
    // cout << bar;
    friend ostream& operator<<(ostream &os, const Bar &b) {
        os << b.name << " " << b.value << " " << b.category;
        return os;
    }

    // This allows you to read a Bar object
    // from an input stream.  For example:
    // cin >> bar;
    friend istream& operator>>(istream &is, Bar &b) {
        is >> b.name >> b.value >> b.category;
        return is;
    } */

};

