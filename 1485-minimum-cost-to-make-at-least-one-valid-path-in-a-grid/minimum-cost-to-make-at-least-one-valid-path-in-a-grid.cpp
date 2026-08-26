class Solution {
public:
    int minCost(vector<vector<int>>& g) {
        int m=g.size(), n=g[0].size(), dr[]={0,0,1,-1}, dc[]={1,-1,0,0};
        deque<pair<int,int>> q{{0,0}};
        vector<vector<int>> d(m,vector<int>(n,1e9));
        d[0][0]=0;

        while(q.size()){
            auto [r,c]=q.front(); q.pop_front();
            for(int k=0;k<4;k++){
                int x=r+dr[k], y=c+dc[k];
                if(x<0||x>=m||y<0||y>=n) continue;
                int w=g[r][c]!=k+1;
                if(d[r][c]+w<d[x][y]){
                    d[x][y]=d[r][c]+w;
                    w?q.push_back({x,y}):q.push_front({x,y});
                }
            }
        }
        return d[m-1][n-1];
    }
};