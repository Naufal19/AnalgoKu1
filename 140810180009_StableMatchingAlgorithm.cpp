/* 
 * C++ Program to Implement Stable Marriage Problem
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#define N  5
using namespace std;
/*
 * returns true if woman 'w' prefers man 'm1' over man 'm'
 */
bool wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
    {
        if (prefer[w][i] == m1)
            return true;
        if (prefer[w][i] == m)
           return false;
    }
}
/*
 * Prints stable matching for N boys and N girls. 
 */
void stableMarriage(int prefer[2*N][N])
{
    int wPartner[N];
    bool mFree[N];
    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    int freeCount = N;
    while (freeCount > 0)
    {
        int m;
        for ( m = 0; m < N; m++)
            if (mFree[m] == false)
                break;
        for (int i = 0; i < N && mFree[m] == false; i++)
        {
            int w = prefer[m][i];
            if (wPartner[w - N] == -1)
            {
                wPartner[w - N] = m;
                mFree[m] = true;
                freeCount--;
            }
 
            else
            {
                int m1 = wPartner[w-N];
                if (wPrefersM1OverM(prefer, w, m, m1) == false)
                {
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            }
        }
    }
    cout << "Woman   Man" << endl;
    for (int i = 0; i < N; i++)
        cout << " " << i + N << "\t" << wPartner[i] << endl;
}
 
/*
 * Main 
 */
int main()
{
    int prefer[2*N][N] = {  {6, 5, 8 ,9, 7 },
                            {8, 6, 5, 7, 9},
                            {6, 9, 7, 8 ,5},
                            {5, 8, 7, 6, 9},
                            {6, 8, 5, 9, 7},
                        
                            {4, 0, 1, 3, 2},
                            {2, 1, 3, 0, 4},
                            {1, 2, 3, 4, 0},
                            {0, 4, 3, 2, 1},
                            {3, 1, 4, 2, 0},
                            };
    stableMarriage(prefer);
    return 0;
}