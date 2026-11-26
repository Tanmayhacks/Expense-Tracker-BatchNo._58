# 💰 Personal Expense Tracker in C

A menu-driven **Personal Expense Tracker** developed using the **C programming language**.

The application allows users to record and manage daily expenses, monitor a monthly budget, search and delete expense records, analyze spending, and permanently store data using file handling.

The project demonstrates practical implementation of fundamental C programming concepts such as **structures, arrays, functions, loops, conditional statements, strings, searching, and file handling**.

---

## 📌 Project Objective

The objective of this project is to create a simple and efficient expense management system that helps users:

- Record daily expenses
- Keep track of total spending
- Organize expenses by category
- Set and monitor a monthly budget
- Search previously recorded expenses
- Delete unwanted expense records
- Analyze spending habits
- Store expense information permanently

---

## ✨ Features

| Feature | Description |
|---|---|
| 📊 Dashboard | Displays an overview of expenses and budget |
| ➕ Add Expense | Adds a new expense with description, category, amount and date |
| 📋 View Expenses | Displays all recorded expenses |
| 💰 Total Expenses | Calculates the total amount spent |
| 🗂️ Category-wise Expenses | Calculates spending for a selected category |
| 🔍 Search Expense | Searches for an expense using its unique ID |
| 🗑️ Delete Expense | Deletes an expense using its ID |
| 🎯 Monthly Budget | Allows the user to set a monthly spending budget |
| 📈 Spending Analysis | Displays total spending, highest expense and budget usage |
| ⚠️ Budget Warning | Warns the user when spending approaches or exceeds the budget |
| 💾 File Handling | Saves expenses and budget so data remains available after restarting the program |

---

# 📊 Program Flowchart

```text
                    ┌─────────────────────┐
                    │        START        │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │   Load Expenses     │
                    │   & Load Budget     │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │  Display Dashboard  │
                    │    & Main Menu      │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │ Enter Menu Choice   │
                    └──────────┬──────────┘
                               │
              ┌────────────────┼─────────────────┐
              │                │                 │
              ▼                ▼                 ▼
        Add Expense      View/Analyze       Search/Delete
              │                │                 │
              └────────────────┼─────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │ Update/Save Data    │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │   Exit Selected?    │
                    └──────┬────────┬─────┘
                           │ No     │ Yes
                           │        │
                           ▼        ▼
                      Main Menu    END
```

---

# 🧭 Menu Flow

```text
                    PERSONAL EXPENSE TRACKER
                              │
                              ▼
                         MAIN MENU
                              │
       ┌──────────────────────┼──────────────────────┐
       │                      │                      │
       ▼                      ▼                      ▼
  Add Expense          View Expenses          Total Expenses
       │                      │                      │
       ├───────────────┬──────┴───────┬──────────────┤
       │               │              │              │
       ▼               ▼              ▼              ▼
   Category          Search         Delete       Set Budget
   Expenses          Expense        Expense
       │               │              │              │
       └───────────────┴──────┬───────┴──────────────┘
                              │
                              ▼
                      Spending Analysis
                              │
                              ▼
                         Main Menu
                              │
                              ▼
                             Exit
```

---

# ➕ Add Expense Flowchart

```text
             ┌───────────────┐
             │  Add Expense  │
             └───────┬───────┘
                     │
                     ▼
          ┌──────────────────────┐
          │ Check Expense Limit  │
          └──────────┬───────────┘
                     │
                     ▼
          ┌──────────────────────┐
          │ Generate Expense ID  │
          └──────────┬───────────┘
                     │
                     ▼
          ┌──────────────────────┐
          │ Enter Description    │
          ├──────────────────────┤
          │ Enter Category       │
          ├──────────────────────┤
          │ Enter Amount         │
          ├──────────────────────┤
          │ Enter Date           │
          └──────────┬───────────┘
                     │
                     ▼
          ┌──────────────────────┐
          │ Store Expense in     │
          │ Structure Array      │
          └──────────┬───────────┘
                     │
                     ▼
          ┌──────────────────────┐
          │ Save to expenses.txt │
          └──────────┬───────────┘
                     │
                     ▼
          ┌──────────────────────┐
          │ Expense Added        │
          │ Successfully         │
          └──────────────────────┘
```

---

# 💾 File Handling Flow

```text
                    Program Starts
                          │
                          ▼
              ┌───────────────────────┐
              │ Read expenses.txt     │
              │ Read budget.txt       │
              └───────────┬───────────┘
                          │
                          ▼
                  Load Data Into
                     Program
                          │
                          ▼
                  User Makes Changes
                          │
                 ┌────────┴────────┐
                 │                 │
                 ▼                 ▼
            Add/Delete         Set Budget
             Expense               │
                 │                 │
                 ▼                 ▼
          expenses.txt         budget.txt
                 │                 │
                 └────────┬────────┘
                          │
                          ▼
                    Data Saved
```

