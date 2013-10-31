#include <stdio.h>
#include <string.h>

struct player
{
    int score, injection;
    char role, alive;
};

struct player a[12];
int r[12];

void readin()
{
    int i;

    for (i = 1; i < 12; i++) scanf("%d", &r[i]);
    a[r[1]].role = a[r[2]].role = 'k';
    a[r[3]].role = a[r[4]].role = 'p';
    a[r[5]].role = 'd';
    a[r[6]].role = 's';
    a[r[7]].role = 'b';
    a[r[8]].role = a[r[9]].role = a[r[10]].role = a[r[11]].role = 'c';

    return;
}

int main()
{
    int round, t, i, j, f, v, s, p, pc, kc, m, vote[12];

    //freopen("data_in.txt", "r", stdin);
    //freopen("data_out.txt", "w", stdout);

    scanf("%d", &t);
    while (t--)
    {
        for (i = 0; i < 12; i++) a[i].score = 0;
        scanf("%d", &round);
        while (round--)
        {
            for (i = 0; i < 12; i++)
            {
                a[i].alive = 1;
                a[i].injection = 0;
            }

            readin();
            pc = kc = 2;
            while (pc && kc)
            {
                scanf("%d", &v);
                a[v].alive = 0;
                if (a[v].role == 'p')
                {
                    a[r[1]].score += 10;
                    a[r[2]].score += 10;
                    pc--;
                }

                scanf("%d", &s);
                if (a[s].role == 'k')
                {
                    a[r[3]].score += 5;
                    a[r[4]].score += 5;
                }

                scanf("%d", &p);
                if (v == p)
                {
                    a[v].alive = 1;
                    a[r[5]].score += 5;
                    if (a[v].role == 'p')
                    {
                        a[r[1]].score -= 10;
                        a[r[2]].score -= 10;
                        pc++;
                    }
                }
                else
                {
                    a[p].injection++;
                    if (a[p].injection > 1)
                    {
                        a[p].alive = 0;
                        if (a[p].role == 'p')
                        {
                            a[r[5]].score -= 5;
                            pc--;
                        }
                        else if (a[p].role == 'k')
                        {
                            a[r[5]].score += 5;
                            kc--;
                        }
                    }
                }

                scanf("%d", &v);
                if (v)
                {
                    a[v].alive = 0;
                    if (a[v].role == 'p')
                    {
                        a[r[6]].score -= 5;
                        pc--;
                    }
                    else if (a[v].role == 'k')
                    {
                        a[r[6]].score += 5;
                        kc--;
                    }
                    a[r[6]].role = 'c';
                }

                scanf("%d", &v);
                if (a[v].role == 'p')
                {
                    a[v].alive = 0;
                    a[r[7]].score += 10;
                    pc--;
                }

                if (!pc || !kc) break;

                memset(vote, 0, sizeof(vote));
                for (i = 0; i < 11; i++)
                {
                    scanf("%d", &m);
                    if (a[i].alive) vote[m]++;
                }

                j = 0;
                for (i = 1; i < 12; i++) if (vote[i] > vote[j]) j = i;
                f = 1;
                for (i = 1; i < 12; i++) if (vote[i] == vote[j] && i != j) f = 0;
                if (f)
                {
                    a[j].alive = 0;
                    if (a[j].role == 'p') pc--;
                    else if (a[j].role == 'k') kc--;
                }
            }

            if (!pc && kc)
            {
                a[r[1]].score += 10;
                a[r[2]].score += 10;
                a[r[7]].score += 10;
            }
            else if (pc && !kc)
            {
                for (i = 3; i < 7; i++) a[r[i]].score += 10;
                for (i = 8; i < 12; i++) a[r[i]].score += 10;
            }
        }

        for (i = 1; i < 12; i++) printf("%d\n", a[i].score);
        printf("\n");
    }

    return 0;
}
