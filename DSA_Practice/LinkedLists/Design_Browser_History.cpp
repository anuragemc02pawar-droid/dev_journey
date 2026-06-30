class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node(string url) {
        data = url;
        next = NULL;
        prev = NULL;
    }
};

class BrowserHistory {
public:
    Node* current;

    BrowserHistory(string homepage) {
        current=new Node(homepage);
    }
    
    void visit(string url) {
       Node* newNode = new Node(url);
       // delete forward history
       current->next = NULL;
       newNode->prev =current;
       current->next=newNode;
       current=newNode;
    }
    
    string back(int steps) {
        while(steps){
            if(current->prev)
            current=current->prev;
            else break;
            steps--;
        }
        return current->data;
    }
    
    string forward(int steps) {
        while(steps){
            if(current->next)
            current=current->next;
            else break;
            steps--;
        }
        return current->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */