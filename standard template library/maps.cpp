//
//  maps.cpp
//  
//
//  Created by Anuya Welling on 1/13/19.
//

#include <iostream>
#include <map>
using namespace std;


int main(){
    map<string,int> ages;
    //keys in the map are always unique
    ages["Anuya"] = 29;
    ages.insert(make_pair("Atul",35));
    ages.insert(pair<string,int>("Arpita",22));
    
    //If we look up a key thats not in the list, that key is created with value 0. The variable is created simply by using it
    cout << ages["baby"] << endl;
    
    //to find an element in the map. Does not add anything to the map.
    if(ages.find("Atul") != ages.end()){
        cout << "Found Atul" << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    for(map<string,int>::iterator it=ages.begin(); it!=ages.end(); it++){
        //Using pair
        pair<string, int> age = *it;
        cout << age.first << " " << age.second << endl;
    }
    for(map<string,int>::iterator it=ages.begin(); it!=ages.end(); it++){
        //the iterator is stored as a pair. Refer the second loop
        cout << it->first << " " << it->zsecond << endl;
    }
    
}
