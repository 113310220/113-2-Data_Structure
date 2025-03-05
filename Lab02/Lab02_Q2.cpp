class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();  // 取得陣列大小
        vector<int> result(n);  // 建立一個相同大小的陣列
        
        result[0] = nums[0];  // 建立一個result來累加
        
        
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] + nums[i];  // 當前位置的值 = 前一個位置的累加和 + 當前數值
        }
        
        return result;  // 回傳結果
    }
};

