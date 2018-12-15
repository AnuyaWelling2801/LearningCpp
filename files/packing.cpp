//
//  packing.cpp
//  
//
//  Created by Anuya Welling on 12/10/18.
//

#include <iostream>
using namespace std;

#pragma pack(push, 1)
struct Person{
    char name[50];
    int age;
    double weight;
};
#pragma pack(pop)

int main(){
    
    Person husband = {"Atul", 35, 77};
    string filename = "test.bin";
    
    //write binary file
    ofstream outputfile;
    outputfile.open(filename, ios::binary);
    if(outputfile.is_open()){
        
        outputfile.write(reinterpret_cast<char *>(&husband), sizeof(Person));
        outputfile.close();
        
    }
    else{
        cout<<"could not create file"<<endl;
    }
    
    Person husband2 = {"", 0, 0};
    
    //read binary file
    ifstream inputfile;
    inputfile.open(filename, ios::binary);
    if(inputfile.is_open()){
        
        inputfile.write(reinterpret_cast<char *>(&husband2), sizeof(Person));
        inputfile.close();
        
    }
    else{
        cout<<"could not create file"<<endl;
    }
    
    cout<<husband2.name<<" "<<husband2.age<<" "<<husband2.weight<<endl;
    return 0;
}
