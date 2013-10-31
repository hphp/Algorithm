#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <climits>
#include <queue>
#include <cassert>

using namespace std;

typedef map<string, int>                 place_type;
typedef map<string, pair<int, string> >  student_type;
typedef place_type::iterator             place_iter;
typedef student_type::iterator           student_iter;

int solve( int __r )
{
    int n, k, t;
    
    if( scanf( "%d%d%d", &n, &k, &t ) == EOF )
	return 0;
    printf( "Case #%d:\n", __r );

    char __cmd[ 20 ], __id[ 1000 ], __buf[ 1000 ];
    int ts;
    place_type   pla;
    student_type stu;
    place_iter   pla_it;
    student_iter stu_it;
    queue<pair<int, string> > que;
    
    for( int i = 0; i < n; ++i )
    {
	scanf( "%d%s%s", &ts, __cmd, __id );

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

	string id( __id ), cmd( __cmd );
	
	if( cmd == "GET" )
	{
	    scanf( "%s", __buf );
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
	else if( cmd == "REG" ) stu[id].first = 1;
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
    }

    for( stu_it = stu.begin( ); stu_it != stu.end( ); ++stu_it )
    {
	if( stu_it->second.first != 3 ) continue;
	printf( "%s %s\n", stu_it->first.c_str( ), stu_it->second.second.c_str( ) );
    }
    
    putchar( '\n' );
    return 1;
}


int main( void )
{
    for( int i = 1; solve( i ); ++i );
    return 0;
}
