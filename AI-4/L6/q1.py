from HillClimbing import HillClimb

maximize = HillClimb({2:-1, 1:5, 0:10}, 1)
x, fx = maximize.run()
print(f'x = {round(x, 3)}, f(x) = {round(fx,3)}')