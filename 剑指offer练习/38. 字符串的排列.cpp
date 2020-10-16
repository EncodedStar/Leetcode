class Solution {
public:
    inline bool occur(string &s, int lef, int rig) {
        for(int i=lef; i<rig; ++i) {
            if(s[i]==s[rig]) {
                return true;
            }
        }
        return false;
    }
    void dfs(string &s, int id, vector<string> &result) {
        if(id==s.size()) {
            result.push_back(s);
        } else {
            for(int i=id; i<s.size(); ++i) {
                if(!occur(s, id, i)) { // s[i] 在 s[id,i) 之间没有出现过
                    swap(s[id], s[i]);
                    dfs(s, id+1, result);
                    swap(s[id], s[i]);
                }
            }
        }
    }
    vector<string> permutation(string s) {
        vector<string> result;
        dfs(s, 0, result);
        return result;
    }
};
