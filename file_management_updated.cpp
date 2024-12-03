#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

// Function to create a file
void createFile(const string &filename) {
    ofstream file(filename);
    if (file.is_open()) {
        cout << "File '" << filename << "' created successfully!\n";
        file.close();
    } else {
        cout << "Failed to create the file.\n";
    }
}

// Function to write data to a file
void writeFile(const string &filename, const string &data) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << data << endl;
        cout << "Data written to the file.\n";
        file.close();
    } else {
        cout << "Failed to write to the file.\n";
    }
}

// Function to read data from a file
void readFile(const string &filename) {
    ifstream file(filename);
    string line;
    if (file.is_open()) {
        cout << "Reading file '" << filename << "':\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Failed to read the file.\n";
    }
}

// Function to delete a file
void deleteFile(const string &filename) {
    if (remove(filename.c_str()) == 0) {
        cout << "File '" << filename << "' deleted successfully!\n";
    } else {
        cout << "Failed to delete the file.\n";
    }
}

// Function to sort and save data in a file
void sortFile(const string &filename) {
    ifstream file(filename);
    vector<string> lines;
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();

        sort(lines.begin(), lines.end());

        ofstream sortedFile(filename);
        for (const auto &l : lines) {
            sortedFile << l << endl;
        }
        sortedFile.close();
        cout << "File sorted successfully!\n";
    } else {
        cout << "Failed to read the file.\n";
    }
}

// Function to rename a file
void renameFile(const string &oldName, const string &newName) {
    if (rename(oldName.c_str(), newName.c_str()) == 0) {
        cout << "File renamed successfully from '" << oldName << "' to '" << newName << "'.\n";
    } else {
        cout << "Failed to rename the file.\n";
    }
}

// Function to copy a file
void copyFile(const string &source, const string &destination) {
    ifstream src(source, ios::binary);
    ofstream dest(destination, ios::binary);

    if (src.is_open() && dest.is_open()) {
        dest << src.rdbuf();
        cout << "File copied from '" << source << "' to '" << destination << "'.\n";
    } else {
        cout << "Failed to copy the file.\n";
    }

    src.close();
    dest.close();
}

// Function to merge two files
void mergeFiles(const string &file1, const string &file2, const string &outputFile) {
    ifstream f1(file1);
    ifstream f2(file2);
    ofstream out(outputFile);

    if (f1.is_open() && f2.is_open() && out.is_open()) {
        string line;
        while (getline(f1, line)) out << line << endl;
        while (getline(f2, line)) out << line << endl;

        cout << "Files '" << file1 << "' and '" << file2 << "' merged into '" << outputFile << "'.\n";
    } else {
        cout << "Failed to merge files.\n";
    }

    f1.close();
    f2.close();
    out.close();
}

int main() {
    string filename, data, newName, file2, outputFile;
    int choice;

    do {
        cout << "\nFile Management System\n";
        cout << "1. Create File\n2. Write to File\n3. Read File\n4. Delete File\n5. Sort File\n";
        cout << "6. Rename File\n7. Copy File\n8. Merge Files\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter file name: ";
            cin >> filename;
            createFile(filename);
            break;
        case 2:
            cout << "Enter file name: ";
            cin >> filename;
            cout << "Enter data to write: ";
            cin.ignore();
            getline(cin, data);
            writeFile(filename, data);
            break;
        case 3:
            cout << "Enter file name: ";
            cin >> filename;
            readFile(filename);
            break;
        case 4:
            cout << "Enter file name: ";
            cin >> filename;
            deleteFile(filename);
            break;
        case 5:
            cout << "Enter file name: ";
            cin >> filename;
            sortFile(filename);
            break;
        case 6:
            cout << "Enter current file name: ";
            cin >> filename;
            cout << "Enter new file name: ";
            cin >> newName;
            renameFile(filename, newName);
            break;
        case 7:
            cout << "Enter source file name: ";
            cin >> filename;
            cout << "Enter destination file name: ";
            cin >> newName;
            copyFile(filename, newName);
            break;
        case 8:
            cout << "Enter first file name: ";
            cin >> filename;
            cout << "Enter second file name: ";
            cin >> file2;
            cout << "Enter output file name: ";
            cin >> outputFile;
            mergeFiles(filename, file2, outputFile);
            break;
        case 9:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
