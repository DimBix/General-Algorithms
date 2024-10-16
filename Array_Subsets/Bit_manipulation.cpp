/*
    Bit manipulation method to generate all possible subsets of a given array

    Time complexity: n * 2^n (n is the lenght of the array)
    Space complexity: n (because we print the subsets)
    Space complexity: n * 2^n (if we would store every single subset)


    This code is good to understand the general idea of bit manipulation but not efficient
    n * 2^n is not the best time complexity to generate all subsets. With backtracking we can generate them (and store them) 
    in 2^n time, to print them, however, we need n * 2^n time
*/
#include <iostream>
using namespace std;

// Function to find the subsets of the given array
void findSubsets(int nums[], int n) {
    // Loop through all possible subsets using bit manipulation
    for (int i = 0; i < (1 << n); i++) {

        // Loop through all elements of the input array
        for (int j = 0; j < n; j++) {

            // Check if the jth bit is set in the current subset
            if ((i & (1 << j)) != 0) {

                // If the jth bit is set, add the jth element to the subset
                cout << nums[j] << " ";
            }
        }

        cout << endl;
    }
}

// Driver Code
int main() {

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    findSubsets(arr, n);
}
