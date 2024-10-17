/*
    Using the function of the standard library we can generate all possible permutations of a given array

    n! is the number of permutations of a given array of size n

    next_permutation works in O(n)

    Time complexity: n * n! (n is the lenght of the array)
    Space complexity: n (because we print them)
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Function to find the possible permutations.
int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6};
    vector<int> permutation;

    for(int i= 0; i < arr.size(); i++){
        permutation.push_back(i);
    }

    do{
        for(int i = 0; i < permutation.size(); i++){
            cout << arr[permutation[i]] << " ";
        }
        cout << endl;
    }while(next_permutation(permutation.begin(), permutation.end()));

}
