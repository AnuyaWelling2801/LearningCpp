//
//  map_custom_keys.cpp
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
    void print() const{
        cout << name << " " << age << endl;
    }
    
    bool operator< (const Person &other) const{
        return name < other.name;
    }
};

int main(){
    map<Person, int> people;
    //keys in the map are always unique
    people[Person("Anuya",29)]=1;
    
    //Wont treat this as a different operator because the comparison method does not mention age
    people[Person("Anuya",2)]=22;
    people.insert(make_pair(Person("Atul",35),3));
    people.insert(pair<Person,int>(Person("Arpita",22),5));
    
    for(map<Person,int>::iterator it=people.begin(); it!=people.end(); it++){
        //The print method needs to be a const here since it prints the keys of the map
        it->first.print();
        cout << it->second << endl;
    }
    
}

