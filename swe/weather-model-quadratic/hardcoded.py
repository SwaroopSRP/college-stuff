def getTemp(a, b, c, t) -> int:
    return a * t ** 2 + b * t + c

if __name__ == "__main__":
    a = 0.5
    b = -3
    c = 28
    t = 5
    print(getTemp(a, b, c, t))

