#! /usr/bin/python
# Paul Geromini

from collections import Counter
import Queue

# Dictionary to hold the final codes
finalDict = {}

class TreeObj:
    def __init__(self, left, right, value):
        self.left = left
        self.right = right
        self.value = value

    def cleanPrint(self):
        print "Left: \t", self.left
        print "Right: \t", self.right
        print "Value: \t", self.value

# Recursively calculate all the paths from the tree
# the paths are the codes
#
# PARAM tree, the tree to get the paths from
# PARAM path, a string of the generated path thus far
# PARAM num, the number string to add to the path
#            start value is 3, ignore it
def printPaths(tree, path, num):

    # Ignore start
    if num != "3":
        path = path + num

    if tree.left == None:
        finalDict[tree.right] = path
        #print finalDict
    elif tree.right == None:
        finalDict[tree.left] = path
        #print finalDict
    else:
        # Just need to be consistent with 0 and 1
        printPaths(tree.left, path, "0")
        printPaths(tree.right, path, "1")

# Take a dictionary of the number of times
# a number appears in a string and create a
# corresponding dictionary of codes for each letter
#
# PARAM : dist, dictionary of letters and number of appearances
# SIDEEFFECT : put the codes into the global finalDict dictionary
def huffman(dist):
    
    # Get two copies of the keys of the dictionary
    # will be destoying the dictionary (dist)
    keys = cleanKeys = dist.keys()

    # For constructing the final dictionary
    finalKeys = dist.keys()

    # Array of tree objects
    tree = [] 

    # Take every element and make it a TreeObj
    sideSwitch = True 
    while len(dist) != 0:
        # Get the item and key
        item = dist.pop(keys[len(dist) - 1])
        key = cleanKeys.pop()

        # Create a node 
        node = TreeObj(None, key, item) if sideSwitch else TreeObj(key, None, item)

        # Switch sides
        sideSwitch = not sideSwitch

        # Add to tree list
        tree.append(node)

    # value of tree object node
    value = 0

    # Combine all the elements in a tree 
    while len(tree) != 1:
        # Get the lowest two nodes
        minVal = float("inf")
        for i in range(len(tree)):
            #print tree[i].value
            if tree[i].value <= minVal:
                minVal = tree[i].value
                minPos = i

        #print minPos
        node1 = tree.pop(minPos)
    
        # Probably a better way than running this twice
        minVal = float("inf")
        for i in range(len(tree)):
            if tree[i].value <= minVal:
                minVal = tree[i].value
                minPos = i

        #print minPos
        node2 = tree.pop(minPos)

        # Combine these two nodes back onto the tree list
        # as a new node 
        node = TreeObj(node1, node2, node1.value + node2.value)       

        # Add back to list
        tree.append(node)

    # Init finalDict with each letter being a key and 
    # the item being an empty string
    for key in finalKeys:
        finalDict[key] = ""
        #print key

    #print finalDict
    #quit()

    # Now we have the proper tree structure in tree
    # just print out all the nodes 
    printPaths(tree[0], "", "3")

    # nothing to return, ans in global dictionary
    return 

def main():

    # Original String
    original = "ABRACADABRA"
    #original = "bannanas and pajamas"
    print "Initial String: ", original

    # original length
    originalLen = len(original)

    # Get count of letters in string
    dist = Counter(original)
    #print "Number distribution is: ", dist

    # Huff it, ans stored in global dictionary 
    huffman(dist)

    # Print out codes from global dictionary
    print "Codes are: "
    for key, value in finalDict.iteritems():
        print key, value

    # All done so encode the original message
    finalString = ""
    for letter in original:
        finalString += finalDict[letter]
 
    print "Final encoded string: ", finalString
    compressedBits = len(finalString)

    # Flip the dictionary of codes from letter -> code to
    # code -> letter. Allows linear lookup
    codeDict = dict(zip(finalDict.values(), finalDict.keys()))

    # Do a simple decode to get original string
    decodedString = ""
    chopItPos = 1
    chunk = ""
    while len(finalString) != 0:
        # Get the possible code
        chunk = finalString[0:chopItPos]

        # Is the code in the dictionary
        if(chunk in codeDict):
            # Substring the remaining string
            finalString = finalString[chopItPos:len(finalString)]

            # Add string value of code to decode String
            decodedString += codeDict[chunk]

            # Reset 
            chunk = ""
            chopItPos = 1
        else:
            # Look at next code
            chopItPos += 1 

    print "Decoded string: ", decodedString

    # Stats
    originalBits = originalLen * 8
    perCom = (compressedBits / float(originalBits)) * 100
    perSav = 100 - perCom 

    print "Compression: ", perCom, "%" 
    print "Size Reduction: ", perSav, "%" 

    # pg out
    return 

# Run main if started from shell
if __name__ == '__main__':
    main()
