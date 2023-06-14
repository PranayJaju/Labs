from collections import deque, defaultdict
from copy import deepcopy
from typing import List

class BFS:

    def __init__(self, graph):
        self.graph = graph
        self.visited = []

    def traverse(self, start_node):
        queue = deque()
        queue.append(start_node)

        while queue:
            node = queue.popleft()
            if node not in self.visited:
                self.visited.append(node)
                for k in self.graph[node]:
                    queue.append(k)
        return self.visited

class TopologicalSort(BFS):

    def __init__(self, graph):
        super().__init__(graph)
        self.in_degrees = defaultdict(int)
        self.sorted = []

    def traverse(self, node):
        super().traverse(node)
        self.sorted.append(node)

    def topo_sort(self):
        for node in self.graph:
            for k in self.graph[node]:
                self.in_degrees[k] += 1

        queue = deque(node for node in self.graph if self.in_degrees[node] == 0)
        while queue:
            node = queue.popleft()
            self.traverse(node)
            for k in self.graph[node]:
                self.in_degrees[k] -= 1
                if self.in_degrees[k] == 0:
                    queue.append(k)

        return self.sorted

class FindAllLoops(BFS):

    def __init__(self, graph):
        super().__init__(graph)
        self.loops = []

    def traverse(self, start_node):
        queue = deque()
        queue.append((start_node, [start_node]))

        while queue:
            node, path = queue.popleft()
            for neighbor in self.graph[node]:
                if neighbor in path:
                    cycle = path[path.index(neighbor):] + [neighbor]
                    self.loops.append(cycle)
                else:
                    queue.append((neighbor, path + [neighbor]))

        return self.loops

class TSP(BFS):

    def __init__(self, graph):
        super().__init__(graph)
        self.min_path = []
        self.min_path_length = float('inf')

    def traverse(self, start_node):
        queue = deque()
        queue.append((start_node, [start_node], 0))

        while queue:
            node, path, path_length = queue.popleft()
            if path_length > self.min_path_length:
                continue
            if len(path) == len(self.graph):
                path_length += self.graph[node][start_node]
                if path_length < self.min_path_length:
                    self.min_path_length = path_length
                    self.min_path = path
                continue
            for neighbor in self.graph[node]:
                if neighbor not in path:
                    queue.append((neighbor, path + [neighbor], path_length + self.graph[node][neighbor]))

        return self.min_path + [start_node], self.min_path_length

#1.
'''#from BFS import TopologicalSort

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
'''#from BFS import FindAllLoops

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
#from BFS import TSP

def main():

    graph = {
        'A': {'B': 2, 'C': 3, 'D': 1},
        'B': {'A': 2, 'C': 4, 'D': 2},
        'C': {'A': 3, 'B': 4, 'D': 3},
        'D': {'A': 1, 'B': 2, 'C': 3}
    }

    print(TSP(graph).traverse('A'))

if __name__ == '__main__':
    main()