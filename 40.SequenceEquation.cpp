/*
Given a sequence of  integers,  where each element is distinct and satisfies . For each  where , that is  increments from  to , find any integer  such that  and keep a history of the values of  in a return array.

Example


Each value of  between  and , the length of the sequence, is analyzed as follows:

, so 
, so 
, so 
, so 
, so 
The values for  are .

Function Description

Complete the permutationEquation function in the editor below.

permutationEquation has the following parameter(s):

int p[n]: an array of integers
Returns

int[n]: the values of  for all  in the arithmetic sequence  to 
Input Format

The first line contains an integer , the number of elements in the sequence.
The second line contains  space-separated integers  where .

Constraints

, where .
Each element in the sequence is distinct.
Sample Input 0

3
2 3 1
Sample Output 0

2
3
1
Explanation 0

Given the values of , , and , we calculate and print the following values for each  from  to :

, so we print the value of  on a new line.
, so we print the value of  on a new line.
, so we print the value of  on a new line.
Sample Input 1

5
4 3 5 1 2
Sample Output 1

1
3
5
4
2
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'permutationEquation' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY p as parameter.
 */

// vector<int> permutationEquation(vector<int> p) {
//     vector<int> ans;
    
//     int i=1;
    
//     while(i<=p.size())
//     {
//         int temp=-1;
        
//         for(int j=0;j<p.size();j++){
//             if(p[j] == i)
//             {
//                 temp=j+1;
//                 break;
//             }
//         }
        
//         for(int j=0;j<p.size();j++){
//             if(p[j]==temp)
//             {
//                 temp=j+1;
//                 break;
//             }   
//         }
        
//         ans.push_back(temp);
        
//         i++;    
//     }   
     
//     return ans;
// }

vector<int> permutationEquation(vector<int> p) {
    vector<int> pos(p.size() + 1);
    
    for(int i=0;i<p.size();i++)
    pos[p[i]] = i + 1;
    
    vector<int> ans;
    
    for(int x=1;x<=p.size();x++)
    ans.push_back(pos[pos[x]]);
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split(rtrim(p_temp_temp));

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    vector<int> result = permutationEquation(p);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
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
