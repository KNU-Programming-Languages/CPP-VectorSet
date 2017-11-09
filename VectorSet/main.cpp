/**
 *
 *  @brief      Assignment tasked to create a class which acts a set.
 *
 *  @file       main.cpp
 *  @name       SetClass
 *  @date       Created on 11/1/17
 *
 *  @author     Alfred
 *  @copyright  Copyright © 2017 Jacob Henning. All rights reserved.
 *  @license    MIT License
 *
 *  @notice     All of the following, unless otherwise noted in the attributes,
 *              is 100% orignal content created by Jacob Henning.
 *
 *  @attributes While this code has been 100% typed by Jacob Henning, some of
 *              the concepts and ideas may have been influenced by professors
 *              and classmates.
 *
 */

/// @include iostream
#include <iostream>

/// @include vector
#include <vector>

/// @include VectorSet
#include "VectorSet.h"

/// @namespace std
using namespace std;

//// test

string cleanUp(string str) {
    string result = "";
    
    for (int i = 0; i < str.length(); i++)
        result += tolower(str[i]);
    
    while (result.size()!=0 && !isalpha(result[0]))
        result = result.substr(1);
    
    while (!isalpha(result.back()))
        result = result.substr(0, str.length() - 1);
    
    return result;
}


/**
 *  @brief Does nothing specific, and is more or less of a playground.
 *
 *  @return 0
 */

int main() {
    
    MySet<int> * intSet1 = new VectorSet<int>;
    MySet<int> * intSet2 = new VectorSet<int>;
    
    intSet1->insert(1);
    intSet1->insert(2);
    intSet1->insert(3);
    intSet1->insert(4);
    intSet1->insert(5);
    intSet1->insert(6);
    intSet1->insert(7);
    
    // intSet1 = [1,2,3,4,5,6,7]        // 7
    
    intSet2->insert(6);
    intSet2->insert(7);
    intSet2->insert(8);
    intSet2->insert(9);
    intSet2->insert(10);
    
    // intSet2 = [6,7,8,9,10]               // 5
    
    MySet<int> * intSet3 = intSet1->set_union(*intSet2);
    
    // intSet3 = [1,2,3,4,5,6,7,8,9,10]     // 10
    
    MySet<int> * intSet4 = intSet1->set_intersect(*intSet2);
    
    // intSet4 = [6,7]                      // 2
    
    MySet<int> * intSet5 = intSet1->set_difference(*intSet2);
    
    // intSet5 = [1,2,3,4,5]                // 5
    
    MySet<int> * intSet6 = intSet1->set_xor(*intSet2);
    
    // intSet6 = [1,2,3,4,5,8,9,10]         // 8
    
    cout << intSet1->size() << endl;
    cout << intSet2->size() << endl;
    cout << intSet3->size() << endl;
    cout << intSet4->size() << endl;
    cout << intSet5->size() << endl;
    cout << intSet6->size() << endl;
    cout << endl << endl << endl << endl;
    
    
    return 0;
}
