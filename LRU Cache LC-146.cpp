// All operations same as below, more organized
// tc=O(1)
// sc=o(capacity)
class LRUCache {
public:
    struct Node{
        int val;
        int key;
        Node* back;
        Node* next;
    };
    Node* head;
    Node* tail;

    unordered_map<int,Node*> map;
    int size;
    
    LRUCache(int capacity) {
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->back=head;
        size=capacity;
    }

    void insertNode(Node* node){
        tail->back->next=node;
        node->back=tail->back;
        node->next=tail;
        tail->back=node;
    }
    

    void deleteNode(Node* node){
        node->back->next=node->next;
        node->next->back=node->back;
    }
    
    int get(int key) {
        if(map.find(key)==map.end()) return -1;
        int op = map[key]->val;
        int k=map[key]->key;
        deleteNode(map[key]);

        Node* x=new Node();
        x->val=op;
        x->key=k;
        insertNode(x);
        map[key]=x;
        return op;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            map[key]->val=value;
            get(key);
            return;
        }
        if(size==map.size()){
            map.erase(head->next->key);
            deleteNode(head->next);
        }

        Node* x=new Node();
        x->val=value;
        x->key=key;
        map[key]=x;
        insertNode(x);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// All operations 
// tc=O(1)
// sc=o(capacity)
class LRUCache {
public:
    struct Node{
        int val;
        int key;
        Node* back;
        Node* next;
    };
    Node* head;
    Node* tail;

    unordered_map<int,Node*> map;
    int size;
    
    LRUCache(int capacity) {
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->back=head;
        size=capacity;
    }
    
    int get(int key) {
        if(map.find(key)==map.end()) return -1;
        Node* temp=map[key];
        int op = temp->val;
        int k=temp->key;
        temp->back->next=temp->next;
        temp->next->back=temp->back;

        Node* front=new Node();
        front->val=op;
        front->key=k;
        front->next=tail;
        front->back=tail->back;
        tail->back->next=front;
        tail->back=front;
        map[key]=front;
        return op;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            map[key]->val=value;
            get(key);
            return;
        }
        if(size==map.size()){
            map.erase(head->next->key);
            head->next=head->next->next;
            head->next->back=head;
        }

        Node* x=new Node();
        x->val=value;
        x->key=key;
        map[key]=x;

        tail->back->next=x;
        x->back=tail->back;
        x->next=tail;
        tail->back=x;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */