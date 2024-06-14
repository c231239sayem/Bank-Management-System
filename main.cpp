#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

void loginPage();
void accountDashboard(string accountNumber);
void createAccountPage();
void adminLoginPage();
void adminPage();
void updateTransactionLogs(string type,string accountNumber,double amount,double balance);

string getDate()
{
    auto currentTimePoint = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(currentTimePoint);
    tm* currentTM = localtime(&currentTime);
    int year = currentTM->tm_year + 1900;
    int month = currentTM->tm_mon + 1;
    int day = currentTM->tm_mday;
    string date;
    date=to_string(year)+"-"+to_string(month)+"-"+to_string(day);
    return date;
}

string getTime()
{
    auto currentTimePoint = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(currentTimePoint);
    tm* currentTM = localtime(&currentTime);
    int hours = currentTM->tm_hour;
    int minutes = currentTM->tm_min;
    int seconds = currentTM->tm_sec;
    string time;
    time=to_string(hours)+":"+to_string(minutes)+":"+to_string(seconds);
    return time;
}

void initialize()
{
    ifstream file1("System/111111.txt");
    if(!file1.good())
    {
        ofstream file("System/111111.txt",ios::trunc);
        file<<"111111";
        file.close();
    }
    ifstream file2("System/transactionlogs.txt");
    if(!file2.good())
    {
        ofstream file("System/transactionlogs.txt",ios::trunc);
        file.close();
    }
    ifstream file3("System/admin.txt");
    if(!file3.good())
    {
        ofstream file("System/admin.txt",ios::trunc);
        file<<"admin";
        file.close();
    }
    ifstream file4("Users/111111.txt");
    if(!file4.good())
    {
        ofstream file("Users/111111.txt",ios::trunc);
        file<< "password" <<endl;
        file<< "Emily Anderson" << endl;
        file<< "emily.anderson@email.com" << endl;
        file<< "(555) 765-4321" << endl;
        file<< "567 Rose Lane" << endl;
        file<< "Blossomville" << endl;
        file<< "Florida" << endl;
        file<< "98765" << endl;
        file<< "United States" << endl;
        file<< "111111" << endl;
        file<< "Savings" << endl;
        file<< 5000.00 << endl;
        file<< getDate() <<endl;
        file<< 0 <<endl;
        file<<getDate()<<"    "<<getTime()<<"    Deposit    111111    $5000.000000    $5000.000000";
        file.close();
    }
}

class User
{
private:
    string fullName;
    string email;
    string phoneNumber;

    string streetAddress;
    string cityTown;
    string stateProvince;
    string postalCode;
    string country;

    string accountNumber;
    string password;
    string accountType;
    double balance;
    string accountCreatedOn;

    int isAccountFrozenFlag=0;

    vector<string> transactionHistory;

public:
    static int defaultAccountNumber;
    // Getter methods
    string getFullName()
    {
        return fullName;
    }
    string getEmail()
    {
        return email;
    }
    string getPhoneNumber()
    {
        return phoneNumber;
    }
    string getStreetAddress()
    {
        return streetAddress;
    }
    string getCityTown()
    {
        return cityTown;
    }
    string getStateProvince()
    {
        return stateProvince;
    }
    string getPostalCode()
    {
        return postalCode;
    }
    string getCountry()
    {
        return country;
    }
    string getAccountNumber()
    {
        return accountNumber;
    }
    string getPassword()
    {
        return password;
    }
    string getAccountType()
    {
        return accountType;
    }
    double getBalance()
    {
        return balance;
    }
    string getAccountCreatedOn()
    {
        return accountCreatedOn;
    }
    int isAccountFrozen()
    {
        return isAccountFrozenFlag;
    }
    vector<string> getTransactionHistory()
    {
        return transactionHistory;
    }

