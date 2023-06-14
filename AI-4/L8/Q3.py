from BestFirstSearch import BestFirstSearch

heuristics = {
            'A': 1,
            'B': 4,
            'C': 2,
            'G': 0,
            'S': 5
        }

graph = {
    'A': [('S', 5), ('G', 1)],
    'B': [('S', 1), ('C', 2)],
    'C': [('B', 2), ('G', 2)],
    'G': [('A', 1), ('C', 2)],
    'S': [('A', 5), ('B', 1)]    
}

print(BestFirstSearch(graph, heuristics).search('S', ['G']))