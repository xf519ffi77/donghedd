$$
\sum_{i = l} ^ {r} \sum_{j = i} ^ {r} (a_i \oplus b_j) = \sum_{i = l} ^ {r} \sum_{j = i} ^ {n} (a_i \oplus b_j) - \sum_{i = l} ^ {r} \sum_{j = r + 1} ^ {n} (a_i \oplus b_j)
$$
**拆位法**，**贡献法**
预处理出a, b数组每一位上的前缀和（1或0的个数）$sa_{i, j}$, $sb_{i, j}$记录前i个数中第j位上1的个数
记录b数组每一个后缀的答案（按位计算贡献）$s_i$记录后i个数的总贡献
$\sum_{i = l} ^ {r} \sum_{j = i} ^ {n} (a_i \oplus b_j)$ = $s_l - s_{r + 1}$
$\sum_{i = l} ^ {r} \sum_{j = r + 1} ^ {n} (a_i \oplus b_j)$ 根据$[l, r]$区间中1和0的个数，分别乘以$[r + 1, n]$区间中0和1的个数，最后对每一位乘以一个这一位对应的二进制值（按位计算贡献）