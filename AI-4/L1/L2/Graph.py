class Graph:
	def __init__(self):
		self.edges=[]

	def addEdge(self, *cons):
		for edge in cons:
			self.edges.append(edge)

	def printEdgeList(self):
		for conn in self.edges:
			if self.edges.index(conn) != len(self.edges)-1 and conn[0] == self.edges[self.edges.index(conn)+1][0]:
				print(f'({conn[0]} -> {conn[1]})', end=' ')
			else:
				print(f'({conn[0]} -> {conn[1]})')

g = Graph()
g.addEdge([0,1], [1,2], [2,0], [2,1], [3,2], [4,5], [5,4])
g.printEdgeList()