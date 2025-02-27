#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iomanip>

using namespace std;

// GroceryTracker Class
class GroceryTracker {
private:
    unordered_map<string, int> itemFrequency;  // Stores item frequencies

public:
    // Constructor - Reads file and builds frequency map
    GroceryTracker(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "❌ Error: Unable to open input file: " << filename << endl;
            exit(1);  // Terminate program if file is missing
        }

        string item;
        while (inputFile >> item) {
            itemFrequency[item]++;
        }
        inputFile.close();

        // Create backup frequency.dat file
        writeBackupFile("frequency.dat");
    }

    // Function to write backup file (frequency.dat)
    void writeBackupFile(const string& filename) {
        ofstream outputFile(filename);
        if (!outputFile) {
            cerr << "❌ Error: Unable to create backup file: " << filename << endl;
            return;
        }
        for (const auto& pair : itemFrequency) {
            outputFile << pair.first << " " << pair.second << endl;
        }
        outputFile.close();
        cout << "✅ Backup file 'frequency.dat' created successfully.\n";
    }

    // Function to get item frequency
    int getItemFrequency(const string& item) const {
        auto it = itemFrequency.find(item);
        return (it != itemFrequency.end()) ? it->second : 0;
    }

    // Function to display item list with frequencies
    void displayItemList() const {
        cout << "\nItem Frequency List\n";
        cout << "===================\n";
        for (const auto& pair : itemFrequency) {
            cout << left << setw(15) << pair.first << pair.second << endl;
        }
    }

    // Function to display a histogram of item frequencies
    void displayHistogram() const {
        cout << "\nItem Frequency Histogram\n";
        cout << "========================\n";
        for (const auto& pair : itemFrequency) {
            cout << left << setw(15) << pair.first << string(pair.second, '*') << endl;
        }
    }
};

// Function to display menu options
void displayMenu() {
    cout << "\nMenu Options:\n";
    cout << "1 - Search for an item\n";
    cout << "2 - Display item frequency list\n";
    cout << "3 - Display item frequency histogram\n";
    cout << "4 - Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    // Initialize GroceryTracker with input file
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt");

    int choice;
    do {
        displayMenu();
        cin >> choice;

        // Validate user input
        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice! Please enter a number between 1 and 4: ";
            cin >> choice;
        }

        if (choice == 1) {  // Search for an item
            string item;
            cout << "Enter item name: ";
            cin >> item;
            int frequency = tracker.getItemFrequency(item);
            cout << item << " appears " << frequency << " times." << endl;
        }
        else if (choice == 2) {  // Display item list with frequencies
            tracker.displayItemList();
        }
        else if (choice == 3) {  // Display histogram
            tracker.displayHistogram();
        }

    } while (choice != 4);

    cout << "✅ Exiting program. Goodbye!\n";
    return 0;
}
