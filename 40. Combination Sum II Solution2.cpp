/*
p = target / min(candidates[i]) + 1
Time: O(C(n, 1) + C(n, 2) + C(n, 3) + … + C(n, p))
Space: O(path + recursion stack) = O(p)
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, res, path);
        return res;
    }
    
private:
    void dfs(const vector<int>& candidates, int target, int idx, vector<vector<int>> & res, vector<int> & path) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        
        for (int next_idx = idx; next_idx < candidates.size(); ++next_idx) {
            if (candidates[next_idx] > target) 
                return;
            
            if (next_idx > idx && candidates[next_idx] == candidates[next_idx - 1])
                continue;

            path.push_back(candidates[next_idx]);
            dfs(candidates, target - candidates[next_idx], next_idx + 1, res, path);
            path.pop_back();
        }        
    }
};
