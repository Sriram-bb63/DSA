def jumpsearch(x, lst):
    step = 5
    for i in range(0, len(lst), step):
        if x in lst[i : i + step]:
            for j in range(i, i + step):
                if lst[j] == x:
                    return j

lst = [1, 5, 9, 6, 3, 7, 4, 8, 2, 0]
lst.sort()
x = 9
print(jumpsearch(x, lst))
