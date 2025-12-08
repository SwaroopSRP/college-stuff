# Given a time in 12-hour AM/PM format, convert it to military (24-hour) time

t_12 = input("Emter 12 hrs time (hh:mm:ss<AM/PM>): ").strip().split(':')

h = int(t_12[0])
m = int(t_12[1])
s = ""
p = ""
for ch in t_12[2]:
    if ch.isdigit():
        s += ch
    else:
        p = ch
        break
s = int(s)

if p.lower() == 'a' or p.lower() == 'am':
    if h == 12:
        h = 0
    elif h < 12:
        h = h

elif p.lower() == 'p' or p.lower() == 'pm':
    if h != 12:
        h += 12
else:
    print("Invalid time format!")
    exit()

print(f"Military time: {h:02}:{m:02}:{s:02}")
