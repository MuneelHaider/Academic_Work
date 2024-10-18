# from collections import deque
# from itertools import permutations
# def load_data_from_file(filepath):
#     graph = {}
    
#     with open(filepath, 'r') as file:
#         for line in file:
#             parts = line.strip().split(',')
#             vertex = int(parts[0])
#             cost = float(parts[-1])
#             # Assuming the parent set is always enclosed in braces
#             parent_set_str = line[line.find('{')+1:line.find('}')]
#             parents = tuple(map(int, parent_set_str.split(','))) if parent_set_str else ()
            
#             if vertex not in graph:
#                 graph[vertex] = []
#             graph[vertex].append((parents, cost))
    
#     return graph

import itertools
import re

def parse_dataset_from_file(file_path):
    graph = {}
    with open(file_path, 'r') as file:
        for line in file:
            parts = re.match(r'(\d+),\{(.*)\},([\d.-]+)', line)
            if parts:
                vertex = int(parts.group(1))
                cost = float(parts.group(3))
                parent_set_str = parts.group(2)
                parents = tuple(map(int, parent_set_str.split(','))) if parent_set_str else ()
                
                if vertex not in graph:
                    graph[vertex] = []
                graph[vertex].append((parents, cost))
    return graph

def is_valid_ordering(ordering, parents):
    return set(parents).issubset(set(ordering))

def find_min_cost_for_vertex(vertex, parents_list, ordering):
    valid_costs = [cost for parents, cost in parents_list if is_valid_ordering(ordering, parents)]
    return min(valid_costs) if valid_costs else float('inf')

def calculate_total_cost(graph, ordering):
    total_cost = 0
    for vertex in ordering:
        cost = find_min_cost_for_vertex(vertex, graph[vertex], ordering[:ordering.index(vertex)])
        if cost == float('inf'):
            return float('inf') 
        total_cost += cost
    return total_cost

def bfs_optimal_ordering(graph):
    vertices = list(graph.keys())
    all_orderings = itertools.permutations(vertices)
    min_cost = float('inf')
    optimal_ordering = None
    
    for ordering in all_orderings:
        current_cost = calculate_total_cost(graph, ordering)
        if current_cost < min_cost:
            min_cost = current_cost
            optimal_ordering = ordering
    
    return optimal_ordering, min_cost

def dfs_optimal_ordering(graph):
    vertices = list(graph.keys())
    stack = [([], 0)]  
    min_cost = float('inf')
    optimal_ordering = []

    while stack:
        current_ordering, current_cost = stack.pop()
        
        if len(current_ordering) == len(vertices):
            if current_cost < min_cost:
                min_cost = current_cost
                optimal_ordering = current_ordering
            continue
        
        for vertex in vertices[::-1]:  
            if vertex not in current_ordering:
                new_ordering = current_ordering + [vertex]
                new_cost = calculate_total_cost(graph, new_ordering)
                if new_cost < min_cost:
                    stack.append((new_ordering, new_cost))
    
    return optimal_ordering, min_cost

import heapq

def ucs_optimal_ordering(graph):
    vertices = list(graph.keys())
    priority_queue = [((0, []))] 
    min_cost = float('inf')
    optimal_ordering = []

    while priority_queue:
        current_cost, current_ordering = heapq.heappop(priority_queue)
        
        if len(current_ordering) == len(vertices):
            if current_cost < min_cost:
                min_cost = current_cost
                optimal_ordering = current_ordering
            continue
        
        for vertex in vertices:
            if vertex not in current_ordering:
                new_ordering = current_ordering + [vertex]
                new_cost = calculate_total_cost(graph, new_ordering)
                if new_cost < min_cost:
                    heapq.heappush(priority_queue, (new_cost, new_ordering))
    
    return optimal_ordering, min_cost


file_path = 'data1.txt'
graph = parse_dataset_from_file(file_path)
print(graph)

optimal_ordering, min_cost = bfs_optimal_ordering(graph)
print(f"Optimal Ordering: {optimal_ordering}, Total Cost: {min_cost}")

optimal_ordering_dfs, min_cost_dfs = dfs_optimal_ordering(graph)
print(f"DFS Optimal Ordering: {optimal_ordering_dfs}, Total Cost: {min_cost_dfs}")

optimal_ordering_ucs, min_cost_ucs = ucs_optimal_ordering(graph)
print(f"UCS Optimal Ordering: {optimal_ordering_ucs}, Total Cost: {min_cost_ucs}")