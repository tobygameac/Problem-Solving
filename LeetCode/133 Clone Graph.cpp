class Solution {
 
 public:
  
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    std::unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> nodes_map;
    return CloneGraph(node, nodes_map);
  }

  UndirectedGraphNode *CloneGraph(UndirectedGraphNode *node, std::unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &nodes_map) {
    if (!node) {
      return 0;
    }
    if (nodes_map.find(node) != nodes_map.end()) {
      return nodes_map[node];
    }
    nodes_map[node] = new UndirectedGraphNode(node->label);
    UndirectedGraphNode *cloned_node = nodes_map[node];
    const size_t N = node->neighbors.size();
    cloned_node->neighbors = std::vector<UndirectedGraphNode *>(N);
    for (size_t i = 0; i < N; ++i) {
      cloned_node->neighbors[i] = CloneGraph(node->neighbors[i], nodes_map);
    }
    return cloned_node;
  }

};
