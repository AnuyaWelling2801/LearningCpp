//
//  map_custom_values.cpp
//  
//
//  Created by Anuya Welling on 1/13/19.
//

#include <iostream>
#include <map>
using namespace std;

class Person{
private:
    string name;
    int age;
public:
    Person(): name(""), age(0)
    {}
    Person(const Person &other){
        cout<<"Copy constructor called" << endl;
        name=other.name;
        age=other.age;
    }
    Person(string name, int age): name(name), age(age){
    }
    void print(){
        cout << name << " " << age << endl;
    }
};

int main(){
    map<int, Person> people;
    //keys in the map are always unique
    people[1] = Person("Anuya",29);
    people.insert(make_pair(3, Person("Atul",35)));
    people.insert(pair<int,Person>(5, Person("Arpita",22)));
    
    for(map<int,Person>::iterator it=people.begin(); it!=people.end(); it++){
        //the iterator is stored as a pair. Refer the second loop
        cout << it->first << " " << flush;
        it->second.print();
    }
    
}
