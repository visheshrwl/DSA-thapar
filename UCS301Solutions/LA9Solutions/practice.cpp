#include<bits/stdc++.h>
using namespace std;

class MaxHeapPriorityQueue{
    private:

    vector<int> heap;
        int parent(int i){return i-1/2;}
        int leftChild(int i){return 2*i+1};
        int rightChild(int i){return 2*i+2};

        void heapifyUp(int i){
            while(i> 0 && heap[parent(i) < heap[i]]){
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        } 

        void heapifyDown(int i){
            int maxIndex = i;
            int l = leftChild(i);
            int r = rightChild(i);

            if(l < heap.size() && heap[i] > heap[maxIndex]){
                maxIndex = l;
            }
            if(r < heap.size() && heap[i] > heap[maxIndex]){
                maxIndex = r;
            }

            if(i!=maxIndex){
                swap(heap[i], heap[maxIndex]);
                heapifyDown(maxIndex);
            }
        }

        public:
            MaxHeapPriorityQueue(){}

            void enqueue(int value){
                heap.push_back(value);
                heapifyUp(heap.size() -1);
            }

            int dequeue(){
                if(heap.empty()){
                    cerr << "Priority queue is empty" << endl;
                    return -1;
                }

                int maxPriority = heap[0];
                heap[0] = heap.back();
                heapifyDown(0);

                return maxPriority;
            }

            bool isEmpty() const{
                return heap.empty();
            }
};

int main(){

}