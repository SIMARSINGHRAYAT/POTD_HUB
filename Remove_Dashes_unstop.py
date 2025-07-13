def process_string(n, s):
    stack = []
    for ch in s:
        if ch == '_':
            if stack:
                stack.pop()  # Remove closest letter to the left
            else:
                continue  # Ignore if nothing to remove
        else:
            stack.append(ch)  # Keep valid letter
    return ''.join(stack) if stack else "-1"

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    n = int(data[0])
    s = data[1]
    print(process_string(n, s))

if __name__ == "__main__":
    main()
