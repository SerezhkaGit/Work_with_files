#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

class FileManager {
public:
    // Створення файлу
    static void createFile(const string& filePath) {
        ofstream file(filePath);
        if (!file.is_open()) {
            throw runtime_error("Unable to create file: " + filePath);
        }
        cout << "File created successfully: " << filePath << endl;
    }

    // Запис 
    static void writeToFile(const string& filePath, const string& data) {
        ofstream file(filePath, ios::app);
        if (!file.is_open()) {
            throw runtime_error("Unable to open file for writing: " + filePath);
        }
        file << data << endl;
        cout << "Data written to file successfully." << endl;
    }

    // Виведення 
    static void displayFileContent(const string& filePath) {
        ifstream file(filePath);
        if (!file.is_open()) {
            throw runtime_error("Unable to open file: " + filePath);
        }
        string line;
        cout << "File content:" << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    // Копіювання вмісту з одного файлу в інший
    static void copyFile(const string& sourcePath, const string& destinationPath) {
        ifstream sourceFile(sourcePath);
        if (!sourceFile.is_open()) {
            throw runtime_error("Unable to open source file: " + sourcePath);
        }

        ofstream destinationFile(destinationPath);
        if (!destinationFile.is_open()) {
            throw runtime_error("Unable to open destination file: " + destinationPath);
        }

        destinationFile << sourceFile.rdbuf();

        sourceFile.close();
        destinationFile.close();
        cout << "File copied successfully from " << sourcePath << " to " << destinationPath << endl;
    }

    // Видалення файлу
    static void deleteFile(const string& filePath) {
        if (remove(filePath.c_str()) != 0) {
            throw runtime_error("Error deleting file: " + filePath);
        }
        cout << "File deleted successfully." << endl;
    }

    // Перейменування файлу
    static void renameFile(const string& oldPath, const string& newPath) {
        if (rename(oldPath.c_str(), newPath.c_str()) != 0) {
            throw runtime_error("Error renaming file.");
        }
        cout << "File renamed successfully." << endl;
    }
};

int main() {
    int choice;
    string filePath, data, sourcePath, destinationPath;

    while (true) {
        cout << "\nFile Management Menu:" << endl;
        cout << "1. Create File" << endl;
        cout << "2. Write to File" << endl;
        cout << "3. Display File Content" << endl;
        cout << "4. Copy File" << endl;
        cout << "5. Delete File" << endl;
        cout << "6. Rename File" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter file path to create: ";
            getline(cin, filePath);
            try {
                FileManager::createFile(filePath);
            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 2) {
            cout << "Enter file path to write: ";
            getline(cin, filePath);
            cout << "Enter data to write: ";
            getline(cin, data);
            try {
                FileManager::writeToFile(filePath, data);
            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 3) {
            cout << "Enter file path to display: ";
            getline(cin, filePath);
            try {
                FileManager::displayFileContent(filePath);
            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 4) {
            cout << "Enter source file path: ";
            getline(cin, sourcePath);
            cout << "Enter destination file path: ";
            getline(cin, destinationPath);
            try {
                FileManager::copyFile(sourcePath, destinationPath);
            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 5) {
            cout << "Enter file path to delete: ";
            getline(cin, filePath);
            try {
                FileManager::deleteFile(filePath);
            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 6) {
            string newFilePath;
            cout << "Enter old file path: ";
            getline(cin, filePath);
            cout << "Enter new file path: ";
            getline(cin, newFilePath);
            try {
                FileManager::renameFile(filePath, newFilePath);
            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 7) {
            cout << "Exiting program." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
        }
    }

    return 0;
}
