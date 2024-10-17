/*
    Recursion method to generate all possible permutations of a given array

    n! is the number of permutations of a given array of size n

    Time complexity: n * n! (n is the lenght of the array)
    Space complexity: n * n! (we store every single subset)


*/
#include <bits/stdc++.h>
using namespace std;

// Function to find the possible permutations. 
// Initial value of idx is 0.
void permutations(vector<vector<int>>& res, vector<int> arr, int idx) {
  
    // Base case: if idx reaches the size of the array, 
     // add the permutation to the result
    if (idx == arr.size()) {
        res.push_back(arr);
        return;
    }

    // Permutations made by swapping each element
    // starting from index `idx`
    for (int i = idx; i < arr.size(); i++) {
      
        // Swapping
        swap(arr[idx], arr[i]);

        // Recursive call to create permutations 
        // for the next element
        permutations(res, arr, idx + 1);

        // Backtracking
        swap(arr[idx], arr[i]);
    }
}

// Function to get the permutations
vector<vector<int>> permute(vector<int>& arr) {
  
    // Declaring result variable
    vector<vector<int>> res;

    // Calling permutations with idx starting at 0
    permutations(res, arr, 0);
    return res;
}

// Driver Code
int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6};
    vector<vector<int>> res = permute(arr);

    // Printing result
    for (auto x : res) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
