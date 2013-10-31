/*
	Problem: BOJ1094
	Algorithm: QSort, Heap, Greed(Specialized)
	Time: O(N)
	Memory: O(N)
	Detail: The same problem as APIO2007 - 2.Backup
	Coded by Biribiri
*/

#include <iostream>
using namespace std;

const int MaxN = 3001;

struct SSeq
{
	int Prev, Next, Dis, HeapPos;
};

int N, K, PrevT, NextT, HeapSize, HeapTop, HeapTopDis, Ans;
int MinHeap[MaxN+1];
SSeq Seq[MaxN+1];

void QuickSort(int L, int R)
{
	int i, j, Tmp, Key;
	i = L;
	j = R;
	Key = Seq[(i+j)/2].Dis;
	do
	{
		while (Seq[i].Dis < Key) ++i;
		while (Seq[j].Dis > Key) --j;
		if (i <= j)
		{
			Tmp = Seq[i].Dis;
			Seq[i].Dis = Seq[j].Dis;
			Seq[j].Dis = Tmp;
			++i;
			--j;
		}
	}
	while (i <= j);
	if (i < R) QuickSort(i, R);
	if (j > L) QuickSort(L, j);
}

void MinHeapExchange(int i, int j)
{
	int Tmp;
	Tmp = MinHeap[i];
	MinHeap[i] = MinHeap[j];
	MinHeap[j] = Tmp;
	Seq[MinHeap[i]].HeapPos = i;
	Seq[MinHeap[j]].HeapPos = j;
}

void MinHeapRise(int i)
{
	int Son = i;
	int Parent = Son >> 1;
	while (Son > 1 && Seq[MinHeap[Parent]].Dis > Seq[MinHeap[Son]].Dis)
	{
		MinHeapExchange(Son, Parent);
		Son = Parent;
		Parent = Parent >> 1;
	}
}

void MinHeapSink(int i)
{
	int Parent = i, LeftSon, RightSon, Smallest;
	LeftSon = Parent << 1;
	RightSon = LeftSon + 1;
	while (LeftSon <= HeapSize)
	{
		if (Seq[MinHeap[Parent]].Dis > Seq[MinHeap[LeftSon]].Dis)
			Smallest = LeftSon;
		else
			Smallest = Parent;
		if (RightSon <= HeapSize && Seq[MinHeap[Smallest]].Dis > Seq[MinHeap[RightSon]].Dis)
			Smallest = RightSon;
		if (Smallest != Parent)
		{
			MinHeapExchange(Parent, Smallest);
			Parent = Smallest;
			LeftSon = Parent << 1;
			RightSon = LeftSon + 1;
		}
		else
			break;
	}
}

void MinHeapInsert(int i)
{
	++HeapSize;
	Seq[i].HeapPos = HeapSize;
	MinHeap[HeapSize] = i;
	MinHeapRise(HeapSize);
}

void MinHeapDelete(int i)
{
	MinHeapExchange(i, HeapSize);
	--HeapSize;
	MinHeapSink(i);
	MinHeapRise(i);
}

int main()
{
	scanf("%d%d", &N , &K);
	scanf("%d", &Seq[0].Dis);
	for (int i = 1; i != N; ++i)
		scanf("%d", &Seq[i].Dis);
	QuickSort(0, N-1);
	for (int i = N-1; i != 0; --i)
	{
		Seq[i].Dis -= Seq[i-1].Dis;
		Seq[i].Dis = Seq[i].Dis*Seq[i].Dis;
	}
	for (int i = 1; i != N; ++i)
	{
		Seq[i].Prev = i-1;
		Seq[i].Next = i+1;
	}
	HeapSize = 0;
	for (int i = 1; i != N; ++i)
	{
		
		MinHeapInsert(i);
	}
	Ans = 0;
	for (int i = 1; i <= K; ++i)
	{
		HeapTop = MinHeap[1];
		HeapTopDis = Seq[HeapTop].Dis;
		Ans += HeapTopDis;
		MinHeapDelete(1);
		PrevT = Seq[HeapTop].Prev;
		NextT = Seq[HeapTop].Next;
		Seq[HeapTop].Prev = Seq[PrevT].Prev;
		Seq[HeapTop].Next = Seq[NextT].Next;
		Seq[Seq[PrevT].Prev].Next = N;
		Seq[Seq[NextT].Next].Prev = 0;
		if (PrevT != 0)
		{
			HeapTopDis -= Seq[PrevT].Dis;
			MinHeapDelete(Seq[PrevT].HeapPos);
			Seq[Seq[NextT].Next].Prev = HeapTop;
		}
		if (NextT != N)
		{
			HeapTopDis -= Seq[NextT].Dis;
			MinHeapDelete(Seq[NextT].HeapPos);
			Seq[Seq[PrevT].Prev].Next = HeapTop;
		}
		if ((PrevT != 0) && (NextT != N))
		{
			Seq[HeapTop].Dis = -HeapTopDis;
			MinHeapInsert(HeapTop);
		}
	}
	printf("%d\n", Ans);
	return 0;
}
