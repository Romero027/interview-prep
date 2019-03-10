//Out goal is trying to use two colors to color the graph and see if there are any adjacent nodes having the same color

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size() == 0)
            return true;
        int length = graph.size();
        vector<int> colors(length, 0);
        
        for(int i = 0; i < length; i++ ) {
            if(colors[i] == 0 && !valid(graph, colors, 1, i)){
                return false;
            }
        }
        
        return true;
    }
    
    bool valid(vector<vector<int>>& graph, vector<int>& colors, int color, int index) {
        //first check if the node has already been colored
        if(colors[index] != 0 ) {
            return colors[index] == color;
        } 
        
        //color the node
        colors[index] = color;
        
        //color all other nodes reachable from current node
        for(int node : graph[index]) {
            if(!valid(graph, colors, -color, node)){
                return false;
            }
        }        
        return true;
    }
};