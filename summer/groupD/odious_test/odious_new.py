def odious(num):
	if(num == 0):
		return 0
	if(num == 1):
		return 1
	two = 1
	while(two*2 < num):
		two <<= 1
	num_new = num - two - 1
	two <<= 1
	
	if(num_new == 0): # if num == 9, 17, ...
		return two
	two_new = 1
	while(two_new <= num_new):
		two_new <<= 1
	odious_new = 0
	if(two_new):
		odious_new = odious(num_new - (two_new // 2) + 1)
	return two + two_new + odious_new

# def odious(num):
# 	if(num == 1):
# 		return 1
# 	ans = 2 * (num - 1)
# 	ones = 0
# 	num = ans
# 	while(num > 0):
# 		if(num & 1):
# 			ones += 1
# 		num >>= 1
# 	if((ones & 1) == 0):
# 		ans += 1
# 	return ans

def str_to_hex(s):
	ans = 0
	for ch in s:
		ans *= 16
		if(ord('a') <= ord(ch) <= ord('f')):
			ans += (ord(ch) - ord('a') + 10)
		else:
			ans += (ord(ch) - ord('0'))
	return ans

# print(str(hex(odious(str_to_hex('aaa'))))[2:])

print(odious(5))
# f_out = open('odious_out.txt', 'w')
# with open('odious_in.txt', 'r') as f:
# 	T = int(f.readline())
# 	while True:
# 		n = f.readline()
# 		if not n:
# 			break
# 		n = n[:-1]
# 		f_out.write(str(hex(odious(str_to_hex(n)+1)))[2:] + '\n')
		# print(str(hex(odious(str_to_hex(n))))[2:])
# f_out = open('odious_out.txt', 'w')
# for i in range(100):
# 	filename = 'odious_in' + str(i) + '.txt'
# 	with open(filename) as f:
# 		f_out.write((str(hex(odious(str_to_hex(str(f.read())[:-1]))))[2:]) + '\n')
# f_out.close()