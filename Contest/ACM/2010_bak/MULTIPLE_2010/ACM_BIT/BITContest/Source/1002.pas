program remove;
const
  maxl1=10000+10;
  maxl2=1000+10;
  maxval=2139062143;
var
  a,b:array[0..maxl1] of char;
  next:array[0..maxl2] of longint;
  t:array[0..maxl2,'a'..'z'] of longint;
  d:array[0..1,0..maxl2] of longint;
  i,j,k,l,m,n,l1,l2,ans,ts:longint;

procedure init;
begin
  l1:=0;l2:=0;
  while not eoln do
    begin
      inc(l1);
      read(a[l1]);
    end;
  readln;
  while not eoln do
    begin
      inc(l2);
      read(b[l2]);
    end;
  readln;
  readln;
end;

procedure build;
var
  ch:char;
begin
  next[1]:=0;k:=0;
  for i:=2 to l2 do
    begin
      while (k>0)and(b[k+1]<>b[i]) do k:=next[k];
      if b[k+1]=b[i] then inc(k);
      next[i]:=k;
    end;
  fillchar(t[0],sizeof(t[0]),0);
  t[0,b[1]]:=1;
  for i:=1 to l2-1 do
    begin
      for ch:='a' to 'z' do
        begin
          k:=i;
          while (k>0)and(b[k+1]<>ch) do k:=next[k];
          if b[k+1]=ch then inc(k);
          t[i,ch]:=k;
        end;
    end;
end;

procedure solve;
var
  x,y:integer;
begin
  x:=0;
  fillchar(d[0],sizeof(d[0]),$7F);
  d[0,0]:=0;
  for i:=1 to l1 do
    begin
      y:=1 xor x;
      fillchar(d[y],sizeof(d[y]),$7F);
      for j:=0 to l2-1 do
        begin
          if d[x,j]+1<d[y,j] then d[y,j]:=d[x,j]+1;
          if d[x,j]<d[y,t[j,a[i]]] then d[y,t[j,a[i]]]:=d[x,j];
        end;
      x:=y;
    end;
  ans:=maxlongint;
  for i:=0 to l2-1 do
    if d[x,i]<ans
      then ans:=d[x,i];
  writeln(ans);
end;

begin
//  assign(input,'necklace.in');reset(input);
//  assign(output,'necklace.out');rewrite(output);
  readln(ts);
  for ts:=1 to ts do
    begin
      init;
      build;
      solve;
    end;
  close(input);close(output);
end.
