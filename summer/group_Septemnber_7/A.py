def gcd(a, b):
	if(b == 0):
		return a
	return gcd(b, a % b)
def lcm(a, b):
	return a * b // gcd(a, b)

x = 0
y = 0
def exgcd(a, b):
	global x
	global y
	if(b == 0):
		x = 1
		y = 0
		return a
	r = exgcd(b, a % b)
	temp = y
	y = x - (a // b) * y
	x = temp
	return r

a = [0]
b = [0]
def excrt(k):
	M = a[1]
	ans = b[1] % a[1]
	for i in range(2, k+1):
		d = exgcd(M, a[i])
		c = (b[i] - ans % a[i] + a[i]) % a[i]
		if(c % d != 0):
			return -1

		t = x
		t = t * (c // d) % a[i]
		ans += (t * M)
		M = lcm(M, a[i])
		ans = (ans % M + M) % M
	return (ans % M + M) % M

MAXN = 1e16
fibo = [1, 1]
def init_fibo():
	maxfibo = 2
	while(1):
		fibo.append(fibo[maxfibo - 1] + fibo[maxfibo - 2])
		if(fibo[maxfibo] > MAXN):
			return
		maxfibo += 1

init_fibo()
k = int(input())
for rnd in range(k):
	ab_str = input()
	ab_str = ab_str.split(' ')
	ab_str = [int(each) for each in ab_str]
	a.append(ab_str[0])
	b.append(ab_str[1])
n = excrt(k)
# print(n)
# print(fibo)
if(n == -1):
	print("Tankernb!")
else:
	flag = False
	for each in fibo:
		if(each == n):
			flag = True
	if(flag):
		print("Lbnb!")
	else:
		print("Zgxnb!")