from WaterJug import WaterJugProblem

problem = WaterJugProblem([8, 5, 3], [8, 0, 0], [4, 4, 'x'])
path = problem.solve(method='dfs', maintain_water=True)
print(*path, sep='-> ')
print(f'Final length of path is {len(path)}')