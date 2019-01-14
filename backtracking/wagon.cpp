//
//  wagon.cpp
//  
//
//  Created by Anuya Welling on 1/12/19.
//




#include <iostream>
#include <vector>
using namespace std;

//using a bottom-up approach
int gold_collector_bottom_up(vector<int> &wagons){
    int size=wagons.size();
    vector<int> gold(size,0);
    gold[0] = wagons[0];
    gold[1] = max(wagons[0],wagons[1]);
    for(int i=2;i<size;i++){
        gold[i]=max(gold[i-1],gold[i-2]+wagons[i]);
    }
    
    return gold[size-1];
}

//using a top down approach - memoization
int gold_collector_memoization(int i, vector<int> &wagons, vector<int> &gold){
    if(i>=gold.size()){
        return 0;
    }
    if(gold[i]>0){
        return gold[i];
    }
    int a = gold_collector_memoization(i+1,wagons,gold);
    int b = gold_collector_memoization(i+2,wagons,gold)+wagons[i];
    gold[i] = max(a,b);
    return gold[i];
    
}
int main(){
    vector<int> wagons = {33,10,20,5,14,26};
    cout << "Gold Collected : " << gold_collector_bottom_up(wagons) << endl;
    vector<int> gold(wagons.size(),0);
    cout <<  "Gold Collected : " << gold_collector_memoization(0,wagons,gold) << endl;
    return 0;
}
