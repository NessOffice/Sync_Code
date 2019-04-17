import random
with open('debug_input.txt', 'w') as f:
	for i in range(1000):
		a = random.randint(0, 10000000)
		b = random.randint(0, 10000000)
		f.write('{a} {b}\n'.format(a = a, b = b))