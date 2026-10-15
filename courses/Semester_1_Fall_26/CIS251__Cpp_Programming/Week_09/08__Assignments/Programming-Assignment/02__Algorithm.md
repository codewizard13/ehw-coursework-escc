## 📊 Pseudocode Algorithm

# WEEK 8 PROGRAMMING ASSIGNMENT — Object-Oriented Programming: Classes, Objects, and Encapsulation



## BANKACCOUNT CLASS: ----------

      Private Data:
      - account holder
      - balance

      Constructor:
      - Set the account holder and starting balance
      - ??? Do not allow a negative starting balance (not sure if this is necessary?)

      Getters:
      - Return the account holder
      - Return the balance

      Methods:
      - Deposit money
      - Withdraw money


## MAIN: -----------------------

      Create two BankAccount objects

      Display each account's holder and starting balance

      Deposit money into the first account
      Withdraw money from the second account

      Attempt a withdrawal greater than the available balance

      Display both accounts' final balances
      Check that the results are correct


## SHOW BALANCE: ---------------

      Return the account's balance through its getter


## MAKE DEPOSIT: ---------------

      Receive the deposit amount

      If the amount is positive:
      Add it to the account's balance
      Otherwise:
      Leave the balance unchanged


## WITHDRAW: -------------------

      Receive the withdrawal amount

      If the amount is positive and does not exceed the balance:
      Subtract it from the account's balance
      Otherwise:
      Leave the balance unchanged
