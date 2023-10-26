class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int>visited(words.size());
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(char c:words[i]){
                visited[i]|=1<<(c-'a');
            }
            for(int j=0;j<i;j++){
                if(!(visited[i]&visited[j])){
                    if(words[i].length()*words[j].length()>ans){
                        ans=words[i].length()*words[j].length();
                    }
                }
            }
        }
        return ans;
    }
};