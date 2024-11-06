# ATM Machine Assignment
This program aims to perform the basic functions of user creation, login, and bank account management. 
This application stores a user's ID, PIN, and balance in a persistent .txt file. This allows the user information to be retained between sessions. 

### Project Structure
main.cpp - Handles program startup.
ATMMachine.cpp / .h - Handles the ATM operations, including user interaction and transactions.
AccountManager.cpp / .h - Handles user accounts, login, acount creation and save/load functionality.
User.h - Defines the User struct.

### Running the program
Navigate to the project directory in your terminal and execute the following command (Using GCC / g++)
```bash
 g++ main.cpp ATMMachine.cpp AccountManager.cpp -o atm_machine
 ```
This will create an executable named ```atm_machine.exe``` which can be opened through your file explorer or by running the following command.
```bash
./atm_machine
```