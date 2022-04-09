def linearsearch(x, lst):
	for i in range(len(lst)):
		if lst[i] == x:
			pos = i
			break
		else:
			pos = -1
	return pos

lst = [7, 5, 3, 6, 9, 8, 4, 2, 0, 1]
x = 4
print(linearsearch(x, lst))