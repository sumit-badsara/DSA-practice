#include<bits/stdc++.h>

using namespace std;

vector<int> computeLPS(string pattern)
{
    vector<int> lps(pattern.size(),0);
    int len=0;
    for(int i=1;i<pattern.size();)
    {
        if(pattern[len]==pattern[i])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len==0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len-1];
            }
        }
    }
    return lps;
}

void KMPSearch(string text, string pattern)
{
    vector <int> lps = computeLPS(pattern);

    int j=0;
    for(int i=0;i<text.size();)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }

        if(j==pattern.size())
        {
            cout<<"Found at "<<i-j<<"\n";
            j = lps[j-1];
        }

        if(i<text.size() && text[i]!=pattern[j])
        {
            if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }
}

int main()
{
    string text="JOJO WANTS A NEW JOJOJO, AS JOJO LOVES JOJOJOS", pattern="JOJO";
    
    KMPSearch(text, pattern);

    return 0;
}