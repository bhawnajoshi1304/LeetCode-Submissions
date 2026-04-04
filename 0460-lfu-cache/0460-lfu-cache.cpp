struct Node {
    int key, value;
    Node *next, *prev;
    Node() {
        this->key = this->value = -1;
        this->prev = this->next = NULL;
    }
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = this->next = NULL;
    }
};
struct DLL {
    Node *head, *tail;
    DLL() {
        this->head = new Node();
        this->tail = new Node();
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }
    void insertAtHead(Node* node) {
        node->next = this->head->next;
        node->prev = this->head;
        this->head->next->prev = node;
        this->head->next = node;
    }
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    bool isEmpty() { return head->next == tail; }
    Node* removeFromTail() {
        if (tail->prev == head)
            return nullptr;
        Node* node = tail->prev;
        node->prev->next = tail;
        tail->prev = node->prev;
        node->next = node->prev = NULL;
        return node;
    }
};
class LFUCache {
public:
    map<int, DLL> freqDLL;
    map<int, pair<Node*, int>> m;
    int capacity;

    LFUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (m.find(key) != m.end()) {
            int freq = m[key].second;
            Node* node = m[key].first;
            freqDLL[freq].remove(node);
            if (freqDLL[freq].isEmpty()) {
                freqDLL.erase(freq);
            }
            freqDLL[freq + 1].insertAtHead(node);
            m[key].second = freq + 1;
            return m[key].first->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;
        if (m.find(key) != m.end()) {
            Node* node = m[key].first;
            node->value = value;
            int freq = m[key].second;
            freqDLL[freq].remove(node);
            if (freqDLL[freq].isEmpty()) {
                freqDLL.erase(freq);
            }
            freqDLL[freq + 1].insertAtHead(node);
            m[key].second = freq + 1;
        } else {
            Node* node = new Node(key, value);
            if (m.size() == capacity) {
                auto it = freqDLL.begin();
                Node* n = it->second.removeFromTail();
                if (it->second.isEmpty()) {
                    freqDLL.erase(it);
                }
                m.erase(n->key);
                delete n;
            }
            freqDLL[1].insertAtHead(node);
            m[key] = {node, 1};
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */