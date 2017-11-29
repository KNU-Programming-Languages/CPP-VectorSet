/**
 *  @file       VectorSet.h
 *  @author     Jacob Henning
 *  @date       Created on 11/1/17
 *
 *  @notice     All of the following, unless otherwise noted in file,
 *              100% orignal content created by Jacob Henning
 */

#include "MySet.h"

/**
 *  A set stored in the form of a vector class
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
 *  Function returns the size of the current set
 *
 *  @return returns the size of the set
 */

template <class T>
inline unsigned long VectorSet<T>::size()const {
    return std::vector<T>::size();
}

/**
 *  Function adds a new value to the set, so long as value isn't already present in set
 *
 *  @param val represents the number which is to be inserted into the set
 */

template <class T>
inline void VectorSet<T>::insert(const T& val) {
    if (!is_member(val))
        std::vector<T>::push_back(val);
}

/**
 *  Function removes value from set
 *
 *  @param val represents the number which is to be removed from the set
 */

template <class T>
inline void VectorSet<T>::remove(const T& val) {
    if (is_member(val)) {
        for (unsigned int i = 0; i < size(); i++) {
            if (std::vector<T>::at(i) == val) {
                (*this)[i] = std::vector<T>::back();
                std::vector<T>::pop_back();
            }
        }
    }
}

/**
 *  Function confirms whether or not value is in current set
 *
 *  @param val represents the number which may or may not be in the set
 *  @return true if val is found, but otherwise false
 */

template <class T>
inline bool VectorSet<T>::is_member(const T& val)const {
    for (unsigned int i = 0; i < std::vector<T>::size(); i++)
        if (val == (*this)[i])
            return true;
    return false;
}

/**
 *  Function returns a set equaling the combination of itself and an additional set
 *
 *  @param rhs is the additional set of which is to be added
 *  @return tmp is the new set which is to be returned
 */

template <class T>
inline MySet<T>* VectorSet<T>::set_union(const MySet<T> & rhs)const {
    MySet<T> * tmp = new VectorSet<T>;
    for (unsigned int i = 0; i < this->size(); i++)
        tmp->insert((*this)[i]);
    T * rhsArr = rhs.toArray();
    for (unsigned int i = 0; i < rhs.size(); i++)
        tmp->insert(rhsArr[i]);
    return tmp;
}

/**
 *  Function returns a set equaling the common values of itself and an additional set
 *
 *  @param rhs is a new set which will be compared with the current set
 *  @return A new object consisting only of values the current set and additional set have in common.
 */

template <class T>
inline MySet<T> * VectorSet<T>::set_intersect(const MySet<T> & rhs)const {
    MySet<T> * tmp = new VectorSet<T>;
    for (unsigned int i = 0; i < size(); i++) {
        if (rhs.is_member((*this)[i])) {
            tmp->insert((*this)[i]);
        }
    }
    return tmp;
}

/**
 *  Function returns its own set aside from the values which are also in the referenced set
 *
 *  @param rhs represents the additional set which will be compared with the current
 *  @return tmp is a new object which represents the current set minus the new set values
 */

template <class T>
inline MySet<T> * VectorSet<T>::set_difference(const MySet<T> & rhs)const {
    MySet<T> * tmp = new VectorSet<T>;
    for (unsigned int i = 0; i < size(); i++) {
        if (!rhs.is_member((*this)[i])) {
            tmp->insert((*this)[i]);
        }
    }
    return tmp;
}

/**
 *  Function returns any values the current and referenced set don't have in common
 *
 *  @param rhs represents the referenced set
 *  @return tmp is the returned set of values which neither set had in common
 */

template <class T>
inline MySet<T> * VectorSet<T>::set_xor(const MySet<T> & rhs)const {
    MySet<T> * tmp = new VectorSet<T>;
    for (unsigned int i = 0; i < size(); i++) {
        if (!rhs.is_member((*this)[i])) {
            tmp->insert((*this)[i]);
        }
    }
    T* arr = rhs.toArray();
    for (unsigned int i = 0; i < rhs.size(); i++) {
        if (!is_member(arr[i])) {
            tmp->insert(arr[i]);
        }
    }
    return tmp;
}

/**
 *  Function returns curren sets values in the form of an array
 *
 *  @return arr is the array consiting of the current sets values
 */

template <class T>
inline T* VectorSet<T>::toArray() const {
    unsigned long arraySize = std::vector<T>::size();
    T* arr = new T[arraySize];
    for (unsigned int i = 0; i < std::vector<T>::size(); i++)
        arr[i] = (*this)[i];
    return arr;
}
