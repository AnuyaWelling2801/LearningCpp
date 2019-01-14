//
//  list.cpp
//  
//
//  Created by Anuya Welling on 1/13/19.
//

#include <iostream>
#include <list>
using namespace std;

int main(){
    //List vs vector
    //insert items in the beginning or end of a list. With a vector its usually at the end.
    //In vector all elements are next to each other. With a list the elements are connected by 2 pointers. DOUBLY LINKED LIST.
    list<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);
    
    //Adding elements at other places in the list
    list<int>::iterator it=numbers.begin();
    it++;
    numbers.insert(it, 100);
    cout << "Element addded : " << *it <<endl;
    
    //To erase the element
    list<int>::iterator erase_it=numbers.begin();
    erase_it++;
    numbers.erase(erase_it);
    //should never do it. It points to the deleted element
    cout << "Element erase: " << *erase_it <<endl;

    //Need an iterator to traverse a list. Cannot do it with a simple for loop.
    for(list<int>::iterator it=numbers.begin(); it!=numbers.end(); it++){
        cout << *it <<endl;
    }
    
    return 0;
}
