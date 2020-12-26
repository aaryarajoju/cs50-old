# CS50-WEEK6-PSET6-DNA
# Implement a program that identifies a person based on their DNA

from csv import reader, DictReader
from sys import argv

if len(argv) != 3:
    print("usage error, dna.py sequence.txt database.csv")
    exit()

with open(argv[2]) as dnaFile:
    dnaReader = reader(dnaFile)
    for row in dnaReader:
        dnaList = row

dna = dnaList[0]
sequences = {}

with open(argv[1]) as peopleFile:
    people = reader(peopleFile)
    for row in people:
        dnaSequences = row
        dnaSequences.pop(0)
        break

for item in dnaSequences:
    sequences[item] = 1

for key in sequences:
    l = len(key)
    tempMax = 0
    temp = 0
    for i in range(len(dna)):
        while temp > 0:
            temp = temp - 1
            continue

        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                temp = temp + 1
                i = i + l

            if temp > tempMax:
                tempMax = temp

    sequences[key] = sequences[key] + tempMax

with open(argv[1], newline='') as peopleFile:
    people = DictReader(peopleFile)
    for person in people:
        match = 0
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match = match + 1
        if match == len(sequences):
            print(person['name'])
            exit()

    print("No match")