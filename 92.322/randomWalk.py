#!/usr/bin/python
# Paul Geromini

import copy
import random 
import math
import string
import operator

# Do a random walk on the gMatrix
#
# PARAM : gMatrix, the g matrix
# RETURN : the result matrix of the random walk
def randomWalk(gMatrix):
    resultMatrix = copy.deepcopy(gMatrix)

    # Add each row of the matrix to the following row
    for i in range(len(resultMatrix[0])):
        # Skip the first row
        if i == 0:
            continue

        for j in range(len(resultMatrix[i])):
            resultMatrix[i][j] = resultMatrix[i][j] + resultMatrix[i - 1][j]

    # Start with all monkeys in a vector at A
    # place 10 * n monkeys
    vector = [10 * len(resultMatrix), 0, 0, 0]
    resultVector = [0, 0, 0, 0]

    # Create a dictionary of rows
    rowDict = {}
    for i in range(len(resultMatrix)):
        newRow = [row[i] for row in resultMatrix]
        rowDict[i] = newRow

    # Seed random num generator
    random.seed()

    # For each monkey (40 total for default)
    # have the monkey move 80 total times
    while vector[0] != 0:
        # Only 10 monkeys to deal with all on first row
        vector[0] -= 1

        # Do the loop 80 times for each monkey
        count = 10 * len(resultMatrix) * len(resultMatrix)

        # Track the row a monkey comes from / ends in
        sect = 0

        # Do not take off a monkey if this is the first walk
        bFirstRun = True
        while count != 0:
            count -= 1 

            # Random number from 0 - 1.0
            num = random.random()
 
            # Determine in which row the monkey belongs
            # sect tracks the row the monkey comes from 
            for i in range(len(rowDict[sect])):
                if num < rowDict[sect][i]:
                    resultVector[i] += 1
                    
                    # Take off old monkey (only for second walk onwards)
                    if not(bFirstRun):
                        resultVector[sect] -= 1
 
                    # For next walk switch to the row
                    # the monkey ended up in
                    sect = i 
                    break    

            # Only take a monkey off if it is the second
            # monkey walk for a number 
            bFirstRun = False

    #print resultVector
    # Divide each number by 10n to form importance vector
    div = 10 * len(resultMatrix)
    for i in range(len(resultVector)):
        resultVector[i] = resultVector[i] / float(div)

    return resultVector

# Create the g matrix
#
# PARAM : sMatrix, the s matrix
# RETURN : the g matrix
def createGMatrix(sMatrix):
    gMatrix = copy.deepcopy(sMatrix)

    # Multiply each element by 0.85 
    # Add 0.15 * length of array * 1
    for i in range(len(gMatrix[0])):
        for j in range(len(gMatrix[i])):
            gMatrix[i][j] = (
                (0.85 * gMatrix[i][j]) + 0.15 * (1.0/len(gMatrix[i])) * 1)

    return gMatrix


# Create the S matrix
#
# PARAM : hMatrix, the h matrix
# RETURN : the s matrix
def createSMatrix(hMatrix):
    # Copy hMatrix to new sMatrix
    sMatrix = copy.deepcopy(hMatrix)

    # Form S matrix
    # if a column has all zeros then do 1/column size 
    # and put that value in each column location
    j = 0
    count = 0 
    while j != 4:
        for i in range(len(hMatrix[0])):
            if hMatrix[i][j] == 0:
                # Found a zero
                count += 1
                continue
            else:
                # Column not all zeros
                break

        if count == len(hMatrix[i]):
            for i in range(len(hMatrix[i])):
                sMatrix[i][j] = 1.0/len(hMatrix[i])

        # Look at next column
        j += 1

        # Reset count
        count = 0

    return sMatrix


def main():
    # Intialize empty 2 dimmensional list
    hMatrix = [[0.0 for x in xrange(4)] for x in xrange(4)]

    # Create h matrix (from homework)
    hMatrix[0][2] = 1.0
    hMatrix[1][0] = 0.5
    hMatrix[2][0] = 0.5
    hMatrix[2][1] = 0.5
    hMatrix[3][1] = 0.5
    #print hMatrix

    # Create S Matrix
    sMatrix = createSMatrix(hMatrix)
    #print sMatrix

    # Create G Matrix
    gMatrix = createGMatrix(sMatrix)
    #print gMatrix

    # Do the random walk
    resultMatrix = randomWalk(gMatrix)
    #print resultMatrix

    # Assign each row a letter in order
    # make it into a dictionay
    finalDict = {}

    # String containing all uppercase letters
    letters = string.uppercase

    for val in resultMatrix:
        finalDict[letters[0]] = val

        # Remove used letter
        letters = letters[1:]

 
    print "Site Letter and Value: ", finalDict

    # Sort the dictionary into a list of tuples
    sortedList = sorted(finalDict.iteritems(), key = operator.itemgetter(1), reverse=True)
    #print sortedList

    # For each tuple get the letter
    finalOrder = tuple(tup[0] for tup in sortedList)
    print "Final Order:", finalOrder

    # pg out
    return 

# Run main if started from shell
if __name__ == '__main__':
    main()
