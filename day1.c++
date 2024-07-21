
// 1. Find the Duplicate Number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        for(int i=0;i<=n;i++){
            int k=nums[i];
            nums[k%(n+2)]+=(n+2);
        }
        int ans=-1;
        for(int i=0;i<=n;i++){
            if(nums[i]/(n+2)>=2){
                ans=i;
                break;
            }
        }
        return ans;
    }
};

// 2. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};

// 3. Two Sum

class Solution {
public:
   vector<int> twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}

};

//4. Majority Element

class Solution {
public:
    int majorityElement(vector<int> v) {

        // size of the given array:
        int n = v.size();
        int cnt = 0; // count
        int el;      // Element

        // applying the algorithm:
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = v[i];
            } else if (el == v[i])
                cnt++;
            else
                cnt--;
        }

        // checking if the stored element
        //  is the majority element:
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == el)
                cnt1++;
        }

        if (cnt1 > (n / 2))
            return el;
        return -1;
    }
};