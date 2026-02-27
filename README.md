🎭 NCU Theater Reservation System (C++)
📌 Project Overview

This project is a console-based theater reservation and membership management system implemented in C++. It allows users to:

Reserve and cancel seats

View available and reserved seats

Register and log in as members

Update member information

Search member data

Load member information from file

The system simulates a simple seat booking platform with basic authentication and file handling functionality.

🧠 System Architecture

The program consists of:

Seat Management Module

Membership Management Module

File Loading Module

Search Functionality

Input Validation Mechanism

Data is stored using fixed-size arrays for seats and member records.

🎟 Seat Management

15 seats available

Status stored using integer array

0 → Available

10 → Reserved

Users can:

Reserve specific seat

Automatically assign seat

Cancel reservation

View seat status

👤 Membership System

Each member includes:

Username

Password

Phone number

Features:

Member registration

Login authentication

Change password

Change phone number

Search member information

📂 File Handling

The system supports loading member information from external file:

username password phone
🛠 Technologies Used

C++

fstream

iostream

string

iomanip

⚠️ Design Limitations

Uses global variables

Fixed maximum 15 members

No dynamic memory allocation

No persistent save-back mechanism

Improve error handling

Modularize menu system