    // Setter methods
    void setFullName(const string& newFullName)
    {
        fullName = newFullName;
    }
    void setEmail(const string& newEmail)
    {
        email = newEmail;
    }
    void setPhoneNumber(const string& newPhoneNumber)
    {
        phoneNumber = newPhoneNumber;
    }
    void setStreetAddress(const string& newStreetAddress)
    {
        streetAddress = newStreetAddress;
    }
    void setCityTown(const string& newCityTown)
    {
        cityTown = newCityTown;
    }
    void setStateProvince(const string& newStateProvince)
    {
        stateProvince = newStateProvince;
    }
    void setPostalCode(const string& newPostalCode)
    {
        postalCode = newPostalCode;
    }
    void setCountry(const string& newCountry)
    {
        country = newCountry;
    }
    void setAccountNumber(const string& newAccountNumber)
    {
        accountNumber = newAccountNumber;
    }
    void setPassword(const string& newPassword)
    {
        password = newPassword;
    }
    void setAccountType(const string& newAccountType)
    {
        accountType = newAccountType;
    }
    void setBalance(double newBalance)
    {
        balance = newBalance;
    }
    void setAccountCreatedOn(const string& newAccountCreatedOn)
    {
        accountCreatedOn = newAccountCreatedOn;
    }
    void setAccountFrozen(int status)
    {
        isAccountFrozenFlag = status;
    }
    void setTransactionHistory(string line)
    {
        transactionHistory.push_back(line);
    }
    void setTransactionHistory(string type,string accountNumber,double amount)
    {
        string line;
        line=getDate()+"    "+getTime()+"    "+type+"    "+accountNumber+"    $"+to_string(amount)+"    $"+to_string(getBalance());
        transactionHistory.push_back(line);
    }
    static void setdefaultAccountNumber()
    {
        ifstream file1("System/111111.txt");
        int number;
        file1>>number;
        ++number;
        defaultAccountNumber=number;
        file1.close();
        ofstream file2("System/111111.txt",ios::trunc);
        file2<<number;
        file2.close();
    }
};
int User::defaultAccountNumber=111111;

User loadUser(string accountNumber)
{
    User user;
    ifstream file("Users/"+accountNumber+".txt");
    string temp;
    getline(file,temp);
    user.setPassword(temp);
    getline(file,temp);
    user.setFullName(temp);
    getline(file,temp);
    user.setEmail(temp);
    getline(file,temp);
    user.setPhoneNumber(temp);
    getline(file,temp);
    user.setStreetAddress(temp);
    getline(file,temp);
    user.setCityTown(temp);
    getline(file,temp);
    user.setStateProvince(temp);
    getline(file,temp);
    user.setPostalCode(temp);
    getline(file,temp);
    user.setCountry(temp);
    getline(file,temp);
    user.setAccountNumber(temp);
    getline(file,temp);
    user.setAccountType(temp);
    getline(file,temp);
    user.setBalance(stod(temp));
    getline(file,temp);
    user.setAccountCreatedOn(temp);
    getline(file,temp);
    user.setAccountFrozen(stoi(temp));
    while(getline(file,temp))
    {
        user.setTransactionHistory(temp);
    }
    file.close();
    return user;
}

void updateUser(User user,string accountNumber)
{
    vector<string> transactionHistory=user.getTransactionHistory();
    ofstream file("Users/"+accountNumber+".txt",ios::trunc);
    if(file.is_open())
    {
        file<< user.getPassword() <<endl;
        file<< user.getFullName() << endl;
        file<< user.getEmail() << endl;
        file<< user.getPhoneNumber() << endl;
        file<< user.getStreetAddress() << endl;
        file<< user.getCityTown() << endl;
        file<< user.getStateProvince() << endl;
        file<< user.getPostalCode() << endl;
        file<< user.getCountry() << endl;
        file<< user.getAccountNumber() << endl;
        file<< user.getAccountType() << endl;
        file<< user.getBalance() << endl;
        file<< user.getAccountCreatedOn()<<endl;
        file<< user.isAccountFrozen()<<endl;
        for(int i=0; i<transactionHistory.size(); i++)
        {
            if(i<(transactionHistory.size()-1))
            {
                file<<transactionHistory[i]<<endl;
            }
            else
            {
                file<<transactionHistory[i];
            }
        }
        file.close();
    }
}

void accountDetails(User &user)
{
    system("cls");
    cout<<"\t----------------------------------\n";
    cout<<"\t\tView Account Details\n";
    cout<<"\t----------------------------------\n\n";
    cout<<"Full Name: "<<user.getFullName()<<endl;
    cout<<"Address: "<<user.getStreetAddress()<<", "<<user.getCityTown()<<", "<<user.getStateProvince()<<", "<<user.getCountry()<<endl;
    cout<<"\nContact information\n";
    cout<<"\tEmail: "<<user.getEmail()<<endl;
    cout<<"\tPhone Number: "<<user.getPhoneNumber()<<endl;
    cout<<"\nAccount Number: "<<user.getAccountNumber()<<endl;
    cout<<"Account Type: "<<user.getAccountType()<<endl;
    cout<<"Account Created On: "<<user.getAccountCreatedOn()<<endl;
    cout<<"\nCurrent Balance: $"<<user.getBalance()<<endl;
    cout<<"\n[Press any key to go back to the Account Dashboard]"<<endl;
    getch();
}

void homePage()
{
    system("cls");
    cout<<"\t-------------------------------------\n";
    cout<<"\tWelcome to the Bank Management System\n";
    cout<<"\t-------------------------------------\n\n";
    cout<<"\t1. Login"<<endl;
    cout<<"\t2. Create an Account"<<endl;
    cout<<"\t3. Admin"<<endl;
    cout<<"\t4. Exit"<<endl;
    cout<<endl;
    cout<<"Please enter the number corresponding to your choice: ";
    int choice;
    do
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
            loginPage();
            break;
        case 2:
            createAccountPage();
            break;
        case 3:
            adminLoginPage();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Enter the correct choice: ";
            break;
        }
    }
    while(choice<1 || choice>4);
}

void loginPage()
{
    system("cls");
    cout<<"\t--------------------------\n";
    cout<<"\t\tLogin Page\n";
    cout<<"\t--------------------------\n\n";
    cout<<"\tEnter your Account Number:\n";
    cout<<"\tEnter your Password:\n";
    cout<<"\nNew User? Press '0' to go back to the homepage\nor any key to continue.\n";
    char choice=getch();
    if(choice=='0')
    {
        homePage();
        return;
    }
    string accountNumber;
    string password;
    cout<<"\nEnter your Account Number: ";
    cin>>accountNumber;
    ifstream file("Users/"+accountNumber+".txt");
    if(file.is_open())
    {
        User user;
        user=loadUser(accountNumber);
        cin.ignore();
        int i=0;
        do
        {
            if(i==0)
                cout<<"Enter your Password: ";
            else if(i>0)
                cout<<"Incorrect! Enter the correct Password: ";
            //cin>>password;
            getline(cin,password);
            i++;
        }
        while(password!=user.getPassword());
        file.close();
        if(password==user.getPassword() && user.isAccountFrozen()==0) accountDashboard(accountNumber);
        else
        {
            cout<<"\nCannot login. Your account is frozen\n";
            cout<<"\n\nPress any key to continue.\n";
            getch();
            loginPage();
        }
    }
    else
    {
        cout<<"\nThere is no account with the account number: "<<accountNumber<<endl;
        cout<<"\n\nPress any key to continue.\n";
        getch();
        loginPage();
    }
}

