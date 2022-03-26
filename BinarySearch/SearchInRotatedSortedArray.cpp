class Solution {
public:
    int binSearch(vector<int>& arr,int lo,int hi,int target)
    {
        while(lo<=hi)
        {
            int mid =lo+(hi-lo)/2;
            if(arr[mid]==target)
                return mid;
            else if(arr[mid]<target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return -1;
    }
    int search(vector<int>& arr, int target) {
        int lo=0,hi=arr.size()-1;
        int pivot=-1;
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            // cout<<"lo "<<lo<<endl;
            // cout<<"hi "<<hi<<endl;
            // cout<<"mid "<<mid<<endl;
            // cout<<"arr[mid] "<<arr[mid]<<endl;
            // cout<<"arr[hi] "<<arr[hi]<<endl;
            if(arr[mid]>arr[hi])
                lo=mid+1;
            else
                hi=mid;
            // cout<<"lo "<<lo<<endl;
            // cout<<"hi "<<hi<<endl;
        }
        pivot=lo;
        // cout<<lo;
        if(target>=arr[pivot] && target<=arr[arr.size()-1])
        {
            return binSearch(arr,pivot,arr.size()-1,target);
        }
        else if(target>=arr[0] && pivot-1 >= 0 && target<=arr[pivot-1])
        {
           return binSearch(arr,0,pivot-1,target);
        }
        return -1;
    }
};
