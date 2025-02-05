//
//  arraySetDriver.cpp
//  SetClass
//
//  Created by Usaid Ali Syed on 2025-02-04.
//

#include "ArraySet.hpp"
#include "ArraySet.cpp"
#include <ctime>

template <class ItemType>
ostream& operator << (ostream &cout, const SetInterface<ItemType> &set_ref) {
    vector<ItemType> v = set_ref.toVector();
    int cardinality = (int)v.size();
    if (cardinality == 0) {
        cout << "{}";
    }
    else {
        cout << "{";
        for (int i = 0; i < cardinality - 1; i++) {
            cout << v[i] << ", ";
        }
        
        cout<< v[cardinality - 1];
        cout << "}";
    }
    return cout;
}

int main() {
    
    srand((int)time(0));
    cout << "Testing the Set ADT" << endl;
    cout << "===================" << endl;
    //Construct a default set object
    SetInterface<int> *set_ptr = new ArraySet<int>();
    cout << "A default set object constructed." << endl;
    cout << "A default set object is " << *set_ptr << endl;
    cout << "Its cardinality is " << set_ptr->getCardinality() << endl;
    //Check if the default set object is an empty set
    
    if (set_ptr->isEmpty())
        cout << "It is empty set" << endl;
    
    else
        cout << "It is not empty set" << endl;
    
    cout << endl;
    //Add a few items to the default set object
    int random_size = rand() % 10 + 10;
    
    for (int i = 0; i < random_size; i++) {
        
        int x = rand() % 21 - 10;
        cout << "Attempting to add the item " << x << " to the set " << *set_ptr << endl;
        
        bool flag = set_ptr->addElement(x);
        
        if (flag)
            cout << "\tSuccessfully added. Now the set is " << *set_ptr << endl;
        
        else
            cout << "\tAddition failed because it is already an element" << endl;
        
    }
    
    cout << "At the end, the set is " << *set_ptr << endl;
    cout << "Its cardinality is " << set_ptr->getCardinality() << endl;
    cout << endl;
    //Check to see if a few items are elements of the set
    for (int i = 0; i < 5; i++) {
        int x = rand() % 21 - 10;
        
        if (set_ptr->contains(x))
            cout << x << " is element of the set " << *set_ptr << endl;
        
        else
            cout << x << " is not element of the set " << *set_ptr << endl;
        
    }
    cout << endl;
    
    for (int i = 0; i < 5; i++) {
        
        int x = rand() % 21 - 10;
        cout << "Attempting to remove " << x << " from the set " << *set_ptr << endl;
        bool flag = set_ptr->removeElement(x);
        
        if (flag)
            cout << "\tSuccessfully removed. Now the set is " << *set_ptr << endl;
        
        else
            cout << "\tRemoval failed because it is not an element" << endl;
    }
    
    cout << "At the end, the set is " << *set_ptr << endl;
    cout << "Its cardinality is " << set_ptr->getCardinality() << endl;
    cout << endl;
    //Clear the set
    set_ptr->clear();
    cout << "After clearing it, the set is " << *set_ptr << endl;
    cout << "Its cardinality is " << set_ptr->getCardinality() << endl;
    cout << endl;
    //Delete any heap memory and finish the program
    delete set_ptr;
    
    cout << "Testing the array set copy constructor, assignment operator, and destructor..." << endl;
    cout << "==============================================================================" << endl;
    //Construct a default set object s1
    ArraySet<int> s1;
    cout << "Constructed a default set object s1 = " << s1 << endl;
    //Add a few elements to the set
    for (int i = 0; i < 10; i++) {
        int x = rand() % 11 - 5;
        cout << "Attempting to add the element " << x << " to the set " << s1 << endl;
        bool flag = s1.addElement(x);
        
        if (flag)
            cout << "\tSuccessfully added. Now the set is " << s1 << endl;
        
        else
            cout << "\tAddition failed because it is already an element" << endl;
    }
    
    cout << "At the end, the set is, s1 = " << s1 << endl;
    cout << endl;
    
    //Construct a set object s2 copied from s1
    ArraySet<int> s2(s1);
    cout << "Constructed a set s2 which is a copy of s1. Now, s1 = " << s1 << " and s2 = " << s2 << endl;
    cout << "s1 is a subset of s2 is " << s1.isSubset(s2) << endl;
    cout << "s2 is a subset of s1 is " << s2.isSubset(s1) << endl;
    cout << endl;
    //Destruct the set s1 and print
    s1.~ArraySet();
    cout << "After destructing s1, we get s1 = " << s1 << " and s2 = " << s2 << endl;
    cout << "s1 is a subset of s2 is " << s1.isSubset(s2) << endl;
    
    cout << "s2 is a subset of s1 is " << s2.isSubset(s1) << endl;
    cout << endl;
    //Assign the value of s2 to s1 and print
    s1 = s2;
    cout << "After assigning a copy of s2 to s1, we get s1 = " << s1 << " and s2 = " << s2 << endl;
    cout << "s1 is a subset of s2 is " << s1.isSubset(s2) << endl;
    cout << "s2 is a subset of s1 is " << s2.isSubset(s1) << endl;
    cout << endl;
    //Destruct the set s2 and print
    s2.~ArraySet();
    cout << "After destructing s2, we get s1 = " << s1 << " and s2 = " << s2 << endl;
    cout << "s1 is a subset of s2 is " << s1.isSubset(s2) << endl;
    cout << "s2 is a subset of s1 is " << s2.isSubset(s1) << endl;
    cout << endl;
    //Destruct both the sets s1 and s2 and print
    s1.~ArraySet();
    s2.~ArraySet();
    cout << "After destructing both the sets s1 and s2, we get s1 = " << s1 << " and s2 = " << s2 << endl;
    cout << "s1 is a subset of s2 is " << s1.isSubset(s2) << endl;
    cout << "s2 is a subset of s1 is " << s2.isSubset(s1) << endl;
    cout << endl;
    system("Pause");
    return 0;
}
