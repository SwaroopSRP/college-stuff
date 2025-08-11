def getTemp(a, b, c, t) -> int:
    return a * t ** 2 + b * t + c

if __name__ == "__main__":
    a = float(input("Enter coefficient a: "))
    b = float(input("Enter coefficient b: "))
    c = float(input("Enter coefficient c: "))
    t = float(input("Enter time t (hour/day): "))
    print(f"Predicted temperature at t={t}: {getTemp(a, b, c, t):.2f}°C")
