struct Node {
    int key;
    int val;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(int k, int v) : key(k), val(v) {}
};

struct List {
    Node* head;
    Node* tail;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
};

class LRUCache {
public:
    List* list = new List();
    unordered_map<int, Node*> mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (!mp.count(key)) return -1;
        Node* node = mp[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        node->prev = list->tail->prev;
        node->next = list->tail;
        list->tail->prev->next = node;
        list->tail->prev = node;
        return node->val;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            mp[key]->val = value;
            get(key);
        } else {
            if (mp.size() == cap) {
                Node* del = list->head->next;
                mp.erase(del->key);
                del->prev->next = del->next;
                del->next->prev = del->prev;
                delete del;
            }
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            newNode->prev = list->tail->prev;
            newNode->next = list->tail;
            list->tail->prev->next = newNode;
            list->tail->prev = newNode;
        }
    }
};
