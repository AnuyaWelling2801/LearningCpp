//
//  sets.cpp
//  
//
//  Created by Anuya Welling on 1/13/19.
//

#include <iostream>
#include <set>
using namespace std;

class Person{
private:
    string name;
    int age;
public:
    Person(): name(""), age(0)
    {}
    Person(const Person &other){
        name=other.name;
        age=other.age;
    }
    Person(string name, int age): name(name), age(age){
    }
    void print() const{
        cout << name << " " << age << endl;
    }
    
    bool operator< (const Person &other) const{
        return name < other.name;
    }
};

int main(){
    //set stores unique elements
    set<Person> person;
    person.insert(Person("Anuya",2));
    person.insert(Person("Atul",3));
    person.insert(Person("Arpita",7));
    
    //Just the name is compared and not the id, hence duplicates are found and this is not considered.
    //In Maps, this will just chane the value, it sets it does nothing
    person.insert(Person("Atul",4));
    
    for(set<Person,int>::iterator it=person.begin(); it!=person.end(); it++){
        //The print method needs to be a const here since it prints the keys of the map
        it->print();
    }
    
}

