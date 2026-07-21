class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(mp.find(key)!=mp.end()){
            mp[key].push_back(make_pair(timestamp,value));
        }
        else{
            pair<int,string> p = {timestamp,value};
            vector<pair<int,string>> a={p};
            mp[key] = a;
        }
    }
    
    string get(string key, int timestamp) {

        string ans;
        if(mp.find(key)==mp.end()){
            return "";
        }

        vector<pair<int,string>> a = mp[key];

        int st=0;
        int end = a.size()-1;
        int closest = -1;
        while(st<=end){
            int mid = (st+end)/2;

            if(a[mid].first==timestamp){
                return a[mid].second;
            }
            else if(a[mid].first<timestamp){
                closest = mid;
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        if(closest ==-1){
            return "";
        }
        else{
            return a[closest].second;
        }
        
    }
};
