from heapq import *

class BestFirstSearch():

	def __init__(self, graph, heuristics):
		self.graph = graph
		self.h = heuristics

	def search(self, start, goals):

		openList = []
		heappush(openList, (0,(start, [start], 0)))
		min_cost = float('inf')
		min_path = []
		while openList:
			f, (node, path, length) = heappop(openList)
			
			if node in goals:
				return path, length

			for neighbour, dist in self.graph[node]:
				if neighbour not in path:
					heappush(openList, (self.h[neighbour], (neighbour, path+[neighbour], length+dist)))
