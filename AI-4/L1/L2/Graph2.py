class Graph:
	def __init__(self):
		self.edges=[]

	def addEdge(self, *cons):
		for edge in cons:
			self.edges.append(edge)

	def printEdgeList(self):
		for conn in self.edges:
			if self.edges.index(conn) != len(self.edges)-1 and conn[0] == self.edges[self.edges.index(conn)+1][0]:
				print(f'({conn[0]} -> {conn[1]}, {conn[2]})', end=' ')
			else:
				print(f'({conn[0]} -> {conn[1]}, {conn[2]})')

g = Graph()
g.addEdge([0,1,6], [1,2,7], [2,0,5], [2,1,4], [3,2,10], [4,5,1], [5,4,3])
g.printEdgeList()