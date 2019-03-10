/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
/*
To clone a graph, you need to have a copy of each node and you need to avoid copying the same node for multiple times. 
So you still need a mapping from an original node to its copy.
*/
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return node;
        
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        dict[node] = newNode;
        deque<UndirectedGraphNode*> dq;
        dq.push_back(node);
        while(!dq.empty()){
            UndirectedGraphNode* temp = dq.front();
            dq.pop_front();
            for(UndirectedGraphNode* neighbor : temp -> neighbors){
                if(dict.count(neighbor) == 0 ) {
                    dict[neighbor] = new UndirectedGraphNode(neighbor->label);
                    dq.push_back(neighbor);
                }
                dict[temp]->neighbors.push_back(dict[neighbor]);
            }
            
        }
        
        return newNode;
        
    }
    
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> dict;
};