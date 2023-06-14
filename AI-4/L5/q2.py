from UCS import UniformCostSearch

def main():
	graph = {
        	'S': [('A', 5), ('B', 9), ('D', 6)],
        	'A': [('B', 3), ('G1', 9)],
        	'B': [('A', 2), ('C', 1)],
        	'C': [('S', 6), ('F', 7), ('G2', 5)],
        	'D': [('C', 2), ('E', 2)],
        	'E': [('G3', 7)],
        	'F': [('D', 2), ('G3', 8)],
        	'G1': [],
        	'G2': [],
        	'G3': [],
            }
	
	print('Goal with the least cost: ', end='')
	print(UniformCostSearch(graph).multiple_goals('S',['G1','G2','G3']))

if __name__ == '__main__':
	main()