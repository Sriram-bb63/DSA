class stack:
	"""
	Stack implementation using lists
	"""
	def __init__(self):
		self.lst = []
		self.top = None

	def insert(self, value):
		self.lst.append(value)
		self.top = self.lst[-1]

	def pop(self):
		self.top = self.lst[-2]
		return self.lst.pop()

	def is_empty(self):
		if len(self.lst) >= 1:
			return False
		else:
			return True

	def peek(self):
		return self.top

	def print_stack(self):
		for i in self.lst[-1::-1]:
			print(i)

x = stack()
for i in range(10):
	x.insert(i)
x.print_stack()