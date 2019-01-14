//
//  robber.cpp
//  
//
//  Created by Anuya Welling on 1/8/19.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <vector>
using namespace std;


int rob(int size, vector<int> &array){
    vector<int> houses(size);
    houses[0] = array[0];
    houses[1] = max(array[0],array[1]);
    
    for(int i=2;i<size;++i){
        houses[i]=max(houses[i-1],houses[i-2]+array[i]);
    }
    return houses[size-1];
}
int main(){
    int size = 7;
    vector<int> array(size);
    for(int i=0; i<size; i++){
        array[i] = (rand()%10)+1;
        cout << array[i] << " ";
    }
    cout << "The maximum money stolen is is " << rob(size, array) << endl;
    return 0;
}
