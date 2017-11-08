/**
 *
 *  @brief      Assignment tasked to create a class which acts a set.
 *
 *  @file       MySet.hpp
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
 *  @attributes Modified from source: Stroup, Bjarne. "C++ Programming
 *              Language" 3rd ed.
 *
 */

#pragma once

/**
 *  @brief  A virtual class
 *
 */

template <class T>
class MySet {
public:
    virtual ~MySet() {}
    virtual unsigned long size()const = 0;
    virtual void insert(const T& val) = 0;
    virtual void remove(const T& val) = 0;
    virtual bool is_member(const T& val)const = 0;
    
    //// Added by Lydia
    virtual MySet<T> * set_union(const MySet<T> & rhs)const = 0;
    virtual MySet<T> * set_intersect(const MySet<T> & rhs)const = 0;
    virtual MySet<T> * set_difference(const MySet<T> & rhs)const = 0;
    virtual MySet<T> * set_xor(const MySet<T> & rhs)const = 0;
    virtual T* toArray()const = 0;
};
