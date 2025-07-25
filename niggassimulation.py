import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Load Excel sheet
file_path = "niggassimulationgroup1all.xlsx"
df = pd.read_excel(file_path, sheet_name="Sheet1")

# Optional: Remove unnamed columns (like index columns)
df = df.loc[:, ~df.columns.str.contains('^Unnamed')]

# Print column names to verify exact names
print("Columns:", df.columns)

# Define small epsilon to avoid log(0)
epsilon = 1e-9

# Take absolute value of all numeric columns
df = df.abs()

# Apply log10 to all numeric columns (replacing in-place)
for col in df.select_dtypes(include=[np.number]).columns:
    df[col] = np.log10(df[col] + epsilon)

# Optional: Preview the transformed data
print(df.head())

# ✅ Plot with matplotlib
# Replace with actual column names from your DataFrame
time_col = 'Time (s)'  # or use df.columns[0] to inspect dynamically
temp_col = 'Boiler Temp (C)'  # adjust based on print(df.columns)

# Create plot
plt.figure(figsize=(10, 6))
plt.plot(df[time_col], df[temp_col], marker='o', linestyle='-')
plt.title('Log(Time) vs Log(Boiler Temperature)')
plt.xlabel('Log Time (s)')
plt.ylabel('Log Boiler Temp (C)')
plt.grid(True)
plt.tight_layout()
plt.savefig("log_boiler_vs_time.png")
plt.show()

