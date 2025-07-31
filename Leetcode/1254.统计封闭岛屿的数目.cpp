/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
    pair<int,int> GetZero(vector<vector<int>>& grid, vector<vector<bool>>& isVisited){
        int i, j;
        for(i = 0; i<grid.size(); ++i)
            for(j = 0; j<grid[i].size(); ++j)
                if(!isVisited[i][j]&&grid[i][j]==0) return {i,j};
        return {-1,-1};
    }
    int numIslands(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        vector<vector<bool>> isVisited(grid.size(),vector<bool>(grid[0].size(),false));
        int count = 0;
        queue<pair<int,int>> islandsQue;
        
        while(true){
            pair<int,int> oneBlock = GetZero(grid,isVisited);
            int i = oneBlock.first, j = oneBlock.second;
            if(i==-1 && j==-1) break;
            islandsQue.push(oneBlock);
            isVisited[i][j] = true;
            while(!islandsQue.empty()){
                oneBlock = islandsQue.front();islandsQue.pop();
                i = oneBlock.first; j = oneBlock.second;
                if(j-1>=0&&!isVisited[i][j-1]&&grid[i][j-1]==0) {islandsQue.push({i,j-1});isVisited[i][j-1]=true;}
                if(j+1<grid[i].size()&&!isVisited[i][j+1]&&grid[i][j+1]==0) {islandsQue.push({i,j+1});isVisited[i][j+1]=true;}
                if(i-1>=0&&!isVisited[i-1][j]&&grid[i-1][j]==0) {islandsQue.push({i-1,j});isVisited[i-1][j]=true;}
                if(i+1<grid.size()&&!isVisited[i+1][j]&&grid[i+1][j]==0) {islandsQue.push({i+1,j});isVisited[i+1][j]=true;}
            }
            ++count;
        }
       
        return count;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        grid.insert(grid.begin(), vector<int>(m+2, 0));
        for (int i = 1; i <= n; ++i) {
            grid[i].insert(grid[i].begin(), 0);
            grid[i].push_back(0);
        }
        grid.push_back(vector<int>(m+2,0));

        // for (int i = 0; i <= n + 1; ++i) {
        //     for (int j = 0; j <= m + 1; ++j) {
        //         cout << grid[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        // 200. 岛屿数量 减去外围陆地
        return numIslands(grid) - 1;
    }
};
// @lc code=end

