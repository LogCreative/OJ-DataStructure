/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

#include<iostream>
using namespace std;

// @lc code=start
class Solution {
    pair<int,int> GetOne(vector<vector<int>>& grid, vector<vector<bool>>& isVisited){
        int i, j;
        for(i = 0; i<grid.size(); ++i)
            for(j = 0; j<grid[i].size(); ++j)
                if(!isVisited[i][j]&&grid[i][j]==1) return {i,j};
        return {-1,-1};
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        vector<vector<bool>> isVisited(grid.size(),vector<bool>(grid[0].size(),false));
        queue<pair<int,int>> islandsQue;
        
        int maxArea = 0;

        while(true){
            pair<int,int> oneBlock = GetOne(grid,isVisited);
            int i = oneBlock.first, j = oneBlock.second;
            if(i==-1 && j==-1) break;
            islandsQue.push(oneBlock);
            isVisited[i][j] = true;
            int area = 0;
            while(!islandsQue.empty()){
                oneBlock = islandsQue.front();islandsQue.pop();++area;
                i = oneBlock.first; j = oneBlock.second;
                if(j-1>=0&&!isVisited[i][j-1]&&grid[i][j-1]==1) {islandsQue.push({i,j-1});isVisited[i][j-1]=true;}
                if(j+1<grid[i].size()&&!isVisited[i][j+1]&&grid[i][j+1]==1) {islandsQue.push({i,j+1});isVisited[i][j+1]=true;}
                if(i-1>=0&&!isVisited[i-1][j]&&grid[i-1][j]==1) {islandsQue.push({i-1,j});isVisited[i-1][j]=true;}
                if(i+1<grid.size()&&!isVisited[i+1][j]&&grid[i+1][j]==1) {islandsQue.push({i+1,j});isVisited[i+1][j]=true;}
            }
            maxArea = max(maxArea, area);
        }
       
        return maxArea;
    }
};
// @lc code=end

