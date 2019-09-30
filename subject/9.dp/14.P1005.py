maxn = 85
dp = [[0 for i in range(maxn)] for i in range(maxn)]
nm_str = input()
nm_str = nm_str.split(' ')
n = int(nm_str[0])
m = int(nm_str[1])

ans_total = 0
for rnd in range(n):
	num = input()
	num = [0] + num.split(' ') + [0]
	num = [int(each) for each in num]

	ans_onerow = 0
	dp = [[0 for i in range(maxn)] for i in range(maxn)]
	for i in range(1, m+1):
		for j in range(m, i-1, -1):
			dp[i][j] = max(dp[i][j], num[i-1]*(1<<(m-1-j+i)) + dp[i-1][j])
			dp[i][j] = max(dp[i][j], num[j+1]*(1<<(m-1-j+i)) + dp[i][j+1])
	for i in range(1, m+1):
		ans_onerow = max(ans_onerow, dp[i][i] + (1<<m)*num[i])
	ans_total += ans_onerow
print(ans_total)
