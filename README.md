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
                    └──────┬
