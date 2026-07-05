class Solution {
public:
    const int INF = 1e9;
    int coinsSum(vector<int>& coins, int amount,vector<int>& memo){
        if(amount <0) return INF;
        if(amount==0) return 0;
        
        if(memo[amount]!=-1) return memo[amount];
        int ans=INF;
        for(int j=0;j<coins.size();j++){
            int sub=coinsSum(coins,amount-coins[j],memo);
            if(sub!=INF) ans=min(ans,1+sub);
        }
        return memo[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1,-1);
        int result = coinsSum(coins,amount,memo);
        return result==INF?-1:result;
    }
};
