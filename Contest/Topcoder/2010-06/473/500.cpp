#include <vector>
#include <string>
using namespace std;

int face[4][2] = {{1,3},{2,0},{3,1},{0,2}};//4:NESW -- 2 : RL
int mv[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};



class SequenceOfCommands
{
	private:
		struct P
		{
			int x,y;
			int f;	
		};
		P getNext(P st,char c)
		{
			if(c == 'S')
			{
				P ans = {st.x+mv[st.f][0],st.y+mv[st.f][1],st.f};
				return ans;
			}
			else if(c == 'R')
			{
				P ans = {st.x,st.y,face[st.f][0]};
				return ans;
			}
			else	if(c == 'L')
			{
				P ans = {st.x,st.y,face[st.f][1]};
				return ans;
			}
		}
	public:
		string whatHappens(vector <string> commands)
		{
			int size = commands.size();
			P st = {0,0,0};
			P nxt;
			for(int i=0;i<size;i++)
			{
				string cur = commands[i];
				int len = cur.length();
				for(int j=0;j<len;j++)
				{
					nxt = getNext(st,cur[j]);
					st = nxt;
				}
			}
			string ans = "bounded";
			if(st.f == 0 && (st.x!=0||st.y!=0))
			{
				ans = "unbounded";
			}
			else ans = "bounded";
			return ans;
		}
};
