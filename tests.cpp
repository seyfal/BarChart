// Seyfal Sultanov 
// UIC CS 251 Fall 2020 
// Professor: Adam Koehler
#include <iostream>
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "barchartanimate.h"
using namespace std;

//-------------------------- start of bar.h tests -----------------------------------
//##################################################################################
//##################################################################################
//##################################################################################
//##################################################################################

bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool testBarDestructor() {
	Bar *b = new Bar("Chicago", 9234324, "US");
	delete b;
	cout << "testBarDestructor: all passed!" << endl;
	return true;
}

bool testBarGetters() {
	Bar b("Chicago", 9234324, "US");
	if (b.getCategory() != "US") {
		cout << "testBarGetCategory: getCategory failed" << endl;
		return false;
	}
	if (b.getName() != "Chicago") {
		cout << "testBarGetName: getName failed" << endl;
		return false;
	}
	if (b.getValue() != 9234324) {
		cout << "testBarGetValue: getValue failed" << endl;
		return false;
	}
	cout << "testBarGetCategory: all passed!" << endl;
	return true;
}

bool testoperators() {
	Bar b1("Chicago", 9234324, "US");
	Bar b2("New York", 9234324, "US");
	Bar b3("San Fransico", 9234324, "US");
	if (!(b1 <= b3)) {
		cout << "testlessthanorequaltooperator: <= operator failed" << endl;
		return false;
	}
	if (!(b1 >= b2)) {
		cout << "testmorethanorequaltooperator: >= operator failed" << endl;
		return false;
	}
	if (!(b1 >= b3)) {
		cout << "testmorethanorequaltooperator: >= operator failed" << endl;
		return false;
	}
	if (b2 < b1) {
		cout << "testlessthanoperator: < operator failed" << endl;
		return false;
	}
	if (b1 > b2) {
		cout << "testmorethanoperator: > operator failed" << endl;
		return false;
	}
	cout << "testlessthanorequaltooperator: all passed!" << endl;
	return true;
}

bool testcopyconstructor() {
	Bar b1("Chicago", 9234324, "US");
	Bar b2(b1);
	if (b2.getName() != "Chicago") {
		cout << "testcopyconstructor: getname failed" << endl;
		return false;
	}
	if (b2.getValue() != 9234324) {
		cout << "testcopyconstructor: getvalue failed" << endl;
		return false;
	}
	if (b2.getCategory() != "US") {
		cout << "testcopyconstructor: getcategory failed" << endl;
		return false;
	}
	cout << "testcopyconstructor: all passed!" << endl;
	return true;
}

//---------------------------- end of bar.h tests -----------------------------------
//##################################################################################
//##################################################################################
//##################################################################################
//##################################################################################
//---------------------------- start of barchart.h tests ----------------------------

bool testBarChartDefaultConstructor() {
	BarChart b;
	if (b.getFrame() != "") {
		cout << "testBarChartDefaultConstructor: getFrame failed" << endl;
		return false;
	} else if (b.getSize() != 0) {
		cout << "testBarChartDefaultConstructor: getSize failed" << endl;
		return false;
	}
	cout << "testBarChartDefaultConstructor: all passed!" << endl;
	return true;
}

bool testBarChartParamConstructor() {
	BarChart b(13);
	if (b.getFrame() != "") {
		cout << "testBarChartParamConstructor: getFrame failed" << endl;
		return false;
	} else if (b.getSize() != 0) {
		cout << "testBarChartParamConstructor: getSize failed" << endl;
		return false;
	} 
	cout << "testBarChartParamConstructor: all passed!" << endl;
	return true;
}

bool testBarChartCopyConstructor() {
	BarChart b1(13);
	BarChart b2(b1);
    if(b2.getFrame() != b1.getFrame()){
		cout << "testBarChartCopyConstructor: getFrame failed" << endl;
		return false;
	}
	else if(b2.getSize() != b1.getSize()){
		cout << "testBarChartCopyConstructor: getSize failed" << endl;
		return false;
	}
	cout << "testBarChartCopyConstructor: all passed!" << endl;
	return true;
}

bool testCopyOperator() {
	BarChart b1(13);
	BarChart b2;
	b2 = b1;
	if (b2.getFrame() != b1.getFrame()) {
		cout << "testCopyOperator: getFrame failed" << endl;
		return false;
	}
	else if (b2.getSize() != b1.getSize()) {
		cout << "testCopyOperator: getSize failed" << endl;
		return false;
	}
	cout << "testCopyOperator: all passed!" << endl;
	return true;
}

bool testclear() {
	BarChart b1(13);
	b1.clear();
	if (b1.getSize() != 0) {
		cout << "testclear: getSize failed" << endl;
		return false;
	}
	else if (b1.getFrame() != "") {
		cout << "testclear: getFrame failed" << endl;
		return false;
	}
	cout << "testclear: all passed!" << endl;
	return true;
}

bool testSetFrame() {
	BarChart b1(13);
	b1.setFrame("test");
	if (b1.getFrame() != "test") {
		cout << "testSetFrame: getFrame failed" << endl;
		return false;
	}
	cout << "testSetFrame: all passed!" << endl;
	return true;
}

bool testGetFrame() {
	BarChart b1(13);
	b1.setFrame("test");
	if (b1.getFrame() != "test") {
		cout << "testGetFrame: getFrame failed" << endl;
		return false;
	}
	cout << "testGetFrame: all passed!" << endl;
	return true;
}

