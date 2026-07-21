class Solution {
public:

    int dist(string a, string b){
        int count = 0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                count++;
            }
        }
        return count;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        vector<vector<int>> graph(wordList.size()+1);
        int end=-1;
        for(int i=0;i<wordList.size();i++){
            if(dist(beginWord,wordList[i])==1){
                graph[0].push_back(i+1);
                graph[i+1].push_back(0);
            }
            if(endWord==wordList[i]){
                end = i+1;
            }
        }
        // if(dist(beginWord,endWord)==1){
        //         graph[0].push_back(wordList.size()+1);
        //         graph[wordList.size()+1].push_back(0);
        //     }


        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                if(dist(wordList[j],wordList[i])==1){
                    graph[j+1].push_back(i+1);
                    graph[i+1].push_back(j+1);
                }
            }
        }

        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }

        queue<int> q;
        vector<int> vis(wordList.size()+2,0);
        // int end=wordList.size()+1;
        q.push(0);
        int l = 0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int s = q.front();
                cout<<s<<endl;
                if(s==end){
                    return l+1;
                }
                q.pop();
                if(vis[s]==0){
                    vis[s]=1;
                    for(auto t: graph[s]){
                        
                        q.push(t);
                    }
                }
            }
            l++;
        }

        return 0;
        
    }
};