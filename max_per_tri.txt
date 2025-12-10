def maximumPerimeterTriangle(sticks):
    sticks.sort()
    
    for i in range(len(sticks) - 3, -1, -1):
        a, b, c = sticks[i], sticks[i+1], sticks[i+2]
        
        if a + b > c:
            return [a, b, c]
    
    return [-1]