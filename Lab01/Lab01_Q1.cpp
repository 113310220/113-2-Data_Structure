class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool numsincrease = false;
        bool numsdecrease = false;
        // 假設遞增和遞減狀態為0
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])        // 如果此數大於上一個數
               numsincrease = true;          // 遞增狀態存在
            else if (nums[i] < nums[i - 1])   // 如果此數小於上一個數
                numsdecrease = true;          // 遞減狀態存在
            if (numsincrease && numsdecrease) // 兩種狀態同時存在
            {
                return false; // 判斷false
            }
        }

        return true; // 判斷為true
    }
};

