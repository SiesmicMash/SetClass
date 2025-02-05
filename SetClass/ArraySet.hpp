//
//  ArraySet.hpp
//  SetClass
//
//  Created by Usaid Ali Syed on 2025-02-03.
//

#ifndef ARRAY_SET_
#define ARRAY_SET_

#include "SetInterface.hpp"

template <class ItemType>
class ArraySet: public SetInterface<ItemType> {
private:
    ItemType *elements;
    int cardinality;
    int elementCount;
    static const int DEFUALT_CARDINALITY = 0;
    
    
    
public:
    ArraySet();
    ArraySet(const ArraySet<ItemType> &sourceSet);
    ~ArraySet();
    ArraySet<ItemType>& operator = (const ArraySet<ItemType> &sourceSet);
    
    int getCardinality() const;
    bool isEmpty() const;
    bool contains(const ItemType& item) const;
    bool addElement(const ItemType& item) const;
    bool removeElement(const ItemType& item) const;
    void clear() const;
    bool isSubset(const ItemType& otherSet)const;
    vector<ItemType> toVector() const;
    
private:
    int getIndexOf(const ItemType& target) const;
    bool containsRecursive(ItemType *arr, int startIndex, int lastIndex, const ItemType& item)const;
};


#endif /* ArraySet_hpp */