void accountDashboard(string accountNumber)
{
    system("cls");
    cout<<"\t---------------------------------\n";
    cout<<"\t\tAccount Dashboard\n";
    cout<<"\t---------------------------------\n\n";
    User user;
    user=loadUser(accountNumber);
    cout<<"\tWelcome, "<<user.getFullName()<<"!\n\n";
    cout<<"\tAccount Number: "<<user.getAccountNumber()<<endl;
    cout<<"\tBalance: $"<<user.getBalance()<<endl;
    cout<<endl;
    cout<<"\t1. View Account Details\n";
    cout<<"\t2. Deposit Money\n";
    cout<<"\t3. Withdraw Money\n";
    cout<<"\t4. Tranfer Funds\n";
    cout<<"\t5. View Transaction History\n";
    cout<<"\t6. Change Password\n";
    cout<<"\t7. Logout\n";
    cout<<endl;
    cout<<"Please enter the number corresponding to your choice: ";
    int choice;
    do
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
            accountDetails(user);
            break;
        case 2:
        {
            system("cls");
            cout<<"\t--------------------------\n";
            cout<<"\t\tDeposit Money\n";
            cout<<"\t--------------------------\n\n";
            cout<<"\tCurrent Balance: $"<<user.getBalance()<<endl;
            double depositAmount;
            cout<<"\nEnter the Deposit Amount: $";
            cin>>depositAmount;
            user.setBalance(depositAmount+user.getBalance());
            user.setTransactionHistory("Deposit",accountNumber,depositAmount);
            updateTransactionLogs("Deposit",accountNumber,depositAmount,user.getBalance());
            cout<<"Amount of money $"<<depositAmount<<" is successfully added to your account.\n";
            cout<<"\tNew Balance: $"<<user.getBalance()<<endl;
            updateUser(user,accountNumber);
            cout<<"\n[Press any key to go back]\n";
            getch();
            break;
        }
        case 3:
        {
            system("cls");
            cout<<"\t------------------------------\n";
            cout<<"\t\tWithdraw Money\n";
            cout<<"\t------------------------------\n\n";
            cout<<"\tCurrent Balance: $"<<user.getBalance()<<endl;
            double withdrawalAmount;
            if(user.getBalance()==0 || user.getBalance()<0.1)
            {
                cout<<"Cannot withdraw money since your balance is $"<<user.getBalance()<<endl;
                cout<<"\n[Press any key to go back]\n";
                getch();
                break;
            }
            else
            {
                int i=0;
                do
                {
                    if(i==0) cout<<"Enter the Withdrawal Amount: $";
                    else if(i>0)
                    {
                        cout<<"\nInsufficient Balance!\n";
                        cout<<"Enter the Withdrawal Amount: $";
                    }
                    cin>>withdrawalAmount;
                    i++;
                }
                while(withdrawalAmount>user.getBalance());
                user.setBalance(user.getBalance()-withdrawalAmount);
                user.setTransactionHistory("Withdraw",accountNumber,withdrawalAmount);
                updateTransactionLogs("Withdraw",accountNumber,withdrawalAmount,user.getBalance());
                cout<<"Amount of money $"<<withdrawalAmount<<" is withdrawn from your account successfully.\n";
                cout<<"\tNew Balance: $"<<user.getBalance()<<endl;
                updateUser(user,accountNumber);
                cout<<"\n[Press any key to go back]\n";
                getch();
                break;
            }
        }
        case 4:
        {
            system("cls");
            cout<<"\t------------------------------\n";
            cout<<"\t\tTransfer Funds\n";
            cout<<"\t------------------------------\n\n";
            cout<<"\tCurrent Balance: $"<<user.getBalance()<<endl;
            double transferAmount;
            if(user.getBalance()==0 || user.getBalance()<0.1)
            {
                cout<<"Cannot transfer funds due to insufficient balance.\n";
                cout<<"\n[Press any key to go back]\n";
                getch();
                break;
            }
            else
            {
                int i=0;
                do
                {
                    if(i==0) cout<<"Enter the Transfer Amount: $";
                    else if(i>0)
                    {
                        cout<<"\nInsufficient Balance!\n";
                        cout<<"\nEnter the Transfer Amount: $";
                    }
                    cin>>transferAmount;
                    i++;
                }
                while(transferAmount>user.getBalance());
                string recipientAccountNumber;
                int j=0;
                int flag=0;
                do
                {
                    flag=0;
                    if(j==0) cout<<"Recipient's Account Number: ";
                    else if(j>0)
                    {
                        if(recipientAccountNumber==accountNumber)
                        {
                            cout<<"\nCannot transfer money to your own account.\n";
                            cout<<"\nEnter another account number: ";
                        }
                        else
                        {
                            cout<<"\nAccount does not exist!\n";
                            cout<<"\nEnter a valid account number: ";
                        }
                    }
                    cin>>recipientAccountNumber;
                    ifstream file("Users/"+recipientAccountNumber+".txt");
                    if(file.is_open())
                    {
                        flag=1;
                        file.close();
                    }
                    j++;
                }
                while(flag==0 || recipientAccountNumber==accountNumber);
                User recipientUser;
                recipientUser=loadUser(recipientAccountNumber);
                if(recipientUser.isAccountFrozen()==1)
                {
                    cout<<"\nCannot transfer funds.\n";
                    cout<<"User's account is locked or frozen.\n";
                    goto end;
                }
                int n;
                cout<<"\nTransferring $"<<transferAmount<<" to the account user named "<<recipientUser.getFullName()<<endl;
                cout<<"\nEnter 1 to continue or 0 to cancel transferring funds: ";
                cin>>n;
                if(n==1)
                {
                    user.setBalance(user.getBalance()-transferAmount);
                    user.setTransactionHistory("Transfer",recipientAccountNumber,transferAmount);
                    recipientUser.setBalance(recipientUser.getBalance()+transferAmount);
                    recipientUser.setTransactionHistory("Transfer",accountNumber,transferAmount);
                    updateTransactionLogs("Transfer",recipientAccountNumber,transferAmount,user.getBalance());
                    updateTransactionLogs("Transfer",accountNumber,transferAmount,recipientUser.getBalance());
                    updateUser(user,accountNumber);
                    updateUser(recipientUser,recipientAccountNumber);
                    cout<<"\nMoney transferred successfully.\n";
                }
                else if(n==0)
                    cout<<"\nMoney transfer denied.\n";
                else
                {
                    cout<<"\nInvalid input.\n";
                    cout<<"Money transfer denied.\n";
                }
end:
                cout<<"\n[Press any key to go back]\n";
                getch();
                break;
            }
        }
        case 5:
        {
            system("cls");
            cout<<"\t-----------------------------------\n";
            cout<<"\t\tTransaction History\n";
            cout<<"\t-----------------------------------\n\n";
            cout<<"------------------------------------------------------------------------------\n";
            cout<<"Date      |   Time    |  Type    |  Account | Amount      |   Running Balance\n";
            cout<<"          |           |          |  Number  |             |\n";
            cout<<"------------------------------------------------------------------------------\n";
            vector<string> transactionHistory=user.getTransactionHistory();
            for(int i=0; i<transactionHistory.size(); i++)
            {
                cout<<transactionHistory[i]<<endl;
            }
            cout<<"\n[Press any key to go back]\n";
            getch();
            break;
        }
        case 6:
        {
            system("cls");
            cout<<"\t------------------------------\n";
            cout<<"\t\tChange Password\n";
            cout<<"\t------------------------------\n\n";
            string oldPassword;
            string newPassword;
            string confirmPassword;
            cin.ignore();
            do
            {
                cout<<"Enter your old password: ";
                getline(cin,oldPassword);
                if(oldPassword!=user.getPassword())
                    cout<<"Password incorrect.\n";
            }
            while(oldPassword!=user.getPassword());
            do
            {
                cout << "Enter your new password: ";
                cin >> newPassword;
                cout << "Confirm your new password: ";
                cin >> confirmPassword;
                if (newPassword != confirmPassword)
                {
                    cout << "Passwords do not match. Please try again.\n";
                }
            }
            while (newPassword != confirmPassword);
            user.setPassword(newPassword);
            updateUser(user,accountNumber);
            cout << "Password changed successfully.\n";
            cout<<"\n[Press any key to go back]\n";
            getch();
            break;
        }
        case 7:
            loginPage();
            break;
        default:
            cout << "Enter the correct choice: ";
            break;
        }
    }
    while(choice<1 || choice>7);
    accountDashboard(accountNumber);
}

