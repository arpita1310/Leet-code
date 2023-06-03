class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n  = nums1.size(),m = nums2.size();
        vector<int> ans(n+m);
        int index1 = 0,index2 = 0;
        int ansIndex= 0;
        while(index1<n && index2 < m)
        {
            if(nums1[index1]<nums2[index2])
            {
                ans[ansIndex] = nums1[index1];
                ansIndex++;
                index1++;
            }
            else{
                ans[ansIndex] = nums2[index2];
                ansIndex++;
                index2++;
            }
        }
        while(index1<n)
        {
            ans[ansIndex] = nums1[index1];
            index1++;ansIndex++;
        }
        while(index2<m)
        {
            ans[ansIndex] = nums2[index2];
            index2++;ansIndex++;
        }
        for(int i = 0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        if(ans.size()%2==0)
		{
		        int mid = ans.size()/2;
		        return (double)(ans[mid]+ans[mid-1])/2;
		}
		else{
		        return (double)ans[ans.size()/2];
		}
    }
};