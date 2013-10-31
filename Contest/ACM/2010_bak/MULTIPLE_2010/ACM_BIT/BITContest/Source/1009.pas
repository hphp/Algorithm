program bb;
const

 maxn=100;
 maxL=1000;
var
 opt:array[0..maxn,0..maxL] of longint;
 w,val:array[0..maxn] of longint;
 n,m,v,ans,t:longint;
procedure init;
 var
  i:longint;
 begin
  readln(n,m,v);
  for i:=1 to n do
   read(w[i],val[i]);
 end;
function max(x,y:longint):longint;
 begin
  max:=y;
  if x>y then max:=x;
 end;
procedure main;
 var
  i,j,k:longint;
 begin
  fillchar(opt,sizeof(opt),0);
  for i:=1 to n do
   for j:=m downto 1 do
    if j<=i then
     for k:=v downto w[i] do
      if (opt[j-1,k-w[i]]>0) or ((j=1) and (k=w[i])) then
       opt[j,k]:=max(opt[j-1,k-w[i]]+val[i],opt[j,k]);
   ans:=-maxlongint;
   for i:=0 to v do
    if opt[m,i]>ans then ans:=opt[m,i];
 end;
procedure print;
 begin
  writeln(ans);
 end;
begin
 readln(t);
 while (t > 0) do
   begin
     init;
     main;
     print;
     dec(t);
   end;
end.
