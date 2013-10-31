{$q-,r-,s-,i-,v-,x-}

program manhattan;
const
  maxn=100000;
type
  Theap=record
          p,x:longint;
        end;
  link=^node;
  node=record
         ch:array ['A'..'Z'] of link;
         p:longint;
       end;
var
  num:array [1..4,0..maxn] of longint;
  h:array [1..4,0..maxn] of Theap;
  i,j,k,m,n,x,y,tot,sum,ts:longint;
  root,niln:link;
  st:string;
  c,d:char;
procedure insert(var r:link;dep:longint);  
  begin
    if r^.ch[upcase(st[dep])]=niln then begin new(r^.ch[upcase(st[dep])]);for d:='A' to 'Z' do r^.ch[upcase(st[dep])]^.ch[d]:=niln; end;
    if dep<length(st) then insert(r^.ch[upcase(st[dep])],dep+1) else r^.ch[upcase(st[dep])]^.p:=sum;
  end;
procedure find(r:link;dep:longint);   
  begin
    if dep<length(st) then find(r^.ch[upcase(st[dep])],dep+1) else m:=r^.ch[upcase(st[dep])]^.p;
  end;
procedure swap(var x,y:Theap);  
  var t:Theap;
  begin
    t:=x;x:=y;y:=t;
  end;
procedure up(f,k:longint);
  begin
    if f<3
      then begin
             while (k>1) and (h[f,k].x>h[f,k shr 1].x) do
               begin
                 swap(h[f,k],h[f,k shr 1]);
                 num[f,h[f,k].p]:=k;num[f,h[f,k shr 1].p]:=k shr 1;
                 k:=k shr 1;
               end;
           end
      else begin
             while (k>1) and (h[f,k].x<h[f,k shr 1].x) do
               begin
                 swap(h[f,k],h[f,k shr 1]);
                 num[f,h[f,k].p]:=k;num[f,h[f,k shr 1].p]:=k shr 1;
                 k:=k shr 1;
               end;
           end;
  end;
procedure down(f,k:longint);
  begin
    if f<3
      then begin
             repeat
              j:=k;
              if (j shl 1<=tot) and (h[f,j shl 1].x>h[f,k].x) then k:=j shl 1;
              if (j shl 1+1<=tot) and (h[f,j shl 1+1].x>h[f,k].x) then k:=j shl 1+1;
              if j<>k
                then begin
                       swap(h[f,j],h[f,k]);
                       num[f,h[f,j].p]:=j;num[f,h[f,k].p]:=k;
                     end;
             until j=k;
           end
      else begin
             repeat
              j:=k;
              if (j shl 1<=tot) and (h[f,j shl 1].x<h[f,k].x) then k:=j shl 1;
              if (j shl 1+1<=tot) and (h[f,j shl 1+1].x<h[f,k].x) then k:=j shl 1+1;
              if j<>k
                then begin
                       swap(h[f,j],h[f,k]);
                       num[f,h[f,j].p]:=j;num[f,h[f,k].p]:=k;
                     end;
             until j=k;
           end;
  end;
begin

  read(ts);
  for ts:=1 to ts do begin
  new(niln);
  fillchar(niln^,sizeof(niln^),0);
  for d:='A' to 'Z' do niln^.ch[d]:=niln;
  new(root);
  for d:='A' to 'Z' do root^.ch[d]:=niln;
  readln(n);
  sum:=0;tot:=0;
  for i:=1 to n do
    begin
      read(j);
      st:='';read(c);
      repeat
       st:=st+c;
       read(c);
      until (c=' ') or (c=#10) or (c=#13);delete(st,1,1);
      if j=1 then read(x,y);readln;
      if j=1
        then begin
               inc(sum);inc(tot);insert(root,1);
               num[1,sum]:=tot;h[1,tot].x:=x+y;h[1,tot].p:=sum;up(1,tot);
               num[2,sum]:=tot;h[2,tot].x:=x-y;h[2,tot].p:=sum;up(2,tot);
               num[3,sum]:=tot;h[3,tot].x:=x+y;h[3,tot].p:=sum;up(3,tot);
               num[4,sum]:=tot;h[4,tot].x:=x-y;h[4,tot].p:=sum;up(4,tot);
             end
        else begin
               find(root,1);
               h[1,num[1,m]]:=h[1,tot];num[1,h[1,tot].p]:=num[1,m];
               h[2,num[2,m]]:=h[2,tot];num[2,h[2,tot].p]:=num[2,m];
               h[3,num[3,m]]:=h[3,tot];num[3,h[3,tot].p]:=num[3,m];
               h[4,num[4,m]]:=h[4,tot];num[4,h[4,tot].p]:=num[4,m];
               dec(tot);
               up(1,num[1,m]);up(2,num[2,m]);up(3,num[3,m]);up(4,num[4,m]);
               down(1,num[1,m]);down(2,num[2,m]);down(3,num[3,m]);down(4,num[4,m]);
             end;
      if tot=0 then begin writeln(-1);continue; end;
      if h[1,1].x-h[3,1].x>h[2,1].x-h[4,1].x then writeln(h[1,1].x-h[3,1].x) else writeln(h[2,1].x-h[4,1].x);
    end;
    writeln;
  end;

end.
