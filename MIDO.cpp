#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int whosWinning( int score1, int score2 )
{
    return (score1==score2)?0:((score1>score2)?1:2);
}

void copyValues( int &oldA, int &newA, int &oldB, int &newB )
{
    oldA = newA;
    oldB = newB;
}

int addSeconds(int newMinutes, int newSeconds, int &oldMinutes, int &oldSeconds )
{
    return (newMinutes*60+newSeconds)-(oldMinutes*60+oldSeconds);
}

int main ()
{
    int N;
    cin >> N;
    int team1=0, team2=0;
    int lastMinute = 0, lastSecond = 0;
    int totalSeconds1 = 0, totalSeconds2 = 0;
    int bstate = 0, astate = 0;
    for( int i=0; i<N; ++i )
    {
        int whoScored;
        cin >> whoScored;

        bstate = whosWinning( team1, team2 );
        if( whoScored == 1 ) ++team1;
        else ++team2;

        astate = whosWinning( team1, team2 );
        int minutes,seconds;
        scanf("%d:%d",&minutes,&seconds);

        if( bstate == 0 && astate == 2 || bstate == 0 && astate == 1 )
            copyValues( lastMinute, minutes, lastSecond, seconds );
        else if( bstate == 1 && astate == 0 )
        {
            totalSeconds1 += addSeconds( minutes, seconds, lastMinute, lastSecond );
            copyValues( lastMinute, minutes, lastSecond, seconds );
        }
        else if( bstate == 2 && astate == 0 )
        {
            totalSeconds2 += addSeconds( minutes, seconds, lastMinute, lastSecond );
            copyValues( lastMinute, minutes, lastSecond, seconds );
        }

    }

    if( astate == 1 )
        totalSeconds1 += addSeconds( 48, 0, lastMinute, lastSecond );
    else if( astate == 2 )
        totalSeconds2 += addSeconds( 48, 0, lastMinute, lastSecond );

    cout << ((totalSeconds1/60 < 10)?"0":"") << totalSeconds1/60 << ":" << ((totalSeconds1%60 < 10)?"0":"") << totalSeconds1%60 << endl;
    cout << ((totalSeconds2/60 < 10)?"0":"") << totalSeconds2/60 << ":" << ((totalSeconds2%60 < 10)?"0":"") << totalSeconds2%60 << endl;

}
