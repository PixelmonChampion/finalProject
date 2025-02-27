# finalProject

__*Overview*__  

This is the Chada Tech Corner Grocery Tracker, it is a C++ program that reads grocery items from a text file (`CS210_Project_Three_Input_File.txt`), calculates their purchase frequency, and provides a user-friendly interface to search, display, and visualize the data. This program also automatically creates a backup file (`frequency.dat`) to store the frequency data for future reference.  

__*Features*__ 
- Reads purchase data from CS210_Project_Three_Input_File.txt.  
- Stores item counts in a hashmap (`unordered_map`) for fast access.  
- Creates a backup file (`frequency.dat`) to save item frequencies.  
- Provides a menu with 4 options:  
  - (1) Search for an item  
  - (2) Display all item frequencies  
  - (3) Display a histogram of item purchases  
  - (4) Exit the program  
- Handles missing input files gracefully with error messages.  
- Validates user input to prevent crashes.
  
__*Functionality*__  

My program initializes by reading data from CS210_Project_Three_Input_File.txt and stores item frequencies in an unordered_map. If the file is missing, the program displays an error message and exits. At startup, the program also generates a backup file called frequency.dat, ensuring data integrity.
The user is presented with a menu that allows them to search for an item, display all item frequencies, or generate a histogram. If an invalid input is entered, the program prompts the user to enter a valid choice.

__*Questions for my Instructor*__ 

The **Chada Grocery Tracker** aimed to **analyze grocery sales data** by tracking the frequency of purchased items. It read data from `CS210_Project_Three_Input_File.txt`, stored item counts in an `unordered_map` for **efficient lookups**, and provided a user-friendly menu to **search for items, display frequencies, and generate a histogram**. Additionally, the program **automatically created a backup file (`frequency.dat`)** to ensure data persistence.  

One area I did particularly well in was **structuring the code with Object-Oriented Programming (OOP)**, using a `GroceryTracker` class to handle **file operations, data storage, and reporting**, making the program **modular and maintainable**.  

To enhance the code, I could implement **exception handling** to better manage **file errors**, such as missing input files, and optimize file I/O by using **buffered reading techniques**. These improvements could make the program **more secure and efficient**, preventing crashes and reducing redundant file operations.  

The most challenging part was handling **user input validation** while keeping the menu responsive. To overcome this, I implemented a **loop that checked for invalid input**, clearing the input buffer when necessary. I also used **debugging tools and online documentation** to refine my approach.  

This project helped strengthen my skills in **file handling, data structures (maps), and user input validation**, all of which are highly transferable to future projects involving **data processing and automation**.  

To ensure maintainability, I used **clear function names, in-line comments, and structured the code logically**, making it **easy to read and adapt** for future enhancements. These practices ensure the program remains **scalable and easy to debug** in future iterations.

