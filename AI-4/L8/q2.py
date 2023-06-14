from BestFirstSearch import BestFirstSearch

heuristics = {
            'A': 30,
            'B': 40,
            'C': 60,
            'D': 10,
            'E': 35,
            'F': 35,
            'G1': 0,
            'G2': 0,
            'S': 45
        }

graph = {
    'A': [('E', 10)],
    'B': [('F', 3)],
    'C': [('D', 10), ('G2', 75)],
    'D': [('G2', 35)],
    'E': [('G1', 25), ('S', 1)],
    'F': [('A', 5), ('C', 5)],
    'G1': ['G2', 0],
    'G2': [],
    'S': [('A', 15), ('B', 2), ('D', 15)]    
}

print(BestFirstSearch(graph, heuristics).search('S', ['G1', 'G2']))