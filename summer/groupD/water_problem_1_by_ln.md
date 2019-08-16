# 题目信息

题目名：enjoy your first blood

题目类型：贪心/二分

是否原创题：改编自CF1176D，略有原创

整体难度：1

（ZOJ应该支持if there're multiple answers print any of them吧QAQ）

# Description

[A water problem without any background]

Given an operation from array $\{ a \}$ to $\{ c \}$, and $\{ c \}$, calculate $\{ a \}$.

And here's the detailed description of the operation: 

1. duplicate $\{ a \}$ to $\{ c \}$,

2. for each $a_i$, calculate $b_i$ and append it to $\{ a \}$(the function from $a_i$ to $b_i$ is given below),

3. shuffle $\{ c \}$.

Convert $a_i$ to its binary representation $a_{i_n} a_{i_{n-1}} \cdots a_{i_0}$. Then $b_i$ is the sum of the square of length of consecutive '1's in $a_{i_n} a_{i_{n-1}} \cdots a_{i_0}$.

For instance, if $a_1 = 42 = (101011)_2$, then $b_1 = 1^2 + 1^2 + 2^2 = 6$.

# Input

On the first line the length $n$ of the array $\{ c \}$.

The next line contains n integers, of which the i-th is $c_{i-1}$.

$0 \leq n \leq 1e5$

$0 \leq c_i \leq 1e5$

# Output

Print the string $\{ s \} = \{ a_i mod 26 + 'a' \}$.

The answer may be not unique. So print any of them if there're multiple answers.

# Sample Input

20

5 4 3 11 7 1 17 4 14 5 5 22 9 5 9 9 14 11 11 2

# Sample Output

helloworld
