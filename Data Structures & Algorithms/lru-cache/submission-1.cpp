class Doubly{
    public:
    int val;
    int key;
    Doubly* next;
    Doubly* prev;
    Doubly(int value,int keyy){
        val = value;
        key = keyy;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    Doubly* head=new Doubly(-1,-1),*tail;
    unordered_map<int,Doubly*> mp;
    int capa = 0;
    int current_size = 0;
    LRUCache(int capacity) {
        capa = capacity;
        tail = head;
    }

    void makeitRecent(int key){

        Doubly* node = mp[key];

        if(tail==node){
            return;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = nullptr;
        tail->next = node;
        node->prev = tail;
        tail = tail->next;
        return;
    }

    void removeLeast(){
        Doubly* node = head->next;
        head->next = node->next;
        if(node->next)
            node->next->prev = head;
        
        mp.erase(node->key);
        cout<<node->key<<endl;
        delete node;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        makeitRecent(key);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            if(capa<=current_size){
                cout<<capa<<" "<<current_size;
                removeLeast();
                current_size--;
            }
            Doubly* node = new Doubly(value,key);
            cout<<key<<" "<<node->key<<endl;
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
            mp[key] = node;
            current_size++;
        }
        else{
            mp[key]->val = value;
            makeitRecent(key);
        }
    }
};
