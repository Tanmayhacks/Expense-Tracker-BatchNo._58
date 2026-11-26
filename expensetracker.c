#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// ==========================================
// STRUCTURE
// ==========================================

struct Expense
{
    int id;
    char description[50];
    char category[20];
    float amount;
    char date[15];
};


// ==========================================
// GLOBAL VARIABLES
// ==========================================

struct Expense expenses[100];

int count = 0;
int nextId = 1;

float monthlyBudget = 0;


// ==========================================
// FUNCTION PROTOTYPES
// ==========================================

void addExpense();
void viewExpenses();
void totalExpenses();
void categoryExpenses();
void searchExpense();
void deleteExpense();
void setBudget();
void spendingAnalysis();


void saveExpenses();
void loadExpenses();

void saveBudget();
void loadBudget();
void dashboard();
void clearScreen();
void waitForEnter();

// ==========================================
// SAVE EXPENSES TO FILE
// ==========================================

void saveExpenses()
{
    FILE *file;

    file = fopen("expenses.txt", "w");

    if(file == NULL)
    {
        printf("Error saving expenses!\n");
        return;
    }

    for(int i = 0; i < count; i++)
    {
        fprintf(file, "%d|%s|%s|%.2f|%s\n",
                expenses[i].id,
                expenses[i].description,
                expenses[i].category,
                expenses[i].amount,
                expenses[i].date);
    }

    fclose(file);
}


// ==========================================
// LOAD EXPENSES FROM FILE
// ==========================================

void loadExpenses()
{
    FILE *file;

    file = fopen("expenses.txt", "r");

    if(file == NULL)
    {
        return;
    }

    count = 0;
    nextId = 1;

    while(count < 100 &&
          fscanf(file, "%d|%49[^|]|%19[^|]|%f|%14[^\n]\n",
                 &expenses[count].id,
                 expenses[count].description,
                 expenses[count].category,
                 &expenses[count].amount,
                 expenses[count].date) == 5)
    {
        if(expenses[count].id >= nextId)
        {
            nextId = expenses[count].id + 1;
        }

        count++;
    }

    fclose(file);
}


// ==========================================
// SAVE BUDGET
// ==========================================

void saveBudget()
{
    FILE *file;

    file = fopen("budget.txt", "w");

    if(file == NULL)
    {
        printf("Error saving budget!\n");
        return;
    }

    fprintf(file, "%.2f", monthlyBudget);

    fclose(file);
}


// ==========================================
// LOAD BUDGET
// ==========================================

void loadBudget()
{
    FILE *file;

    file = fopen("budget.txt", "r");

    if(file == NULL)
    {
        return;
    }

    fscanf(file, "%f", &monthlyBudget);

    fclose(file);
}


// ==========================================
// 1. ADD EXPENSE
// ==========================================

void addExpense()
{
    if(count >= 100)
    {
        printf("\nExpense limit reached!\n");
        return;
    }

    printf("\n========== ADD EXPENSE ==========\n");

    expenses[count].id = nextId;
    nextId++;

    printf("Enter description: ");
    scanf(" %49[^\n]", expenses[count].description);

    printf("Enter category: ");
    scanf(" %19[^\n]", expenses[count].category);

    printf("Enter amount: ");
    scanf("%f", &expenses[count].amount);

    printf("Enter date (DD/MM/YYYY): ");
    scanf("%14s", expenses[count].date);

    count++;

    saveExpenses();

    printf("\nExpense added successfully!\n");
}


// ==========================================
// 2. VIEW ALL EXPENSES
// ==========================================

void viewExpenses()
{
    if(count == 0)
    {
        printf("\nNo expenses found!\n");
        return;
    }

    printf("\n========== ALL EXPENSES ==========\n");

    for(int i = 0; i < count; i++)
    {
        printf("\nExpense %d\n", i + 1);
        printf("----------------------------\n");

        printf("ID          : %d\n",
               expenses[i].id);

        printf("Description : %s\n",
               expenses[i].description);

        printf("Category    : %s\n",
               expenses[i].category);

        printf("Amount      : %.2f\n",
               expenses[i].amount);

        printf("Date        : %s\n",
               expenses[i].date);
    }
}


// ==========================================
// 3. TOTAL EXPENSES
// ==========================================

void totalExpenses()
{
    float total = 0;

    if(count == 0)
    {
        printf("\nNo expenses found!\n");
        return;
    }

    for(int i = 0; i < count; i++)
    {
        total = total + expenses[i].amount;
    }

    printf("\n========== TOTAL EXPENSES ==========\n");

    printf("Total Amount Spent: %.2f\n", total);
}


// ==========================================
// 4. CATEGORY-WISE EXPENSES
// ==========================================

void categoryExpenses()
{
    char category[20];

    float total = 0;

    int found = 0;

    printf("\n========== CATEGORY EXPENSES ==========\n");

    printf("Enter category: ");
    scanf(" %19[^\n]", category);

    for(int i = 0; i < count; i++)
    {
        if(strcmp(expenses[i].category, category) == 0)
        {
            printf("\n%s - %.2f",
                   expenses[i].description,
                   expenses[i].amount);

            total = total + expenses[i].amount;

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nNo expenses found in this category!\n");
    }
    else
    {
        printf("\n\nTotal spent on %s: %.2f\n",
               category,
               total);
    }
}


// ==========================================
// 5. SEARCH EXPENSE
// ==========================================

void searchExpense()
{
    int id;

    int found = 0;

    printf("\n========== SEARCH EXPENSE ==========\n");

    printf("Enter Expense ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(expenses[i].id == id)
        {
            printf("\nExpense Found!\n");

            printf("----------------------------\n");

            printf("ID          : %d\n",
                   expenses[i].id);

            printf("Description : %s\n",
                   expenses[i].description);

            printf("Category    : %s\n",
                   expenses[i].category);

            printf("Amount      : %.2f\n",
                   expenses[i].amount);

            printf("Date        : %s\n",
                   expenses[i].date);

            found = 1;

            break;
        }
    }

    if(found == 0)
    {
        printf("\nExpense not found!\n");
    }
}


// ==========================================
// 6. DELETE EXPENSE
// ==========================================

void deleteExpense()
{
    int id;

    int found = 0;

    printf("\n========== DELETE EXPENSE ==========\n");

    printf("Enter Expense ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(expenses[i].id == id)
        {
            // Shift remaining expenses left

            for(int j = i; j < count - 1; j++)
            {
                expenses[j] = expenses[j + 1];
            }

            count--;

            saveExpenses();

            found = 1;

            printf("\nExpense deleted successfully!\n");

            break;
        }
    }

    if(found == 0)
    {
        printf("\nExpense not found!\n");
    }
}


// ==========================================
// 7. SET MONTHLY BUDGET
// ==========================================

void setBudget()
{
    float total = 0;

    printf("\n========== SET MONTHLY BUDGET ==========\n");

    printf("Enter your monthly budget: ");

    scanf("%f", &monthlyBudget);

    saveBudget();

    for(int i = 0; i < count; i++)
    {
        total = total + expenses[i].amount;
    }

    printf("\nMonthly Budget : %.2f\n",
           monthlyBudget);

    printf("Total Spent    : %.2f\n",
           total);

    printf("Remaining      : %.2f\n",
           monthlyBudget - total);


    if(total > monthlyBudget)
    {
        printf("\nWARNING: You have exceeded your budget!\n");
    }
    else
    {
        printf("\nYou are within your budget.\n");
    }
}


// ==========================================
// 8. SPENDING ANALYSIS
// ==========================================

void spendingAnalysis()
{
    float total = 0;

    float percentage;

    int highestIndex = 0;


    printf("\n========== SPENDING ANALYSIS ==========\n");


    if(count == 0)
    {
        printf("No expenses available for analysis!\n");

        return;
    }


    // Calculate total expenses
    // and find highest expense

    for(int i = 0; i < count; i++)
    {
        total = total + expenses[i].amount;


        if(expenses[i].amount >
           expenses[highestIndex].amount)
        {
            highestIndex = i;
        }
    }


    printf("\nTotal Expenses : %.2f\n",
           total);


    printf("Highest Expense: %s - %.2f\n",
           expenses[highestIndex].description,
           expenses[highestIndex].amount);


    // Check monthly budget

    if(monthlyBudget > 0)
    {
        percentage =
            (total / monthlyBudget) * 100;


        printf("Monthly Budget : %.2f\n",
               monthlyBudget);


        printf("Budget Used    : %.2f%%\n",
               percentage);


        printf("Remaining      : %.2f\n",
               monthlyBudget - total);


        if(percentage >= 100)
        {
            printf("\nWARNING: Budget exceeded!\n");
        }

        else if(percentage >= 80)
        {
            printf("\nWARNING: You have used more than 80%% of your budget!\n");
        }

        else
        {
            printf("\nYour spending is under control.\n");
        }
    }

    else
    {
        printf("\nMonthly budget has not been set yet.\n");
    }
}


 void clearScreen()
{
    system("cls");
}

void waitForEnter()
{
    printf("\n\nPress ENTER to return to main menu...");

    // Remove the \n left behind by scanf()
    getchar();

    // Actually wait for the user
    getchar();
}
 void dashboard()
{
    // dashboard cod
    float total = 0;
    float remaining;
    float percentage = 0;
    int highestIndex = 0;

    // Calculate total spending
    for(int i = 0; i < count; i++)
    {
        total = total + expenses[i].amount;

        if(expenses[i].amount > expenses[highestIndex].amount)
        {
            highestIndex = i;
        }
    }

    remaining = monthlyBudget - total;

    if(monthlyBudget > 0)
    {
        percentage = (total / monthlyBudget) * 100;
    }

    printf("\n");
    printf("========================================================\n");
    printf("                PERSONAL EXPENSE TRACKER\n");
    printf("========================================================\n");

    printf("\n                     DASHBOARD\n\n");

    printf("--------------------------------------------------------\n");
    printf(" Monthly Budget : Rs. %.2f\n", monthlyBudget);
    printf(" Total Spent    : Rs. %.2f\n", total);

    if(monthlyBudget > 0)
        printf(" Remaining      : Rs. %.2f\n", remaining);
    else
        printf(" Remaining      : Set a budget first\n");

    printf("--------------------------------------------------------\n");

    printf(" Total Expenses : %d\n", count);

    if(monthlyBudget > 0)
        printf(" Budget Used    : %.2f%%\n", percentage);
    else
        printf(" Budget Used    : Budget not set\n");

    // Highest expense
    if(count > 0)
    {
        printf("\n Highest Expense: %s - Rs. %.2f\n",
               expenses[highestIndex].description,
               expenses[highestIndex].amount);
    }
    else
    {
        printf("\n No expenses recorded yet.\n");
    }

    // Budget progress bar
    if(monthlyBudget > 0)
    {
        int bars = (int)(percentage / 5);

        if(bars > 20)
            bars = 20;

        printf("\n Budget Status  : [");

        for(int i = 0; i < 20; i++)
        {
            if(i < bars)
                printf("#");
            else
                printf("-");
        }

        printf("] %.1f%%\n", percentage);

        if(percentage >= 100)
            printf("\n STATUS: Budget exceeded!\n");
        else if(percentage >= 80)
            printf("\n STATUS: You are close to your budget!\n");
        else
            printf("\n STATUS: Your spending is under control.\n");
    }

    printf("\n========================================================\n");
}

int main()
{
    int choice;


    // Load previous data

    loadExpenses();

    loadBudget();


    while(1)
{
    clearScreen();
    dashboard();

    printf("\n=====================================\n");
    printf("       PERSONAL EXPENSE TRACKER\n");
    printf("=====================================\n");

    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Category-wise Expenses\n");
    printf("5. Search Expense\n");
    printf("6. Delete Expense\n");
    printf("7. Set Monthly Budget\n");
    printf("8. Spending Analysis\n");
    printf("9. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    clearScreen();

    switch(choice)
    {
        case 1:
            addExpense();
            waitForEnter();
            break;

        case 2:
            viewExpenses();
            waitForEnter();
            break;

        case 3:
            totalExpenses();
            waitForEnter();
            break;

        case 4:
            categoryExpenses();
            waitForEnter();
            break;

        case 5:
            searchExpense();
            waitForEnter();
            break;

        case 6:
            deleteExpense();
            waitForEnter();
            break;

        case 7:
            setBudget();
            waitForEnter();
            break;

        case 8:
            spendingAnalysis();
            waitForEnter();
            break;

        case 9:
            clearScreen();
            printf("\nThank you for using Expense Tracker!\n");
            return 0;

        default:
            printf("\nInvalid choice! Please try again.\n");
            waitForEnter();
    }
}
    


    return 0;
}