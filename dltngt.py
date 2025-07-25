import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def plot_positive_values_vs_time(file_path, time_column_name='Time (sec)', columns_to_plot=None):
    """
    Reads a CSV file, replaces all negative numerical values with NaN,
    and then plots specified numerical columns against a specified time column.

    Args:
        file_path (str): The path to the CSV file.
        time_column_name (str): The name of the column representing time.
        columns_to_plot (list): A list of column names (strings) to plot.
                                 If None or empty, all valid numerical columns will be plotted.
    """
    try:
        # 1. Load the CSV file into a pandas DataFrame
        df = pd.read_csv(file_path)
        print(f"Original DataFrame head:\n{df.head()}\n")

        # 2. Identify the 'time (s)' column
        if time_column_name not in df.columns:
            print(f"Error: The '{time_column_name}' column was not found in the file.")
            print(f"Available columns are: {df.columns.tolist()}")
            return

        time_data = pd.to_numeric(df[time_column_name], errors='coerce').dropna()
        if time_data.empty:
            print(f"Error: The '{time_column_name}' column contains no valid numeric data.")
            return

        # Create a new DataFrame for plotting, copying the original
        df_for_plot = df.copy()

        # 3. For all other numerical columns, replace negative values with NaN
        for col in df_for_plot.columns:
            if col != time_column_name:
                try:
                    # Convert to numeric, coercing errors, then replace negative values
                    df_for_plot[col] = pd.to_numeric(df_for_plot[col], errors='coerce')
                    df_for_plot.loc[df_for_plot[col] < 0, col] = np.nan
                except Exception as e:
                    print(f"Could not process column '{col}': {e}. Skipping numerical conversion for this column.")

        # Drop rows where the time_data is NaN as we can't plot against a missing time
        df_for_plot = df_for_plot.dropna(subset=[time_column_name])

        print(f"DataFrame head after replacing negative values with NaN:\n{df_for_plot.head()}\n")

        # Determine which columns to plot
        if columns_to_plot is None or not columns_to_plot:
            # If no specific columns are provided, plot all numerical columns except the time column
            cols_to_plot_final = [col for col in df_for_plot.columns if col != time_column_name and pd.to_numeric(df_for_plot[col], errors='coerce').dropna().empty is False]
            print("No specific columns provided. Attempting to plot all valid numerical columns.")
        else:
            # Use the specified columns
            cols_to_plot_final = [col for col in columns_to_plot if col in df_for_plot.columns and pd.to_numeric(df_for_plot[col], errors='coerce').dropna().empty is False]
            if not cols_to_plot_final:
                print(f"None of the specified columns ({columns_to_plot}) are valid or contain positive numeric data to plot.")
                print(f"Available numerical columns after processing: {[col for col in df_for_plot.columns if col != time_column_name and pd.to_numeric(df_for_plot[col], errors='coerce').dropna().empty is False]}")
                return

        if not cols_to_plot_final:
            print("No suitable numerical columns found to plot against time after removing negative values.")
            return

        # 4. Plot each of the specified columns against the 'Time (sec)' column individually
        for col_name in cols_to_plot_final:
            plt.figure(figsize=(10, 6))
            plt.scatter(df_for_plot[time_column_name], df_for_plot[col_name], label=col_name,s=5)
            plt.title(f'{col_name} vs. {time_column_name} (Positive Values Only)')
            plt.xlabel(time_column_name)
            plt.ylabel(col_name)
            plt.legend()
            plt.grid(True)
            plt.tight_layout()
            plt.show()

    except FileNotFoundError:
        print(f"Error: The file '{file_path}' was not found.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

# Specify the path to your CSV file
file_path = 'niggassimulationgroup1all.csv'

# Example usage:
# To plot 'Boiler Temp (C)' and 'Turbine In Temp (C)' individually
plot_positive_values_vs_time(file_path, columns_to_plot=['Voltage (Volts)'])

# To plot 'Boiler Pres (psig)' only
# plot_positive_values_vs_time(file_path, columns_to_plot=['Boiler Pres (psig)'])

# To plot all numerical columns (excluding time and non-numeric/empty columns)
# plot_positive_values_vs_time(file_path)
