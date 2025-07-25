import pandas as pd

def convert_xlsx_to_csv(xlsx_file_path, csv_file_path, sheet_name=0):
    """
    Converts a specified sheet from an XLSX file to a CSV file.

    Args:
        xlsx_file_path (str): The path to the input XLSX file.
        csv_file_path (str): The path where the output CSV file will be saved.
        sheet_name (str or int, optional): The name or index of the sheet to convert.
                                          Defaults to 0 (the first sheet).
    """
    try:
        # Read the specified sheet from the XLSX file into a pandas DataFrame
        df = pd.read_excel(xlsx_file_path, sheet_name=sheet_name)
        
        # Save the DataFrame to a CSV file
        df.to_csv(csv_file_path, index=False) # index=False prevents writing the DataFrame index as a column
        
        print(f"Successfully converted '{xlsx_file_path}' (sheet: {sheet_name}) to '{csv_file_path}'")
    except FileNotFoundError:
        print(f"Error: The file '{xlsx_file_path}' was not found.")
    except ValueError as ve:
        print(f"Error: Could not find sheet '{sheet_name}' in '{xlsx_file_path}'. {ve}")
    except Exception as e:
        print(f"An unexpected error occurred during conversion: {e}")

# Example usage:
# Replace 'your_input_file.xlsx' with the actual name of your XLSX file
# Replace 'your_output_file.csv' with the desired name for your CSV file
# If your XLSX has multiple sheets, you can specify the sheet name or index (e.g., sheet_name='Sheet2' or sheet_name=1)
input_xlsx_file = 'niggassimulationgroup1all.xlsx' # Assuming this is your original XLSX file
output_csv_file = 'niggassimulationgroup1all.csv' # Desired output CSV file name

# Call the function to perform the conversion
convert_xlsx_to_csv(input_xlsx_file, output_csv_file)
