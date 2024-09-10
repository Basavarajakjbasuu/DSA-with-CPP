#include <iostream>
#include <stack>
#include <utility>

class StockSpanner {
public:
    // Stack to store pairs of (price, span).
    std::stack<std::pair<int, int>> st;

    // Constructor to initialize the StockSpanner object.
    StockSpanner() {
        // The constructor is empty as no initialization is required.
    }
    
    // Function to calculate the stock span for the given price.
    int next(int price) {
        int span = 1;  // Initialize the span to 1 for the current day.

        // Pop elements from the stack while the top price is less than or equal to the current price.
        // Accumulate the span of each popped element.
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Add the span of the top element.
            st.pop(); // Remove the top element from the stack.
        }

        // Push the current price and its span onto the stack.
        st.push({price, span});
        
        // Return the calculated span for the current price.
        return span;
    }
};

// Example usage of the StockSpanner class.
int main() {
    // Create a StockSpanner object.
    StockSpanner* spanner = new StockSpanner();
    
    // Test the StockSpanner with some example prices.
    std::cout << "Span for price 100: " << spanner->next(100) << std::endl; // Output: 1
    std::cout << "Span for price 80: " << spanner->next(80) << std::endl;   // Output: 1
    std::cout << "Span for price 60: " << spanner->next(60) << std::endl;   // Output: 1
    std::cout << "Span for price 70: " << spanner->next(70) << std::endl;   // Output: 2
    std::cout << "Span for price 60: " << spanner->next(60) << std::endl;   // Output: 1
    std::cout << "Span for price 75: " << spanner->next(75) << std::endl;   // Output: 4
    std::cout << "Span for price 85: " << spanner->next(85) << std::endl;   // Output: 6

    // Clean up the dynamically allocated StockSpanner object.
    delete spanner;

    return 0;
}

/*
  Span for price 100: 1
  Span for price 80: 1
  Span for price 60: 1
  Span for price 70: 2
  Span for price 60: 1
  Span for price 75: 4
  Span for price 85: 6
*/