/***
All right! Let's implement some pattern-matching using CPP strings.
You are given a string s of x and y. You need to verify whether the string follows the pattern xnyn. That is the string is valid only if equal number of ys follow equal number of xs.
As an example: xxyyxxyy is valid. xy is valid. xxyyx is invalid. xxxyyyxxyyxy is valid.
Input Format:
The first line of input contains T, the number of testcase. T testcases follow. Each testcase contains single line of input denoting the string s.
Output Format:
For each testcase, in a new line, print 1 if the string is valid else print 0.
Your Task:
Since this is a function problem, you don't need to take any input. Just complete the function follPatt(string s) that outputs 1 if string is valid, else it outputs 0.
Constraints:
1 <= T <= 100
1 <= |s| <=100
Examples:
Input:
2
xxyy
xyx
Output:
1
0
***/

#include <iostream>
#include<stack>
using namespace std;

bool check(char str[]){
	stack<char> s;
	char temp;
	int i=0;
	for(i=0;str[i]!='\0';i++){
		if(str[i]=='x'){
			s.push(str[i]);
			continue;
		}
		if(s.empty()){
			return false;
		}
		if(str[i]=='y'){
			s.pop();
		}
	}
	return (s.empty());
}
