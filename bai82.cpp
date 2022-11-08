#include <iostream>
#include <set>
#include <vector>
#include <experimental/iterator>
using namespace std;
 
// Function to print all distinct combinations of length `k`
void findCombinations(vector<int> const &arr, int i, int k,
                set<vector<int>> &subarrays, vector<int> &out)
{
    // do nothing for empty input
    if (arr.size() == 0) {
        return;
    }
 
    // base case: combination size is `k`
    if (k == 0) {
        subarrays.insert(out);
        return;
    }
 
    // return if no more elements are left
    if (i == arr.size()) {
        return;
    }
 
    // include the current element in the current combination and recur
    out.push_back(arr[i]);
    findCombinations(arr, i + 1, k - 1, subarrays, out);
 
    // exclude the current element from the current combination
    out.pop_back();        // backtrack
 
    // exclude the current element from the current combination and recur
    findCombinations(arr, i + 1, k, subarrays, out);
}
 
template <typename T>
void printVector(vector<T> const &input)
{
    cout << "[";
    copy(begin(input),
            end(input),
            experimental::make_ostream_joiner(cout, ", "));
    cout << "]\n";
}
 
int main()
{
    vector<int> arr = { 1, 2, 3 };
    int k = 2;
 
    // set to store all combinations
    set<vector<int>> subarrays;
 
    // vector to store a combination
    vector<int> out;
 
    // process elements from left to right
    findCombinations(arr, 0, k, subarrays, out);
 
    // print subarrays
    for (auto const &vec: subarrays) {
        printVector(vec);
    }
 
    return 0;
}