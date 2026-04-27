#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Instruction function
void instructions()
{
    cout << "\n----------- Instructions -------------" << endl;
    cout << "Username:" << endl;
    cout << "- At least 7 characters" << endl;
    cout << "- Must contain '@'" << endl << endl;

    cout << "Password:" << endl;
    cout << "- At least 5 characters" << endl;
    cout << "- Must contain a special character" << endl;
    cout << "--------------------------------------" << endl;
}

// Registration function
void registration()
{
    string username, password;
    bool duplicate = false;

    do
    {
        cout << "\nEnter username: ";
        cin >> username;

        if (username.empty())
        {
            cout << "Error: Fields cannot be empty." << endl;
        }
        if (username.length() < 7)
        {
            cout << "Error: Username must be at least 7 characters." << endl;
        }
        else if (username.find('@') == string::npos)
        {
            cout << "Error: Username must contain '@'" << endl;
        }
    } while (username.length() < 7 || username.find('@') == string::npos);

    string specials = "!@#$%^&*";
    bool found = false;

    do
    {
        cout << "Enter password: ";
        cin >> password;

        if (password.empty())
        {
            cout << "Error: Fields cannot be empty." << endl;
            return;
        }
        if (password.length() < 5)
        {
            cout << "Error: Password must be at least 5 characters." << endl;
        }

        for (int i = 0; i < specials.length(); i++)
        {
            if (password.find(specials[i]) != string::npos)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Error: Password must contain a special character." << endl;
        }
    } while (password.length() < 5 || !found);

    // Check duplicate username
    ifstream readFile("users.txt");
    string fileUser, filePass;

    while (readFile >> fileUser >> filePass)
    {
        if (fileUser == username)
        {
            duplicate = true;
            break;
        }
    }
    readFile.close();

    if (duplicate)
    {
        cout << "Error: Username already exists." << endl;
        return;
    }

    // Store in file
    ofstream writeFile("users.txt", ios::app);
    writeFile << username << " " << password << endl;
    writeFile.close();

    cout << "Registration successful!" << endl;
}

// Login function
void login()
{
    string username, password;
    bool found_username = false;
    bool found_password = false;

    cout << "\nEnter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream readFile("users.txt");
    string fileUser, filePass;

    while (readFile >> fileUser >> filePass)
    {
        if (fileUser == username)
        {
            found_username = true;
        }
        if (filePass == password)
        {
            found_password = true;
            break;
        }
    }
    readFile.close();

    if (found_username)
    {
        if (found_password)
        {
            cout << "Login successful! Welcome, " << username << "." << endl;
        }
        else
        {
            cout << "Error: Invalid Password." << endl;
        }
    }
    else
    {
        cout << "Error: Invalid Username." << endl;
    }
}

int main()
{
    int choice;
    cout << "======================================" << endl;
    cout << "       Login Registration System  " << endl;
    cout << "======================================" << endl;
    do
    {
        cout << "\n1. Instructions\n2. Register\n3. Login\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            instructions();
        }
        else if (choice == 2)
        {
            registration();
        }
        else if (choice == 3)
        {
            login();
        }
        else if (choice == 4)
        {
            cout << "Exiting program! Thanks for using this system." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    system("pause");
    return 0;
}