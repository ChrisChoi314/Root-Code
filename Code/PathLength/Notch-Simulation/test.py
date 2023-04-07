import matplotlib.pyplot as plt

mypaths = []
hpaths = []

with open('test.txt', 'r') as f:
    for x in f:
        x = float(x.strip('\r\n'))
        if len(mypaths) == len(hpaths):
            mypaths.append(x)
        else:
            hpaths.append(x)

xs = []
ys = []

d = 0.00000005

for i, (a, b) in enumerate(zip(mypaths, hpaths)):
    if 0.20 < abs(a - b) / d < 0.25:
        print(i)

for a, b in zip(mypaths, hpaths):
    if abs(a - b) < d:
        xs.append(abs(a - b) / d)
        ys.append(0)

# plt.hist(xs, log=True)
plt.scatter(xs, ys)
plt.show()
plt.savefig('test.png', dpi=384)