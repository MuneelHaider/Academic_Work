import numpy as np
import random

# Muneel Haider i210640
# AI - CS(G)
# Assignment 2 - Question 2

# TIME COMPLEXITY:  O(g*n)

# Where 'g' is number of generations which is constant
# Where 'n' is population size

# If 'n' is large, then size of g is insignificant

# TIME COMPLEXITY IF 'n' is large: O(n)

# SPACE COMPLEXITY: O(n)

def isMagicSquare(m):
   
    # Sums each ROW, COLUMN, ALL DIAGONALS
    # Check if sums are 15
    magicSum = 15
   
    return (
   
        all(np.sum(m, axis=1) == magicSum) and
        all(np.sum(m, axis=0) == magicSum) and
        np.sum(np.diag(m)) == magicSum and
        np.sum(np.diag(np.fliplr(m))) == magicSum
    )

def fitness(matrix):
    
    # Calculates total deviation of ROWS, COLUMSN, and ALL DIAGONALS
    magicSum = 15
    row_diff = sum(abs(magicSum - sum(row)) for row in matrix)
    col_diff = sum(abs(magicSum - sum(col)) for col in zip(*matrix))
    diag_diff = abs(magicSum - sum(matrix[i][i] for i in range(3))) + abs(magicSum - sum(matrix[i][2-i] for i in range(3)))
    
    return row_diff + col_diff + diag_diff

def generate_population(size):

    # Generates matrices filled with 1-9
    population = [np.random.permutation(9) + 1 for _ in range(size)]
    
    return [p.reshape((3,3)) for p in population]

def select_parents(population):

    # Pciks two matrices to be parents
    return random.sample(population, 2)

def crossover(parent1, parent2):

    cutoff = random.randint(1, 8)
    child = np.zeros(9, dtype=int)
    child[:cutoff], child[cutoff:] = parent1.flatten()[:cutoff], parent2.flatten()[cutoff:]
    missing = set(range(1, 10)) - set(child)
    
    for i in range(9):
    
        if child[i] == 0:
            child[i] = missing.pop()
    
    return child.reshape((3,3))

def mutate(child):

    # Swap two numbers in matrix for uniqueness
    i, j = random.sample(range(9), 2)
    child.flat[i], child.flat[j] = child.flat[j], child.flat[i]
 
    return child

def display_population(population):

    # Prints all matrices
    for index, matrix in enumerate(population):
        print(f"Matrix {index}:")
        print(matrix)
        print()

def genetic_algorithm():
    
    # Algoritm to change population to magic square
    population_size = 50
    generations = 1000
    mutation_rate = 0.3
    
    # Initial generation and display
    population = generate_population(population_size)
    display_population(population)
    
    # Evolution:
    # loop: sort, breed, mutate, and replace the population
    for generation in range(generations):

        # SORT
        population.sort(key=fitness)
       
        # FITNESS CHECK
        if fitness(population[0]) == 0:
            return population[0]
       
        new_generation = population[:population_size//2]
       
        while len(new_generation) < population_size:
            
            # BREED
            parent1, parent2 = select_parents(new_generation)
            child1, child2 = crossover(parent1, parent2), crossover(parent2, parent1)
            
            # MUTATE
            new_generation.extend([mutate(child1), mutate(child2)] if random.random() < mutation_rate else [child1, child2])
       
        # REPLACE
        population = new_generation
    
    return None  # No magic square found


solution = genetic_algorithm()
print()

if solution is not None:
    print("A solution was found:")
    print(solution)

else:
    print("No solution found.")

print()
