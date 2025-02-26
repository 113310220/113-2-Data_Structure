void printPairs(const vector<int>& arr) {
count++;//i=0
for (int i = 0; i < arr.size(); i++) {
count++;//i<arr
count++;//j=i
for (int j = i + 1; j < arr.size(); j++) {
count++;//j<arr
cout << arr[i] << "," << arr[j] << endl;
}
}
}
