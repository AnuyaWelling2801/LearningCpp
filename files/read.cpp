//
//  files1.cpp
//  
//
//  Created by Anuya Welling on 12/10/18.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    
    ifstream infile;
    string inFileName = "file1.txt";
    infile.open(inFileName);
    
    if(infile.is_open()){
        
        string line;
        while(infile){
            getline(infile,line);
            cout << line <<endl;
        }
        
        infile.close();
    }
    else{
        cout << "error" <<endl;
    }
    return 0;
}
