class MyCalendar {
    map<int, int> cal; // <endTime, statIme>
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        map<int,int>::iterator itr = cal.upper_bound(start);
        if(itr == cal.end() || end<= itr->second) {
            cal[end]=start;
            return true;
        } else {                        
            return false;
        }
    }
};