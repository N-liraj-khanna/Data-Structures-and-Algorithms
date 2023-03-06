// tc=o(n)
// sc=o(n)
class History{
    public:
        string link;
        History* next;
        History* prev;
        History(string _link){
            link=_link;
            next=NULL;
            prev=NULL;
        }
};
class BrowserHistory {
public:

    History* hist;

    BrowserHistory(string homepage) {
        hist=new History(homepage);
    }
    
    void visit(string url) {
        hist->next=new History(url);
        hist->next->prev=hist;
        hist=hist->next;
    }
    
    string back(int steps) {
        while(steps-- && hist->prev){
            hist=hist->prev;
        }
        return hist->link;
    }
    
    string forward(int steps) {
        while(steps-- && hist->next){
            hist=hist->next;
        }
        return hist->link;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */