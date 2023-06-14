def eucledian(x, y):
	sq = 0
	for a, b in zip(x,y):
		sq += (a-b)**2

	return sq**0.5	

def BubbleSort(a):
	for i in range(len(a)):
		for j in range(len(a)-1-i):
			if a[j]>a[j+1]: a[j], a[j+1] = a[j+1], a[j]

	return a

X = [(0,3), (7, 24), (8, 0), (21, 0)]
Y = [(4,0), (0, 0), (0, 15), (0, 20)]

dist = [eucledian(x, y) for x,y in zip(X, Y)]
BubbleSort(dist)
print(dist)