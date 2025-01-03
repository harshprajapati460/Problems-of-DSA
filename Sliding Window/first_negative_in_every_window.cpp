#include<bits/stdc++.h>
using namespace std;

vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        queue<int>q;
        int i=0,j=0;
        vector<int>ans;
        while(j < n){
            if(arr[j] < 0) q.push(arr[j]);
            
            if(j-i+1 == k){
                if(q.size() == 0) ans.push_back(0);
                else {
                    ans.push_back(q.front());
                    if(arr[i] == q.front()) q.pop();
                    
                }
                i++;
                j++;
            }
            else if(j-i+1 < k) j++;
            else {
                while(j-i+1 > k){
                    if(arr[i] == q.front()) q.pop();
                    i++;
                } 
                j++;
            }
            
        }
        return ans;
    }

    int main(){
    vector<int>arr = {-2,1,-4,5,-6,3,2};
    int k = 4;
    vector<int>ans =  FirstNegativeInteger(arr,k);
    for(auto it:ans) cout<<it<<" ";
    return 0;

    }