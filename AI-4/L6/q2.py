from HillClimbing import HillClimb

minimize = HillClimb({3:1, 2:-4, 1:3, 0:1}, -1)
x, fx = minimize.run()
print(f'x = {round(x, 3)}, f(x) = {round(fx,3)}')