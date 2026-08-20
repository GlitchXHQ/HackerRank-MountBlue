/*
Given an array of stick lengths, use  of them to construct a non-degenerate triangle with the maximum possible perimeter. Return an array of the lengths of its sides as  integers in non-decreasing order.

If there are several valid triangles having the maximum perimeter:

Choose the one with the longest maximum side.
If more than one has that maximum, choose from them the one with the longest minimum side.
If more than one has that maximum as well, print any one them.
If no non-degenerate triangle exists, return .

Example

The triplet  will not form a triangle. Neither will  or , so the problem is reduced to  and . The longer perimeter is .

Function Description

Complete the maximumPerimeterTriangle function in the editor below.

maximumPerimeterTriangle has the following parameter(s):

int sticks[n]: the lengths of sticks available
Returns

int[3] or int[1]: the side lengths of the chosen triangle in non-decreasing order or -1
Input Format

The first line contains single integer , the size of array .
The second line contains  space-separated integers , each a stick length.

Constraints

Sample Input 0

5
1 1 1 3 3
Sample Output 0

1 3 3
Explanation 0

There are  possible unique triangles:

The second triangle has the largest perimeter, so we print its side lengths on a new line in non-decreasing order.

Sample Input 1

3
1 2 3
Sample Output 1

-1
Explanation 1

The triangle  is degenerate and thus can't be constructed, so we print -1 on a new line.

Sample Input 2

6
1 1 1 2 3 5
Sample Output 2

1 1 1
Explanation 2

The triangle (1,1,1) is the only valid triangle.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximumPerimeterTriangle' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY sticks as parameter.
 */

vector<int> maximumPerimeterTriangle(vector<int> sticks) {
    sort(sticks.begin(), sticks.end());
    vector<int> ans;

    for(int i = sticks.size()-3; i >= 0; i--) {
        if(sticks[i] + sticks[i+1] > sticks[i+2]) {
            ans = {sticks[i], sticks[i+1], sticks[i+2]};
            return ans; 
        }
    }

    return {-1};
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string sticks_temp_temp;
    getline(cin, sticks_temp_temp);

    vector<string> sticks_temp = split(rtrim(sticks_temp_temp));

    vector<int> sticks(n);

    for (int i = 0; i < n; i++) {
        int sticks_item = stoi(sticks_temp[i]);

        sticks[i] = sticks_item;
    }

    vector<int> result = maximumPerimeterTriangle(sticks);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