bool testgetsize() {
	BarChart b1(13);
	b1.addBar("Chicago", 9234324, "US");
	b1.addBar("New York", 9234324, "US");
	b1.addBar("Chicago", 9234324, "US");

	if (b1.getSize() != 3) {
		cout << "testgetsize: getSize failed" << endl;
		return false;
	}
	cout << "testgetsize: all passed!" << endl;
	return true;
}

bool testaddbar() {
	BarChart b1(13);
	b1.addBar("Chicago", 9234324, "US");
	b1.addBar("New York", 9234324, "US");
	b1.addBar("SF", 9234324, "US");
	if (b1.getSize() != 3) {
		cout << "testaddbar: getSize failed" << endl;
		return false;
	}
	cout << "testaddbar: all passed!" << endl;
	return true;
}

bool testBracketOperator() {
	BarChart b1(13);
	b1.addBar("Chicago", 9234324, "US");
	b1.addBar("New York", 182139, "China");
	b1.addBar("SF", 945939, "UK");
	if (b1[0].getName() != "Chicago") {
		cout << "testBracketOperator: getName failed" << endl;
		return false;
	}
	else if (b1[1].getName() != "New York") {
		cout << "testBracketOperator: getName failed" << endl;
		return false;
	}
	else if (b1[2].getName() != "SF") {
		cout << "testBracketOperator: getName failed" << endl;
		return false;
	}
	else if (b1[0].getValue() != 9234324) {
		cout << "testBracketOperator: getValue failed" << endl;
		return false;
	}
	else if (b1[1].getValue() != 182139) {
		cout << "testBracketOperator: getValue failed" << endl;
		return false;
	}
	else if (b1[2].getValue() != 945939) {
		cout << "testBracketOperator: getValue failed" << endl;
		return false;
	}
	else if (b1[0].getCategory() != "US") {
		cout << "testBracketOperator: getCategory failed" << endl;
		return false;
	}
	else if (b1[1].getCategory() != "China") {
		cout << "testBracketOperator: getCategory failed" << endl;
		return false;
	}
	else if (b1[2].getCategory() != "UK") {
		cout << "testBracketOperator: getCategory failed" << endl;
		return false;
	}
	cout << "testBracketOperator: all passed!" << endl;
	return true;
}

void testDump() {
	BarChart b1(13);
	b1.setFrame("1000");
	b1.addBar("Chicago", 234324, "US");
	b1.addBar("New York", 182139, "China");
	b1.addBar("SF", 445939, "UK");
	stringstream ss("");
	b1.dump(ss);
	cout << ss.str() << endl;
}

void testdumpempty() {
	BarChart b1;
	b1.dump(cout);
}

void testGraph(){
	BarChart b1(13);
	b1.setFrame("1000");
	b1.addBar("Chicago", 9234324, "US");
	b1.addBar("New York", 882139, "China");
	string cyan("\033[0;36m");
	string green("\033[0;32m");
	map<string, string> colorMap;
	colorMap["US"] = cyan;
	colorMap["China"] = green;
	b1.graph(cout, colorMap, 2);

	cout << "############################################" << endl;
}

void testbiggergraph(){
	BarChart b1(13);
	b1.setFrame("1000");
	b1.addBar("Chicago", 423434, "US");
	b1.addBar("New York", 182139, "China");
	b1.addBar("SF", 245939, "UK");
	b1.addBar("Baku", 129039, "Azerbaijan");
	b1.addBar("Quba", 205939, "Azerbaijan");
	b1.addBar("Qusar", 305939, "Azerbaijan");
	string cyan("\033[0;36m");
	string green("\033[0;32m");
	string red("\033[0;31m");
	string yellow("\033[0;33m");
	map<string, string> colorMap;
	colorMap["US"] = cyan;
	colorMap["China"] = green;
	colorMap["UK"] = red;
	colorMap["Azerbaijan"] = yellow;
	b1.graph(cout, colorMap, 6);
}

void testEmptyGraph(){
	BarChart b1;
	map<string, string> colorMap; 
	b1.graph(cout, colorMap, 1);
}

void testcolorless(){
	BarChart b1(13);
	b1.setFrame("1000");
	b1.addBar("Chicago", 423434, "US");
	b1.addBar("New York", 182139, "China");
	b1.addBar("SF", 245939, "UK");
	b1.addBar("Baku", 129039, "Azerbaijan");
	b1.addBar("Quba", 205939, "Azerbaijan");
	b1.addBar("Qusar", 305939, "Azerbaijan");
	map<string, string> colorMap;
	b1.graph(cout, colorMap, 6);
}

//---------------------------- end of barchart.h tests ------------------------------
//##################################################################################
//##################################################################################
//##################################################################################
//##################################################################################

int main() {

	// start of bar.h tests 
	testBarDefaultConstructor();
	testBarParamConstructor();
	testBarDestructor();
	testBarGetters();
	testoperators();
	testcopyconstructor();

	// start of barchart.h tests 
	testBarChartDefaultConstructor();
	testBarChartParamConstructor();
	testBarChartCopyConstructor();
	testCopyOperator();
	testclear();
	testSetFrame(); 
	testGetFrame();
	testgetsize();
	testaddbar();
	testBracketOperator();
	testDump();
	testdumpempty();
	testGraph();
	testbiggergraph();
	testcolorless();
	testEmptyGraph();

	return 0;
}
