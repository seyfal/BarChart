// barchartanimate.h
// Seyfal Sultanov 
// UIC CS 251 Fall 2020 
// Professor: Adam Koehler

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size; // number of elements stored
    int capacity; // the number of elements that can be stored in the array
    map<string, string> colorMap; // map of color names to color codes

    // added new 
    string title; // title of the chart
    string xlable; // x axis label
    string source;  // source of the data

 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    // Should allocate memory on heap for
    // barcharts.  This will be a dynamic
    // array that expands (by doubling
    // itself) each time it runs out of room
    // to add a new frame.  In the
    // constructor, the capacity should be 4.
    // Everything else should be initialized
    // to default values
    BarChartAnimate(string title, string xlabel, string source) { // constructor
        barcharts = new BarChart[capacity]; // allocate memory on heap for barcharts
        capacity = 4; // capacity should be 4
        size = 0; // size should be 0
        this->title = title; // set title
        this->xlable = xlabel; // set xlabel
        this->source = source; // set source
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        if (barcharts != nullptr) { delete[] barcharts; } // delete barcharts
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    //
    // The file stream passed in guaranteed
    // to be the format provided above.
    // This explanation is referring to
    // Figure 1 (the file format).
    // Pre condition:  when addFrame is
    // called, it assumes that the fstream’s
    // first getline call will get the empty
    // line above the “group of records”
    // blue box.
    // Post condition: The function should
    // read the file to the end of the last
    // record in the group of records (12
    // records total, in the example given).
    // The function should build a BarChart
    // using this group of records and add it
    // to the BarChartAnimate object
    void addFrame(ifstream &file) {
        string line; // input line
        string key1; // key as a first value in the line 
        string name; // name as a second value in the line
        string country; // country as a third value in the line
        string value; // value as a fourth value in the line
        string category;  // category as a fifth value in the line

        int lines; // number of lines
        int barNum; // bar value

        getline(file, line); // get empty line

        if (file.eof()) // if file is empty
            return;
 
        else 
        {

            if (size == capacity) // if size is equal to capacity 
            {
                capacity = capacity*2; // double the capacity
                BarChart* temp = new BarChart[capacity*2]; // create new array with new capacity
                for (int i = 0; i < size; i++) // copy old array to a new one 
                {
                    temp[i] = barcharts[i]; // assign every bar in the old array to a new one
                }
                delete[] barcharts; // delete old array
                barcharts = temp; // assign new array to old one
            }

            getline(file, line); // get the second line 
            lines = stoi(line);  // string converts to integer

            BarChart barGroup(lines); // create new bar chart with number of lines

            for (int i = 0; i < lines; i++) // loop thru the lines 
            {
                getline(file, line, '\n'); // get the line
                stringstream ss(line); // create string stream

                getline(ss, key1, ',');      // get the year
                getline(ss, name, ',');      // get the name of city
                getline(ss, country, ',');   // get the name of country
                getline(ss, value, ',');     // get the value
                getline(ss, category, ',');  // get the category
        
                barNum = stoi(value); // convert string to integer
                barGroup.setFrame(key1); // set the frame
                barGroup.addBar(name, barNum, category); // add the bar to the chart 

                // if (!(colorMap.count(barCategory))) { // if color map does not contain the category
                //     colorMap[category] = COLORS[colorIndex]; // assign the color to the category
                //     colorIndex++; // increment the color index
                //     if(colorIndex == (int) COLORS.size()) { // if color index is equal to the size of the color vector
                //          colorIndex = 0; // set color index to 0
                //     } 
                // }
            }
            barcharts[size] = barGroup; // add the bar chart to the array
            size++; // increment the size
        }

    }
 
    // setTitle:
    // sets the title of the BarChartAnimate object
    // to the string passed in.
    void setTitle(string title) { 
        this->title = title; // set title
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
    // 
    // Animate should produce the final Bar
    // Chart Animation.  A few important
    // details are described below in
    // “Animation Details” as well as an
    // image.  The parameter top
    // determines the number of the top
    // bars are graphed.  The parameter
    // endIter determines how many
    // iterations of the animation are
    // graphed.  E.g. the first call will
    // animate the top 12 bars for 10
    // iterations.  The second call will
    // animate the 10 bars for all iterations
    // in the data file.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000; // 50,000 microseconds = 0.05 seconds 

        if(endIter == -1) { // if endIter is -1, then we want to animate all iterations 
            endIter = size; // set endIter to the size of the array
        }

    	for (int i = 0; i < endIter; i++) { // for each frame
            output << CLEARCONSOLE; // clear the console
            output << WHITE << title << endl; // print the title
            output << WHITE << source << endl; // print the source

            // print the bars 
    	    barcharts[i].graph(output, colorMap, top); // graph the frame

    	    output << WHITE << xlable << endl; // print the x label
            output << "Frame:" << barcharts[i].getFrame() << endl; // print the frame number
            usleep(3 * microsecond); // pause
    	}        
	}

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        return size; // return the size of the array
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){ // overload the [] operator
        BarChart bc; // create a new bar chart
        if (i < 0 || i >= size) { // if i is out of bounds
            throw out_of_range("BarChartAnimate: i out of bounds"); // throw an error
        }
        return barcharts[i];  // return the bar chart
    }
};
