#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> stk1, stk2; // ✌️ Two stacks used to simulate the queue behavior

    // 🏗️ Constructor
    MyQueue() {
        // The constructor is left empty for now as no specific initialization is needed
    }
    
    // 📥 Push element into the queue
    void push(int x) {
        stk1.push(x); // Simply push onto the first stack
    }
    
    // 📤 Pop the front element from the queue
    int pop() {
        int poppedElement = -1;

        // Check if stk2 has elements (these are the front elements)
        if (!stk2.empty()) {
            poppedElement = stk2.top();
        } else {
            // 🚀 Move elements from stk1 to stk2 to reverse the order
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
            poppedElement = stk2.top();
        }
        stk2.pop(); // Remove the top element (front of the queue)
        return poppedElement;
    }
    
    // 👀 Peek the front element without removing it
    int peek() {
        int peekElement = -1;

        // If stk2 has elements, that's the front of the queue
        if (!stk2.empty()) {
            peekElement = stk2.top();
        } else {
            // Move elements from stk1 to stk2 if stk2 is empty
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
            peekElement = stk2.top(); // Front element
        }
        return peekElement;
    }
    
    // 🤔 Check if the queue is empty
    bool empty() {
        // Queue is empty if both stacks are empty
        return stk1.empty() && stk2.empty();
    }
};

// 🏃‍♂️ Main function for local execution and testing
int main() {
    MyQueue* queue = new MyQueue();
    
    // 👨‍💻 Test case: pushing and popping elements from the queue
    queue->push(10);
    queue->push(20);
    queue->push(30);

    cout << "Pop: " << queue->pop() << endl;  // Expected: 10
    cout << "Peek: " << queue->peek() << endl; // Expected: 20
    cout << "Is Empty: " << (queue->empty() ? "Yes" : "No") << endl; // Expected: No
    
    queue->push(40);
    cout << "Pop: " << queue->pop() << endl;  // Expected: 20
    cout << "Pop: " << queue->pop() << endl;  // Expected: 30
    cout << "Peek: " << queue->peek() << endl; // Expected: 40
    cout << "Pop: " << queue->pop() << endl;  // Expected: 40
    cout << "Is Empty: " << (queue->empty() ? "Yes" : "No") << endl; // Expected: Yes

    delete queue; // Clean up dynamically allocated memory
    return 0;
}

/*
⏳ Time Complexity:
- Push operation: O(1) as we are simply pushing elements onto the first stack.
-Pop operation: Worst case O(n) when all elements need to be moved from `stk1` to `stk2`.
  However, the amortized time complexity is O(1) since each element is only moved once between the two stacks.
- Peek operation: Amortized O(1) for the same reason as the pop.
- Empty operation: O(1) as it's a simple check on both stacks.

💾 Space Complexity:
- O(n), where n is the number of elements in the queue, as both stacks hold the elements.

📊 Example Output:
Pop: 10
Peek: 20
Is Empty: No
Pop: 20
Pop: 30
Peek: 40
Pop: 40
Is Empty: Yes
*/
