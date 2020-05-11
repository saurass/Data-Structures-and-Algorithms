class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<int> > trustees(N + 1);
        vector<bool> doesTrust(N + 1, false);
        for(int i = 0; i < trust.size(); i++) {
            trustees[trust[i][1]].push_back(trust[i][0]);
            doesTrust[trust[i][0]] = true;
        }
        int town_judge = -1;
        int no_of_town_judge = 0;
        for(int i = 1; i < trustees.size(); i++) {
            if(trustees[i].size() == N - 1 and doesTrust[i] == false) {
                town_judge = i;
                no_of_town_judge++;
            }
        }
        
        if(no_of_town_judge > 1)
            return -1;
        return town_judge;
    }
};