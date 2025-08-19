Spy Message Relay - Encryption System
📌 Overview

A C++ application that implements a secure message relay system with multiple encryption algorithms. Users can encrypt, decrypt, store, and retrieve messages using either Caesar Cipher or Reverse Cipher encryption methods.
✨ Features

    Two Encryption Methods:

        Caesar Cipher: Shifts letters by a configurable number of positions

        Reverse Cipher: Reverses the entire message

    Message Management:

        Send and receive encrypted messages

        View message history

        Save/load messages to/from file

    Bonus Feature: Binary representation of messages

    Polymorphic Design: Easy to add new encryption algorithms

🛠️ Technical Implementation

    Object-Oriented Design using abstract base class and inheritance

    STL Components: vector, bitset, file streams

    Memory Management: Proper cleanup with virtual destructors

    User Interface: Console-based menu system

📋 Requirements

    C++11 or later compatible compiler

    Standard Library support

🚀 How to Use

    Compile the program:
    bash

g++ AMS.cpp -o spy_message

Run the executable:
bash

    ./spy_message

    Follow the menu prompts:

        Select encryption method (Caesar or Reverse)

        Choose from available operations:

            Send messages

            Decrypt messages

            Save/load to file

            View history

            Exit program

📂 File Operations

    Messages are saved to spy_messages.txt by default

    One message per line format

    File is created automatically if it doesn't exist

🧠 Code Structure
text

AMS.cpp
├── Encryption (Abstract Base Class)
│   ├── CaesarCipher (Derived Class)
│   └── ReverseCipher (Derived Class)
├── SpyMessage (Message Handler)
│   ├── Message History
│   ├── File Operations
│   └── Encryption Delegation
└── Utilities
    └── Binary Converter

⚠️ Limitations

    Caesar Cipher: Only 25 possible keys (not secure for real use)

    Character Support: Best with ASCII characters

    File Security: Messages stored in plaintext (only obfuscated)

    Memory: Decrypted messages remain in memory

🔮 Possible Extensions

    Add stronger encryption algorithms (AES, RSA)

    Implement secure memory wiping

    Add password protection

    Support for Unicode characters

    Network transmission capability

📝 Example Usage

🕵️‍♂️ Welcome to SPY MESSAGE RELAY 🔐

Select Encryption:
1. Caesar Cipher
2. Reverse Cipher
> 1

1. Send Message
2. Read Message
3. Save to File
4. Load from File
5. Show History
6. Exit
> 1
Enter message: Hello World
🔒 Encrypted: Khoor Zruog
🔢 Binary: 01001000 01100101 01101100 01101100 01101111 00100000 01010111 01101111 01110010 01101100 01100100 


This project is open-source and available for educational purposes. Modify and use as needed.

Note: This implementation is for educational purposes only. Not suitable for real secure communications.
