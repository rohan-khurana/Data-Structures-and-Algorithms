#include<bits/stdc++.h>
using namespace std;

void fill(vector<vector<int>>& image, int sr, int sc, int newColor, int currColor){
    if(sr>=0 && sr<image.size() && sc>=0 && sc<image[0].size() && image[sr][sc]==currColor){
        image[sr][sc]=newColor;
        fill(image,sr+1,sc,newColor,currColor);
        fill(image,sr-1,sc,newColor,currColor);
        fill(image,sr,sc+1,newColor,currColor);
        fill(image,sr,sc-1,newColor,currColor);
    }
    else
        return;
}
    
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int currColor = image[sr][sc];
    if(newColor==currColor){
        return image;
    }
    fill(image,sr,sc,newColor,currColor);
    return image;
}