/*
Alice has a binary string. She thinks a binary string is beautiful if and only if it doesn't contain the substring .

In one step, Alice can change a  to a  or vice versa. Count and print the minimum number of steps needed to make Alice see the string as beautiful.

Example


She can change any one element and have a beautiful string.

Function Description

Complete the beautifulBinaryString function in the editor below.

beautifulBinaryString has the following parameter(s):

string b: a string of binary digits
Returns

int: the minimum moves required
Input Format

The first line contains an integer , the length of binary string.
The second line contains a single binary string .

Constraints

.
Output Format

Print the minimum number of steps needed to make the string beautiful.

Sample Input 0

STDIN       Function
-----       --------
7           length of string n = 7
0101010     b = '0101010'
Sample Output 0

2  
Explanation 0:

In this sample, 

The figure below shows a way to get rid of each instance of :

binary.png

Make the string beautiful by changing  characters ( and ).

Sample Input 1

5
01100
Sample Output 1

0
Sample Case 1:

In this sample 

Explanation 1

The substring  does not occur in , so the string is already beautiful in  moves.

Sample Input 2

10
0100101010
Sample Output 2

3
Explanation 2

In this sample 

One solution is to change the values of  to form a beautiful string.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'beautifulBinaryString' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING b as parameter.
 */

int beautifulBinaryString(string s) {
    int count=0;
    for(int i=0;i<s.length()-2;i++)
    if(s[i]=='0' && s[i+1]=='1' && s[i+2]=='0'){
         s[i+2]='1';
         count++;
    }
    
    return count; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";

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
