/*
Given a time in -hour AM/PM format, convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

Example


Return '12:01:00'.


Return '00:01:00'.

Function Description

Complete the  function with the following parameter(s):

: a time in  hour format
Returns

: the time in  hour format
Input Format

A single string  that represents a time in -hour clock format (i.e.:  or ).

Constraints

All input times are valid
Sample Input 0

07:05:45PM
Sample Output 0

19:05:45
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string amOrpm=s.substr(s.length()-2);
    int time=stoi(s.substr(0,2));
    string restofTime=s.substr(2,6);
    string formattedHr="";

    if(amOrpm=="AM")
    {
        if(time == 12)
        formattedHr="00";
        else 
        formattedHr=s.substr(0,2);
    }

    else
    {
        if(time==12)
        formattedHr="12";
        else 
        formattedHr=to_string(time + 12);
    }
    return formattedHr + restofTime;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
