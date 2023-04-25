#include <bits/stdc++.h>
using namespace std;
char removechar(char st[],char given,char replace)
{   int i;
    for(i=0;st[i]!='\0';i++)
    {

    }
    if(i==0)
    {
      return 0;
    }
	if(st[0]==given)
	{
	  st[0]=replace;
	}
	return removechar(st+1,given,replace);

}
int main()
{
	char st[100];
	cin>>st;
	char given,replace;
	cin>>given>>replace;
    removechar(st,given,replace);
    cout<<st;
    return 0;
}