//
//  2d.cpp
//  
//
//  Created by Anuya Welling on 1/13/19.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> grid(3, vector<int>(4,12));
    for(int row=0; row<grid.size();row++){
        for(int col=0; col<grid[row].size(); col++){
            cout << grid[row][col]*(row+1)*(col+1) << " ";
        }
        cout << endl;
    }
}
