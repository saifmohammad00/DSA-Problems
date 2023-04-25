#include<bits/stdc++.h>
using namespace std;
int palindrome(string s,int i,int j)
{
	if(s[i]!=s[j])
	{
		cout<<"false";
		return 0;
	}
	if(s[i]==s[j])
	{
		if((i+1)>(j-1)||(i==j))
		{
			cout<<"true";
            return 1;
		}
		i++;
		j--;
	}
	return palindrome(s,i,j);

}
int main()
{
	string s;
	cin>>s;
	int i=0,j=s.size();
	palindrome(s,i,j-1);
	return 0;
}