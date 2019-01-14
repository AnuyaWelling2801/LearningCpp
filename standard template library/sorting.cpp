//
//  sorting.cpp
//  
//
//  Created by Anuya Welling on 1/13/19.
//

#include <iostream>
#include <vector>
using namespace std;

class Test{
private:
    string name;
    int id;
public:
    Test(string name, int id) : name(name), id(id){
    }
    ~Test(){
       
    }
    /*bool operator<(const Test &other) const{
        return id < other.id;
    }*/
    void print(){
        cout << name << " " << id << endl;
    }
    friend bool comp(const Test &test1, const Test &test2);
};

//The foolwing function can access the private variables of the Test class. It is prototyped "Friend" in the class
bool comp(const Test &test1, const Test &test2){
    return test1.id < test2.id;
}

int main(){
    vector<Test> tests;
    tests.push_back(Test("Anuya",1));
    tests.push_back(Test("Atul",0));
    tests.push_back(Test("Arpita",3));
    
    sort(tests.begin(),tests.end(),comp );
    for(auto test : tests){
        test.print();
    }
}
