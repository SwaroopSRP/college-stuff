with open("inputs_single.txt", "r") as f:
    lines = f.readlines()

a = float(lines[0])
b = float(lines[1])
c = float(lines[2])
t = float(lines[3])

def getTemp(a, b, c, t) -> int:
    return a * t ** 2 + b * t + c

print(f"Predicted temperature at t={t}: {getTemp(a, b, c, t):.2f}°C")
