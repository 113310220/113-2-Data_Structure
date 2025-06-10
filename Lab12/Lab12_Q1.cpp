class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;         
    int j = n - 1;         
    int k = m + n - 1;   

    
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) //矩陣一某數大於矩陣二某數
        {
            nums1[k--] = nums1[i--]; //位置向右
        } else {
            nums1[k--] = nums2[j--]; //位置向右
        }
    }

    
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
    }
};
