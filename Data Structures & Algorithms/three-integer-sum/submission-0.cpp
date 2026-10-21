class Solution {
   public:
/*
    Brute force form triplets through three loops

    Flaws in this approach:
    1. 3 loops and sorting contributes to an overall T(N) of O(nlogn) + O(N^3) = O(N^3)
    2. we have to use set for this approach which increase the space complexity from O(N) to O(2n)
    
    How can we improve this approach
    
    ## Hashset/Hashmap (This solution although optimal struggles in the longer inputs)
    1. First we should think from the previous solutions i.e 2sum and 2sum2 
    2. In two sum we summed two numbers and wished it would be equal to the target 
    so we can recreate this problem to be a variation of 2sum by fixing one number out of the 3 and then setting the negative of that number to be the target then the question should be same as two sum except there is one twist how to fix the target ??
    3. Why did sorting helped in 2sum ?
        Because to apply two pointers the sorting will lead to a pattern from which inc/dec sum is easier. 
       Why did the hashmap helped? 
        Because storing the number will cost us less in a hashmap then normally 
        we checked the diff instead of number first because we wanted to check the number first. 
        if the target is fixed then we should check the diff = target - first number to be present in the hashmap and if diff is present then we should push all the three the first number , target - first number i.e the second number and the target in the set  
    4. Some edge cases we dealt with are : 
        i.) if the number of elements in array are less than 3 then it should return {}
        ii.) the duplicates for the first element can be reduced by comparing the current with previous and continuing 
    5. This approach is still hefty and time taking as we still sort each time and give it to a set to remove the duplicates which does it through red-black-tree insertion each time.. 

    ## Sorting + 2 pointer approach (The second approach we could use in 2 sum problem or 2sum2)
    1. We will sort the array first to make sum easy to increase/decrease by moving left/right pointers
    2. the left pointer movement increases the sum while the right one decreases it.
    3. we have to take care of the de-duplication part here as well without any set ofcourse other wise that same problem will happen.
    4. So to avoid deduplication :
    1. we will compare if each window from left and right when the sum == target that the nums[direction] != num[dirction-1] 
    */


    // Hashset (semi-optimised solution)
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> clean;
        int n = nums.size();

        // Edge cases
        if (n < 3) return {};

        for (int i = 0; i < n; i++) {
            int target = -nums[i];
            unordered_set<int> st;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {  // costs O(n-1) per O(N) so the overall complexity
                                               // for the loops would be O(n*(n-1)) i.e ~ O(N^2)
                int first = nums[j];
                int secondOrDiff = target - first;
                if (st.contains(secondOrDiff)) {
                    // contains cost is O(log n i.e less than O(Nlogn))
                    // These two following operations are very cost heavy for larger inputs if we
                    // didn't remove the duplicate iterations which we did when going for the outer
                    // loop duplicates
                    vector<int> temp({first, secondOrDiff, -target});
                    sort(temp.begin(), temp.end());  //(O(nlogn))

                    clean.insert(temp);  // The set itself as well sorts the vectors so that
                }
                st.insert(first);
            }
        }
        return vector<vector<int>>(clean.begin(), clean.end());
    }
};