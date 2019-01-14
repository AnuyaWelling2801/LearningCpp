//
//  multimap.cpp
//  
//
//  Created by Anuya Welling on 1/13/19.
//

#include <iostream>
#include <map>
using namespace std;

int main(){
    //multimap can have duplicate keys
    multimap<string,int> lookup;
    lookup.insert(make_pair("Atul",35));
    lookup.insert(make_pair("Anuya",29));
    lookup.insert(make_pair("Arpita",22));
    lookup.insert(make_pair("Anuya",2));
    for(multimap<string,int>::iterator it=lookup.begin(); it!=lookup.end(); it++){
        //the iterator is stored as a pair. Refer the second loop
        cout << it->first << " " << it->second << endl;
    }
    
    //to find elements with the same
    pair<multimap<string,int>::iterator,multimap<string,int>::iterator> its = lookup.equal_range("Anuya");
    for(multimap<string,int>::iterator it=its.first;it!=its.second; it++){
        cout << it->first << " " << it->second << endl;
    }
    
    //For a c++11 compliant solution
    auto its2 = lookup.equal_range("Anuya");
    for(multimap<string,int>::iterator it=its2.first;it!=its2.second; it++){
        cout << it->first << " " << it->second << endl;
    }
}
