from typing import Optional


# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution(object):
    
    def __init__(self):
        self.visited = {}   # 用于存放已经访问过的节点
    
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return node

        if node in self.visited:
            return self.visited[node]
        
        clone_node = Node(node.val, [])
        
        self.visited[node] = clone_node
        
        if node.neighbors:
            clone_node.neighbors = [self.cloneGraph(n) for n in node.neighbors]
            
        return clone_node

if __name__ == "__main__":
    # 构建图
    addj_list = [[2, 4], [1, 3], [2, 4], [1, 3]]
    nodes = [Node(i) for i in range(1, 5)]
    for i, node in enumerate(nodes):
        node.neighbors = [nodes[j - 1] for j in addj_list[i]]
    # 深度拷贝
    solution = Solution()
    clone_node = solution.cloneGraph(nodes[0])
    

    