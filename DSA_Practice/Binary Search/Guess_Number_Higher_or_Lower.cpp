/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=0;
        int r=n;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            int api=guess(mid);
            if(api==-1){
                r=mid-1;
            }
            if(api==1){
                l=mid+1;
            }
            if(api==0){
                ans= mid;
                break;
            }
        }
        return ans;
    }
};