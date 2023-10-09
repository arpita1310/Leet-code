class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>s(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endWord)  return step;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char j='a'; j<='z';j++){
                   word[i]=j;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};