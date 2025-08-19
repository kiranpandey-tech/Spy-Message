#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>
#include <algorithm>

using namespace std;

// Base Encryption Class
class Encryption {
public:
    virtual string encrypt(const string& message) = 0;
    virtual string decrypt(const string& message) = 0;
    virtual ~Encryption() {}
};

// Caesar Cipher (Shift letters by N positions)
class CaesarCipher : public Encryption {
private:
    int shift;
public:
    CaesarCipher(int s = 3) : shift(s) {}

    string encrypt(const string& message) override {
        string result;
        for (char c : message) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = ((c - base + shift) % 26) + base;
            }
            result += c;
        }
        return result;
    }

    string decrypt(const string& message) override {
        string result;
        for (char c : message) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = ((c - base - shift + 26) % 26) + base;
            }
            result += c;
        }
        return result;
    }
};

// Reverse Cipher (Flips the message backward)
class ReverseCipher : public Encryption {
public:
    string encrypt(const string& message) override {
        return string(message.rbegin(), message.rend());
    }

    string decrypt(const string& message) override {
        return string(message.rbegin(), message.rend()); // Same as encrypt
    }
};

// Spy Message Class (Handles storage and file operations)
class SpyMessage {
private:
    vector<string> messageHistory;
    Encryption* encryptor;

public:
    SpyMessage(Encryption* e) : encryptor(e) {}

    void sendMessage(const string& message) {
        string encrypted = encryptor->encrypt(message);
        messageHistory.push_back(encrypted);
        cout << "🔒 Encrypted: " << encrypted << endl;
    }

    void readMessage(const string& message) {
        string decrypted = encryptor->decrypt(message);
        cout << "🔓 Decrypted: " << decrypted << endl;
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (file) {
            for (const auto& msg : messageHistory) {
                file << msg << "\n";
            }
            cout << "💾 Saved " << messageHistory.size() << " messages to " << filename << endl;
        } else {
            cerr << "Error saving file!" << endl;
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file) {
            messageHistory.clear();
            string line;
            while (getline(file, line)) {
                messageHistory.push_back(line);
            }
            cout << "📂 Loaded " << messageHistory.size() << " messages from " << filename << endl;
        } else {
            cerr << "Error loading file!" << endl;
        }
    }

    void displayHistory() {
        cout << "\n📜 Message History:" << endl;
        for (const auto& msg : messageHistory) {
            cout << "→ " << msg << endl;
        }
    }

    ~SpyMessage() {
        delete encryptor;
    }
};

// Binary Converter (Extra STL Feature)
string toBinary(const string& message) {
    string binary;
    for (char c : message) {
        binary += bitset<8>(c).to_string() + " ";
    }
    return binary;
}

// Main Menu
int main() {
    cout << "🕵️‍♂️ Welcome to SPY MESSAGE RELAY 🔐\n";

    // Let user choose encryption method
    cout << "\nSelect Encryption:\n1. Caesar Cipher\n2. Reverse Cipher\n> ";
    int choice;
    cin >> choice;
    cin.ignore();

    Encryption* encryptor = nullptr;
    if (choice == 1) {
        encryptor = new CaesarCipher();
    } else {
        encryptor = new ReverseCipher();
    }

    SpyMessage spy(encryptor);

    while (true) {
        cout << "\n1. Send Message\n2. Read Message\n3. Save to File\n4. Load from File\n5. Show History\n6. Exit\n> ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter message: ";
            string msg;
            getline(cin, msg);
            spy.sendMessage(msg);
            
            // Bonus: Show binary representation (STL bitset)
            cout << "🔢 Binary: " << toBinary(msg) << endl;
        } 
        else if (choice == 2) {
            cout << "Enter encrypted message: ";
            string msg;
            getline(cin, msg);
            spy.readMessage(msg);
        } 
        else if (choice == 3) {
            spy.saveToFile("spy_messages.txt");
        } 
        else if (choice == 4) {
            spy.loadFromFile("spy_messages.txt");
        } 
        else if (choice == 5) {
            spy.displayHistory();
        } 
        else {
            break;
        }
    }

    return 0;
}