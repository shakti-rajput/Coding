int uniqueElement(vector<int> arr, int n)
{
    int lo=0;
    int hi=n-1;
    int mid;
    while(lo<hi)
    {
        mid = lo+(hi-lo)/2;
        mid=mid&1?mid-1:mid;
        if(arr[mid]==arr[mid+1]&&mid!=n-1)
        {
            lo=mid+2;
        }
        else
        {
            hi=mid;
        }
    }
    return arr[lo];
}
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for(inti=0;i<n;i++)
	{

	}
	cout<<uniqueElement(n);
	return 0;
}
