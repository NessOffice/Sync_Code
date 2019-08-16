len_num = int(input())
num_str = input()
len_1 = len_num // 2
len_2 = len_1
if(len_num & 1):
	len_2 += 1
flag = 0
ans = 0
while(True):
	if(num_str[len_1] != '0'):
		num1 = int(num_str[:len_1]) + int(num_str[len_1:len_num])
		ans = num1
		flag = 1
	if(len_2 < len_num and num_str[len_2] != '0'):
		num2 = int(num_str[:len_2]) + int(num_str[len_2:len_num])
		if(flag):
			if(ans > num2):
				ans = num2
		else:
			ans = num2
		flag = 1
	len_1 -= 1
	len_2 += 1
	if(flag):
		break
print(ans)