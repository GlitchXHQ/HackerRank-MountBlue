/*
A numeric string, , is beautiful if it can be split into a sequence of two or more positive integers, , satisfying the following conditions:

 for any  (i.e., each element in the sequence is  more than the previous element).
No  contains a leading zero. For example, we can split  into the sequence , but it is not beautiful because  and  have leading zeroes.
The contents of the sequence cannot be rearranged. For example, we can split  into the sequence , but it is not beautiful because it breaks our first constraint (i.e., ).
The diagram below depicts some beautiful strings:

image

Perform  queries where each query consists of some integer string . For each query, print whether or not the string is beautiful on a new line. If it is beautiful, print YES x, where  is the first number of the increasing sequence. If there are multiple such values of , choose the smallest. Otherwise, print NO.

Function Description

Complete the separateNumbers function in the editor below.

separateNumbers has the following parameter:

s: an integer value represented as a string
Prints
- string: Print a string as described above. Return nothing.

Input Format

The first line contains an integer , the number of strings to evaluate.
Each of the next  lines contains an integer string  to query.

Constraints

Sample Input 0

7
1234
91011
99100
101103
010203
13
1
Sample Output 0

YES 1
YES 9
YES 99
NO
NO
NO
NO
Explanation 0

The first three numbers are beautiful (see the diagram above). The remaining numbers are not beautiful:

For , all possible splits violate the first and/or second conditions.
For , it starts with a zero so all possible splits violate the second condition.
For , the only possible split is , which violates the first condition.
For , there are no possible splits because  only has one digit.
Sample Input 1

4
99910001001
7891011
9899100
999100010001
Sample Output 1

YES 999
YES 7
YES 98
NO
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */

void separateNumbers(string s) {
    int n = s.size();
    
    for (int len = 1; len <= n/2; len++) {
        string first = s.substr(0, len);
        long long num = stoll(first);
        string built = first;
        
        while (built.size() < n) {
            num++;
            built += to_string(num);
        }
        
        if (built == s) {
            cout<< "YES " + first<<endl;
            return;
        }
    }
    cout<< "NO"<<endl;
}


int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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
