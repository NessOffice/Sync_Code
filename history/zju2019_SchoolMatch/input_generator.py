# with open("debug_I_input.txt", "w") as f:
# 	f.write("20\n")
# 	for i in range(2, 22):
# 		f.write("{i} 0\n".format(i = i))
# 		for j in range(1, i+1):
# 			f.write('{j}\n'.format(j = j))

cnt = 0
for i in range(1, 31):
	print(i)
for i in range(2, 31):
	print('1 {i}'.format(i = i))
	cnt += 1
print(cnt)