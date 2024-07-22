
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

//5. Best Time to Buy and Sell Stocks I

class Solution {
public:
    int maxProfit(vector<int> &arr) {
    int maxProfit=0;
    int mini = arr[0];
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int cost=arr[i]-mini;
            maxProfit = max(maxProfit,cost);
            mini=min(mini,arr[i]);
            }
    return maxProfit;
    }
};

//6. Best Time to Buy and Sell Stocks II

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int ans = 0,n=prices.size();
        for(int i = 1; i < n; i++){
            if(prices[i]>prices[i-1])
                ans += prices[i]-prices[i-1];
        }
        return ans;
    }
};

//7. Move Zeroes

class Solution {
public:
   vector<int> moveZeroes(vector<int>& nums) {
         int j=-1;
         
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
       
           if(j == -1) 
             return nums;
       

        for(int i=j+1;i<nums.size();i++){
        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
    }
    return nums;
}
};

//8. Reverse Pairs

class Solution {
public:
    int c = 0;
    int revPairs(vector<int> &a, vector<int> &b){
        int count = 0;
        int i=0; // a
        int j=0; // b
        while(i<a.size() && j<b.size()){
            long long int bruh = b[j];
            if(a[i]>2*bruh){
                count += a.size()-i;
                j++;
            }
            else{ // a[i]<=b[j];
                i++;
            }
        }
        return count;
    }
    void merge(vector<int> &a, vector<int> &b, vector<int> &res){
        int i=0, j=0, k=0;
        while(i<a.size()&&j<b.size()){
            if(a[i]<=b[j]) res[k++] = a[i++];
            else res[k++] = b[j++];
        }
        if(i==a.size()) while(j<b.size()) res[k++] = b[j++];
        else if(j==b.size()) while(i<a.size()) res[k++] = a[i++];
    }
    void mergeSort(vector<int> &v){
        int n = v.size();
        if(n==1) return;
        int n1 = n/2, n2 = n - n/2;
        vector<int> a(n1), b(n2);
        // copy paste
        for(int i=0; i<n1; i++) a[i] = v[i];
        for(int i=0; i<n2; i++) b[i] = v[i+n1];
        // magic
        mergeSort(a);
        mergeSort(b);
        // count reverse pairs
        c += revPairs(a,b);
        // merge
        merge(a,b,v);
        a.clear(); b.clear();
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums);
        return c;
    }
};