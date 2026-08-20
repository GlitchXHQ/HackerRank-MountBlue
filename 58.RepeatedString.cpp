/*
There is a string, , of lowercase English letters that is repeated infinitely many times. Given an integer, , find and print the number of letter a's in the first  letters of the infinite string.

Example


The substring we consider is , the first  characters of the infinite string. There are  occurrences of a in the substring.

Function Description

Complete the repeatedString function in the editor below.

repeatedString has the following parameter(s):

s: a string to repeat
n: the number of characters to consider
Returns

int: the frequency of a in the substring
Input Format

The first line contains a single string, .
The second line contains an integer, .

Constraints

For  of the test cases, .
Sample Input

Sample Input 0

aba
10
Sample Output 0

7
Explanation 0
The first  letters of the infinite string are abaabaabaa. Because there are  a's, we return .

Sample Input 1

a
1000000000000
Sample Output 1

1000000000000
Explanation 1
Because all of the first  letters of the infinite string are a, we return .
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long repeatedString(string s, long n) {
    if(s.length()==1 && s[0]=='a') return n;
    long count=0;
    
    for(char c:s)
    if(c=='a') count++;
    
    long val=n/s.length();
    long total=count*val;
    
    long extra = n%s.length();
    for(int i=0;i<extra;i++)
    if(s[i]=='a') total++;
    
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

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
