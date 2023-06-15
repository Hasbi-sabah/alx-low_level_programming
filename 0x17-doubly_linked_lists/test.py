a = 999
while a > 900:
    b = 999
    while b > 900:
        s = str(a * b)
        if s[0] == s[-1] and s[1] == s[-2] and s[2] == s[-3]:
            print(s)
        b -= 1
    a -= 1
