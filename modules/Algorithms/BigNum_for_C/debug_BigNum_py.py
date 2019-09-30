import random
a = []
b = []
with open('debug_input.txt', 'r') as f:
	for line in f:
		line = line.split(' ')
		a.append(int(line[0]))
		b.append(int(line[1]))

add = []
subtract = []
multiply = []
div1 = []
r1 = []
div2 = []
r2 = []
with open('debug_output_add_py.txt', 'w') as f:
	for i in range(len(a)):
		add.append(a[i] + b[i])
	for term in add:
		f.write(str(term) + '\n')

with open('debug_output_subtract_py.txt', 'w') as f:
	for i in range(len(a)):
		subtract.append(abs(a[i] - b[i]))
	for term in subtract:
		f.write(str(term) + '\n')

with open('debug_output_multiply_py.txt', 'w') as f:
	for i in range(len(a)):
		multiply.append(a[i] * b[i])
	for term in multiply:
		f.write(str(term) + '\n')

with open('debug_output_divide1_py.txt', 'w') as f:
	for i in range(len(a)):
		div1.append(a[i] // b[i])
		r1.append(a[i] % b[i])
	for i in range(len(div1)):
		f.write('{a}\n{b}\n'.format(a = div1[i], b = r1[i]))