def binarysearh(lst, x, left, right):
	if left <= right:
		mid = left + (right - left) // 2
		if lst[mid] == x:
			return mid
		elif lst[mid] > x:
			return binarysearh(lst, x, left, mid-1)
		else:
			return binarysearh(lst, x, mid+1, right)
	else:
		return -1


lst = [7, 5, 3, 6, 9, 1, 0, 2, 4, 8]
x = 5
print(binarysearh(lst, x, 0, len(lst)-1))