void createAccountPage()
{
    system("cls");
    cout<<"\t-------------------------------\n";
    cout<<"\tCreate an Account\n";
    cout<<"\t-------------------------------\n\n";

    User user;
    cout<<"\tEnter your Full Name:\n";
    cout<<"\tEmail:\n";
    cout<<"\tPhone Number:\n";
    cout<<"\tStreet Address:\n";
    cout<<"\tCity/Town:\n";
    cout<<"\tState/Province:\n";
    cout<<"\tPostal Code/ZIP Code:\n";
    cout<<"\tCountry:\n";
    cout<<"\tAccount Type(Savings/Checking/Fixed Deposit):\n";
    cout<<"\tInitial Deposit Amount:\n";
    cout<<"\tCreate a Password:\n";
    cout<<"\nPress '0' to go back to the homepage or any other keys to continue.\n";
    char input=getch();
    if(input=='0') homePage();
    cout<<endl;

    string temp;
    cout<<"Enter your Full Name: ";
    cin.ignore();
    getline(cin,temp);
    user.setFullName(temp);
    cout<<"Email: ";
    cin>>temp;
    user.setEmail(temp);
    cout<<"Phone Number: ";
    cin.ignore();
    getline(cin,temp);
    user.setPhoneNumber(temp);
    cout<<"Street Address: ";
    getline(cin,temp);
    user.setStreetAddress(temp);
    cout<<"City/Town: ";
    getline(cin,temp);
    user.setCityTown(temp);
    cout<<"State/Province: ";
    getline(cin,temp);
    user.setStateProvince(temp);
    cout<<"Postal Code/ZIP Code: ";
    cin>>temp;
    user.setPostalCode(temp);
    cout<<"Country: ";
    cin.ignore();
    getline(cin,temp);
    user.setCountry(temp);
    cout<<"Choose your Account Type:\n\t(a)Savings\n\t(b)Checking\n\t(c)Fixed Deposit\n";
    cout<<"\tYour Choice: ";
    cin>>temp;
    if(temp=="a") user.setAccountType("Savings");
    else if(temp=="b") user.setAccountType("Checking");
    else if(temp=="c") user.setAccountType("Fixed Deposit");
    cout<<"Initial Deposit Amount: $";
    cin>>temp;
    user.setBalance(stod(temp));
    cout<<"Create a Password: ";
    cin.ignore();
    getline(cin,temp);
    string confirmPassword;
    do
    {
        cout<<"Confirm Password: ";
        getline(cin,confirmPassword);
    }
    while(confirmPassword!=temp);
    user.setPassword(temp);
    User::setdefaultAccountNumber();
    user.setAccountNumber(to_string(User::defaultAccountNumber));
    temp=to_string(User::defaultAccountNumber);
    user.setAccountCreatedOn(getDate());
    user.setTransactionHistory("Deposit",user.getAccountNumber(),user.getBalance());
    updateTransactionLogs("Deposit",user.getAccountNumber(),user.getBalance(),user.getBalance());
    string line=getDate()+"    "+getTime()+"    "+"Deposit"+"    "+user.getAccountNumber()+"    $"+to_string(user.getBalance())+"    $"+to_string(user.getBalance());
    ofstream file("Users/"+temp+".txt",ios::trunc);
    if(file.is_open())
    {
        file<< user.getPassword() <<endl;
        file<< user.getFullName() << endl;
        file<< user.getEmail() << endl;
        file<< user.getPhoneNumber() << endl;
        file<< user.getStreetAddress() << endl;
        file<< user.getCityTown() << endl;
        file<< user.getStateProvince() << endl;
        file<< user.getPostalCode() << endl;
        file<< user.getCountry() << endl;
        file<< user.getAccountNumber() << endl;
        file<< user.getAccountType() << endl;
        file<< user.getBalance() << endl;
        file<< user.getAccountCreatedOn()<<endl;
        file<< user.isAccountFrozen()<<endl;
        file<< line;
        file.close();

        system("cls");
        cout<<"\t------------------------------------\n";
        cout<<"\t\tAccount Creation Success\n";
        cout<<"\t------------------------------------\n\n";
        cout<<"\tCongratulations, "<<user.getFullName()<<"! Your account has been successfully created.\n";
        cout<<"\n\tYour Unique Account Number: "<<user.getAccountNumber()<<endl;
        cout<<"\n\tPlease make note of this account number for future reference.\n\tYou can now log in to your account and start managing your finances.\n";
        cout<<"\n[Press any key to go back to the homepage]\n";
        getch();
        homePage();
    }
    else cout<<"Error opening file for new user\n";
}

