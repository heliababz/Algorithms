import math

def eratosthenes(n):

  # Initialize the "grid" with nothing crossed out. (every index is set to True)
  could_be_prime = (n+1)*[True]

  # Get rid of 0 and 1 (not prime)
  could_be_prime[0] = False
  could_be_prime[1] = False

  # Lagest factor that needs to be crossed out
  max_factor = int(math.sqrt(n))

  # For all j up to max_factor, cross out
  for j in range(max_factor+1):
    # Only cross out multiples of j if j is prime
    if could_be_prime[j]: 
      crossout = j+j # The first thing we need to cross out is 2j
      while(crossout <= n):
        could_be_prime[crossout] = False
        crossout += j # Note: addition is much faster than multiplication

  # Clean up: put the remaining numbers in could_be_prime into a list of primes
  prime_list = [j for j in range(n+1) if could_be_prime[j]]

  return prime_list

primes = eratosthenes(100)
