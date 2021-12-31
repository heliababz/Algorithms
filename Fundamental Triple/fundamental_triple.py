import random

def fundamental_triple_generator():
    #generate two random numbers one odd one even between 1 and 10
    a = random.randrange(2, 10, 2)
    b = random.randrange(1, 9, 2)

    #they have to be coprime
    while(gcd(a,b) != 1):
        b = random.randrange(1, 99, 2)


    #fundamental triple (a2 − b2, 2ab, a2 + b2)

    a2 = a*a
    b2 = b*b
    return [abs(a2-b2), 2*a*b, a2+b2]



def gcd(p,q):
# Create the gcd of two positive integers.
    while q != 0:
        p, q = q, p%q
    return p


print(fundamental_triple_generator())
