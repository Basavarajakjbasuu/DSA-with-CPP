#include <iostream>
#include <queue>
using namespace std;

class RecentCounter {
public:
    queue<int> q; // 🛤️ Queue to store the pings

    RecentCounter() {
        // 🚀 Constructor: Initializes an empty counter
    }
    
    // ⏲️ Record a new ping at time 't' and return the number of pings in the last 3000 ms
    int ping(int t) {
        q.push(t); // 🌟 Add the current ping time to the queue

        // 🧹 Remove pings that occurred before (t - 3000) ms
        while (!q.empty() && q.front() < (t - 3000)) {
            q.pop();
        }

        // 📊 Return the size of the queue, which gives the number of recent pings
        return q.size();
    }
};

// 🚀 Main function for local execution
int main() {
    RecentCounter* obj = new RecentCounter();
    
    // 🧪 Test case
    cout << "Ping at 1: " << obj->ping(1) << endl;     // 📥 Should return 1
    cout << "Ping at 100: " << obj->ping(100) << endl; // 📥 Should return 2
    cout << "Ping at 3001: " << obj->ping(3001) << endl; // 📥 Should return 3
    cout << "Ping at 3002: " << obj->ping(3002) << endl; // 📥 Should return 3

    delete obj; // 💥 Free memory
    return 0;
}

/*
⏳ Time Complexity:
- `ping`: O(n), where n is the number of elements in the queue. The while loop removes pings outside the 3000 ms range, and each element is processed at most once.

💾 Space Complexity:
- O(n), where n is the number of pings in the last 3000 ms. Each ping is stored in the queue until it becomes older than 3000 ms.

📊 Example Output:
Ping at 1: 1
Ping at 100: 2
Ping at 3001: 3
Ping at 3002: 3
*/
