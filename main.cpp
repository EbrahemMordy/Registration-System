#include <bits/stdc++.h>
using namespace std;
map<string,int>Used;
map<string,string>DB;
map<string,pair<string,string>>Info;
void valid(string&s){
    string fi;
    for(auto i:s){
        if(i==' ')
            continue;
        fi+=i;
    }
    s=fi;
}
void RestPassword() {
    cout << "\t\t\t\t\t\t Welcome To Our Reset Password Page" << endl;
    string UserName, PassWord;
    cout << "Please Enter Your Username: ";
    Take_User:
    getline(cin, UserName);
    valid(UserName);
    if (UserName.empty() || !Used.count(UserName)) {
        goto Take_User;
    }
    cout << "Please Enter New Password: ";
    Take_Pass:
    getline(cin, PassWord);
    if (PassWord.empty()) {
        goto Take_Pass;
    }
    valid(UserName);
    valid(PassWord);
    DB[UserName] = PassWord;
}
void SignUp() {
    cout << "\t\t\t\t\t\t Welcome To Our Sign Up Page" << endl;
    string UserName, PassWord;
    cout << "Please Enter Username: ";
    Take_User:
    getline(cin, UserName);
    if (UserName.empty()) {
        goto Take_User;
    }
    string FirstName, LastName;
    cout << "Please Enter Your First Name: ";
    Take_First:
    getline(cin, FirstName);
    if (FirstName.empty()) {
        goto Take_First;
    }
    cout << "Please Enter Your Last Name: ";
    Take_Last:
    getline(cin, LastName);
    if (LastName.empty()) {
        goto Take_Last;
    }
    cout << "Please Enter Password: ";
    Take_Pass:
    getline(cin, PassWord);
    if (PassWord.empty()) {
        goto Take_Pass;
    }
    valid(UserName);
    valid(PassWord);
    Used[UserName] = 1;
    DB[UserName] = PassWord;
    Info[UserName] = {FirstName, LastName};
    cout << "\t\t\t\t\t\t Successfully Sign Up You Can Log In Now" << endl;
}
void LogIn() {
    Start:
    cout << "\t\t\t\t\t\t Welcome To Our Log In Page" << endl;
    string UserName, PassWord;
    cout << "Please Enter Username: ";
    Take_User:
    getline(cin, UserName);
    if (UserName.empty()) {
        goto Take_User;
    }
    cout << "Please Enter Password: ";
    Take_Pass:
    getline(cin, PassWord);
    if (PassWord.empty()) {
        goto Take_Pass;
    }
    valid(UserName);
    valid(PassWord);
    if (DB.count(UserName) && DB[UserName] == PassWord) {
        cout << "\t\t\t\t\t\t Log In Successfully" << endl;
        cout << "\t\t\t\t\t\t Your Informations:" << endl;
        cout << "Username: \t" << UserName << endl;
        cout << "First Name: \t" << Info[UserName].first << endl;
        cout << "Last Name: \t" << Info[UserName].second << endl;
    } else if (!DB.count(UserName)) {
        cout << "\t\t\t\t\t\t InCorrect Username" << endl;
        cout << "\t\t Want To Try Again? (Y/N)" << endl;
        char x;
        cin >> x;
        x = toupper(x);
        if (x == 'Y')
            goto Start;
        else
            return;
    } else {
        cout << "\t\t\t\t\t\t InCorrect Password" << endl;
        cout << "\t\t Want To Try Again? (Y/N)" << endl;
        char x;
        cin >> x;
        x = toupper(x);
        if (x == 'Y')
            goto Start;
        else
            return;
    }
}
int MainPage() {
    int x{};
    cout << "\t\t\t\t\t\t Welcome To Our Registration System" << endl;
    cout << "Please Select Want U Want To Do And Enter Number Of It:" << endl;
    while (!x) {
        cout << "\t 1 For Log in" << endl;
        cout << "\t 2 For Sign Up" << endl;
        cout << "\t 3 For Reset Password" << endl;
        cout << "\t 4 For Exit" << endl;
        cin >> x;
        if (x > 4 || x < 1) {
            cout << "\tPlease Enter Valid Number!!" << endl;
            x = 0;
        }
    }
    return x;
}
int main() {
    int OpType{};
    while ((OpType = MainPage() % 4)) {
        switch (OpType) {
            case 1:
                LogIn();
                break;
            case 2:
                SignUp();
                break;
            case 3:
                RestPassword();
                break;
            default:
                break;
        }
    }
    system("pause");
}