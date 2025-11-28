def marcsCakewalk(c)
    c.sort(reverse=True)
    result = 0
    i = 0
    while i  len(c)
        result += pow(2, i)  c[i]
        i += 1
    print(result)
