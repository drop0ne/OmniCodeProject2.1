// OmniCodeProject2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include "Simple Snake.cpp"

using namespace std;

class consoleInterface {
protected:
    const string programName = "OmniCodeProject 2";
    const string programVersion = "Version 0.11";
    const string commandPrompt = " Please a Enter Command: ";
    const string invalidCommand = " is not a valid Command!";
    string userName = "User";
    char userInput;
    bool validCommandCheck = true;

    void drawHeaderMethod() {
        system("cls");
        cout << programName;
        cout << " ";
        cout << programVersion;
        cout << endl;
    }


    void userInputMethod() {
        cout << endl << userName << commandPrompt;
        cin >> userInput;
    }

    void invalidUserInputMethod() {
        cout  << "[" << userInput  << "]" << invalidCommand;
        validCommandCheck = true;
    }

        
public:
    void userInputInterface() {
        userInputMethod();
    }

    void drawHeaderInterface() {
        drawHeaderMethod();
    }

    void invalidUserInputInterface() {

        invalidUserInputMethod();
    }
};


class consolePrograms :public consoleInterface {
private:
    void welcomeScreenMethod()
    {
        if (validCommandCheck != false)
        {
            system("cls");
            system("color 0F");
            cout << endl << "Greetings!!!  Thank You for chosing " << programName << " " << programVersion;
            cout << endl << endl;
            cout << "My Name Is Jake D and this is my C++ program.  I am learning C/C++ and I am using this program to apply" << endl;
            cout << "what I am learning as I learn it." << endl;
            cout << "The main part of this program is an interface I built to showcase to programs I have written as I advance in my studies" << endl;
            cout << "The next screen will ask you for your first and last name as well as your birth date.  I intend yo use this information" << endl;
            cout << "Within the program to make it feel more personable.  When you close the program everything you entered is deleted.";
            cout << endl << endl;
            cout << "By TYPING 'y' you give your concent for " << programName << " to collect personal data.";
            cout << endl << "If you do not concent then TYPE 'q' to quit the program immediately!" << endl;
        }
        else
        {
            invalidUserInputInterface();
        }

        userInputInterface();
        switch (userInput)
        {
        case 'q': _Exit(0); break;
        case 'y': return; break;
        default:
        {
            validCommandCheck = false;
            welcomeScreenMethod();
            break;
        }
        }
    }


    void moreInformationMethod()
    {
        if (validCommandCheck != false)
        {
            drawHeaderInterface();
            cout << endl << endl;
            cout << "Simple Snake is the very first game I have written in c++ code.  I followed online instructions to build the game and then I modified the code to intagrate it into THIS program" << endl;
            cout << "I have plans to modify the game to allow for different diffcaulty settings.";
            cout << endl << endl;
            cout << "Type 'r' to return to the Main Menu" << endl;
        }
        else
        {
            invalidUserInputInterface();
        }

        userInputInterface();
        switch (userInput)
        {
        case 'r':
        {
            return;
            break;
        }
        default:
        {
            validCommandCheck = false;
            moreInformationMethod();
            break;
        }
        }
    }

public:
    void  welcomeScreenInterface() {
        welcomeScreenMethod();
    }

    void moreInformationInterface() {
        moreInformationMethod();
    }

};


class userID :public consolePrograms {
private:
    string firstName;
    string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;
    int age;

    void inputUserDataMethod() {
        system("cls");
        cout << endl << "For the best user experience, please use true and accurate data for the following questions" << endl << endl;
        cout << "What is your first name?: ";
        cin >> firstName;
        cout << "What is your last name?: ";
        cin >> lastName;
        cout << endl << "Next I am going to ask you for your birth date.  Please use number only!" << endl;
        cout << "An example of a valid date is 11/12/1984" << endl << endl;
        cout << "What is you birth MONTH?: ";
        cin >> birthMonth;
        cout << "What DAY where you born on?: ";
        cin >> birthDay;
        cout << "What YEAR where you born in?: ";
        cin >> birthYear;
        setAgeMethod();
        setUserNameMethod();
    }

    void setAgeMethod() {
        //magic code to pull the current year from the system
        time_t current_time;
        current_time = time(NULL);
        int currentYear;
        currentYear = 1970 + current_time / 31537970;
        //inorder to set 'age' variable
        age = currentYear - birthYear;
    }

    void setUserNameMethod() {
        userName = firstName;
    }


    void outPutUserDataMethod()
    {
        if (validCommandCheck != false) {
            drawHeaderInterface();
            cout << endl << endl;
            cout << "The Current User of this program is " << firstName << " " << lastName;
            cout << endl << "You told me your Birth date was " << birthMonth << "/" << birthDay << "/" << birthYear;
            cout << endl << "That means you will turn " << age << " this year";
            cout << endl << endl;
            cout << "Type 'r' to return to the Main Menu" << endl;

        }
        else {
            invalidUserInputInterface();
        }

        userInputInterface();
        switch (userInput) {
        case 'r': {
            return; break;
        }
        default: {
            validCommandCheck = false;
            outPutUserDataMethod();
            break;
        }
        }
    }

public:
    void inputUserDataInterface() {
        inputUserDataMethod();
    }

    void getUserDataInterface() {
        outPutUserDataMethod();
    }
};

class mainMenu :public userID {
protected:
    void optionsMenuMethod()
    {
        system("color 02");
        if (validCommandCheck != false)
        {
            drawHeaderInterface();
            cout << endl << endl;
            cout << "The following is a list of available commands" << endl << endl;
            cout << "Type '1' to Launch " << ssProgramName << " " << ssProgramVersion << endl;
            cout << "Type 'i' for more information about the programs listed here" << endl;
            cout << "Type 'u' to see your user information" << endl;
            cout << "Type 'r' to Refesh the screen" << endl;
            cout << "Type 'q' to Quit " << programName;
            cout << endl << endl;
        }
        else
        {
            invalidUserInputInterface();
        }

        userInputInterface();
        switch (userInput)
        {
        case '1': simpleSnake(); break;
        case 'i': moreInformationInterface(); break;
        case 'u': getUserDataInterface(); break;
        case 'r': validCommandCheck = true; optionsMenuMethod(); break;
        case 'q': _Exit(0); break;
        default:
        {
            validCommandCheck = false;
            optionsMenuMethod();
            break;
        }
        }
        optionsMenuMethod();
    }

public:
    void optionsMenuInterface() {
        optionsMenuMethod();
    }
};

class program :private mainMenu {
private:
    void runProgramMethod() {
        welcomeScreenInterface();
        inputUserDataInterface();
        optionsMenuInterface();
    }
public:
    void runProgram() {
        runProgramMethod();
    }
};


int main() {
    program OmniCodePropject;
    OmniCodePropject.runProgram();
}