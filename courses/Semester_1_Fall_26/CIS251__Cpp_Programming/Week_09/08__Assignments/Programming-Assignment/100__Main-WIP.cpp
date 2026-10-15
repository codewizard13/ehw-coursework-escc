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
 * @status Fully Working
 *
 * @author Eric L. Hepperle
 * @date 2026-10-11
 * @updated 2026-10-14
 * @version 1.06
 *
 * @par Notes
 * - Uses hard-coded transaction values for testing.
 * - Negative opening balances are rejected and set to zero.
 * - Does not implement authentication, an interactive ATM menu, or
 *   transaction history; those are beyond the assignment scope.
 *
 * @par Lessons Learned
 * - A constructor cannot prevent object creation by returning early;
 *   invalid initialization must either be corrected, throw an exception,
 *   or be handled by the caller.
 * - Keep user-interface/menu logic separate from account behavior so the
 *   BankAccount class remains focused on encapsulation and balance rules.
 *
 * @see https://github.com/codewizard13
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
 * - showBalance() displays the holder and current balance.
 *
 * - Successful deposits and withdrawals preserve a nonnegative balance.
 */
class BankAccount
{
private:
  string account_holder = "";
  double balance = 0.0;

public:
  /**
   * @brief Constructor: Constructs a bank account.
   *
   * @param account_holder Name of the account holder.
   * @param balance Opening balance in USD.
   * @note A negative opening balance is rejected and set to zero.
   */
  BankAccount(string account_holder, double balance)
  {

    this->account_holder = account_holder;

    // Only allow non-negative starting balance
    if (balance < 0)
    {
      this->balance = 0.0;
      cout << "Invalid Input: Starting balance cannot be negative.\n";
      cout << " - " << this->account_holder << "'s account created | Starting Balance: $0.00\n";
    }
    else
    {
      this->balance = balance;
    }
  }

  /**
   * @brief Gets the account holder's name.
   *
   * @return The account holder's name.
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

    // Reject if amount is negative or zero.
    if (amount <= 0)
    {
      cout << " - Invalid input: withdrawal amount cannot be negative. ";
      cout << account_holder << "'s balance of $" << balance << " is unchanged.\n";
      return false;
    }

    // Reject if (balance minus amount) is negative.
    if (balance - amount < 0)
    {
      cout << " - Insufficient Funds. ";
      cout << account_holder << "'s balance of $" << balance << " is unchanged.\n";
      return false;
    }
    balance -= amount;

    cout << " - Success: Withdrew $" << amount << ".\n";
    cout << " - Old Balance: $" << old_bal << " | New balance: $" << balance << "\n";

    return true;
  }

  /**
   * @brief Displays the holder and current balance.
   *
   * @note This method writes to standard output and does not change the account.
   */
  void showBalance()
  {
    cout << this->getAccountHolder();
    cout << "'s balance is $" << getBalance() << endl;
  }
};

int main()
{

  /**
   * NOTE: We’ll use Jen’s account for most of the test cases, then we’ll test
   *       independence between multiple accounts with Eric’s account at the end.
   */

  // Ensure 2 decimal point precision from here on
  //  so dollar amounts display correctly
  cout << setprecision(2) << fixed;

  cout << "___________ BASIC BANK ACCOUNTS SIM _________\n";

  // TEST CASE 1: Initial balances
  // - Validates that multiple accounts can be created with an account holder
  //   and opening balance; integer literals are implicitly converted
  //   to double.
  cout << "\n************ TEST CASE: 1 ************\n\n";
  BankAccount jen_acct("Jennifer", 250);
  BankAccount eric_acct("Eric", 100.00);

  jen_acct.showBalance();
  eric_acct.showBalance();

  // TEST CASE 2: Invalid deposit -> negative deposit
  cout << "\n************ TEST CASE: 2 ************\n\n";
  jen_acct.deposit(-200.00);

  // TEST CASE 3: Valid deposit
  cout << "\n************ TEST CASE: 3 ************\n\n";
  jen_acct.deposit(70.50);

  // TEST CASE 4: Valid withdrawal
  cout << "\n************ TEST CASE: 4 ************\n\n";
  jen_acct.withdraw(200.00);

  // TEST CASE 5: Insufficient funds
  cout << "\n************ TEST CASE: 5 ************\n\n";
  eric_acct.withdraw(500.00);

  // TEST CASE 6: Exact-balance withdrawal
  cout << "\n************ TEST CASE: 6 ************\n\n";
  eric_acct.withdraw(100.00);

  // TEST CASE 7: Object independence
  // - After Run 6, call showBalance() on both accounts
  cout << "\n************ TEST CASE: 7 ************\n\n";
  jen_acct.showBalance();
  eric_acct.showBalance();

  // TEST CASE 8: Negative starting balance
  cout << "\n************ TEST CASE: 8 ************\n\n";
  BankAccount mike_acct("Mike", -10);

  // Get balance - it should be zero
  cout << " - Verifying ... ";
  mike_acct.showBalance();

  // TEST CASE 9: Zero dollar starting balance
  cout << "\n************ TEST CASE: 9 ************\n\n";
  BankAccount zero_acct("Zero", 0);

  // Get balance - it should be zero
  zero_acct.showBalance();

  cout << "_________________ END PROGRAM _______________\n\n";

  return 0;
}
