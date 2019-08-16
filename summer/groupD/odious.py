# def odious(num):
# 	if(num == 0):
# 		return 0
# 	if(num == 1):
# 		return 1
# 	two = 1
# 	while(two*2 < num):
# 		two <<= 1
# 	num_new = num - two - 1
# 	two <<= 1

# 	if(num_new == 0): # if num == 9, 17, ...
# 		return two
# 	two_new = 1
# 	while(two_new <= num_new):
# 		two_new <<= 1
# 	odious_new = 0
# 	if(two_new):
# 		odious_new = odious(num_new - (two_new // 2) + 1)
# 	return two + two_new + odious_new

def odious(num):
	ans = 2 * (num - 1)
	ones = 0
	while(num > 0):
		if(num & 1):
			ones += 1
		num >>= 1
	if(ones & 1 == 0):
		ans += 1
	return ans

def str_to_hex(s):
	ans = 0
	for ch in s:
		ans *= 16
		if(ord('a') <= ord(ch) <= ord('f')):
			ans += (ord(ch) - ord('a') + 10)
		else:
			ans += (ord(ch) - ord('0'))
	return ans

# print(str(hex(odious(str_to_hex(input()))))[2:])
print(str(hex(odious(str_to_hex('a'))))[2:])