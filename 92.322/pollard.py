#! /usr/bin/python
# Paul Geromini

import random
import fractions
import sys
import math

# Deterimine if a number is prime.
# PARAM : num, the number to be tested.
# RETURN : true if prime, false otherwise.
def isPrime(num):
    # number must be positive
    num = abs(num)

    # Quick checks
    if num == 0 or num == 1:
        return False

    # Number cannot be even since we already checked for it.
    # Furthermore, it cannot be 1 or 0 since we checked for that to.
    # Create a range of numbers then from 3 to the square root of the number
    # in question. Add 1 to offset the inveitable truncation that 
    # happens when converting from a float to an int. 
    for i in range(3, int(math.sqrt(num)) + 1):
        if num % i == 0:
            # Number is not prime
            return False
    
    # Number is prime
    return True 

# Find a factor of a number using the Pollard Rho method
# PARAM : num, the number to execute the pollard rho method on
# RETURN : a divisor of the number received
def pollardRho(num):
    # Check for a bunch of edge cases
    # If even, return 2 as factor
    if num % 2 == 0:
        return 2
    # If 1 return 1 so we do not get caught in infinte loop
    if num == 1:
        return 1
    # If 0 return 0 since it has no factors
    if num == 0:
        print "0 has no factors"
        return 0

    # Pollard rho does not work on prime numbers
    if isPrime(num):
        # Number is prime
        print "The number you entered is prime."
        return 1

    # Select random numbers in range 
    #x = y = random.randint(1, num - 1)
    #c = random.randint(1, num - 1)

    # Or just start with two 
    x = y = 2 
    c = 2

    # Start gcd at 1 since every int has a gcd of 1
    gcd = 1
    
    # Keep looping until a factor is found or we timeout
    timeout = 0
    while gcd == 1:             
        x = ((x * x) % num + c) % num
        y = ((y * y) % num + c) % num
        y = ((y * y) % num + c) % num
        gcd = fractions.gcd(abs(x-y),num)

        timeout = timeout + 1
        if timeout == 1000:
            print "Timeout reached"
            break;

    # Return what we found 
    #print timeout
    return gcd

# Find the modular multiplicative inverse 
# of some given numbers recursively
# PARAM : e, the value ^-1
# PARAM : modVal, the value to take mod from
# RETURN : the partially computed value
def modInv(e, modVal):
    # Base case, exponent all done
    if e == 0:
        return (modVal, 0, 1)
    else:
        # Return tuple 
        g, y, x = modInv(modVal % e, e)
        return (g, x - (modVal // e) * y, y)

# Helper function to facilitate recursive
# multiplicative inverse
# PARAM : e, the value ^-1
# PARAM : modVal, the value to take mod from
# RETURN : the modular inverse
def modHelp(e, modVal):
    g, x, y = modInv(e, modVal)
    if g != 1:
        return None
    else:
        return x % modVal

# Decrpyt the given message
# PARAM : msg, the msg to decrypt
# PARAM : pubKey, the public key
# PARAM : e, the exponent
# RETURN : the value of the decrypted method
def rsaDecrypt(encryptedMsg, pubKey, e):

    # Find the factors of the public key
    print "Public key ", pubKey 
    factor1 = pollardRho(pubKey)
    factor2 = pubKey / factor1
    print "Factors ", factor1, " ", factor2

    # Find totient
    tot = (factor1 - 1) * (factor2 - 1)
    print "Totitent is ", tot

    # Find modular multiplicative inverse
    #print modHelp(17, 3120)
    #quit()
 
    d = modHelp(e, tot)
    print "Mod inverse is ", d
    print "Encrypted msg is ", encryptedMsg

    # remainder algorithim
    return chineseRemainder(encryptedMsg, d, factor1, factor2)

# Use the chinese remainder algorithim to 
# take a large power efficiently (from wikipedia)
# PARAM : msg, encrypted message
# PARAM : d, the modular multiplicative inverse of e
# PARAM : prime1, first prime number
# PARAM : prime2, second prime number
# RETURN : the decrypted message
def chineseRemainder(msg, d, prime1, prime2):
    dp = d % (prime1 - 1)
    dq = d % (prime2 - 1)

    qinv = modHelp(prime2, prime1)

    m1 = pow(msg, dp) % prime1
    m2 = pow(msg, dq) % prime2
    h = qinv * (m1 - m2) % prime1

    m = m2 + (h * prime2)
    return m

# Encrypt the given msg
# PARAM : msg, the message to encrypt
# PARAM : n, part of public key (mod value)
# PARAM : e, part of public key (exponent)
# RETURN : the encrypted sequence
def rsaEncrypt(msg, n, e):
    encryptedSeq = pow(msg, e)
    encryptedSeq = encryptedSeq % n

    return encryptedSeq

# Main function
def main():

    # Initial msg string
    initialMsg = "100110000011101110011000001110111010101110001111"

    # Split string into two parts
    msgList = initialMsg[:len(initialMsg)/2], initialMsg[len(initialMsg)/2:]

    # init finalString, will contain final complete decrypted string
    finalString = ""

    # Loop through list to construct encrypted and decrypted msg
    for msg in msgList:

        # Convert binary string to a long int
        msg = long(msg, base = 2)
        print "base 10 # is", msg

        n = 79841071
        e = 31
    
        # Wiki test values 
        #n = 3233
        #e = 17
        #msg = 65

        # Encrypt this msg
        encryptedMsg = rsaEncrypt(msg, n ,e)
        print "Encrypted to ", encryptedMsg
        
        # Decrypt this encrypted msg 
        decryptMsg = rsaDecrypt(encryptedMsg, n, e)
        print "Base 10 decryption ", decryptMsg

        # convert back to base 2, convert to string
        # chop of 0b from string
        decryptMsg = str(bin(decryptMsg))[2:]
        print "Decrypted to ", decryptMsg 
        
        # Append to decrypted msg string
        finalString += decryptMsg

    # Final value
    print "\n\nDecrypted message is: ", finalString

    return

# Run main if started from shell
if __name__ == '__main__':
    main()

