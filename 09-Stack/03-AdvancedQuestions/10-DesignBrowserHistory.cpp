#include <iostream>
#include <stack>
#include <string>
using namespace std;

class BrowserHistory {
    // 🛠️ Two stacks to handle browsing history: 
    // 1. `browserStack` for backward history
    // 2. `fwdStack` for forward history.
    stack<string> browserStack, fwdStack;

public:
    /*
    📝 Algorithm:
    1. **visit**: When visiting a new URL, clear the `fwdStack` (since forward navigation is invalid after a new visit) and push the new URL onto `browserStack`.
    2. **back**: Move back up to `steps` times in the browsing history by popping from `browserStack` and pushing onto `fwdStack`. Stop when there's only one page left (i.e., homepage).
    3. **forward**: Move forward up to `steps` times by popping from `fwdStack` and pushing back onto `browserStack`.
    
    Time Complexity:
    - visit: O(n) in the worst case when clearing `fwdStack`.
    - back/forward: O(min(n, steps)) where `n` is the number of steps available in history or forward stack.

    Space Complexity:
    - O(n) for both `browserStack` and `fwdStack`, where `n` is the number of URLs stored.
    */

    BrowserHistory(string homepage) {
        // Push the homepage onto the backward stack
        browserStack.push(homepage);
    }

    // 🌐 Visit a new URL and clear forward history
    void visit(string url) {
        while (!fwdStack.empty()) {
            fwdStack.pop(); // Clear forward history on visiting new URL
        }
        browserStack.push(url); // Push new URL onto backward stack
    }

    // ⏪ Go back 'steps' in history
    string back(int steps) {
        while (steps--) {
            if (browserStack.size() > 1) { // Don't pop the homepage
                fwdStack.push(browserStack.top()); // Push the current page onto the forward stack
                browserStack.pop(); // Remove the current page from backward stack
            } else {
                break; // Stop if we can't go back any further
            }
        }
        return browserStack.top(); // Return the page at the top of the backward stack
    }

    // ⏩ Go forward 'steps' in history
    string forward(int steps) {
        while (steps--) {
            if (!fwdStack.empty()) {
                browserStack.push(fwdStack.top()); // Move from forward stack to backward stack
                fwdStack.pop();
            } else {
                break; // Stop if no more forward history
            }
        }
        return browserStack.top(); // Return the current page
    }
};

// Sample usage (not part of the Solution class)
int main() {
    BrowserHistory browser("homepage.com");

    browser.visit("page1.com");
    browser.visit("page2.com");
    cout << "Current page after visiting page2: " << browser.back(1) << endl;
    cout << "Current page after going back: " << browser.back(1) << endl;
    cout << "Current page after going forward: " << browser.forward(1) << endl;

    browser.visit("page3.com");
    cout << "Current page after visiting page3: " << browser.back(2) << endl;

    return 0;
}

/*
Sample Output:
Current page after visiting page2: page1.com
Current page after going back: homepage.com
Current page after going forward: page1.com
Current page after visiting page3: homepage.com
*/
