#!/usr/bin/python

import time

filename = input("Вкажіть назву файлу: ")
Graph = open(filename, "r")

nm = Graph.readline().split()

def get_mass(file):
    data = []
    m = int(nm[1])
    while m > 0:
        m -= 1
        data.append(file.readline().split())
    return data

data = get_mass(Graph)

def incedent(file):
    incedent_matrix = []
    for edge in range(int(nm[0])):
        edges = []
        for j in range(int(nm[1])):
            if edge + 1 == int(file[j][0]) == int(file[j][1]):
                edges.append(2)
            elif edge + 1 == int(file[j][0]):
                edges.append(-1)
            elif edge + 1 == int(file[j][1]):
                edges.append(1)
            else:
                edges.append(0)
        incedent_matrix.append(edges)
    return incedent_matrix

def symizh(file):
    symizh_matrix = [[0 for i in range(int(nm[0]))] for j in range(int(nm[0]))]
    for i in range(int(nm[1])):
        k = int(file[i][0])
        l = int(file[i][1])
        symizh_matrix[k-1][l-1] = 1
    return symizh_matrix

def print_matrix(m):
    edge = int(1)
    for i in m:
        print('{0:3d}'.format(edge), end=" ")
        for j in i:
            print('{0:2d}'.format(j), end=" ")
        edge=int(edge)+1
        print()

def write_to_file(matrix, mode):
    with open("Result.txt", mode) as Result:
        for i in matrix:
            Result.write(str(i))
            Result.write("\n")



if __name__ == "__main__": 

    print(nm)
    answer = input("Перевести в iнцидентну матрицю? [y/n]   ")

    flag = False

    if answer == 'y':
        flag = True
        write_to_file(incedent(data), "w")
        print("   ", end=" ")
        for i in range(int(nm[1])):
            print('{0:2d}'.format(i+1), end=" ")
        print()
        print_matrix(incedent(data))

    answer = input("Перевести в матрицю сумiжностi? [y/n]   ")

    if answer == 'y':
        if flag:
            mode="a"
        else: mode="w"
        write_to_file(symizh(data), mode)
        print("   ", end=" ")
        for i in range(int(nm[0])):
            print('{0:2d}'.format(i+1), end=" ")
        print()
        print_matrix(symizh(data))
    time.sleep(5)

Graph.close()
