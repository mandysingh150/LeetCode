#define ss second
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        for(int i=0 ; i<paths.size() ; ++i) {
            stringstream ss(paths[i]);
            string filePath, file;
            ss>>filePath;
            filePath += '/';
            
            while(ss>>file) {
                int len = file.size();
                for(int i=5 ; i<len ; ++i) {
                    if(file[i]=='(') {
                        string content = file.substr(i+1,len-i-2);
                        mp[content].push_back((filePath+file.substr(0,i)));
                        break;
                    }
                }
            }
        }
        
        vector<vector<string>> v;
        for(auto i: mp) {
            if(i.ss.size()>=2) {
                v.push_back(i.ss);
            }
        }
        return v;
    }
};