void updateTransactionLogs(string type,string accountNumber,double amount,double balance)
{
    string line;
    line=getDate()+"    "+getTime()+"    "+type+"    "+accountNumber+"    $"+to_string(amount)+"    $"+to_string(balance);
    ofstream file("System/transactionlogs.txt",ios::app);
    if(file.is_open())
    {
        file<<line<<endl;
        file.close();
    }
    else
    {
        cout<<"\nError opening System/transactionlogs.txt\n";
    }
}

void viewUserAccounts()
{
    system("cls");
    cout<<"\t--------------------------------\n";
    cout<<"\t\tView User Accounts\n";
    cout<<"\t--------------------------------\n\n";
    int lastAccountNumber;
    ifstream file("System/111111.txt");
    file>>lastAccountNumber;
    file.close();
    cout<<"---------------------------------------------------------\n";
    cout<<"Account Number\tName\t\t\tCurrent Balance\n";
    cout<<"---------------------------------------------------------\n";
    for(int i=111111; i<=lastAccountNumber; i++)
    {
        User user=loadUser(to_string(i));
        cout<<user.getAccountNumber()<<"\t\t"<<user.getFullName()<<"\t\t"<<"$"<<user.getBalance()<<endl;
    }
    cout<<"\n[Press any key to go back]\n";
    getch();
}

