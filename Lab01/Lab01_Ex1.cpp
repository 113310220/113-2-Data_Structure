int findMax(const vector<int>& arr) {
int max = arr[0];//count=2,Array Access arr[0] + max = arr[0]
for (int i = 1; i < arr.size(); i++) {//count=2
if (arr[i] > max) { //count=2
max = arr[i]; //count=2
}
return max;//count=1
}
//// Total operations:
// 3 (initial) + n * 6 (loop operations) + 1 (return)
// = 4 + 6n operations
// Therefore, O(n) complexity

