import math

def extended_gcd(p, q):
    old_r, r = p, q
    old_s, s = 1, 0
    old_t, t = 0, 1
    while r != 0:
        quotient = old_r // r
        old_r, r = r, old_r - quotient * r
        old_s, s = s, old_s - quotient * s
        old_t, t = t, old_t - quotient * t
    return (old_s, old_t)

def main():
    data = input().split()
    a = int(data[0])
    b = int(data[1])
    d = int(data[2])
    
    if d == 0:
        print(0)
        return
        
    if a == 0 and b == 0:
        print(1)
        return
        
    g = math.gcd(a, b)
    
    if d % g != 0:
        print(1)
        return
        
    a1 = a // g
    b1 = b // g
    d1 = d // g
    
    x0, y0 = extended_gcd(a1, b1)
    A = x0 * d1
    C = y0 * d1
    
    candidate_k = set()
    if b1 != 0:
        k1 = -A / b1
        candidate_k.add(math.floor(k1))
        candidate_k.add(math.ceil(k1))
    if a1 != 0:
        k2 = C / a1
        candidate_k.add(math.floor(k2))
        candidate_k.add(math.ceil(k2))
        
    min_ops = float('inf')
    for k in candidate_k:
        x_val = A + k * b1
        y_val = C - k * a1
        total_ops = abs(x_val) + abs(y_val)
        if total_ops < min_ops:
            min_ops = total_ops
            
    print(min_ops)

if __name__ == "__main__":
    main()
