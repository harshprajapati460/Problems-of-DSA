#include<bits/stdc++.h>
using namespace std;

int maximumSumSubarray(vector<int>&arr,int k){
    int n = arr.size();
    int i=0,j=0,ans=0,sum=0;
    while(j < n){
        sum += arr[j];
        if(j-i+1 < k) j++;
        else if(j-i+1 > k){
            while(j-i+1 > k){
                sum -= arr[i];
                i++;
            }
            ans = max(ans,sum);
            j++;
        }
        else {
            ans = max(ans,sum);
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int>arr = {2,1,4,5,6,3,2};
    int k = 4;
    cout<<maximumSumSubarray(arr,k)<<endl;
    return 0;
}