class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp=head;
        while(temp){
            if(temp->child){
                Node* fake=temp->child;
                while(fake->next){
                    fake=fake->next;
                }
                fake->next=temp->next;
                if(temp->next){
                    temp->next->prev=fake;
                }
                temp->child->prev=temp;
                temp->next=temp->child;
                temp->child=NULL;
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};