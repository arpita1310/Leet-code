class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>arr;
        ListNode* tmp= head;
        while(tmp!=NULL){
            int value=tmp->val;
            arr.push_back(value);
            tmp=tmp->next;
        }
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            if(st.empty() || (st.empty() && arr[i]<=arr[st.top()])){
                st.push(i);
            }
            else{
                while(!st.empty() && (arr[i]>arr[st.top()])){
                    arr[st.top()]=arr[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            arr[st.top()]=0;
            st.pop();
        }
        return arr;
    }
};