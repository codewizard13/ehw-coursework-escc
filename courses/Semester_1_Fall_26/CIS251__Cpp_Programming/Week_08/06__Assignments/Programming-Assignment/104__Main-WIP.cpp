/**
 * @brief Simple Bank Account Simulator — Week 8 C++ programming assignment:
 *        BankAccount class, objects, and encapsulation.
 *
 * @course ESCC, CIS-251 - C++ Programming
 * @assignment Week 8 Programming Assignment
 * @lesson_focus Object-Oriented Programming: Classes, Objects, and Encapsulation
 *
 * @instructions BankAccount Class: define a class with private account
 * holder/balance data, a constructor, getters, and deposit/withdraw methods
 * that preserve a nonnegative balance. Create and test multiple objects
 * in main().
 *
 * This program creates multiple BankAccount objects, displays their
 * balances, and tests valid and invalid deposits and withdrawals.
 *
 * @status WIP - Successfully migrated showBalance() into class method
 *
 * @author Eric L. Hepperle
 * @date 2026-10-11
 * @updated 2026-10-13
 * @version 1.04
 *
 * @par Notes
 * - Convert file and class comments to better align with Doxygen style
 *
 * @par Lessons Learned
 * -
 *
 * @note Uses hard-coded transaction values for testing; does not implement
 *       authentication, an interactive ATM menu, or transaction history.
 *
 * @link https://github.com/codewizard13
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**
 * @class BankAccount
 * @brief Models a bank account with an account holder and balance.
 *
 * Each BankAccount object owns its own private account holder and balance.
 * Public getters provide read-only access, while deposit() and withdraw()
 * are the only operations that change the balance.
 *
 * - showBalance() displays the account number, holder, and current balance.
 *
 * - Successful deposits and withdrawals preserve a nonnegative balance.
 */
class BankAccount
{
private:
  string account_holder = "";
  double balance = 0.0;

public:
  int acct_no = 0;

  /**
   * @brief Constructor: Constructs a bank account.
   *
   * @param acct_no Account number.
   * @param account_holder Name of the account holder.
   * @param balance Opening balance in USD.
   * @warning A negative opening balance is currently accepted.
   */
  BankAccount(int acct_no, string account_holder, double balance)
  {
    this->acct_no = acct_no;
    this->account_holder = account_holder;
    this->balance = balance;
  }

  /**
   * @brief Gets the account holder's name
   *
   * @return The account holder's name
   */
  string getAccountHolder()
  {
    return account_holder;
  }

  /**
   * @brief Gets the account's current balance
   *
   * @return The current balance in USD
   */
  double getBalance()
  {
    return balance;
  }

  /**
   * @brief Deposits money into the account.
   *
   * @param amount Deposit amount in USD; must be greater than zero.
   * @return true if the deposit succeeded; false otherwise
   * @note A rejected deposit leaves the balance unchanged
   */
  bool deposit(double amount)
  {
    double old_bal = balance; // temp var to store current balance

    cout << "Depositing $" << amount << " in " << account_holder << "'s account ...\n";
    if (amount <= 0)
    {
      cout << " - Invalid input: deposit amount must be at least $1.\n";
      cout << " - " << account_holder << "'s balance of $" << balance << " is unchanged.\n";
      return false;
    }

    balance += amount;

    cout << " - Success: Deposited $" << amount << ".\n";
    cout << " - Old Balance: $" << old_bal << " | New balance: $" << balance;
    cout << "\n";

    return true;
  }

  /**
   * @brief Withdraws money from the account without overdrawing it.
   *
   * @param amount Withdrawal amount in USD; must be positive and no greater
   *               than the current balance.
   * @return true if the withdrawal succeeded; false otherwise.
   * @note A rejected withdrawal leaves the balance unchanged.
   */
  bool withdraw(double amount)
  {
    double old_bal = balance; // temp var to store current balance

    cout << "Withdrawing $" << amount << " from " << account_holder << "'s account ...\n";

    // Reject if amount is negative or zero
    if (amount <= 0)
    {
      cout << " - Invalid input: withdrawal amount cannot be negative. ";
      cout << account_holder << "'s balance of $" << balance << " is unchanged.\n";
      cout << endl;
      return false;
    }

    // Reject if (balance minus amount) is negative
    if (balance - amount < 0)
    {
      cout << " - Insufficient Funds. ";
      cout << account_holder << "'s balance of $" << balance << " is unchanged.\n";
      cout << endl;
      return false;
    }
    balance -= amount;

    cout << " - Success: Withdrew $" << amount << ".\n";
    cout << " - Old Balance: $" << old_bal << " | New balance: $" << balance << "\n";
    cout << "\n";

    return true;
  }

  /**
   * @brief Displays the account number, holder, and current balance.
   *
   * @note This method writes to standard output and does not change the account.
   */
  void showBalance()
  {
    cout << "Account #";
    cout << setfill('0') << setw(3) << this->acct_no << setfill(' ');
    cout << " belongs to " << this->getAccountHolder();
    cout << " and has a balance of $" << getBalance() << endl;
  }

};

int main()
{

  string bar = "**************************************";

  // DEFINE BANK ACCOUNTS
  BankAccount jen_acct(001, "Jennifer", 250);
  BankAccount eric_acct(002, "Eric", 100);

  // Ensure 2 decimal point precision from here on
  //  so dollar amounts display correctly
  cout << setprecision(2) << fixed;

  // cout << "\n************ SHOW BALANCE ************\n";

  cout << "\n_________BANK ACCOUNT SIMULATOR _____________\n";

  cout << "\n************ SHOW START BALANCE ******\n\n";

  jen_acct.showBalance();
  eric_acct.showBalance();

  cout << "\n************ MAKE DEPOSITS************\n";

  cout << "\n## Testing: Negative deposit\n";
  jen_acct.deposit(-200.00);

  cout << "\n## Testing: Positive deposit\n";
  jen_acct.deposit(70.50);

  cout << "\n\n************ MAKE WITHDRAWaLS *********\n\n";

  jen_acct.withdraw(200.00);
  eric_acct.withdraw(500.00);

  cout << "\n************ SHOW END BALANCE ********\n\n";

  // jen_acct.showBalance()

  cout << "\n_________________ END PROGRAM _______________\n\n";
  return 0;
}
