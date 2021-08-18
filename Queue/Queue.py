class queue:
	"""
	Queue implementation using lists
	"""
	def __init__(self):
		self.lst = []
		self.front = None

	def enqueue(self, value):
		self.lst.append(value)
		self.front = self.lst[0]

	def dequeue(self):
		slef.front = self.lst[1]
		return self.lst.pop(0)

	def is_empty(self):
		if len(self.lst) > 0:
			return False
		else:
			return True

	def print_queue(self):
		for i in self.lst:
			print(i)

x = queue()
for i in range(10):
	x.enqueue(i)
x.print_queue()