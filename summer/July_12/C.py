T = int(input())
while(T > 0):
	num_list = input().split(' ')
	ans = 0
	n1 = int(num_list[0]) % 2
	n2 = int(num_list[1]) % 3
	n3 = int(num_list[2]) % 4
	n4 = int(num_list[3]) % 5
	ans = n1^n2^n3^n4
	if(ans == 0):
		ans = 1
	else:
		ans = 0
	print(ans)
	T -= 1