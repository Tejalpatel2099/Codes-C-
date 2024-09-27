#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Heap {  
    vector<int> vec;  // vector to represent the heap (CBT)

public:
    // Function to insert a value into the heap
    void push(int val) {
        vec.push_back(val);  // Add the value to the end of the vector

        int x = vec.size() - 1;  // Index of the newly added element
        int pI = (x - 1) / 2;    // Parent index

        
        while (x > 0 && vec[x] > vec[pI]) {  // here used parent child relation, 
            swap(vec[x], vec[pI]);  // Swap the child and parent
            x = pI;                 // Move up to the parent index
            pI = (x - 1) / 2;       // Update the parent index
        }
    }
    void heapify(int i) {  // i is parent index 
    if (i >=vec.size()){ // base case , for when vector becomes empty 
        return;
    }
        int left = 2*i+1; 
        int right = 2*i+2;

        int maxIndex = i; // maxidx is equal to pI but if not tyhen swap 
        if(left < vec.size() && vec[left] > vec[maxIndex] ) { // left child should have valid value, if vectorof left  value becomes greater than maxidx then maxidx update  
            maxIndex = left;
        } 
         if(right < vec.size() && vec[right] > vec[maxIndex] ) {
            maxIndex = right; 
         }
         swap(vec[i],vec[maxIndex]); 
         if(maxIndex != i) {  // swapping is done but if swapping is done with child node then recursive heapify is called 
         heapify(maxIndex);

         }
    }

    void pop() {
        swap(vec[0], vec[vec.size()-1]);  // swap lastindex with first index 
        vec.pop_back(); // delete lastindex so pop back 
        heapify(0);
    }
    int top() {
        return vec[0]; // highest priority element 
    }
    void printHeap() {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }

};

int main() {
    Heap h;
    h.push(9);
    h.push(4);
    h.push(8);
    h.push(1);
    h.push(2);
    h.push(5);

cout << "Heap after insertion: ";
    h.printHeap();

    // Removing the top element
    h.pop();
    cout << "Heap after pop: ";
    h.printHeap();

    // Displaying the top element of the heap
    cout << "Top element: " << h.top() << endl;


    return 0;
}
