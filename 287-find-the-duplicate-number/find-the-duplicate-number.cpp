// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         map<int,int> mpp;

//         for(int i = 0; i < nums.size(); i++){
//             mpp[nums[i]]++;
//         }

//         for(auto it : mpp){
//             if(it.second > 1) return it.first;
//         }

//         return -1; 
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast)
                break;
        }

        slow = 0;

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};