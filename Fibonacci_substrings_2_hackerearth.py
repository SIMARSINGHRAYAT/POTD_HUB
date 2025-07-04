import sys

fib = [1, 1]
while fib[-1] <= 10**18:
    fib.append(fib[-1] + fib[-2])
fib.pop()

def total_length(k):
    if k == 0:
        return 0
    total = 0
    m = 1
    while m < len(fib) and fib[m] <= k:
        low = fib[m]
        high = min(k, fib[m+1]-1)
        count = high - low + 1
        total += count * m
        m += 1
    return total

def find_number(X):
    if X == 0:
        return (0, 0)
    low_n = 0
    high_n = 10**18
    n0 = None
    while low_n <= high_n:
        mid = (low_n + high_n) // 2
        T_mid = total_length(mid)
        if T_mid < X:
            low_n = mid + 1
        else:
            n0 = mid
            high_n = mid - 1
    T_prev = total_length(n0 - 1)
    offset = X - T_prev
    return (n0, offset)

def get_representation(n):
    if n == 0:
        return "0"
    fibs = []
    a, b = 1, 1
    while a <= n:
        fibs.append(a)
        a, b = b, a + b
    fibs.reverse()
    s = []
    for f in fibs:
        if n >= f:
            s.append('1')
            n -= f
        else:
            s.append('0')
    s = ''.join(s).lstrip('0')
    if s == '':
        return '0'
    return s

def count_patterns_in_string(s):
    c00, c01, c10, c11 = 0, 0, 0, 0
    for i in range(len(s) - 1):
        substr = s[i:i+2]
        if substr == "00":
            c00 += 1
        elif substr == "01":
            c01 += 1
        elif substr == "10":
            c10 += 1
        elif substr == "11":
            c11 += 1
    return (c00, c01, c10, c11)

def count_in_block_iter(m, bound_str):
    bound_digits = [int(c) for c in bound_str]
    dp = [[[ [0]*5 for _ in range(2) ] for __ in range(2) ] for i in range(m+1)]
    first_digit_val = 1
    tight0 = 1 if (first_digit_val == bound_digits[0]) else 0
    dp[1][tight0][1] = [0, 0, 0, 0, 1]
    for i in range(1, m):
        for tight in range(2):
            for last in range(2):
                state = dp[i][tight][last]
                cnt_state = state[4]
                if cnt_state == 0:
                    continue
                for next_d in [0, 1]:
                    if last == 1 and next_d == 1:
                        continue
                    if tight:
                        if next_d > bound_digits[i]:
                            continue
                        new_tight = 1 if (next_d == bound_digits[i]) else 0
                    else:
                        new_tight = 0
                    add00 = 1 if (last == 0 and next_d == 0) else 0
                    add01 = 1 if (last == 0 and next_d == 1) else 0
                    add10 = 1 if (last == 1 and next_d == 0) else 0
                    add11 = 1 if (last == 1 and next_d == 1) else 0
                    new_c00 = state[0] + add00 * cnt_state
                    new_c01 = state[1] + add01 * cnt_state
                    new_c10 = state[2] + add10 * cnt_state
                    new_c11 = state[3] + add11 * cnt_state
                    new_count = cnt_state
                    target = dp[i+1][new_tight][next_d]
                    target[0] += new_c00
                    target[1] += new_c01
                    target[2] += new_c10
                    target[3] += new_c11
                    target[4] += new_count
    total_c00 = 0
    total_c01 = 0
    total_c10 = 0
    total_c11 = 0
    total_count = 0
    count_last0 = 0
    count_last1 = 0
    for tight in range(2):
        for last in range(2):
            state = dp[m][tight][last]
            cnt_here = state[4]
            total_c00 += state[0]
            total_c01 += state[1]
            total_c10 += state[2]
            total_c11 += state[3]
            total_count += cnt_here
            if last == 0:
                count_last0 += cnt_here
            else:
                count_last1 += cnt_here
    return (total_c00, total_c01, total_c10, total_c11, total_count, count_last0, count_last1)

precom_block = {}
for m_val in range(1, len(fib)):
    if fib[m_val] > 10**18:
        break
    total_count_block = fib[m_val-1]
    last_num_in_block = fib[m_val] + total_count_block - 1
    last_rep_str = get_representation(last_num_in_block)
    res = count_in_block_iter(m_val, last_rep_str)
    precom_block[m_val] = {
        'within': (res[0], res[1], res[2], res[3]),
        'count_last0': res[5],
        'count_last1': res[6]
    }

def F_ab(X):
    if X == 0:
        return (0, 0, 0, 0)
    n0, offset0 = find_number(X)
    T_prev = total_length(n0 - 1)
    L0 = X - T_prev
    c00, c01, c10, c11 = 0, 0, 0, 0
    boundaries_01, boundaries_11 = 0, 0
    A = n0 - 1
    if A > 0:
        m = 1
        while m < len(fib) and fib[m] <= A:
            low_m = fib[m]
            high_m = min(A, fib[m+1]-1)
            count_in_seg = high_m - low_m + 1
            total_in_block_val = fib[m-1]
            if count_in_seg == total_in_block_val:
                block_data = precom_block.get(m)
                if block_data is None:
                    last_num_in_seg = fib[m] + count_in_seg - 1
                    last_rep_str_seg = get_representation(last_num_in_seg)
                    res_seg = count_in_block_iter(m, last_rep_str_seg)
                    block_data_seg = {
                        'within': (res_seg[0], res_seg[1], res_seg[2], res_seg[3]),
                        'count_last0': res_seg[5],
                        'count_last1': res_seg[6]
                    }
                else:
                    block_data_seg = block_data
                w = block_data_seg['within']
                c00w, c01w, c10w, c11w = w
                c0b = block_data_seg['count_last0']
                c1b = block_data_seg['count_last1']
            else:
                last_num_in_seg = high_m
                last_rep_str_seg = get_representation(last_num_in_seg)
                res_seg = count_in_block_iter(m, last_rep_str_seg)
                c00w, c01w, c10w, c11w = res_seg[0], res_seg[1], res_seg[2], res_seg[3]
                c0b = res_seg[5]
                c1b = res_seg[6]
            c00 += c00w
            c01 += c01w
            c10 += c10w
            c11 += c11w
            boundaries_01 += c0b
            boundaries_11 += c1b
            m += 1
    c01 += boundaries_01
    c11 += boundaries_11
    rep_n0 = get_representation(n0)
    prefix = rep_n0[:L0]
    if len(prefix) > 1:
        p00, p01, p10, p11 = count_patterns_in_string(prefix)
        c00 += p00
        c01 += p01
        c10 += p10
        c11 += p11
    return (c00, c01, c10, c11)

def get_char_at(i):
    n, offset = find_number(i)
    rep = get_representation(n)
    return rep[offset-1]

def main():
    data = sys.stdin.readline().split()
    L = int(data[0])
    R = int(data[1])
    resR = F_ab(R)
    if L-1 == 0:
        resL = (0,0,0,0)
    else:
        resL = F_ab(L-1)
    c00 = resR[0] - resL[0]
    c01 = resR[1] - resL[1]
    c10 = resR[2] - resL[2]
    c11 = resR[3] - resL[3]
    if L >= 2:
        char1 = get_char_at(L-1)
        char2 = get_char_at(L)
        pattern = char1 + char2
        if pattern == "00":
            c00 -= 1
        elif pattern == "01":
            c01 -= 1
        elif pattern == "10":
            c10 -= 1
        elif pattern == "11":
            c11 -= 1
    print(f"{c00} {c01} {c10} {c11}")

if __name__ == "__main__":
    main()
