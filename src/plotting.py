import matplotlib.pyplot as plt
import csv

x = []
y = []
with open("fourier_plot_data.csv", "r") as f:
    csv = csv.DictReader(f)
    frequencies, x, y = zip(
        *[
            (
                float(row["frequency"]),
                float(row["x"]),
                float(row["y"]),
            )
            for row in csv
        ]
    )

# plot x and y side by side in different plots, where 'frequency' is the x-axis
fig, (ax1, ax2) = plt.subplots(1, 2)
ax1.plot(frequencies, x)
ax2.plot(frequencies, y)
plt.show()
