/**
 *
 *  @brief      Assignment tasked to create a class which acts a set.
 *
 *  @file       VectorSet.hpp
 *  @name       SetClass
 *  @date       Created on 11/1/17
 *
 *  @author     Alfred
 *  @copyright  Copyright © 2017 Jacob Henning. All rights reserved..
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

/// @include MySet
#include "MySet.h"

#pragma once

/**
 *  @brief  A set stored in the form of a vector class
 *
 *  @package vector
 *  @package MySet
 *  @var template <class T>
 */

template <class T>
class VectorSet : public MySet<T>, private std::vector<T> {
public:
    VectorSet(){}
    ~VectorSet(){}
    unsigned long size()const;
    void insert(const T& val);
    void remove(const T& val);
    bool is_member(const T& val)const;
    MySet<T> * set_union(const MySet<T> & rhs) const;
    MySet<T> * set_intersect(const MySet<T> & rhs)const;
    MySet<T> * set_difference(const MySet<T> & rhs)const;
    MySet<T> * set_xor(const MySet<T> & rhs)const;
    T* toArray() const;
};

/**
 *  @brief This function will return the number of items in the set
 *
 *  @return returns the size of the set
 */

template <class T>
inline unsigned long VectorSet<T>::size()const {
    return std::vector<T>::size();
}

/**
 *  @brief Function adds a new value to the set. New value must not already be in the set.
 *
 *  @param val represents the number which is to be inserted into the set
 */

template <class T>
inline void VectorSet<T>::insert(const T& val) {
    if (!is_member(val))
        std::vector<T>::push_back(val);
}

/**
 *  @brief Function will remove value from set, and if value isn't present, will do nothing.
 *
 *  @param val represents the number which is to be removed from the set
 */

template <class T>
inline void VectorSet<T>::remove(const T& val) {
    if (is_member(val)) {
        for (unsigned int i = 0; i < std::vector<T>::size(); i++) {
            if (std::vector<T>::at(i) == val) {
                (*this)[i] = std::vector<T>::back();
                std::vector<T>::pop_back();
            }
        }
    }
}

/**
 *  @brief Function will remove value from set, and if value isn't present, will do nothing.
 *
 *  @param val represents the number which may or may not be in the set.
 *  @return true if val is found, but otherwise false.
 */

template <class T>
inline bool VectorSet<T>::is_member(const T& val)const {
    for (unsigned int i = 0; i < std::vector<T>::size(); i++)
        if (val == (*this)[i])
            return true;
    return false;
}

/**
 *  @brief Function returns a union combined with itself.
 *
 *  @note The function only returns the union of sets, but doesn't change the original sets within
 *        the functions scope.
 *
 *  @param rhs represents the first set which will be added to the return type.
 *  @return A new object consisting of the current set and rhs set's combined value.
 */

template <class T>
inline MySet<T>* VectorSet<T>::set_union(const MySet<T> & rhs)const {
    MySet<T> * tmp = new VectorSet<T>;
    for (int i = 0; i < this->size(); i++)
        tmp->insert((*this)[i]);
    T * rhsArr = rhs.toArray();
    for (int i = 0; i < rhs.size(); i++)
        tmp->insert(rhsArr[i]);
    return tmp;
}

template <class T>
inline MySet<T> * VectorSet<T>::set_intersect(const MySet<T> & rhs)const {
    MySet<T> * tmp = new VectorSet<T>;
    for (int i = 0; i < size(); i++) {
        if (rhs.is_member((*this)[i])) {
            tmp->insert((*this)[i]);
        }
    }
    return tmp;
}

template <class T>
inline MySet<T> * VectorSet<T>::set_difference(const MySet<T> & rhs)const {
    MySet<T> * tmp = new VectorSet<T>;
    for (int i = 0; i < size(); i++) {
        if (!rhs.is_member((*this)[i])) {
            tmp->insert((*this)[i]);
        }
    }
    return tmp;
}

template <class T>
inline MySet<T> * VectorSet<T>::set_xor(const MySet<T> & rhs)const {
    MySet<T> * tmp = new VectorSet<T>;
    for (int i = 0; i < size(); i++) {
        if (!rhs.is_member((*this)[i])) {
            tmp->insert((*this)[i]);
        }
    }
    T* arr = rhs.toArray();
    for (int i = 0; i < rhs.size(); i++) {
        if (!is_member(arr[i])) {
            tmp->insert(arr[i]);
        }
    }
    return tmp;
}

template <class T>
inline T* VectorSet<T>::toArray() const {
    T* arr = new T[size()];
    for (int i = 0; i < size(); i++)
        arr[i] = (*this)[i];
    return arr;
}
