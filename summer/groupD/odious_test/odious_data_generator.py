import random
T = 100
alphabeta = [str(i) for i in range(10)]
alphabeta_letter = [chr(ch) for ch in range(ord('a'), ord('f')+1)]
alphabeta += alphabeta_letter
# with open('odious_in.txt', 'w') as f:
# 	f.write("100\n")
# 	for i in range(T):
# 		if(i <= 20):
# 			f.write("{i}\n".format(i = str(hex(i+1)))[2:])
# 		else:
# 			len = random.randint(3, 15)
# 			f.write("a")
# 			for j in range(len-1):
# 				ch = random.randint(1, 15)
# 				f.write(alphabeta[ch])
# 			f.write("\n")
# for i in range(T):
# 	filename = 'odious_in' + str(i) + '.txt'
# 	with open(filename, 'w') as f:
# 		if(i <= 20):
# 			f.write("{i}\n".format(i = str(hex(i+1)))[2:])
# 		else:
# 			len = int(100 * (i / T))
# 			if(i >= 50):
# 				len = int(10000 * (i / T))
# 			f.write("a")
# 			for j in range(len-1):
# 				ch = random.randint(1, 15)
# 				f.write(alphabeta[ch])
# 			f.write("\n")

upper_bound = 2**55
with open('odious_edited_in.txt', "w") as f:
	f.write('100\n')
	for i in range(T):
		rnd = random.randint(1, upper_bound)
		if(i <= 50):
			rnd = i + 1
		f.write("{rnd}\n".format(rnd = rnd))