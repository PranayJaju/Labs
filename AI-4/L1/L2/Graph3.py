class Connection():
    def __init__(self, v1, v2):
        self.v1 = v1
        self.v2 = v2
 
class Graph():
 
    def __init__(self):
        self.edges = []
        self.vertices = []
 
    def addVertice(self, *vals):
        self.vertices += list(vals)
 
    def addConnection(self, *args):
        for arg in args:
            v1, v2 = arg
            self.edges.append(Connection(v1, v2))
 
    def printAdjacencyList(self):
 
        adjList = {}
 
        for cntn in self.edges:
            if cntn.v1 in adjList:
                adjList[cntn.v1].append((cntn.v2))
            else:
                adjList[cntn.v1] = [(cntn.v2)]

            if cntn.v2 in adjList:
                adjList[cntn.v2].append((cntn.v1))
            else:
                adjList[cntn.v2] = [(cntn.v1)]
 
        print(adjList)
 
    def printAdjacencyMatrix(self):
 
        mat = [[0,0,0,0,0], [0,0,0,0,0], [0,0,0,0,0], [0,0,0,0,0], [0,0,0,0,0]]

        idx= lambda x: self.vertices.index(x)
 
        for cntn in self.edges:
            mat[idx(cntn.v1)][idx(cntn.v2)] = mat[idx(cntn.v2)][idx(cntn.v1)] = 1
        
        for matrix in mat:
            print(matrix)
 
g = Graph()
g.addVertice('A', 'B', 'C', 'D', 'E')
g.addConnection(['A','B'], ['A','C'], ['A','E'], ['B','C'], ['B','D'], ['C','D'], ['C','E'])
g.printAdjacencyList()
g.printAdjacencyMatrix()