def sieve(n):
    primos = [True] * (n + 1)
    primos[0 : 2] = [False, False]
    res = []
    
    for i in range(2, n + 1):
        if primos[i]:
            res.append(i)
            for j in range(i, n + 1, i):
                primos[j] = False
    
    return res

def main():
    t = 20
    primes = sieve(1000)
    while t:
        n = int(input())
        ans = 1
        for prime in primes:
            if ans * prime <= n:
                ans = ans * prime
            else:
                break
        print(ans)
        t -= 1

if __name__ == "__main__":
    main()
