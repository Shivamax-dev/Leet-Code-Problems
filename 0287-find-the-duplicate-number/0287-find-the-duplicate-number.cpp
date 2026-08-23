class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;  
        while(fast != nums.size()){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            if(slow == fast){  //for sure cycle to hai hi due duplicate
                slow = 0;     //re-assigning the starting index(head) of the linklist
                while(slow != fast){
                    slow = nums[slow];    //To find starting point as dupicate present at the starting node of the cycle.
                    fast = nums[fast];
                }
                return slow;  //OR return fast;
            }
            
        }
        return false;
    }
};