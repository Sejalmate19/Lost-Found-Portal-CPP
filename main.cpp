#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Item {
    int id;
    string name;
    string category;
    string date;
    bool isClaimed;
};

// Function to add a lost item
void addItem() {
    Item newItem;
    ofstream file("database.txt", ios::app);

    cout << "Enter Item ID: "; cin >> newItem.id;
    cin.ignore();
    cout << "Enter Item Name: "; getline(cin, newItem.name);
    cout << "Enter Category (ID, Bottle, Calc, etc.): "; getline(cin, newItem.category);
    cout << "Enter Date (DD/MM/YYYY): "; getline(cin, newItem.date);
    newItem.isClaimed = false;

    file << newItem.id << "|" << newItem.name << "|" << newItem.category << "|" << newItem.date << "|" << newItem.isClaimed << endl;
    file.close();
    cout << "\nItem logged successfully!\n";
}

// Function to search items by category
void searchByCategory() {
    string searchCat;
    cout << "Enter category to search: ";
    cin.ignore();
    getline(cin, searchCat);

    ifstream file("database.txt");
    string line;
    cout << "\n--- Search Results ---\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Date" << "Status" << endl;

    while (getline(file, line)) {
        // Simple string matching logic
        if (line.find(searchCat) != string::npos) {
            cout << line << endl; 
        }
    }
    file.close();
}

int main() {
    int choice;
    while (true) {
        cout << "\n=== College Lost & Found Portal ===";
        cout << "\n1. Report Lost Item\n2. Search Items\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) addItem();
        else if (choice == 2) searchByCategory();
        else break;
    }
    return 0;
}
