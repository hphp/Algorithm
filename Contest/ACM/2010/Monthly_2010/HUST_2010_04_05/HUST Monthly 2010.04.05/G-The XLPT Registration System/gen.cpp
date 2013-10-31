#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cstring>
#include <climits>
#include <queue>
#include <cassert>

using namespace std;

typedef map<string, int>                 place_type;
typedef map<string, pair<int, string> >  student_type;
typedef place_type::iterator             place_iter;
typedef student_type::iterator           student_iter;


const int maxn = 1 << 16;
const int name_len = 12;
const int N = 4;

int nn[10] = { 1000, 5000, 10000, 50000 };
int kk[10] = {   20,   30,    40,    50 };
int tt[10] = {  300, 1000,  3000,  5000 };

char *sigma = "0123456789_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

string stu_id[ maxn ];
string pla_id[ maxn ];

FILE *fin, *fout;


void gen_name( int n, int m )
{
    int ll = strlen( sigma );
    for( int i = 0; i < n; ++i )
    {
	stu_id[i] = "";
	for( int j = 0; j < name_len; ++j )
	    stu_id[i].push_back( sigma[ rand( ) % ll ] );
    }

    for( int i = 0; i < m; ++i )
    {
	pla_id[i] = "";
	for( int j = 0; j < name_len; ++j )
	    pla_id[i].push_back( sigma[ rand( ) % ll ] );
    }
}



void solve( int __r )
{
    int n, k, t, m;

    n = nn[__r];
    m = n / 10;
    t = tt[__r];
    k = kk[__r];
    

    gen_name( n, m );

    char __cmd[ 20 ], __id[ 1000 ], __buf[ 1000 ];
    int ts;
    place_type   pla;
    student_type stu;
    place_iter   pla_it;
    student_iter stu_it;
    queue<pair<int, string> > que;

    printf( "%d %d %d\n", n, k, t );
    
    for( int i = 0; i <= n; ++i )
    {
	if( i < n ) {
	    int t1, t2;
	    
	    ts = i;
	    
	    t1 = rand( ) % n;
	    strcpy( __id, stu_id[t1].c_str( ) );

	    t2 =  rand( ) % 12;
	    
	    if( t2 == 0 ){
		stu_it = stu.find( stu_id[t1] );
		if( stu_it != stu.end( ) )
		{
		    --i;
		    continue;
		}
		strcpy( __cmd, "REG" );
	    }
	    else
	    {
		stu_it = stu.find( stu_id[t1] );
		if( stu_it == stu.end( ) )
		{
		    strcpy( __cmd, "REG" );
		}
		else
		{
		    if( t2 == 1 || t2 > 3 ) strcpy( __cmd, "GET" );
		    else if( t2 == 2 ) strcpy( __cmd, "PAY" );
		    else              strcpy( __cmd, "CAL" );
		}
	    }


	}
	else ts = INT_MAX;

	while( !que.empty( ) && que.front( ).first <= ts )
	{
	    stu_it = stu.find( que.front( ).second );
	    if( stu_it->second.first != 3 )
	    {
		stu_it->second.first = 1;
		pla_it = pla.find( stu_it->second.second );
		pla_it->second--;
	    }
	    que.pop( );
	}

	if( i == n ) break;

	string id( __id ), cmd( __cmd );
	
	if( cmd == "GET" )
	{
	    {
		int t = rand( ) % m;
		strcpy( __buf, pla_id[t].c_str( ) );
	    }
	    string place( __buf );
	    
	    stu_it = stu.find( id );
	    if( stu_it->second.first == 1 )
	    {
		pla.insert( make_pair( place, 0 ) );
		pla_it = pla.find( place );
		
		assert( pla_it != pla.end( ) );
		
		if( pla_it->second < k )
		{
		    stu_it->second.first = 2;
		    stu_it->second.second = place;
		    pla_it->second++;
		    que.push( make_pair( ts + t, id ) );
		}
	    }
	}
	else if( cmd == "REG" )
	{
	    stu[id].first = 1;
	}
	else if( cmd == "PAY" ) {
	    stu_it = stu.find( id );
	    if( stu_it->second.first == 2 )
		stu_it->second.first =  3;
	}
	else if( cmd == "CAL" )
	{
	    stu_it = stu.find( id );
	    if( stu_it->second.first == 2 )
	    {
		stu_it->second.first = 1;
		pla_it = pla.find( id );
		pla_it->second--;
	    }
	}
	printf( "%d %s %s", ts, cmd.c_str( ), id.c_str( ) );
	if( cmd == "GET" ) printf( " %s", __buf );
	printf( "\n" );
    }
    /*
    for( stu_it = stu.begin( ); stu_it != stu.end( ); ++stu_it )
    {
	if( stu_it->second.first != 3 ) continue;
	fprintf( stderr, "%s %s\n", stu_it->first.c_str( ), stu_it->second.second.c_str( ) );
    }
    */
    
    putchar( '\n' );
}


int main( void )
{
    srand( 0 );
    for( int i = 0; i < N; ++i )
	solve( i );
    return 0;
}
