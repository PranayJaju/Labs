class DFS:

    def __init__(self, graph):
        self.graph = graph
        self.visited = []

    def traverse(self, node):
        if node not in self.visited:
            self.visited.append(node)
            for k in self.graph[node]:
                self.dfs(k)
        return self.visited

class TopologicalSort(DFS):

    def __init__(self, graph):
        super().__init__(graph)
        self.sorted = []

    def topological_sort_node(self, node):
        if node not in self.visited:
            self.visited.append(node)
            for k in self.graph[node]:
                self.topological_sort_node(k)
            self.sorted.append(node)
        return self.sorted

    def topo_sort(self):
        for k in self.graph:
            self.topological_sort_node(k)
        return self.sorted[::-1]

class FindAllLoops(DFS):

    def __init__(self, graph):
        super().__init__(graph)
        self.loops = []
        self.current_path = []

    def traverse(self, node):
        self.current_path.append(node)
        self.visited.append(node)
        for k in self.graph[node]:
            if k not in self.visited:
                self.traverse(k)
            elif k in self.current_path:
                loop = self.current_path[self.current_path.index(k):] + [k]
                self.loops.append(loop)
        self.current_path.remove(node)

        return self.loops

class SolveMaze(DFS):

    def __init__(self, graph):
        super().__init__(graph)
        self.path = []

    def traverse(self, node, end):
        self.visited.append(node)
        self.path.append(node)
        if node == end:
            return self.path
        for k in self.graph[node]:
            if k not in self.visited:
                path = self.traverse(k, end)
                if path:
                    return path
        self.path.remove(node)

#1.
''' #from DFS import TopologicalSort

def main():

    graph = {
        0: [],
        1: [],
        2: [3],
        3: [1],
        4: [0, 1],
        5: [0, 2],
    }

    print(TopologicalSort(graph).topo_sort())

if __name__ == '__main__':
    main()'''

#2.
'''#from DFS import FindAllLoops

def main():

    graph = {
        0: [1, 2],
        1: [2],
        2: [0, 3],
        3: [3]
    }

    print(FindAllLoops(graph).traverse(2))

if __name__ == '__main__':
    main()'''

#3.
'''#from DFS import SolveMaze

def main():

    graph = {
        1: [2, 6],
        2: [1, 3],
        3: [2, 8],
        4: [5],
        5: [4, 10],
        6: [1, 11],
        7: [8],
        8: [3, 7],
        9: [10, 14],
        10: [5, 9, 15],
        11: [6, 12],
        12: [11, 17],
        13: [14],
        14: [9, 13, 19],
        15: [10, 20],
        16: [17],
        17: [12, 16, 18],
        18: [17, 19],
        19: [14, 18],
        20: [15]
    }

    print(SolveMaze(graph).traverse(1, 20))

if __name__ == '__main__':
    main()'''