---

# 🧠 Spending Analysis Logic

The spending analysis feature calculates the user's overall expenditure and compares it with the monthly budget.

```text
                    Spending Analysis
                           │
                           ▼
                 Calculate Total Expense
                           │
                           ▼
                 Find Highest Expense
                           │
                           ▼
                  Is Budget Available?
                     /            \
                   YES             NO
                    │               │
                    ▼               ▼
             Calculate Budget    Display
                Percentage       "Budget Not Set"
                    │
                    ▼
             ┌───────────────┐
             │ Percentage?   │
             └───────┬───────┘
                     │
        ┌────────────┼────────────┐
        │            │            │
      <80%        80-99%        ≥100%
        │            │            │
        ▼            ▼            ▼
     Spending      Warning       Budget
     Under         Message       Exceeded
     Control
```

The budget percentage is calculated using:

```text
Budget Used (%) = (Total Expenses / Monthly Budget) × 100
```

---

# 🏗️ Expense Data Structure

Each expense is represented using a C structure:

```c
struct Expense
{
    int id;
    char description[50];
    char category[20];
    float amount;
    char date[15];
};
```

Each expense therefore contains:

| Field | Purpose |
|---|---|
| `id` | Unique identification number |
| `description` | Description of the expense |
| `category` | Expense category |
| `amount` | Amount spent |
| `date` | Date of expense |

---

# 🛠️ Technologies Used

- **Language:** C
- **Compiler:** GCC
- **Development Environment:** Visual Studio Code
- **Version Control:** Git
- **Repository Hosting:** GitHub
- **Storage:** Text files using C File Handling

---

# 📚 C Programming Concepts Used

This project demonstrates:

- Structures
- Arrays
- Functions
- Function Prototypes
- Loops
- Conditional Statements
- Switch-Case
- Strings
- String Comparison
- File Handling
- Searching
- Array Element Deletion
- Global Variables
- Formatted Input/Output

---

# 📂 Project Structure

```text
Expense-Tracker/
│
├── expensetracker.c
├── expenses.txt
├── budget.txt
├── README.md
└── .gitignore
```

### `expensetracker.c`

Contains the main source code and all Expense Tracker functions.

### `expenses.txt`

Stores expense records permanently.

### `budget.txt`

Stores the user's monthly budget.

### `.gitignore`

Prevents unnecessary compiled files such as `.exe` files from being uploaded to GitHub.

---

# ▶️ How to Compile and Run

## Requirements

Make sure GCC is installed.

Check using:

```bash
gcc --version
```

## Compile

Open the terminal in the project directory and run:

```bash
gcc expensetracker.c -o expensetracker
```

## Run on Windows

```bash
.\expensetracker.exe
```

---

# 🖥️ Example Dashboard

```text
========================================================
                PERSONAL EXPENSE TRACKER
========================================================

                     DASHBOARD

--------------------------------------------------------
 Monthly Budget : Rs. 5000.00
 Total Spent    : Rs. 1220.00
 Remaining      : Rs. 3780.00
--------------------------------------------------------

 Total Expenses : 4
 Budget Used    : 24.40%

 Highest Expense: Shopping - Rs. 600.00

 Budget Status  : [####----------------] 24.4%

 STATUS: Your spending is under control.

========================================================

1. Add Expense
2. View Expenses
3. Total Expenses
4. Category-wise Expenses
5. Search Expense
6. Delete Expense
7. Set Monthly Budget
8. Spending Analysis
9. Exit
```

---

# 👥 Team Members

| Name | Batch |
|---|---:|
| **Shourya Veer Singh** | 58 |
| **Tanmay Gopera** | 57 |
| **Vaishnavi** | 58 |

---

# 🚀 Future Improvements

The project can be further improved by adding:

- Graphical User Interface (GUI)
- User login system
- Multiple user accounts
- Monthly and yearly reports
- Expense editing
- Automatic date detection
- More detailed category analysis
- Graphical spending charts
- CSV export
- Improved input validation
- Database integration

---

# 🎯 Conclusion

The **Personal Expense Tracker** provides a simple way to record, organize, and analyze personal expenses.

The project demonstrates how fundamental C programming concepts can be combined to create a practical application. File handling allows expense and budget information to persist between program executions, while features such as category tracking, searching, deletion, budget monitoring, and spending analysis make the application useful for basic personal finance management.

---

## ⭐ Repository

If you find this project useful, consider giving the repository a ⭐ on GitHub.
