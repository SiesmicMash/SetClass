//
//  ArraySet.cpp
//  SetClass
//
//  Created by Usaid Ali Syed on 2025-02-03.
//

#include "ArraySet.hpp"

template <class ItemType>
ArraySet<ItemType> :: ArraySet() : cardinality(DEFUALT_CARDINALITY), elementCount(0) {
    
    elements = new ItemType[cardinality];
};

template <class ItemType>
ArraySet<ItemType> :: ArraySet (const ArraySet<ItemType> &sourceSet) : cardinality(sourceSet.cardinality), elementCount(sourceSet.elementCount) {
    
    if (cardinality > 0) {
        elements = new ItemType[cardinality];
        for (int i = 0; i < elementCount; i++) {
            elements[i] = sourceSet.elements[i];
        }
    }
}

template <class ItemType>
ArraySet<ItemType>:: ~ArraySet() {
    
    if (cardinality > 0) {
        delete [] elements;
        cardinality = 0;
        elementCount = 0;
        elements = nullptr;
    }
}

template <class ItemType>
ArraySet<ItemType>& ArraySet<ItemType>::operator=(const ArraySet<ItemType> &sourceSet) {
    if (this != &sourceSet) {
        this ->~ArraySet();
        cardinality = sourceSet.cardinality;
        elementCount = sourceSet.elementCount;
        
        if (cardinality > 0) {
            elements = new ItemType[cardinality];
            
            for(int i = 0; i < elementCount; i++) {
                elements[i] = sourceSet.elements[i];
            }
        }
        
    }
    
    return *this;
}

template <class ItemType>
int ArraySet<ItemType>:: getCardinality() const{
    return elementCount;
}

template <class ItemType>
bool ArraySet<ItemType>:: contains(const ItemType &item) const{
    return containsRecursive(elements, 0, elementCount, item);
}



template <class ItemType>
bool ArraySet<ItemType>:: addElement(const ItemType &item) const{
    
    if (!contains(item)) {
        if (elementCount == cardinality) {
            resize(cardinality *2);
        }
        elements[elementCount ++] = item;
    }
}

template <class ItemType>
bool ArraySet<ItemType>:: removeElement(const ItemType &item) const{
    
    int index = getIndexOf(item);
    
    if (index == -1) {
        return false;
    }
    else{
        elements[index] = elements[elementCount - 1];
        elementCount --;
        
        return true;
    }
}

template <class ItemType>
void ArraySet<ItemType>:: clear() const{
    elementCount = 0;
}

template <class ItemType>
bool ArraySet<ItemType>:: isSubset(const ItemType &otherSet) const{
    return true;
}

template <class ItemType>
vector<ItemType> ArraySet<ItemType>:: toVector() const{
    
    vector<ItemType> v;
    
    for (int i = 0; i < elementCount; i ++) {
        v.push_back(elements[i]);
    }
    
    return v;
}

template <class ItemType>
int ArraySet<ItemType>:: getIndexOf(const ItemType &target) const{
    
    for (int  i = 0; i< elementCount; i++) {
        if (elements[i] == target) {
            return i;
        }
    }
    return -1;
}

template <class ItemType>
bool ArraySet<ItemType>:: containsRecursive(ItemType *arr, int startIndex, int lastIndex, const ItemType &item)const{
    
    if(startIndex > lastIndex) {
        return false;
    } else{
        
        if (startIndex == item) {
            return true;
        }
        
        else{
            return (elements, startIndex + 1, lastIndex, item);
        }
    }
}

