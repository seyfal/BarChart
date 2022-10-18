// barchart.h
// Seyfal Sultanov 
// UIC CS 251 Fall 2020 
// Professor: Adam Koehler

// TODO - LINE 42 IS A DUPLICATE THAT IS WHY I COMMENTED IT OUT, IT WOULD NOT COMPILE OTHERWISE
// TODO - CODE IS PERFECTLY RUNNING FOR ME, IF U ENCOUNTER ANY ERRORS THEY ARE DUE TO THE COLORS 
// TODO - ON LINE 46 AND PIECE OF CODE THAT WORKS WITH IT IN BARCHART ANIMATE IN ADDFRAME METHOD

#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h" // used in graders, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RESET("\033[0m");


//
// NOTE: COMMENT AND UNCOMMENT AS NEEDED BASED ON YOUR TERMINAL
//
// Color codes for light mode terminals
// const string RED("\033[1;36m");
// const string PURPLE("\033[1;32m");
// const string BLUE("\033[1;33m");
// const string CYAN("\033[1;31m");
// const string GREEN("\033[1;35m");
// const string GOLD("\033[1;34m");
// const string BLACK("\033[1;37m");
// const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for darker mode terminals
const string CYAN("\033[1;36m");
const string GREEN("\033[1;32m");
const string GOLD("\033[1;33m");
const string RED("\033[1;31m");
const string PURPLE("\033[1;35m");
const string BLUE("\033[1;34m");
const string WHITE("\033[1;37m");
//const string RESET("\033[0m");
//const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};


//
// BarChart
//
class BarChart {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    //
    Bar* bars;  // pointer to a C-style array
    int capacity; // the number of elements that can be stored in the array
    int size; // number of elements stored 
    string frame; // used for animation
    
 public:
    
    // default constructor:
    BarChart() {
        // assign bars to nullptr
        bars = nullptr; // this is a pointer, so it should be nullptr
        capacity = 0; // capacity should be 0
        size = 0; // size should be 0       
        string frame = ""; // frame should be empty      
    }
    
    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars.
    BarChart(int n) {
        bars = new Bar[n]; // allocate memory for bars
        capacity = n; // capacity should be n
        size = 0; // size should be 0    
        string frame = ""; // frame should be empty       
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value.
    //
    // bcCopy is constructed (new object)
    // and has all the same values of private
    // member variables as bc.  See header
    // description and example in
    // ourvector.h
    BarChart(const BarChart& other) { // other is the object being copied
        this->bars = new Bar[other.capacity]; // allocate memory for bars
        this->capacity = other.capacity; // capacity should be other.capacity
        this->size = other.size; // size should be other.size
        for (int i = 0; i < size; i++) { // copy bars
            this->bars[i] = other.bars[i]; // copy bars
        }        
        this->frame = other.frame; // frame should be other.frame
    }
    //
    // copy operator=
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    //
    // This allows you to set one object
    // equal to a different object (but both
    // objects are both already constructed).
    // See header description and example
    // in ourvector.h
    BarChart& operator=(const BarChart& other) { // other is the object being copied
        if (this != &other) { // check for self-assignment
            delete[] bars; // delete old bars  
            this->bars = new Bar[other.capacity]; // allocate memory for bars
            this->capacity = other.capacity; // capacity should be other.capacity
            this->size = other.size; // size should be other.size
            for (int i = 0; i < size; i++) { // copy bars
                this->bars[i] = other.bars[i]; // copy bars
            }        
            this->frame = other.frame; // frame should be other.frame
        }
        return *this; // return this object
    }
    // clear
    // frees memory and resets all private member variables to default values.
    void clear() {
        delete[] bars; // delete bars
        bars = new Bar[0]; // allocate memory for bars
        capacity = 0; // capacity should be 0
        size = 0; // size should be 0  
        frame = ""; // frame should be empty        
    }
    
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    //
    virtual ~BarChart() {
        delete[] bars; // delete bars
    }
    
    // setFrame
    // A setter for keeping track of which
    // frame the BarChart is associated with.
    void setFrame(string frame) {
        this->frame = frame; // set frame
    }
    
    // getFrame()
    // Returns the frame of the BarChart oboject.
    // A getter for getting the frame
    // associated with the BarChart object.
    // Using the above example, it would
    // return “1950”
    string getFrame() {
        return frame; // return frame
    }

    // addBar
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) { // add a bar
        if (size < capacity) { // check if there is room
            bars[size] = Bar(name, value, category); // add bar
            size++; // increment size
            return true; // return true
        }
        return false; // return false
    }
    
    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() {
        return size; // return size
    }
    
    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {

        if (i < 0 || i >= size) { // check if i is out of bounds
            throw out_of_range("BarChart: i out of bounds"); // throw error
        } 
        return bars[i]; // return bar                     
    }
    
    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) {
        // sort in descending order
        sort(bars, bars + size, greater<Bar>()); // sort bars in descending order
 
        //std::sort(bars, bars + size); // wouldnt work because of the ascending order
        
        output << "frame: " << getFrame() << endl; // print frame

        for (int i = 0; i < size; i++) { // for each bar
            output << bars[i].getName() << " " << bars[i].getValue() << " " << bars[i].getCategory() << endl; // print bar
        }        
    }
    
    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    //
    // This will produce the visualization of
    // the BarChart.  colorMap determines
    // how to color each category and top
    // determines how many bars are printed
    // on each frame.  See Figure 2 for what
    // is printed for this example.  If no
    // color map is provided, it should be
    // printed using the black color.  See
    // section titled “Graph Details” for
    // more information on how to translate
    // values into bars.  Note the bars are
    // printed in descending order by value.
    // If the colorMap is empty or the
    // category is not found in the colorMap,
    // the bar should be printed with
    // BLACK.

    void graph(ostream &output, map<string, string> &colorMap, int top) {
        // sort bars
        std::sort(bars, bars + size, greater<Bar>());
        
        int lenMax = 60;  // this is number of BOXs that should be printed
                          // for the top bar (max value)

        int highestBar = bars[0].getValue(); // get highest bar value
        int numBox = 0; // number of boxes to print

        string barstorage = ""; // string to store bars
        string color = WHITE; // default color is white

        // print bars
        for (int i = 0; i < top; i++) { // for each bar
            // reset barstorage 
            barstorage = ""; // reset barstorage
            // find number of BOXs to print
            // numBox = (this->bars[i].getValue() * lenMax) / highestBar;

            numBox = (bars[i].getValue() * lenMax) / highestBar; // find number of BOXs to print
            // find color
            if (colorMap.find(bars[i].getCategory()) != colorMap.end()) { // check if category is in colorMap
                color = colorMap[bars[i].getCategory()]; // set color
            }
            // print BOXs
            for (int j = 0; j < numBox; j++) { // for each box
                barstorage += BOX; // add box to barstorage
            }
            // print bar
            output << color << barstorage << ' ' << bars[i].getName() << ' ' << bars[i].getValue() << endl; // print bar
        }
    }
};
