import java.io.*;
import java.util.*;
import java.awt.*;
import java.text.*;
import java.math.*;


class Main
{
    public Scanner sc;
    public PrintStream ps;

    public String toString()
    {
        return "ninjaway";
    }

    public void doit() throws Exception
    {
        sc = new Scanner( System.in ); 
        ps = System.out; 

    int T = sc.nextInt();
        for(int cas = 1; cas <= T; cas++)
        {
            int n = sc.nextInt();
            int d = sc.nextInt();

            int houses[] = new int[n];
            int sorted[] = new int[n];

            for( int i=0; i<n; i++ )
            {
                houses[i] = sc.nextInt();
                sorted[i] = houses[i];
            }
            Arrays.sort( sorted );

             int position[] = new int[n];
             for( int i=0; i<n; i++ )
            {
                int p = Arrays.binarySearch( sorted, houses[i] );
                position[p] = i;
            }

            int start = position[0];
            int finish = position[n-1];
            if( finish<start )
            {
                int t = start;
                start = finish;
                finish = t;
            }

            int dist[] = new int[n];
            boolean failed = false;
            for( int i=0; i<n-1; i++ )
            {
                dist[i] = Math.abs( position[i+1]-position[i] );
                if( dist[i]>d ) failed=true;
            }

            int total;

            if( failed )
            {
                total = -1;
            }
            else
            {
                boolean spans[][] = new boolean[n][n];
                for( int i=0; i<n; i++ )
                {
                    Arrays.fill( spans[i], false );
                }
                for( int i=0; i<n-1; i++ )
                {
                    int lo = Math.min( position[i], position[i+1] );
                    int hi = Math.max( position[i], position[i+1] );
                    for( int j=lo; j<hi; j++ )
                    {
                        spans[i][j] = true;
                    }
                }

                total = finish-start;

                for( int j=start; j<finish; j++ )
                {
                    int maxdist = 0;
                    for( int i=0; i<n-1; i++ ) if( spans[i][j] )
                    {
                        if( dist[i]>maxdist )
                        {
                            maxdist=dist[i];
                        }
                    }

                    int stretch = d-maxdist;

                    total += stretch;

                    for( int i=0; i<n-1; i++ ) if( spans[i][j] )
                    {
                        dist[i] += stretch;
                    }
                }
            }

            ps.println( "Case "+cas+": "+total );
        }
    }

    public static void main(String[] args) throws Exception
    {
        new Main().doit();
    }
}
