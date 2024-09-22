#include <bits/stdc++.h>
using namespace std;

class NQueue {
public:
    int freeSpot; // Tracks first available free index
    int *arr, *next, *front, *rear; // Arrays to manage elements, links, and front/rear pointers
    int size, numQueues; // Total size of the array and number of queues

    // 📝 Algorithm:
    // 1. **Constructor**: Initializes arrays for storing elements, tracking free spots, and managing front/rear pointers. Links free spots.
    // 2. **enqueue**: Adds an element to the specified queue:
    //    - Finds the first free index.
    //    - Updates the front and rear pointers as necessary.
    // 3. **dequeue**: Removes the front element from the specified queue:
    //    - Updates the front pointer and manages free spots.
    
    // Time Complexity:
    // - enqueue: O(1) for adding an element.
    // - dequeue: O(1) for removing an element.
    
    // Space Complexity:
    // - O(n) for the arrays used to manage the queues where n is the total size.

    // Constructor to initialize the structure
    NQueue(int n, int s) {
        size = s; // Total size of array
        numQueues = n; // Number of queues
        arr = new int[size]; // Array to store elements
        next = new int[size]; // Next free spot or next element in queue
        front = new int[numQueues]; // Front of each queue
        rear = new int[numQueues]; // Rear of each queue

        freeSpot = 0; // Initially, the first index is free

        // Initialize front and rear for each queue as -1 (empty)
        for (int i = 0; i < numQueues; i++) {
            front[i] = rear[i] = -1;
        }

        // Link all free spots
        for (int i = 0; i < size - 1; i++) {
            next[i] = i + 1;
        }
        next[size - 1] = -1; // Last index points to -1 (no free spot after this)
    }

    // 🌟 Enqueue operation to add 'X' to the M-th queue
    bool enqueue(int X, int m) {
        // Check for overflow (no free spot available)
        if (freeSpot == -1) {
            return false;
        }

        // Find the first free index
        int index = freeSpot;

        // Update freeSpot to the next available spot
        freeSpot = next[index];

        // If the queue is empty, set front and rear to this index
        if (front[m - 1] == -1) {
            front[m - 1] = index;
        } else {
            // Link the new element to the current rear element
            next[rear[m - 1]] = index;
        }

        // Update rear to the new index
        rear[m - 1] = index;

        // Insert the element into the array
        arr[index] = X;

        // Mark the next of the current rear as -1 (end of queue)
        next[index] = -1;

        return true;
    }

    // ⏳ Dequeue operation to remove the front element from the M-th queue
    int dequeue(int m) {
        // Check for underflow (queue is empty)
        if (front[m - 1] == -1) {
            return -1;
        }

        // Get the index of the front element
        int index = front[m - 1];

        // Update front to the next element in the queue
        front[m - 1] = next[index];

        // If the queue becomes empty, reset rear to -1
        if (front[m - 1] == -1) {
            rear[m - 1] = -1;
        }

        // Add the index back to the free spot list
        next[index] = freeSpot;
        freeSpot = index;

        // Return the dequeued element
        return arr[index];
    }
};

// Sample usage (not part of the NQueue class)
int main() {
    NQueue nQueue(3, 10); // 3 queues, total size of 10

    nQueue.enqueue(1, 1);
    nQueue.enqueue(2, 1);
    nQueue.enqueue(3, 2);
    nQueue.enqueue(4, 3);
    
    cout << "Dequeued from queue 1: " << nQueue.dequeue(1) << endl; // Should output 1
    cout << "Dequeued from queue 2: " << nQueue.dequeue(2) << endl; // Should output 3
    cout << "Dequeued from queue 3: " << nQueue.dequeue(3) << endl; // Should output 4

    return 0;
}

/*
Sample Output:
Dequeued from queue 1: 1
Dequeued from queue 2: 3
Dequeued from queue 3: 4
*/
