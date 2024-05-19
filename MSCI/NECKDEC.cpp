/*
 * Sample solution for problem "Necklace Decomposition", NCPC 2005.
 * Author: Nils Grimsmo
 *
 * Solution: Iteratively join joinable neighbouring necklaces.
 *           Start by dividing string into the simple necklaces (0*1*).
 *           Fast but ugly.
 */

#include <iostream>
#include <string>
#include <vector>

#define MIN(X,Y) (((X) < Y) ? (X) : (Y))

using namespace std;

bool necklace(string T)
{
    size_t n = T.size();
    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (T[j] < T[(i+j) % n])
            {
                break;
            }
            if (T[j] > T[(i+j) % n])
            {
                return false;
            }
        }
    }
    return true;
}

void decomp(string S)
{
    vector<string> D;
    size_t i = 0;
    while (i < S.size())
    {
        string t;
        while (S[i] == '0')
        {
            t += "0";
            i++;
        }
        while (S[i] == '1')
        {
            t += "1";
            i++;
        }
        D.push_back(t);
    }
    bool changed = true;
    while (changed)
    {
        vector<string> newD;
        changed = false;
        for (size_t j = 0; j < D.size(); )
        {
            if (j < D.size() - 1 && D[j] <= D[j+1])
            {
                changed = true;
                newD.push_back(D[j] + D[j+1]);
                j += 2;
            }
            else
            {
                newD.push_back(D[j]);
                j += 1;
            }
        }
        if (! changed)
        {
            D = newD;
            newD = vector<string>();
            for (size_t j = 0; j < D.size(); )
            {
                if (j < D.size() - 1 && necklace(D[j] + D[j+1]))
                {
                    changed = true;
                    newD.push_back(D[j] + D[j+1]);
                    j += 2;
                }
                else
                {
                    newD.push_back(D[j]);
                    j += 1;
                }
            }
        }
        D = newD;
    }

    for (vector<string>::const_iterator it = D.begin(); it != D.end(); it++)
    {
        cout << "(" << *it << ")";
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string S;
        cin >> S;
        decomp(S);
        cout << endl;
    }
}
