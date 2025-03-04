class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[501]={0};//設立一個計算的矩陣
       // 計算每個數字出現的次數
        for (int num : arr) {
            freq[num]++;
        }
        
        // 反向檢查從最大可能的數字到 1
        for (int i = 500; i >= 1; --i) {
            if (freq[i] == i) {
                return i;  // 找到並返回符合條件的最大 "幸運數字"
            }
        }
        
        return -1;  // 沒有找到幸運數字，返回 -1
    }
};
