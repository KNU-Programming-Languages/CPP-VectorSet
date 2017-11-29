/**
 *  @file       main.cpp
 *  @author     Jacob Henning
 *  @date       Created on 11/1/17
 *
 *  @notice     All of the following, unless otherwise noted in file,
 *              100% orignal content created by Jacob Henning
 */

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "VectorSet.h"

using namespace std;

void printSet(VectorSet<int> set);

/**
 *  Function designed to remove all non-alpha values from string
 *
 *  @param str is the string to be modified
 *  @return result is the modified string
 */

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
 *  Function designed to console out all anagram combinations
 *
 *  @param word is the string to be analyzed
 */

void getAnagrams(string word) {
    MySet<string> * arrangements = new VectorSet<string>;
    string original = word;
    sort(word.begin(), word.end());
    arrangements->insert(word);
    while (next_permutation(word.begin(), word.end()))
        arrangements->insert(word);
    cout << "There are " << arrangements->size() << " unique arra";
    cout << "ngements of the word \"" << original << "\"" << endl;
}

/**
 *  Function designed to print out set in its entirety
 *
 *  @param set will be printed
 */

void printSet(MySet<int> * set) {
    int * arr = set->toArray();
    for (unsigned int i = 0; i < set->size(); i++)
        cout << arr[i];
    cout << endl;
}

/*
void printSet(int * arr, size_t arraySize) {
    for (unsigned int i = 0; i < arraySize; i++)
        cout << arr[i];
    cout << endl;
}
 */

/**
 *  Main function can be used in whatever way needed, which in this case,
 *  is to complete the requirements of this assignment.
 *
 *  @return 0
 */

int main() {
    
    ifstream fin("test.in");
    
    if (!fin) {
        cerr << "File not found \n";
        exit(1);
    }
    
    string str;
    
    while (fin >> str) {
        str = cleanUp(str);
        getAnagrams(str);
    }

    MySet<int> * intSet1 = new VectorSet<int>;
    MySet<int> * intSet2 = new VectorSet<int>;

    intSet1->insert(1);
    intSet1->insert(2);
    intSet1->insert(3);

    intSet2->insert(3);
    intSet2->insert(4);
    intSet2->insert(5);

    MySet<int> * intSet3 = intSet1->set_union(*intSet2);
    MySet<int> * intSet4 = intSet1->set_intersect(*intSet2);
    MySet<int> * intSet5 = intSet1->set_difference(*intSet2);
    MySet<int> * intSet6 = intSet1->set_xor(*intSet2);

    
    printSet(intSet1);
    cout << "Set 1: ";
    printSet(intSet1);
    cout << "Set 2: ";
    printSet(intSet2);
    cout << "Set 3: ";
    printSet(intSet3);
    cout << "Set 4: ";
    printSet(intSet4);
    cout << "Set 5: ";
    printSet(intSet5);
    cout << "Set 6: ";
    printSet(intSet6);

    return 0;
}
