import random
with open('debug_closest_input.txt', 'w') as f:
	f.write('1000\n')
	for i in range(1000):
		n = random.randint(2, 20)
		f.write('{n}\n'.format(n = n))
		for j in range(n):
			x = random.randint(-100, 100)
			y = random.randint(-100, 100)
			f.write('{x} {y}\n'.format(x = x, y = y))