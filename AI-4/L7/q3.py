from heapq import *
import numpy as np

class Board():

    def __init__(self, positions):
        self.pos = positions
        self.g = float('inf')
        self.neighbours = None
        self.parent = None
        self.goal = None
    
    def h(self, goal):
        self.goal = goal
        h = 0
        for i in range(9):
            if self.pos[i] != goal[i]:
                h += 1

        return h
    
    def f(self, goal):
        self.goal = goal
        return self.g + self.h(goal)
    
    def copy(self):
        return Board(self.pos.copy())
    
    def to_print(self):
        return np.reshape(self.pos, (3, 3))
    
    def __eq__(self, other):
        return self.pos == other.pos
    
    def __lt__(self, other):
        if self.g != other.g:
            return self.g < other.g
        else:
            return self.h(self.goal) < other.h(self.goal)
        
    def __gt__(self, other):
        return not self.__lt__(self, other)
    



class AStar():

    def __init__(self):
        self.open = []
        self.closed = []

    def get_neighbours(self, board):
        empty_idx = board.pos.index(0)
        possible_swaps = [empty_idx+i for i in range(-3,5,2) if 0 <= empty_idx+i <= 8]
        neighbours = []
        for idx in possible_swaps:
            n = board.copy()
            n.pos[idx], n.pos[empty_idx] = n.pos[empty_idx], n.pos[idx]
            neighbours.append(n)

        return neighbours
    
    def best_path(self, goal):
        n = goal
        path = []
        while n is not None:
            path.append(n.to_print())
            n = n.parent

        return path[::-1]
    
    
    def search(self, start, goal):
        start_state = Board(start)
        start_state.g = 0

        heappush(self.open, (start_state.f(goal), start_state))
        while self.open != []:
            f, node = heappop(self.open)
            
            if node.pos == goal:
                return self.best_path(node)
            
            for n in self.get_neighbours(node):
                get_nodes = lambda x: [i[1] for i in x]
                if n not in get_nodes(self.open):
                    n.parent = node
                    n.g = node.g + 1
                    heappush(self.open, (n.f(goal), n))
                elif n not in self.closed:
                    tentative_g = node.g + 1
                    if tentative_g < n.g:
                        n.g = tentative_g
                        n.parent = node

            self.closed.append(n)

        return False


def main():

    start = [2, 8, 3, 1, 6, 4, 7, 0, 5]
    goal = [1, 2, 3, 8, 0, 4, 7, 6, 5]

    best_path = AStar().search(start, goal)
    for arr in best_path:
        print(arr, '\n')

if __name__ == '__main__':
    main()