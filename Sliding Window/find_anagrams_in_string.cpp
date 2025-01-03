int search(string &pat, string &txt) {
        // code here
        int n = txt.length(),k = pat.length();
        int ans = 0;
        unordered_map<char,int>map;
        for(int i=0; i<k; i++){
            map[pat[i]]++;
        }
        int count = map.size();
        int j=0,i=0;
        while(j < n){
            if(map.find(txt[j]) != map.end()){
                map[txt[j]]--;
                if(map[txt[j]] == 0) count--;
            }
            
            if(j-i+1 < k) j++;
            
            else if(j-i+1 == k){
                
                if(count == 0) ans++;
                
                if(map.find(txt[i]) != map.end()){
                    map[txt[i]]++;
                    if(map[txt[i]] == 1) count++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }