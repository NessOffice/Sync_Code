# with open("debug_I_input.txt", "w") as f:
# 	f.write("20\n")
# 	for i in range(2, 22):
# 		f.write("{i} 0\n".format(i = i))
# 		for j in range(1, i+1):
# 			f.write('{j}\n'.format(j = j))

for i in range(1, 10):
	for j in range(i+1, 10):
		print('{i} {j}'.format(i = i, j = j))