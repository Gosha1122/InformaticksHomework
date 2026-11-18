#include <iostream>
#include "maxheap.h"
using namespace std;


int main() {
    int n; cin >> n;
    MaxHeap heap;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        heap.push(t);
    }
    while(heap.count() > 1){
        int x = heap.pop();
        int y = heap.pop();
        if(x != y){
            heap.push(max(x, y) - min(x, y));
        }
    }
    if(heap.count() == 0){
        cout << 0 << endl;
    }else{
        cout << heap.pop() << endl;
    }

}