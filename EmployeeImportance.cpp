class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int result=0;
        unordered_map<int, Employee*>emap;
        queue<Employee*>q;
        for(auto& employ:employees){
            emap[employ->id]=employ;
        }
        q.push(emap[id]);
        while(!q.empty()){
            Employee* f= q.front(); 
            q.pop();
            result+=f->importance;
            for(int s:f->subordinates){
                q.push(emap[s]);
            }
        }
        return result;
    }
};