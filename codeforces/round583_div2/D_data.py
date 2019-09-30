import random
n = random.randint(3, 10)
m = random.randint(3, 10)
print(n, m)
for i in range(n):
	ans = ""
	for j in range(m):
		grid = random.randint(0, 10)
		if(grid > 9):
			ans += "#"
		else:
			ans += "."
	
	print(ans)