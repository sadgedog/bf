import matplotlib.pyplot as plt

x = [115, 521, 1518, 2676, 11594]
y = [0.276, 0.020, 0.046, 0.690, 82.096]
yy = [0.105, 0.214, 0.248, 0.321, 0.853]

plt.plot(x, y, label="Interpreter")
plt.plot(x, yy, label="C translated")
plt.xlabel("Bytes")
plt.ylabel("Second")
plt.legend()
plt.show()
