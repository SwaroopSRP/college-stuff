def getTemp(a, b, c, t) -> int:
    return a * t ** 2 + b * t + c

with open("inputs_multiple.txt", "r") as f:
    for line in f:
        a, b, c, t = map(float, line.strip().split())
        
        print(f"a={a}, b={b}, c={c}, t={t} -> T={getTemp(a, b, c, t):.2f}°C")
