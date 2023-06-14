class Connection():
    def __init__(self, parent, child, weight):
        self.parent = parent
        self.child = child
        self.weight = weight
 
class Graph():
 
    def __init__(self):
        self.edges = []
        self.vertices = []
 
    def addVertice(self, *vals):
        self.vertices += list(vals)
 
    def addConnection(self, *args):
        for arg in args:
            parent, child, weight = arg
            self.edges.append(Connection(parent, child, weight))
 
    def printAdjacencyList(self):
 
        adjList = {}
 
        for cntn in self.edges:
            if cntn.parent in adjList:
                adjList[cntn.parent].append((cntn.child, cntn.weight))
            else:
                adjList[cntn.parent] = [(cntn.child, cntn.weight)]
 
        print(adjList)
 
    def printAdjacencyMatrix(self):
 
        mat = [[0,0,0,0], [0,0,0,0], [0,0,0,0], [0,0,0,0]]
 
        for cntn in self.edges:
            mat[cntn.parent-1][cntn.child-1] = cntn.weight
        
        print(mat)
 
g = Graph()
g.addVertice(1, 2, 3, 4)
g.addConnection([1, 2, 1],
                [1, 3, 1],
                [2, 3, 3],
                [3, 4, 4],
                [4, 1, 5])
 
g.printAdjacencyList()
g.printAdjacencyMatrix()