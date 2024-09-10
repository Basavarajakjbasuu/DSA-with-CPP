#include <iostream>

class NStack
{
public:
    // Constructor to initialize the data structure.
    NStack(int numStacks, int size)
    {
        // Initialize the number of stacks and size of the array.
        numOfStacks = numStacks;
        arraySize = size;
        
        // Allocate memory for the main storage array, top index array, and next free index array.
        storage = new int[arraySize];
        stackTop = new int[numOfStacks];
        nextFree = new int[arraySize];
        
        // Initialize top of each stack as -1 indicating that the stacks are empty.
        for (int i = 0; i < numOfStacks; ++i) {
            stackTop[i] = -1;
        }
        
        // Initialize the next free spots array.
        for (int i = 0; i < arraySize - 1; ++i) {
            nextFree[i] = i + 1; // Each element points to the next free index.
        }
        nextFree[arraySize - 1] = -1; // The last element points to -1 indicating no more free spots.
        
        // Set the first free spot to 0.
        freeSpot = 0;
    }

    // Pushes 'value' into the specified stack (1-based index). Returns true if successful, false otherwise.
    bool push(int value, int stackNumber)
    {
        // Check if there is a free spot available.
        if (freeSpot == -1) 
            return false;

        // Get the index to insert the new element.
        int insertIndex = freeSpot;
        
        // Update the freeSpot to the next available free index.
        freeSpot = nextFree[insertIndex];
        
        // Place the value into the storage array.
        storage[insertIndex] = value;

        // Update the nextFree array to point to the previous top index of the stack.
        nextFree[insertIndex] = stackTop[stackNumber - 1];
        
        // Update the top of the stack to the new index.
        stackTop[stackNumber - 1] = insertIndex;
        return true;
    }

    // Pops the top element from the specified stack (1-based index). Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int stackNumber)
    {
        // Check if the stack is empty.
        if (stackTop[stackNumber - 1] == -1) 
            return -1;

        // Get the index of the top element of the stack.
        int topIndex = stackTop[stackNumber - 1];
        
        // Update the top of the stack to the previous index.
        stackTop[stackNumber - 1] = nextFree[topIndex];
        
        // Retrieve the popped element.
        int poppedElement = storage[topIndex];
        
        // Update the nextFree array to include the freed index.
        nextFree[topIndex] = freeSpot;
        
        // Update the freeSpot to the freed index.
        freeSpot = topIndex;
        return poppedElement;
    }

    // Destructor to clean up allocated memory.
    ~NStack() {
        delete[] storage;
        delete[] stackTop;
        delete[] nextFree;
    }

private:
    int *storage;      // Array to store the actual elements.
    int *stackTop;     // Array to track the top index of each stack.
    int *nextFree;     // Array to track the next free spot in the storage array.
    int freeSpot;      // Index of the current free spot in the storage array.
    int numOfStacks;   // Total number of stacks.
    int arraySize;     // Size of the storage array.
};

// Example usage of the NStack class.
int main() {
    // Create 3 stacks in a single array of size 10.
    NStack stacks(3, 10);
    
    // Push elements into different stacks.
    stacks.push(10, 1);
    stacks.push(20, 2);
    stacks.push(30, 3);
    stacks.push(40, 1);
    
    // Pop elements from different stacks.
    std::cout << "Popped from stack 1: " << stacks.pop(1) << std::endl; // Should print 40
    std::cout << "Popped from stack 2: " << stacks.pop(2) << std::endl; // Should print 20
    std::cout << "Popped from stack 3: " << stacks.pop(3) << std::endl; // Should print 30
    std::cout << "Popped from stack 1: " << stacks.pop(1) << std::endl; // Should print 10
    std::cout << "Popped from stack 1: " << stacks.pop(1) << std::endl; // Should print -1 (empty stack)

    return 0;
}

/*
  Popped from stack 1: 40
  Popped from stack 2: 20
  Popped from stack 3: 30
  Popped from stack 1: 10
  Popped from stack 1: -1
*/
