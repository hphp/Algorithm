const
  maxn=100;
var
  path:array[1..maxn*2] of integer;
  q:array[1..maxn*2] of integer;
  c,f:array[1..maxn*2,1..maxn*2] of integer;
  head,tail,x,y,i,v,k,m,n,s,t,mincut,ts:integer;

procedure init;
begin
  fillchar(c,sizeof(c),0);
  fillchar(f,sizeof(f),0);
  read(n,m,s,t);
  for i:=1 to n do
    read(c[i,i+n]);
  for i:=1 to m do
    begin
      read(x,y);
      c[x+n,y]:=maxint;c[y+n,x]:=maxint;
    end;
  inc(s,n);n:=n*2;
end;

procedure ford;
begin
  repeat
    fillchar(path,sizeof(path),0);
    head:=0;tail:=1;q[1]:=s;path[s]:=-1;
    while (head<tail)and(path[t]=0) do
      begin
        inc(head);v:=q[head];
        for i:=1 to n do
          if path[i]=0
            then begin
                   if c[v,i]-f[v,i]>0
                     then begin
                            path[i]:=v;
                            inc(tail);q[tail]:=i;continue;
                          end;
                   if f[i,v]>0
                     then begin
                            path[i]:=-v;
                            inc(tail);q[tail]:=i;
                          end;
                 end;
      end;
    if path[t]<>0
      then begin
             x:=t;m:=maxint;
             repeat
               y:=abs(path[x]);
               if (path[x]>0)and(c[y,x]-f[y,x]<m) then m:=c[y,x]-f[y,x];
               if (path[x]<0)and(f[x,y]<m) then m:=f[x,y];
               x:=y;
             until y=s;
             x:=t;
             repeat
               y:=abs(path[x]);
               if path[x]>0 then inc(f[y,x],m) else dec(f[x,y],m);
               x:=y;
             until y=s;
           end;
  until path[t]=0;
end;

procedure solve;
begin
  ford;
  mincut:=0;
  for i:=1 to n do
    inc(mincut,f[i,t]);
  writeln(mincut);
end;

begin
  
  readln(ts);
  for ts:=1 to ts do
    begin
      init;
      solve;
    end;

end.
