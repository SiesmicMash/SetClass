//
//  SetInterface.hpp
//  SetClass
//
//  Created by Usaid Ali Syed on 2025-02-01.
//

#ifndef SET_INTERFACE_
#define SET_INTERFACE_

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
template <class ItemType>

class SetInterface {

public:
    virtual int getCardinality() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool contains(const ItemType& anEntry) const = 0;
    virtual bool addElement(const ItemType& newEntry) = 0;
    virtual bool removeElement(const ItemType& anEntry) = 0;
    virtual void clear() = 0;
    virtual void isSubset(const ItemType& otherSet) = 0;
    virtual vector<ItemType> toVector() const = 0;
    virtual ~SetInterface () { }; //Empty destructor
};

#endif /* SetInterface_hpp */
