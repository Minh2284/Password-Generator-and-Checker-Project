// Minh Nguyen
// Password Generator Personal Project
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
const string LOWER = "abcdefghijklmnopqrstuvwxyz";
const string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string NUM = "1234567890";
const string SPECIAL_CHAR = "!@#$%^&*()";
const string allPossible = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
string generatingPassword(int); // Generate password prototype
bool validatePass(string); // Validating password prototype
bool validateGenerator(string);
int userLength;
const int MIN_LENGTH = 8; // Minimum length that the user password has to be
int main(){
    string userInput;
    cout << "Do you want to generate a random password or check the strength of your current password? (Check/Generate): ";
    cin >> userInput;
    
    while(userInput != "Check" && userInput != "Generate"){
        cout << "Please enter a valid choice ('Check' or 'Generate'): ";
        cin >> userInput;
    }
    if(userInput == "Check"){
        string userPassword;
        cout << "Enter your password here: ";
        cin >> userPassword;
        validatePass(userPassword);
    } else if(userInput == "Generate"){
        string generatedPassword;
        do {
            generatedPassword = generatingPassword(MIN_LENGTH); // Generate a password with the minimum length
        } while (!validateGenerator(generatedPassword));
    }
    return 0;
}
// Generating random password function
string generatingPassword(int length){
    srand(static_cast<unsigned int>(time(nullptr)));
    string generatedPassword;
    for (int i = 0; i < length; ++i) {
        generatedPassword += allPossible[rand() % allPossible.size()];
    }
    return generatedPassword;
}
// Validating password function
bool validatePass(string password){
    long int length = password.length();
    bool hasLower = false;
    bool hasUpper = false;
    bool hasNum = false;
    bool hasSpecialChar = false;
    if(length < MIN_LENGTH){
        cout << "Your password is less than the minimum length which is " << MIN_LENGTH << ".\n";
        return false;
    }
    for(int i = 0; i < length; i++){
        for(int j = 0; j < LOWER.length(); j++){
            if(password[i] == LOWER[j]){
                hasLower = true;
                break;
            }
        }
        for(int t = 0; t < SPECIAL_CHAR.length(); t++){
            if(password[i] == SPECIAL_CHAR[t]){
                hasSpecialChar = true;
                break;
            }
        }
        for(int p = 0; p < UPPER.length(); p++){
            if(password[i] == UPPER[p]){
                hasUpper = true;
                break;
            }
        }
        for(int k = 0; k < NUM.length(); k++){
            if(password[i] == NUM[k]){
                hasNum = true;
                break;
            }
        }
    }
    if(!hasSpecialChar){
        cout << "Your password should contain at least one special character." << endl;
    }
    if(!hasNum){
        cout << "Your password should contain at least one number." << endl;
    }
    if(!hasUpper){
        cout << "Your password should contain at least one uppercase letter." << endl;
    }
    if(!hasLower){
        cout << "Your password should contain at least one lowercase letter." << endl;
    }
    if(hasLower && hasUpper && hasNum && hasSpecialChar){
        cout << "You have a good password. Your password meets all the criteria with having a special character, having a number, having a lower and uppercase letter, and having a minimum of at least 8 characters." << endl;
    }
    return hasLower && hasUpper && hasNum && hasSpecialChar;
}
// This function validates the generated password to make sure it pushes out a valid password
bool validateGenerator(string generatedPassword){
    long int length = generatedPassword.length();
    bool hasLower = false;
    bool hasUpper = false;
    bool hasNum = false;
    bool hasSpecialChar = false;
    if(length < MIN_LENGTH){
        cout << "Your password is less than the minimum length which is " << MIN_LENGTH << ".\n";
        return false;
    }
    for(int i = 0; i < length; i++){
        for(int j = 0; j < LOWER.length(); j++){
            if(generatedPassword[i] == LOWER[j]){
                hasLower = true;
                break;
            }
        }
        for(int t = 0; t < SPECIAL_CHAR.length(); t++){
            if(generatedPassword[i] == SPECIAL_CHAR[t]){
                hasSpecialChar = true;
                break;
            }
        }
        for(int p = 0; p < UPPER.length(); p++){
            if(generatedPassword[i] == UPPER[p]){
                hasUpper = true;
                break;
            }
        }
        for(int k = 0; k < NUM.length(); k++){
            if(generatedPassword[i] == NUM[k]){
                hasNum = true;
                break;
            }
        }
    }
    if(hasLower && hasUpper && hasNum && hasSpecialChar){
        cout << "Here is the generated password: " << generatedPassword << endl;
    }
    return hasLower && hasUpper && hasNum && hasSpecialChar;
}
