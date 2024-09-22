#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // For sorting

using namespace std;

// 🚗 Class to represent a car with position and speed
class Car {
public:
    int pos, speed;
    Car(int p, int s): pos(p), speed(s) {}; // 🛠️ Constructor for Car class
};

// ⚖️ Custom comparator to sort cars based on their position
bool myComp(Car &a, Car &b){
    return a.pos < b.pos; // 🏎️ Sort cars based on position
}

/*
* 🧠 Algorithm Explanation:
* 1. We create a vector of Car objects with position and speed.
* 2. Sort the cars based on their positions in ascending order.
* 3. For each car, calculate the time it will take to reach the target.
* 4. Use a stack to maintain the distinct fleets. If a car catches up to a fleet, it joins that fleet.
* 5. The number of fleets is the size of the stack at the end.
*/

// 🏁 Function to calculate the number of car fleets reaching the target
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<Car> cars;

    // 🚗 Initialize car objects and store them in the cars vector
    for (int i = 0; i < position.size(); ++i) {
        Car car(position[i], speed[i]); // 🔄 Create a car with its position and speed
        cars.push_back(car); // ➕ Add car to vector
    }

    // 📊 Sort cars by position in ascending order
    sort(cars.begin(), cars.end(), myComp);

    // 🚧 Stack to store the time required for each car to reach the target
    stack<float> st;

    // ⏱️ Loop through the sorted cars to calculate their time to target
    for (auto car : cars) {
        float time = (target - car.pos) / ((float) car.speed); // ⏳ Time to target
        // 🔁 Remove cars from the stack if the current car catches up to them
        while (!st.empty() && time >= st.top()) {
            st.pop(); // 🚗💨 Remove cars that will be part of the same fleet
        }
        st.push(time); // 🆕 Add the current car's time to the stack
    }

    return st.size(); // 🎯 The number of fleets is the size of the stack
}

// 🎯 Main function for local execution
int main() {
    vector<int> position = {10, 8, 0, 5, 3}; // 🛣️ Positions of cars
    vector<int> speed = {2, 4, 1, 1, 3};    // 🚗 Speeds of cars
    int target = 12;                         // 🎯 Target distance

    int fleets = carFleet(target, position, speed);
    cout << "Number of car fleets: " << fleets << endl;

    return 0;
}

/**

 *
 * 📈 Time Complexity:
 * - Sorting the cars takes O(n log n), where n is the number of cars.
 * - The loop to calculate fleet size runs in O(n), making the overall time complexity O(n log n).
 *
 * 🧠 Space Complexity:
 * - We use O(n) space for the car objects and O(n) space for the stack, so the space complexity is O(n).
 */

