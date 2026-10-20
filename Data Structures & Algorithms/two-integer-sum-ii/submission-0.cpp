class Solution {
public:
    /*
        Potential solutions (for two sum)
        1. Brute force can be to go through each iteration and compare O(n^2) 
        2. You can convert the array into array of pairs ,sort the pair array and make it into two pointer problem. O(nlogn),O(1) (This question that is two integere sum II follows this approach without the conversion part)
        3. You can make a hashmap and do a two pass on that know if the diff exist (O(n),O(n))
        4. You can find the diff instead to exist in the hashmap and if the number doesn't exit add the number in the hashmap.(O(n),O(1))
    
    */
    vector<int> twoSum(vector<int>& numbers, int target) {
       int i=0;
       int n=numbers.size();
       int j=n-1;
       while(i<j){
         int sum=numbers[i]+numbers[j];
         if(sum<target){
            i++;
         }
         else if(sum>target){
            j--;
         }
         else if(sum==target){
            return{i+1,j+1};
         }
         else{i++,j--;}

       }
       return {};

    }
};