/*
Louise joined a social networking site to stay in touch with her friends. The signup page required her to input a name and a password. However, the password must be strong. The website considers a password to be strong if it satisfies the following criteria:

Its length is at least .
It contains at least one digit.
It contains at least one lowercase English character.
It contains at least one uppercase English character.
It contains at least one special character. The special characters are: !@#$%^&*()-+
She typed a random string of length  in the password field but wasn't sure if it was strong. Given the string she typed, can you find the minimum number of characters she must add to make her password strong?

Note: Here's the set of types of characters in a form you can paste in your solution:

numbers = "0123456789"
lower_case = "abcdefghijklmnopqrstuvwxyz"
upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
special_characters = "!@#$%^&*()-+"
Example


This password is 5 characters long and is missing an uppercase and a special character. The minimum number of characters to add is .


This password is 5 characters long and has at least one of each character type. The minimum number of characters to add is .

Function Description

Complete the minimumNumber function in the editor below.

minimumNumber has the following parameters:

int n: the length of the password
string password: the password to test
Returns

int: the minimum number of characters to add
Input Format

The first line contains an integer , the length of the password.

The second line contains the password string. Each character is either a lowercase/uppercase English alphabet, a digit, or a special character.

Constraints

All characters in  are in [a-z], [A-Z], [0-9], or [!@#$%^&*()-+ ].
Sample Input 0

3
Ab1
Sample Output 0

3
Explanation 0

She can make the password strong by adding  characters, for example, $hk, turning the password into Ab1$hk which is strong.

 characters aren't enough since the length must be at least .

Sample Input 1

11
#HackerRank
Sample Output 1

1
Explanation 1

The password isn't strong, but she can make it strong by adding a single digit.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

bool numberPresent(string password, string numbers)
{
    return password.find_first_of(numbers) != string::npos;
}

bool lowrCasePresent(string password, string lower_case)
{
    return password.find_first_of(lower_case) != string::npos;
}

bool UprCasePresent(string password, string Upr_case)
{
    return password.find_first_of(Upr_case) != string::npos;
}

bool SplCasePresent(string password, string Spl_case)
{
    return password.find_first_of(Spl_case) != string::npos;
}

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int cnt=0,length_shortfall = max(0, 6 - n);;

    if(!numberPresent(password, "0123456789")) cnt++;
    if(!lowrCasePresent(password, "abcdefghijklmnopqrstuvwxyz")) cnt++;
    if(!UprCasePresent(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")) cnt++;
    if(!SplCasePresent(password, "!@#$%^&*()-+")) cnt++;
    
    return max(length_shortfall,cnt);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
