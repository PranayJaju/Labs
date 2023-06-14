from collections import deque

class Jug:

    def __init__(self, name, capacity, vol=0):
        self.capacity = capacity
        self.vol = vol
        self.name = name

    def remaining(self):
        return self.capacity - self.vol

    def fill(self):
        self.vol = self.capacity

    def spill(self):
        self.vol = 0

    def copy(self):
        return Jug(self.name, self.capacity, self.vol)

    def __eq__(self, other):
        return self.name == other.name and self.capacity == other.capacity

    @classmethod
    def transfer(self, source, dest):
        if (source.vol > dest.remaining()):
            source.vol -= dest.remaining()
            dest.vol += dest.remaining()

        else:
            dest.vol += source.vol
            source.vol = 0


class State:

    def __init__(self, state):
        self.state = state
        self.parent = None

    def copy(self):
        new_state = State([jug.copy() for jug in self.state])
        new_state.parent = self
        return new_state

    def get_neighbours(self, maintain_water):
        neighbours = []

        if not maintain_water:
            for i, jug in enumerate(self.state):
                new_state_1 = self.copy()
                new_state_1.state[i].fill()

                neighbours.append(new_state_1)

                new_state_2 = self.copy()
                new_state_2.state[i].spill()
                neighbours.append(new_state_2)

        for i in range(len(self.state)):
            for j in range(i + 1, len(self.state)):
                new_state_1 = self.copy()
                new_state_2 = self.copy()
                Jug.transfer(new_state_1.state[i], new_state_1.state[j])
                Jug.transfer(new_state_2.state[j], new_state_2.state[i])

                neighbours.append(new_state_1)
                neighbours.append(new_state_2)

        neighbours = [n for n in neighbours if
                      not all(self.state[idx].vol == n.state[idx].vol for idx in range(len(n.state)))]
        return neighbours

    def __str__(self):
        return '[' + ' '.join(str(i.vol) for i in self.state) + '] '

    def __eq__(self, other):
        return all(self.state[idx].vol == other.state[idx].vol for idx in range(len(self.state)))


class WaterJugProblem:

    def __init__(self, jugs, start, goal):
        self.goal = goal
        self.start = self.convert_to_state(jugs, start)

    def convert_to_state(self, jugs, start):
        jug_objs = [Jug(i, jugs[i], start[i]) for i in range(len(jugs))]
        return State(jug_objs)

    def is_goal(self, state):
        current_vols = [i.vol for i in state.state]
        for i in range(len(current_vols)):
            if self.goal[i] == 'x':
                continue

            if self.goal[i] != current_vols[i]:
                return False

        return True

    def solve(self, method, maintain_water=False):
        q = deque([])
        q.append(self.start)
        closed = []

        while (len(q) > 0):
            state = q.pop() if method == 'dfs' else q.popleft()
            closed.append(state)

            if self.is_goal(state):
                path = [state]
                while state.parent is not None:
                    state = state.parent
                    path.append(state)

                return path[::-1]

            for n in state.get_neighbours(maintain_water):
                if n in closed:
                    continue
                q.append(n)