from WaterJug import WaterJugProblem

problem = WaterJugProblem([5, 3], [0, 0], [4, 'x'])
path = problem.solve(method='bfs')
print(*path, sep='-> ')