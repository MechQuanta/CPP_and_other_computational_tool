import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def plot_transformed_csv(file_path):
    """
    Reads a CSV file, applies absolute value and natural logarithm to numerical columns,
    and then plots the transformed data.

    Args:
        file_path (str): The path to the CSV file.
    """
    try:
        # 1. Read the CSV file into a pandas DataFrame
        df = pd.read_csv(file_path)
        print(f"Original DataFrame head:\n{df.head()}\n")

        # Create a new DataFrame to store transformed data
        df_transformed = pd.DataFrame()
        transformed_columns = []

        # 2. Iterate through columns, convert to numeric if possible,
        #    take absolute value, then take log.
        for col in df.columns:
            try:
                # Attempt to convert column to numeric, coercing errors to NaN
                numeric_col = pd.to_numeric(df[col], errors='coerce')

                # Drop NaN values that resulted from coercion (non-numeric entries)
                numeric_col = numeric_col.dropna()

                if not numeric_col.empty:
                    # Take absolute value
                    abs_values = numeric_col.abs()

                    # Take natural logarithm. Add a small epsilon to avoid log(0) if any value is 0.
                    # np.log handles positive values. For values that are zero, we add a small number.
                    # For values that are negative, abs() already handled them.
                    log_values = np.log(abs_values.replace(0, np.finfo(float).eps))
                    df_transformed[col] = log_values
                    transformed_columns.append(col)
                else:
                    print(f"Skipping column '{col}' as it contains no convertible numeric data.")

            except Exception as e:
                print(f"Could not process column '{col}': {e}. Skipping.")

        if df_transformed.empty:
            print("No numerical columns were found or successfully transformed for plotting.")
            return

        print(f"Transformed DataFrame head:\n{df_transformed.head()}\n")

        # 3. Plot the transformed data
        plt.figure(figsize=(12, 7))

 
        plt.plot(df_transformed['Time (sec)'], df_transformed['Boiler Temp (C)'], label=col)

        plt.title('Log-Transformed Absolute Values of CSV Data')
        plt.xlabel('Time')
        plt.ylabel('Log(Absolute Value boiler)')
        plt.legend(title='Columns')
        plt.grid(True)
        plt.tight_layout()
        plt.show()

    except FileNotFoundError:
        print(f"Error: The file '{file_path}' was not found.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

# Specify the path to your uploaded CSV file
file_path = 'niggassimulationgroup1all.csv'

# Call the function to process and plot the data
plot_transformed_csv(file_path)
