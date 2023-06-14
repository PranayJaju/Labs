from UCS import UniformCostSearch

def main():
	graph = {
	    	0:[(1,2),(3,5)],
	    	1:[(6,1)],
			2:[(1,4)],
			3:[(1,5),(4,2),(6,6)],
			4:[(2,4),(5,3)],
			5:[(2,6),(6,3)],
			6:[(4,7)]
			}
	
	print('Shortest path from S to G: ', end='')
	print(UniformCostSearch(graph).search(0,6))

if __name__ == '__main__':
	main()