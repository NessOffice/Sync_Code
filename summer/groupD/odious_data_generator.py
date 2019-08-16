import random
T = 30
alphabeta = [str(i) for i in range(10)]
alphabeta_letter = [chr(ch) for ch in range(ord('a'), ord('f')+1)]
alphabeta += alphabeta_letter
for i in range(T):
	filename = 'odious_in' + str(i) + '.txt'
	with open(filename, 'w') as f:
		if(i <= 20):
			f.write("{i}\n".format(i = str(hex(i+1)))[2:])
		else:
			len = int(100 * (i / T))
			if(i >= 70):
				len = int(10000 * (i / T))
			if(i >= 90):
				len = int(100000 * (i / T))
			f.write("a")
			for j in range(len-1):
				ch = random.randint(1, 15)
				f.write(alphabeta[ch])
			f.write("\n")