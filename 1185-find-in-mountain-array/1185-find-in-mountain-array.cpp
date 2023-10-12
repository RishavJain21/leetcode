/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int t, MountainArray &ma) {
        int n=ma.length();
        int l=1,h=n-2;
        int peak=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int a=ma.get(mid),b=ma.get(mid+1),c=ma.get(mid-1);
            if(a>b && a>c){
                peak=mid;
                break;
            }else if(a>b){
                h=mid-1;
            }else l=mid+1;
        }
        
        l=0;h=peak;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int a=ma.get(mid);
            if(a==t) {
                ans=mid;
                h=mid-1;
            }
            else if(a>t) h=mid-1;
            else l=mid+1;
        }
        if(ans!=-1) return ans;
        l=peak+1;h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int a=ma.get(mid);
            if(a==t){
                ans=mid;
                h=mid-1;
            }else if(a>t)l=mid+1;
            else h=mid-1;
        }
        return ans;
    }
};