#include <iostream>
#include <vector>

using namespace std;

class MaxHeapPriorityQueue {
private:
    vector<int> heap;

    // Helper functions
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l < heap.size() && heap[l] > heap[maxIndex])
            maxIndex = l;

        if (r < heap.size() && heap[r] > heap[maxIndex])
            maxIndex = r;

        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:
    // Constructor
    MaxHeapPriorityQueue() {}

    // Insert a new element with priority
    void enqueue(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Extract the element with the highest priority
    int dequeue() {
        if (heap.empty()) {
            cerr << "Priority queue is empty." << endl;
            return -1; // or some sentinel value
        }

        int maxPriority = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxPriority;
    }

    // Check if the priority queue is empty
    bool isEmpty() const {
        return heap.empty();
    }
};

int main() {
    MaxHeapPriorityQueue priorityQueue;

    priorityQueue.enqueue(10);
    priorityQueue.enqueue(30);
    priorityQueue.enqueue(20);

    cout << "Dequeued: " << priorityQueue.dequeue() << endl;

    priorityQueue.enqueue(5);
    priorityQueue.enqueue(15);

    cout << "Dequeued: " << priorityQueue.dequeue() << endl;

    while (!priorityQueue.isEmpty()) {
        cout << "Dequeued: " << priorityQueue.dequeue() << endl;
    }

    return 0;
}