void adminLoginPage()
{
    system("cls");
    cout<<"\t------------------------------\n";
    cout<<"\t\tAdmin Login\n";
    cout<<"\t------------------------------\n\n";
    cout<<"Enter your Password: ";
    string password;
    cin.ignore();
    getline(cin,password);
    ifstream file("System/admin.txt");
    string temp;
    file>>temp;
    if(password==temp) adminPage();
    else
    {
        cout<<"Password incorrect!\n";
        cout<<"\n[Press any key to go back]\n";
        getch();
        homePage();
    }
}

void adminPage()
{
    system("cls");
    cout<<"\t------------------------------\n";
    cout<<"\t\tAdmin Login\n";
    cout<<"\t------------------------------\n\n";
    cout<<"\t1. View User Accounts\n";
    cout<<"\t2. Search User Accounts\n";
    cout<<"\t3. Freeze User Accounts\n";
    cout<<"\t4. Unfreeze User Accounts\n";
    cout<<"\t5. View Transaction Logs\n";
    cout<<"\t6. Change Password\n";
    cout<<"\t7. Logout\n";
    cout<<endl;
    cout<<"Please enter the number corresponding to your choice: ";
    int choice;
    do
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
            viewUserAccounts();
            break;
        case 2:
        {
            system("cls");
            cout<<"\t---------------------------------\n";
            cout<<"\t\tSearch User Accounts\n";
            cout<<"\t---------------------------------\n\n";
            string accountNumber;
            cout<<"Enter the Account Number of the user: ";
            cin>>accountNumber;
            ifstream file("Users/"+accountNumber+".txt");
            if(file.is_open())
            {
                cout<<"Account user found!\n";
                User user=loadUser(accountNumber);
                cout<<"\n\tFull Name: "<<user.getFullName()<<endl;
                cout<<"\n\tContact information\n";
                cout<<"\t\tEmail: "<<user.getEmail()<<endl;
                cout<<"\t\tPhone Number: "<<user.getPhoneNumber()<<endl;
                cout<<"\n\tAccount Number: "<<user.getAccountNumber()<<endl;
                cout<<"\tAccount Type: "<<user.getAccountType()<<endl;
                cout<<"\tAccount Created On: "<<user.getAccountCreatedOn()<<endl;
                cout<<"\n\tCurrent Balance: $"<<user.getBalance()<<endl;
                cout<<"\n\tTransaction History of the user\n";
                cout<<"------------------------------------------------------------------------------\n";
                cout<<"Date      |   Time    |  Type    |  Account | Amount      |   Running Balance\n";
                cout<<"          |           |          |  Number  |             |\n";
                cout<<"------------------------------------------------------------------------------\n";
                vector<string> transactionHistory=user.getTransactionHistory();
                for(int i=0; i<transactionHistory.size(); i++)
                {
                    cout<<transactionHistory[i]<<endl;
                }
            }
            else
            {
                cout<<"\nSearched user not found.\n";
            }
            cout<<"\n[Press any key to go back]\n";
            getch();
            break;
        }
        case 3:
        {
            system("cls");
            cout<<"\t-------------------------------------\n";
            cout<<"\t\tFreeze User Accounts\n";
            cout<<"\t-------------------------------------\n\n";
            string accountNumber;
            cout<<"Enter the Account Number of the user to Freeze: ";
            cin>>accountNumber;
            ifstream file("Users/"+accountNumber+".txt");
            if(file.is_open())
            {
                cout<<"Account user found!\n";
                User user=loadUser(accountNumber);
                if(user.isAccountFrozen()==0)
                {
                    cout<<"Are you sure to freeze the account user named \""<<user.getFullName()<<"\"\n";
                    cout<<"Enter (Y/y) to freeze or (N/n) to cancel freezing account: ";
                    char choice;
                    cin>>choice;
                    if(choice=='Y' || choice=='y')
                    {
                        user.setAccountFrozen(1);
                        updateUser(user,accountNumber);
                        cout<<"\nAccount frozen successfully.\n";
                    }
                    else if(choice=='N' || choice=='n')
                    {
                        cout<<"Cancelled freezing account\n";
                    }
                }
                else
                {
                    cout<<"User account already frozen.\n";
                }
                file.close();
            }
            else
            {
                cout<<"\nSearched user not found.\n";
            }
            cout<<"\n[Press any key to go back]\n";
            getch();
            break;
        }
        case 4:
        {
            system("cls");
            cout<<"\t--------------------------------------\n";
            cout<<"\t\tUnfreeze User Accounts\n";
            cout<<"\t--------------------------------------\n\n";
            string accountNumber;
            cout<<"Enter the Account Number of the user to Unfreeze: ";
            cin>>accountNumber;
            ifstream file("Users/"+accountNumber+".txt");
            if(file.is_open())
            {
                cout<<"Account user found!\n";
                User user=loadUser(accountNumber);
                if(user.isAccountFrozen()==1)
                {
                    cout<<"Are you sure to unfreeze the account user named \""<<user.getFullName()<<"\"\n";
                    cout<<"Enter (Y/y) to unfreeze or (N/n) to cancel unfreezing account: ";
                    char choice;
                    cin>>choice;
                    if(choice=='Y' || choice=='y')
                    {
                        user.setAccountFrozen(0);
                        updateUser(user,accountNumber);
                        cout<<"\nAccount unfrozen successfully.\n";
                    }
                    else if(choice=='N' || choice=='n')
                    {
                        cout<<"Cancelled unfreezing account\n";
                    }
                }
                else
                {
                    cout<<"\nUser account already unfrozen.\n";
                }
                file.close();
            }
            else
            {
                cout<<"\nSearched user not found.\n";
            }
            cout<<"\n[Press any key to go back]\n";
            getch();
            break;
        }
        case 5:
        {
            system("cls");
            cout<<"\t--------------------------------\n";
            cout<<"\t\tView Transaction Logs\n";
            cout<<"\t--------------------------------\n\n";
            string line;
            ifstream file("System/transactionlogs.txt");
            if(file.is_open())
            {
                cout<<"\n\tTransaction History of the All Users\n";
                cout<<"------------------------------------------------------------------------------\n";
                cout<<"Date      |   Time    |  Type    |  Account | Amount      |   Running Balance\n";
                cout<<"          |           |          |  Number  |             |\n";
                cout<<"------------------------------------------------------------------------------\n";
                while(getline(file,line))
                {
                    cout<<line<<endl;
                }
                file.close();
            }
            else
            {
                cout<<"Error opening file System/transactionlogs.txt\n";
            }
            cout<<"\n[Press any key to go back]\n";
            getch();
            break;
        }
        case 6:
        {
            system("cls");
            cout<<"\t------------------------------\n";
            cout<<"\t\tChange Password\n";
            cout<<"\t------------------------------\n\n";
            string oldPassword;
            string newPassword;
            string confirmPassword;
            string temp;
            ifstream file1("System/admin.txt");
            getline(file1,temp);
            file1.close();
            cin.ignore();
            do
            {
                cout<<"Enter your old password: ";
                getline(cin,oldPassword);
                if(oldPassword!=temp)
                    cout<<"Password incorrect.\n";
            }
            while(oldPassword!=temp);
            do
            {
                cout << "Enter your new password: ";
                cin >> newPassword;
                cout << "Confirm your new password: ";
                cin >> confirmPassword;
                if (newPassword != confirmPassword)
                {
                    cout << "Passwords do not match. Please try again.\n";
                }
            }
            while (newPassword != confirmPassword);
            ofstream file2("System/admin.txt",ios::trunc);
            file2<<newPassword;
            file2.close();
            cout << "Password changed successfully.\n";
            cout<<"\n[Press any key to go back]\n";
            getch();
            break;
        }
        case 7:
            homePage();
            break;
        default:
            cout << "Enter the correct choice: ";
            break;
        }
    }
    while(choice<1 || choice>7);
    adminPage();
}

int main()
{
    initialize();
    homePage();
    return 0;
}
