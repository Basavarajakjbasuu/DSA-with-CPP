#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> qu;

    MyStack() {
        // 🚀 Constructor: Initializes an empty stack
    }

    // 🌟 Push element x onto the stack
    void push(int x) {
        qu.push(x); // 🌱 Add the element to the queue

        // 🔄 Rotate the queue to simulate stack behavior
        for (int i = 0; i < qu.size() - 1; ++i) {
            int front = qu.front();
            qu.pop();
            qu.push(front); // 🔄 Move the front element to the back
        }
    }

    // 🚮 Removes the element on top of the stack and returns it
    int pop() {
        int top = qu.front(); // 🚀 The top element (queue front) is stored
        qu.pop(); // 🔥 Remove the top element
        return top;
    }

    // 🧐 Get the top element of the stack
    int top() {
        return qu.front(); // 🏔️ The top element is at the front of the queue
    }

    // 🕳️ Check if the stack is empty
    bool empty() {
        return qu.empty(); // ❓ Returns true if the queue is empty
    }
};

// 🚀 Main function for local execution
int main() {
    MyStack* obj = new MyStack();

    // 🧪 Test cases
    obj->push(10);  // 🌟 Push 10
    obj->push(20);  // 🌟 Push 20
    cout << "Top element: " << obj->top() << endl;  // 🧐 Get top element -> should be 20
    cout << "Pop element: " << obj->pop() << endl;  // 🚮 Pop top element -> should return 20
    cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl;  // 🕳️ Check if stack is empty -> should be No

    delete obj;  // 💥 Free memory
    return 0;
}

/*
⏳ Time Complexity:
- `push`: O(n) because for each element, the queue is rotated n times.
- `pop`: O(1) because removing the front element is constant time.
- `top`: O(1) because fetching the front element is constant time.
- `empty`: O(1) since it only checks if the queue is empty.

💾 Space Complexity:
- O(n), where n is the number of elements in the stack (held in the queue).

📊 Example Output:
Top element: 20
Pop element: 20
Is stack empty? No
*/
