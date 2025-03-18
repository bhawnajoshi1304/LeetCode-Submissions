struct Node {
    int key, val;
    Node *prev, *next;

    Node() {
        this->key = this->val = -1;
        this->next = this->prev = nullptr;
    }

    Node(int key, int value) {
        this->key = key;
        this->val = value;
        this->next = this->prev = nullptr;
    }
};

class DLL {
    Node *head, *tail;

public:
    DLL() {
        this->head = new Node();
        this->tail = new Node();
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    void insertAfterHead(Node* node) {
        node->next = this->head->next;
        this->head->next->prev = node;
        node->prev = this->head;
        this->head->next = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = node->prev = nullptr;
    }

    Node* removeFromTail() {
        if (this->head->next != this->tail) {
            Node* node = this->tail->prev;
            node->prev->next = this->tail;
            this->tail->prev = node->prev;
            node->prev = node->next = nullptr;
            return node;
        }
        return nullptr;
    }
};

class LRUCache {
    map<int, Node*> m;
    DLL list;
    int capacity;

public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        } else {
            Node* node = m[key];
            this->list.remove(node);
            this->list.insertAfterHead(node);
            return node->val;
        }
    }

    void put(int key, int value) {
        Node* node;
        if (m.find(key) == m.end()) {
            if (m.size() == this->capacity) {
                node = this->list.removeFromTail();
                if (node != nullptr) {
                    m.erase(node->key);
                }
                node->key = key;
                node->val = value;
            } else {
                node = new Node(key, value);
            }
        } else {
            node = m[key];
            this->list.remove(node);
            node->val = value;
        }
        this->list.insertAfterHead(node);
        m[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
