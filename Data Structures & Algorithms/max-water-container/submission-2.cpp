
class Solution {
public:
    int maxArea(vector<int>& heights) {
        /*
        Reframing the question in my words: 
        1. I am given a list of heights where each element in the list represents that positioned bar's height 
        2. Two bars can be picked to form a container 
        3. We have to return the maximum amount of water in between two bars , the width of the container formed by two bars can be calculated by subtracting the indexes at which the bars are located at.

        ## Solutions 
        ### Brute force compare each height and capacity and find max of the capacity

        for i to n:
            tempMax
            for j to n:    O(N) for each i so O(N^2)
                w=j-i
                h=min(height[i],height[j])
                tempMax=max(tempMax,h*w) // O(N)
            maxi=max(tempMax,maxi) // O(N)
        return maxi
        T(N) : O(n^2)
        S(N) : O(1)
        
        ### Two pointer solution (We using two pointers because here we are comparing in two directions and two pairs of things which also changes by indices as well)

        i=0,j=n-1
        while i<j:
            hc= min(heights[i],heights[j])
            wc= j-i
            area = hc * wc 
            if hc==heights[i]:
                i++;
            elif hc ==heights[j]:
                j--;
            else: 
                maxi=max(maxi,area)
                
            
        */
        int n=heights.size();
        int i=0,j=n-1;
        int maxi=INT_MIN;
        while(i<j){
            int hc= min(heights[i],heights[j]);
            int wc= j-i;
            int area = hc*wc;
            if (hc==heights[i]){
                i++;
            }
            else if(hc==heights[j]){
                j--;
            }
            maxi=max(maxi,area);

        }
        return maxi;
    }
};
