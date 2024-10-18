import itertools
import heapq
import re

def readData(file_path):

    array = {}
    with open(file_path, 'r') as file:

        for line in file:
            lineRead = re.match(r'(\d+),\{(.*)\},([\d.-]+)', line)

            if lineRead:
                vertex = int(lineRead.group(1))
                cost = float(lineRead.group(3))
                parentBlock = lineRead.group(2)
                parent = tuple(map(int, parentBlock.split(','))) if parentBlock else ()
                
                if vertex not in array:
                    array[vertex] = []

                array[vertex].append((parent, cost))

    return array

def orderingCheck(ordering, parent):
    return set(parent).issubset(set(ordering))

def minCostOfVertex(vertex, parents, ordering):
    validCosts = [cost for parent, cost in parents if orderingCheck(ordering, parent)]
    return min(validCosts) if validCosts else float('inf')

def totalCostCalc(array, ordering):
    total_cost = 0

    for vertex in ordering:
        cost = minCostOfVertex(vertex, array[vertex], ordering[:ordering.index(vertex)])
    
        if cost == float('inf'):
            return float('inf') 
    
        total_cost += cost
    return total_cost

def AlgoBFS(array):
    vertices = list(array.keys())
    allOrders = itertools.permutations(vertices)
    minCost = float('inf')
    optimalOrdering = None
    
    for ordering in allOrders:
        currentCost = totalCostCalc(array, ordering)
        
        if currentCost < minCost:
            minCost = currentCost
            optimalOrdering = ordering
    
    return optimalOrdering, minCost

def AlgoDFS(array):
    vertices = list(array.keys())
    stack = [([], 0)]  
    minCost = float('inf')
    optimalOrdering = []

    while stack:
        currentOrdering, currentCost = stack.pop()
        
        if len(currentOrdering) == len(vertices):
           
            if currentCost < minCost:
                minCost = currentCost
                optimalOrdering = currentOrdering
            continue
        
        for vertex in vertices[::-1]:  
            
            if vertex not in currentOrdering:
                newOrder = currentOrdering + [vertex]
                newCost = totalCostCalc(array, newOrder)
            
                if newCost < minCost:
                    stack.append((newOrder, newCost))
    
    return optimalOrdering, minCost

def AlgoUCS(array):
    vertices = list(array.keys())
    priorityQueue = [((0, []))] 
    minCost = float('inf')
    optimalOrdering = []

    while priorityQueue:
        currentCost, currentOrdering = heapq.heappop(priorityQueue)
        
        if len(currentOrdering) == len(vertices):
       
            if currentCost < minCost:
                minCost = currentCost
                optimalOrdering = currentOrdering
            continue
        
        for vertex in vertices:
       
            if vertex not in currentOrdering:
                newOrder = currentOrdering + [vertex]
                newCost = totalCostCalc(array, newOrder)
       
                if newCost < minCost:
                    heapq.heappush(priorityQueue, (newCost, newOrder))
    
    return optimalOrdering, minCost


file_path = 'data0.txt'
array = readData(file_path)
print(array)

resultBFS, costBFS = AlgoBFS(array)
print(f"Optimal Ordering: {resultBFS}, Total Cost: {costBFS}")

resultDFS, costDFS = AlgoDFS(array)
print(f"DFS Optimal Ordering: {resultDFS}, Total Cost: {costDFS}")

resultUCS, costUCS = AlgoUCS(array)
print(f"UCS Optimal Ordering: {resultUCS}, Total Cost: {costUCS}")