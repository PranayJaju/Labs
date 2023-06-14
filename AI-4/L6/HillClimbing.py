import random

class HillClimb():

	def __init__(self, coeff, min_max):
		self.coeff = coeff #coeff and expo dict
		self.min_max = min_max # to check for minimize(-1) and maximize(1)
		self.step_size = 0.1

	# funciton to evalute f(x) for given x
	def f(self, x):
		fx = 0
		for exp, cof in self.coeff.items():
			fx += cof * (x ** exp)
		return fx


	def run(self):
		x = random.randint(5, 10) # chooisng a value for X at random
		px = None # previous X
		ppx = None # previous-previous X

		while True:
			pos_x = x + self.step_size # step in positive direction
			neg_x = x - self.step_size # step in negative direction
			
			pos_dx = self.f(pos_x) - self.f(x) # difference in positive-step x and X
			neg_dx = self.f(neg_x) - self.f(x) # difference in negative-step x and X

			# this is for when the step size if too big and the X values keep oscillating
			# in that case the ppx and x will have the same value and thier diff = 0 
			# (but due to floating point errors we can assume them to be very very small, hence check with 1e-9)
			if(ppx is not None and abs(ppx - x)<1e-9):
				self.step_size *= 0.6
				if(self.step_size < 1e-9): return x, self.f(x)

			ppx, px = px, x

			# checking if we want to maximize or minimize, respectively
			if(pos_dx * self.min_max > 0): x = pos_x
			else: x = neg_x

			# if the difference between current X and previous X is very small, we have reached our output
			if abs(x - px) < 1e-9:
				return x, self.f(x)