#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int modulo;
int tmp[21][21];
int base[21][21];
int matrix[21][21];

void calc( int n )
{
    if ( n == 0 )
    {
        memset ( matrix, 0, sizeof ( matrix ) );
        for ( int i = 0; i < 11; i ++ )
            matrix[i][i] = 1;
        return;
    }
    calc(n/2);
    int i, j, k;
    for ( i = 0; i < 11; i ++ )
        for ( j = 0; j < 11; j ++ )
        {
            tmp[i][j] = 0;
            for ( k = 0; k < 11; k ++ )
                tmp[i][j] = ( 1LL * matrix[i][k] * matrix[k][j] + tmp[i][j] ) % modulo;
        }
    if ( n&1 )
        for ( i = 0; i < 11; i ++ )
            for ( j = 0; j < 11; j ++ )
            {
                matrix[i][j] = 0;
                for ( k = 0; k < 11; k ++ )
                    matrix[i][j] = ( tmp[i][k] * base[k][j] + matrix[i][j] ) % modulo;
            }
    else
        for ( i = 0; i < 11; i ++ )
            for ( j = 0; j < 11; j ++ )
                matrix[i][j] = tmp[i][j];
}

main()
{
    int t, i, j, n, ret;

    memset( base, 0, sizeof ( base ) );
    for ( i = 0; i < 10; i ++ )
        for ( j = i + 1; j < 10; j ++ )
        {
            base[i][19-10-j] = 1;
            base[19-10-j][i] = 1;
        }
    for ( i = 0; i < 10; i ++ )
        for ( j = 0; j < 10; j ++ )
            base[i][10] += base[i][j];
    base[10][10] = 1;
    scanf ( "%d", &t );
    while( t -- )
    {
        scanf ( "%d %d", &n, &modulo );
        calc( n - 1 );
        ret = 0;
        for ( i = 1; i < 9; i ++ )
            ret = ( ret + 2 * matrix[i][10] ) % modulo;
        ret = ( ret + matrix[0][10] + matrix[9][10] + 10 * matrix[10][10] ) % modulo;
        printf( "%d\n", ret );
    }

    return 0;
}
