#include<iostream>
using namespace std;

//Insertion-  heapification 
class Heap{
  public:
    int *arr;
    int capacity;
    int size;

    Heap(int capacity) {
      this->arr = new int[capacity];
      this->capacity = capacity;
      this->size = 0;
    }

    void insert(int val) {
      if(size == capacity) {
        cout << "Oops! Heap overflow" <<  endl;
        return;
      }
      // size increases when new node add
      size++;
      int index = size;
      arr[index] = val;

      // place that value to correct position

      while(index > 1) {
        int parentIndex = index / 2;
        if(arr[index] > arr[parentIndex]) {
          swap(arr[index], arr[parentIndex]);
          index = parentIndex;
        } else {
          break;
        }
      }

    }
    
    void printHeap() {
      for(int i=1; i<=size; i++) {
        cout << arr[i] << " ";
      }
    }

    //Deletion
    int deleteHeap() {
      int answer = arr[1];
      //Replacement of leaf last node to root node
      arr[1] = arr[size];
      size--;

      int index = 1;
      //heapification
      while(index < size) {
        int leftIndex = 2*index;
        int rightIndex = 2*index;

        //find out largest index
        int largestIndex = index;
        //check left child
        if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]) {
          largestIndex = leftIndex;
        }

        //check in right child
        if(rightIndex <= size && arr[largestIndex] < arr[rightIndex]) {
          largestIndex = rightIndex;
        }

        //No changes
        if(index == largestIndex) {
          break;
        } else {
          swap(arr[index], arr[largestIndex]);
          index = largestIndex;
        }
      }
      return answer;
    }
};





int main() {
  
  Heap h(20);
  h.insert(10);
  h.insert(20);
  h.insert(5);
  h.insert(11);
  h.insert(6);

  cout << "Printing Heap content: ";
  h.printHeap(); // Printing Heap content: 20 11 5 10 6 
  
  cout <<  endl;
  int ans = h.deleteHeap();
  cout << "Deleted node is: " << ans; // Deleted node is: 20
  cout << endl;
  cout << "Printing Heap content: ";
  h.printHeap(); // Printing Heap content: 11 10 5 6

  return 0;
}