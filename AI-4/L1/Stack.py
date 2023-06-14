class Stack:
	def __init__(self):
		self.stack = []

	def push(self, item):
		self.stack.append(item)

	def pop(self):
		return self.stack.pop() if self.stack else None

	def peek(self):
		if self.stack:
			print(self.stack[-1])
		else:
			print('Empty stack')

	def isEmpty(self):
		return not self.stack

	def size(self):
		return len(self.stack)

	def display(self):
		for i in reversed(self.stack):
			print(i)


class Queue:
	def __init__(self):
		self.stack1 = Stack()
		self.stack2 = Stack()

	def enqueue(self,item):
		self.stack1.push(item)

	def dequeue(self):
		if self.stack2.isEmpty():
			while self.stack1.size()>0:
				self.stack2.push(self.stack1.pop())
		return self.stack2.pop()

	def display(self):
		if self.stack1:
			if self.stack2:
				stack2.display()
				stack1[::-1].display()

			else:
				stack1[::-1].display()

		if self.stack2:
			stack2[::-1].display()

q = Queue()
for i in range(1,6):
	q.enqueue(i)
for i in range(1,6):
	print(q.dequeue(), end=' ')			



