#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 


static bool cmpPoint(std::vector<int>& p1, std::vector<int>& p2) {
    if (p1[0] == p2[0])
        return p1[1] < p2[1];
    else
        return p1[0] < p2[0];
}


int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0) return 0;
    
    /* First sort the points accroding to start positon (if equal, compare the end position) */
    std::sort(points.begin(), points.end(), cmpPoint);
    
    /* Use Greedy Algorithm
    shot at first ballon's [end] position
    if the next ballon's start < [end], 
    it mean we can shot both ballon at the same time at postion min(end, next's end)
    otherwise (next ballon's start > end),
    we can't shot ballons at the same time, so we increase n_shot by one.
    */
    int n_shot = 1;
    int end = points[0][1];
    for (int i=1; i<points.size(); i++) {
        if (points[i][0] <= end) {
            end = std::min(end, points[i][1]);
        }
        else{
            n_shot += 1;
            end = points[i][1];
        }
    }
    return n_shot;
}
