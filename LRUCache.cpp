class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };

    node* head=new node(-1,-1);
    node* end=new node(-1,-1);

    int cap;
    unordered_map<int,node*>m;

    LRUCache(int capacity) {
     cap=capacity;   
     head->next=end;
     end->prev=head;
    }

    void addNode(node* newnode){
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    
    void deleteNode(node* deletenode){
        node* prevn=deletenode->prev;
        node* nextn=deletenode->next;

        prevn->next=nextn;
        nextn->prev=prevn;
    }

    int get(int key) {
        if(m.find(key)!=m.end()){
            node* temp=m[key];
            int ans= temp->val;
            m.erase(key);
            deleteNode(temp);
            addNode(temp);
            m[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node* curr=m[key];
            m.erase(key);
            deleteNode(curr);
        }
        if(m.size()==cap){
            m.erase(end->prev->key);
            deleteNode(end->prev);
        }
        addNode(new node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

