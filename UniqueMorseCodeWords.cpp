class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> def={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string>s;
        for(auto gw:words){
              string transform;
              for(auto ch: gw )transform += def[ch - 'a'];
              s.insert(transform);
        }
        return s.size();


    }
};