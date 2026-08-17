/*
You wish to buy video games from the famous online video game store Mist.

Usually, all games are sold at the same price,  dollars. However, they are planning to have the seasonal Halloween Sale next month in which you can buy games at a cheaper price. Specifically, the first game will cost  dollars, and every subsequent game will cost  dollars less than the previous one. This continues until the cost becomes less than or equal to  dollars, after which every game will cost  dollars. How many games can you buy during the Halloween Sale?

Example



.

The following are the costs of the first , in order:

Start at  units cost, reduce that by  units each iteration until reaching a minimum possible price, . Starting with  units of currency in your Mist wallet, you can buy 5 games: .

Function Description

Complete the howManyGames function in the editor below.

howManyGames has the following parameters:

int p: the price of the first game
int d: the discount from the previous game price
int m: the minimum cost of a game
int s: the starting budget
Input Format

The first and only line of input contains four space-separated integers , ,  and .

Constraints

Sample Input 0

20 3 6 80
Sample Output 0

6
Explanation 0

Assumptions other than starting funds, , match the example in the problem statement. With a budget of , you can buy  games at a cost of . A  game for an additional  units exceeds the budget.

Sample Input 1

20 3 6 85
Sample Output 1

7
Explanation 1

This is the same as the previous case, except this time the starting budget  units of currency. This time, you can buy  games since they cost . An additional game at  units will exceed the budget.
*/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'howManyGames' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER d
 *  3. INTEGER m
 *  4. INTEGER s
 */

int howManyGames(int p, int d, int m, int s) {
    // Return the number of games you can buy
    int count=0;

    while(s>=p){        
        s-=p;
        count++;
        p=max(p-d,m);
    }
    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int p = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    int m = stoi(first_multiple_input[2]);

    int s = stoi(first_multiple_input[3]);

    int answer = howManyGames(p, d, m, s);

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
