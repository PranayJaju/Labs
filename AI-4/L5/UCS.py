from heapq import *

class UniformCostSearch():

	def __init__(self, graph):
		self.graph=graph

	def search(self, start, goal):
	
		q = []
		heappush(q, (0,(start, [start])))
		min_cost = float('inf')
		min_path = []
		while q:
			cost, (node, path) = heappop(q)
			if cost > min_cost:
				continue
			if node == goal:
				min_path = path 
				min_cost = cost 
				continue
			for neighbour, length in self.graph[node]:
				if neighbour not in path:
					heappush(q, (cost+length, (neighbour, path+[neighbour])))
	
		return min_cost, min_path
	
	def multiple_goals(self, start, goals):
		return sorted(
			[self.search(start, goal) for goal in goals],
			key = lambda x: x[0])[0]	