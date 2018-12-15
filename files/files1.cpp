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
    
    ofstream outfile;
    string outputFileName = "file1.txt";
    outfile.open(outputFileName);
    
    if(outfile.is_open()){
        outfile << "this is a line" << endl;
        outfile << 28 <<endl;
        
    }
    else{
        cout << "error" <<endl;
    }
    outfile.close();
    return 0;
}
