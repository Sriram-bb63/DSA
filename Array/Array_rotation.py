def array_rotation_right(lst, n):
	l = len(lst)
	for _ in range(n):
		lst = lst[l-1:] + lst[:l-1]
	return lst

def array_rotation_left(lst, n):
	l = len(lst)
	for _ in range(n):
		lst = lst[1:] + lst[:-l+1]
	return lst

lst = [1, 2, 3, 4, 5, 6, 7, 8, 9]
n = 3
lst_right_rotation = array_rotation_right(lst, n)
print(*lst_right_rotation)
lst_left_rotation = array_rotation_left(lst, n)
print(*lst_left_rotation)
