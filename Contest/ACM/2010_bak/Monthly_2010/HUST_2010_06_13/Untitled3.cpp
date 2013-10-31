
		std::sort(rec,rec+rcnt);
		int rrcnt = 0;
		for(int i=0;i<rcnt;i++)
			if((i==0)||(rec[i]!=rec[i-1]))
				real[rrcnt++] = rec[i];
