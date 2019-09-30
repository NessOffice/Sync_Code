maxn = 9 # nine primes to ensure the algorithm
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]
def qpow(base, expo, MOD):
    ans = 1
    while(expo != 0):
        if(expo & 1):
            ans = ans * base % MOD
        expo >>= 1
        base = base * base % MOD
    return ans
def miller_rabin(num):
    if(num == 1):
    	return "N"
    for i in range(maxn):
        if(num == primes[i]):
        	return "Y"
        if(num < primes[i]):
        	return "N"
        expo = num-1
        res = qpow(primes[i], expo, num)
        if(res != 1):
        	return "N"
        while(res == 1 and (expo & 1) == 0):
            expo >>= 1
            res = qpow(primes[i], expo, num)
            if(res != 1 and res != num-1):
            	return "N"
    return "Y"
n = 0
while True:
    try:
        n = int(input())
        print(miller_rabin(n))
    except:
        break
