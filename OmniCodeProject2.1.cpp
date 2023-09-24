#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Simple Snake.cpp"

class consoleInterface {
protected:
    const std::string programName = "OmniCodeProject 2";
    const std::string programVersion = "Version 0.11";
    const std::string commandPrompt = " Please a Enter Command: ";
    const std::string invalidCommand = " is not a valid Command!";
    std::string userName = "User";
    char userInput;
    bool validCommandCheck = true;

    void drawHeaderMethod() {
        system("cls");
        std::cout << programName;
        std::cout << " ";
        std::cout << programVersion;
        std::cout << std::endl;
    }

    void userInputMethod() {
        std::cout << std::endl << userName << commandPrompt;
        std::cin >> userInput;
    }

    void invalidUserInputMethod() {
        std::cout << "[" << userInput << "]" << invalidCommand;
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

class consolePrograms : public consoleInterface {
private:
    void welcomeScreenMethod() {
        if (validCommandCheck != false) {
            system("cls");
            system("color 0F");
            std::cout << std::endl << "Greetings!!!  Thank You for chosing " << programName << " " << programVersion;
            std::cout << std::endl << std::endl;
            std::cout << "My Name Is Jake D and this is my C++ program.  I am learning C/C++ and I am using this program to apply" << std::endl;
            std::cout << "what I am learning as I learn it." << std::endl;
            std::cout << "The main part of this program is an interface I built to showcase to programs I have written as I advance in my studies" << std::endl;
            std::cout << "The next screen will ask you for your first and last name as well as your birth date.  I intend yo use this information" << std::endl;
            std::cout << "Within the program to make it feel more personable.  When you close the program everything you entered is deleted.";
            std::cout << std::endl << std::endl;
            std::cout << "By TYPING 'y' you give your concent for " << programName << " to collect personal data.";
            std::cout << std::endl << "If you do not concent then TYPE 'q' to quit the program immediately!" << std::endl;
        }
        else {
            invalidUserInputInterface();
        }

        userInputInterface();
        switch (userInput) {
        case 'q': std::_Exit(0); break;
        case 'y': return; break;
        default: {
            validCommandCheck = false;
            welcomeScreenMethod();
            break;
        }
        }
    }

    void moreInformationMethod() {
        if (validCommandCheck != false) {
            drawHeaderInterface();
            std::cout << std::endl << std::endl;
            std::cout << "Simple Snake is the very first game I have written in c++ code.  I followed online instructions to build the game and then I modified the code to intagrate it into THIS program" << std::endl;
            std::cout << "I have plans to modify the game to allow for different diffcaulty settings.";
            std::cout << std::endl << std::endl;
            std::cout << "Type 'r' to return to the Main Menu" << std::endl;
        }
        else {
            invalidUserInputInterface();
        }

        userInputInterface();
        switch (userInput) {
        case 'r':
        {
            return;
            break;
        }
        default: {
            validCommandCheck = false;
            moreInformationMethod();
            break;
        }
        }
    }

public:
    void welcomeScreenInterface() {
        welcomeScreenMethod();
    }

    void moreInformationInterface() {
        moreInformationMethod();
    }
};

class userID : public consolePrograms {
private:
    std::string firstName;
    std::string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;
    int age;

    void inputUserDataMethod() {
        system("cls");
        std::cout << std::endl << "For the best user experience, please use true and accurate data for the following questions" << std::endl << std::endl;
        std::cout << "What is your first name?: ";
        std::cin >> firstName;
        std::cout << "What is your last name?: ";
        std::cin >> lastName;
        std::cout << std::endl << "Next I am going to ask you for your birth date.  Please use number only!" << std::endl;
        std::cout << "An example of a valid date is 11/12/1984" << std::endl << std::endl;
        std::cout << "What is you birth MONTH?: ";
        std::cin >> birthMonth;
        std::cout << "What DAY where you born on?: ";
        std::cin >> birthDay;
        std::cout << "What YEAR where you born in?: ";
        std::cin >> birthYear;
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

    void outPutUserDataMethod() {
        if (validCommandCheck != false) {
            drawHeaderInterface();
            std::cout << std::endl << std::endl;
            std::cout << "The Current User of this program is " << firstName << " " << lastName;
            std::cout << std::endl << "You told me your Birth date was " << birthMonth << "/" << birthDay << "/" << birthYear;
            std::cout << std::endl << "That means you will turn " << age << " this year";
            std::cout << std::endl << std::endl;
            std::cout << "Type 'r' to return to the Main Menu" << std::endl;

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

class mainMenu : public userID {
protected:
    void optionsMenuMethod() {
        system("color 02");
        if (validCommandCheck != false) {
            drawHeaderInterface();
            std::cout << std::endl << std::endl;
            std::cout << "The following is a list of available commands" << std::endl << std::endl;
            std::cout << "Type '1' to Launch " << ssProgramName << " " << ssProgramVersion << std::endl;
            std::cout << "Type 'i' for more information about the programs listed here" << std::endl;
            std::cout << "Type 'u' to see your user information" << std::endl;
            std::cout << "Type 'r' to Refesh the screen" << std::endl;
            std::cout << "Type 'q' to Quit " << programName;
            std::cout << std::endl << std::endl;
        }
        else {
            invalidUserInputInterface();
        }

        userInputInterface();
        switch (userInput) {
        case '1': simpleSnake(); break;
        case 'i': moreInformationInterface(); break;
        case 'u': getUserDataInterface(); break;
        case 'r': validCommandCheck = true; optionsMenuMethod(); break;
        case 'q': std::_Exit(0); break;
        default: {
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

class program : private mainMenu {
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
