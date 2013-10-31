#include <stdio.h>
#include <map>
#include <algorithm>

typedef long long LL;

#define N 10010
#define Q 50010

struct Node
{
	char name[40];
	int proi;
	LL time;
	std::map<int, LL> lines;
};

struct Commond
{
	int id;
	int type;
	int line;
	LL time;

	bool operator < (const Commond & c) const
	{
		return time < c.time;
	}
};

struct Line
{
	int id;
	LL time;
	int line;

	bool operator < (const Line & c) const
	{
		return line < c.line;
	}
};

int n;
struct Node p[N];
std::map<int, int> lines;
int cnt;
struct Line ls[Q];
int q;
struct Commond comms[Q];
LL cur_time;

int main()
{
	while (scanf("%d", &n)!=EOF && n)	
	{
		q = 0;
		cnt = 0;
		cur_time = 0;
		lines.clear();
		for (int i = 1; i <= n; i++)
		{
			int qi;
			scanf("%s %d %d", p[i].name, &p[i].proi, &qi);
			p[i].lines.clear();
			for (int j = 0; j < qi; j++)
			{
				char str[40];
				int year, month, day, hour, min, sec;
				char date[40], date1[40];
				scanf("%s %s %s", date, date1, str);
				sscanf(date, "[%d/%d/%d", &year, &month, &day);
				sscanf(date1, "%d:%d:%d]", &hour, &min, &sec);

				LL d1 = year*1000 + month*100 +day;
				LL d2 = hour*10000 +min*100 + sec;
				comms[q].time = d1*1000000 + d2;
				comms[q].id = i;
				if (strcmp(str, "SYNC") == 0)
				{
					comms[q].type = 1;
				}
				else if (strcmp(str, "SUBMIT") == 0)
				{
					comms[q].type = 2;
				}
				else
				{
					comms[q].type = 3;
					scanf("%d", &comms[q].line);
				}
				q++;
			}
		}

		std::sort(comms, comms+q);

		for (int i = 0; i < q; i++)
		{

			if (comms[i].type == 1)
			{
				int id = comms[i].id;
				p[id].time = comms[i].time;
			}
			else if (comms[i].type == 2)
			{
				int id = comms[i].id;
				LL time = comms[i].time;
				for (std::map<int, LL>::iterator it = p[id].lines.begin(); it != p[id].lines.end(); ++it)
				{
					int line = it->first;
					LL m_time = it->second;

					int hid = lines[line];

					if (hid == 0)
					{
						cnt++;
						hid = cnt;
						ls[hid].id = id;
						ls[hid].line = line;
						ls[hid].time = time;
						lines[line] = hid;
					}
					else
					{
						if (ls[hid].time < p[id].time)
						{
							ls[hid].id = id;
							ls[hid].time = time;
						}
						else
						{
							if (p[id].proi > p[ls[hid].id].proi)
							{
								ls[hid].id = id;
								ls[hid].time = time;
							}
						}
					}
				}

				p[id].lines.clear();
				p[id].time = time;
			}
			else if (comms[i].type == 3)
			{
				int id = comms[i].id;
				int line = comms[i].line;
				LL time = comms[i].time;
				p[id].lines[line] = time;
			}
		}

		if (cnt)
		{
			std::sort(ls+1, ls+cnt+1);
			for (int i = 1; i <= cnt; i++)
			{
				LL date = ls[i].time / 1000000;
				LL date1 = ls[i].time % 1000000;
				int year = date / 1000;
				int month = (date-year*1000) / 100;
				int day = date % 100;
				int hour = date1 / 10000;
				int min = (date1 - hour*10000) / 100;
				int sec = date1 % 100;
				printf("%d [%04d/%02d/%02d %02d:%02d:%02d] BY %s\n", ls[i].line, year, month, day, hour, min, sec, p[ls[i].id].name);
			}
		}
		printf("END\n");
	}

	return 0;
}