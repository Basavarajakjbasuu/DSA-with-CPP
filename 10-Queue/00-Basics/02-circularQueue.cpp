#include<iostream> 
using namespace std; 

class CQueue { 
  public: 
    int *arr; // Dynamic array to store elements in the queue
    int size; // Size of the queue
    int front; // Points to the front of the queue
    int rear;  // Points to the rear of the queue

    // Constructor to initialize the queue with a given size
    CQueue(int size) { 
      arr = new int[size]; // Allocate memory for the queue
      this->size = size;   // Store the size of the queue
      front = -1; // Initialize front to -1, meaning the queue is empty
      rear = -1;  // Initialize rear to -1, meaning the queue is empty
    }

    // Function to add an element to the circular queue
    void push(int val) { 
      // Overflow condition: If the queue is full (circular nature)
      if((front == 0 && rear == size - 1) || (rear == front - 1)) { 
        cout << "Oops! Overflow." << endl;
      }
      // Empty queue case: Adding the first element
      else if(front == -1 && rear == -1) { 
        front++; // Move front to the first position
        rear++;  // Move rear to the first position
        arr[rear] = val; // Insert the value at rear
      }
      // Circular condition: Rear reaches the end of the queue, but front is not at 0
      else if(rear == size-1 && front != 0) { 
        rear = 0; // Wrap rear to the beginning of the queue (circular behavior)
        arr[rear] = val; // Insert the value at rear
      }
      // Normal case: Just increment rear and insert the value
      else { 
        rear++; // Move rear to the next position
        arr[rear] = val; // Insert the value at rear
      } 
    }

    // Function to remove an element from the circular queue
    void pop() { 
      // Underflow condition: If the queue is empty
      if(front == -1 && rear == -1) { 
        cout << "Oops! underflow." << endl; 
      }
      // Single element case: After removing the last element, reset the queue
      else if(front == rear) { 
        arr[front] = -1; // Mark the element as removed
        front = -1; // Reset front
        rear = -1;  // Reset rear
      }
      // Circular condition: Front reaches the end of the queue
      else if(front == size - 1) { 
        arr[front] = -1; // Mark the element as removed
        front = 0; // Wrap front to the beginning (circular behavior)
      }
      // Normal case: Just increment front to remove the element
      else { 
        arr[front] = -1; // Mark the element as removed
        front++; // Move front to the next position
      }
    }

    // Function to print the current state of the queue
    void print() { 
      cout << "Printing Queue: "; 
      for (int i = 0; i < size; i++) { 
        cout << arr[i] << " "; // Print all elements in the queue (including empty slots)
      } 
      cout << endl; 
    }
};  

int main() { 
  // Initialize a circular queue with a size of 5
  CQueue cq(5); 

  // Push some elements into the queue
  cq.push(20); 
  cq.push(40); 
  cq.push(60); 
  cq.push(80); 
  cq.push(100); 
  // cq.push(200); Oops! Overflow. (Uncomment this line to check overflow)
  cq.print(); // Printing Queue: 20 40 60 80 100 

  // Remove some elements from the queue
  cq.pop(); 
  cq.pop(); 
  cq.pop(); 
  cq.print(); // Printing Queue: -1 -1 -1 80 100 

  // Push more elements after popping
  cq.push(445); 
  cq.push(345); 
  cq.push(225); 
  // cq.push(125); //Oops! Overflow. (Uncomment this line to check overflow)
  cq.print(); // Printing Queue: 445 345 225 80 100 

  return 0; 
}
