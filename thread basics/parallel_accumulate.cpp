//
//  parallel_accumulate.cpp
//  
//
//  Created by Anuya Welling on 1/4/19.
//

#include <iostream>
#include <thread>
using namespace std;

template<typename iterator, typename T>
void accumulate_block(iterator start, iterator end, T& result ){
    accumulate(start,end, result);
    
}
template<typename iterator, typename T>
T accumulate_list(iterator start, iterator end, T init){
    int distance = distance(start,end);
    const int min_elements = 500;
    int allowed_threads = thread::hardware_concurrency();
    int running_threads = min(allowed_threads, distance/min_elements);
    vector<T> results(running_threads);
    vector<thread> threads(running_threads-1);
    iterator block_start = start;
    int block_size = distance/(running_threads);
    
    for(int i=0;i < (running_threads-1) ; i++){
        iterator block_end = block_start;
        advance(block_end,block_size);
        threads[i] = threads(accumulate_block<iterator,T>(block_start,block_end,ref(results[i]) ));
        block_start = block_end;
    }
    
    accumulate_block<iterator,T>(block_start,end,ref(results[running_threads-1]) );
    for_each(threads.begin(),threads.end(),mem_fn(&thread::join));
    return accumulate(results.begin(), results.end(), init );
    
}

int main(){
    int elements = 5000;
    vector<int> values(elements);
    for (int i=0;i<elements;i++){
        values[i] = i;
    }
    int val = 0;
    cout << accumulate_list(values.begin(), values.end(), val) << endl;
    return 0;
}
