#include <iostream>
using namespace std;

int subset(int input[], int n, int output[][50], int k) {
    if (n == 0) {
        output[0][0] = 0;
        return 1;
    }

    int small = subset(input + 1, n - 1, output, k);
    int count = 0;

    for (int i = 0; i < small; i++) {
        output[small + count][1] = input[0];
        int sum = input[0];
        int l = 0;

        for (int j = 2; output[small - count - 1][j - 1] != 0; j++) {
            l++;
            output[small + count][j] = output[small - count - 1][j - 1];
            sum = sum + output[small - count - 1][j - 1];
        }

        output[small + count][0] = -1;

        if (sum == k) {
            output[small + count][0] = l + 1;
        }

        count++;
    }

    return small + count;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    int temp[1110000][50];
    int size = subset(input, n, temp, k);
    int m = 0;

    for (int i = 0; i < size; i++) {
        if (temp[i][0] > 0) {
            for (int j = 0; j < temp[i][0]; j++) {
                output[m][j] = temp[i][j];
            }
            m++;  // Increment m to update the index in the output array
        }
    }

    return m;
}

int main() {
    int input[] = {1, 2, 3, 4};
    int n = sizeof(input) / sizeof(input[0]);
    int output[1110000][50];

    int result = subsetSumToK(input, n, output, 5);

    // Print the subsets
    for (int i = 0; i < result; i++) {
        cout << "Subset " << i + 1 << ": ";
        for (int j = 1; j <= output[i][0]; j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
