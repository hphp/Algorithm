program _Code;

const
  maxn = 60;
  modes = 1000;
  maxL = 3;

type integer = longint;
     TNum = array[0 .. 100] of integer;

var a, c, s, ind, stack       : array[1 .. maxn] of integer;
    rep, temp                 : array[1 .. maxn] of string;
    f                         : array[1 .. maxn] of TNum;
    n, m                      : integer;

procedure init;
var i : integer;
begin
  readln(n);
  for i := 1 to n do read(c[i]); readln;
end;

procedure print(var a: TNum);
var i: integer;
    st: string[4];
begin
  write(a[a[0]]);
  for i := a[0] - 1 downto 1 do begin
    str(a[i], st);
    while length(st) < maxL do st := '0' + st;
    write(st);
  end; writeln;
end;

procedure mult(var a: TNum; k: integer); overload;
var i, temp: integer;
begin
  temp := 0;
  for i := 1 to a[0] do begin
    a[i] := a[i] * k + temp;
    temp := a[i] div modes;
    a[i] := a[i] - temp * modes;
  end;
  if temp > 0 then begin
    inc(a[0]);
    a[a[0]] := temp;
  end;
end;

var g: TNum;

procedure mult(var a, b: TNum); overload;
var i, j: integer;
begin
  fillchar(g, sizeof(g), 0);
  for i := 1 to a[0] do
    for j := 1 to b[0] do
      inc(g[i + j - 1], a[i] * b[j]);
  g[0] := a[0] + b[0] - 1; a := g;
  mult(a, 1);
end;

procedure divide(var a: TNum; k: integer);
var i, temp: integer;
begin
  temp := 0;
  for i := a[0] downto 1 do begin
    a[i] := a[i] + temp * modes;
    temp := a[i] mod k;
    a[i] := a[i] div k;
  end;
  while (a[0] > 0) and (a[a[0]] = 0) do dec(a[0]);
end;

procedure process(var sol : TNum; var st : string);
var i, j, k, temp : integer;
begin
  for i := 1 to m do begin
    j := i;
    while (j > 1) and (rep[a[j]] < rep[a[j - 1]]) do begin
      temp := a[j]; a[j] := a[j - 1]; a[j - 1] := temp;
    end;
  end;

  st := '('; k := 0; sol[1] := 1; sol[0] := 1;
  for i := 1 to m do begin
    st := st + rep[a[i]];
    mult(sol, f[a[i]]);
    k := k + s[a[i]];
  end; st := st + ')';
  for i := 1 to k do mult(sol, i);
  for i := 1 to m do
    for j := 1 to s[a[i]] do divide(sol, j);
  i := 1;
  while i < m do begin
    j := i + 1;
    while (j <= m) and (rep[a[j]] = rep[a[i]]) do j := j + 1;
    for k := 1 to j - i do divide(sol, k);
    i := j;
  end;
end;

procedure main;
var i, j, k, u, top, L  : integer;
    t                   : integer;
    st                  : string;
    answer              : TNum;
begin
  fillchar(ind, sizeof(ind), 0);
  fillchar(f, sizeof(f), 0);
  for i := 1 to n do begin
    inc(ind[c[i]]);
    s[i] := 1; f[i, 0] := 1; f[i, 1] := 1;
  end;
  top := 0;
  for i := 1 to n do if ind[i] = 0 then begin
    top := top + 1;
    stack[top] := i;
    rep[i] := '()';
  end;

  while top > 0 do begin
    u := stack[top]; dec(top);
    dec(ind[c[u]]); inc(s[c[u]], s[u]);

    if ind[c[u]] = 0 then begin
      inc(top);
      stack[top] := c[u];
    end;

    if s[u] > 1 then begin
      m := 0;
      for i := 1 to n do if c[i] = u then begin
        m := m + 1;
        a[m] := i;
      end;
      process(f[u], rep[u]);
      mult(f[u], s[u]);
    end;
  end;

  t := 0;
  for i := 1 to n do if ind[i] > 0 then begin
    L := 0; k := i;
    t := t + 1; s[n + t] := 0;
    f[n + t, 0] := 1; f[n + t, 1] := 1;
    repeat
      m := 0;
      for j := 1 to n do if (c[j] = k) and (ind[j] = 0) then begin
        m := m + 1;
        a[m] := j;
      end;
      if m > 0 then begin
        process(f[k], rep[k]);
        mult(f[k], s[k]);
      end;
      k := c[k];
    until k = i;

    repeat
      L := L + 1; a[L] := k;
      s[n + t] := s[n + t] + s[k]; mult(f[n + t], f[k]);
      ind[k] := 0; k := c[k];
    until k = i;

    for j := 1 to L do a[L + j] := a[j];
    for j := 1 to L + 1 do begin
      temp[j] := '';
      for k := 0 to L - 1 do temp[j] := temp[j] + rep[a[j + k]];
    end;

    for j := 1 to s[n + t] do mult(f[n + t], j);
    for j := 1 to L do
      for k := 1 to s[a[j]] do
        divide(f[n + t], k);

    k := 0;
    for j := 1 to l do if temp[1] = temp[1 + j] then begin
      k := j;
      break;
    end;

    divide(f[n + t], L div k); rep[n + t] := temp[1];
    for j := 1 to L do if temp[j] < rep[n + t] then rep[n + t] := temp[j];
  end;

  m := t;
  for i := 1 to m do a[i] := n + i;
  fillchar(answer, sizeof(answer), 0);
  process(answer, st);
  print(answer);
end;

var
        nowCase, task : integer;

begin
  readln(task);
  for nowCase := 1 to task do begin
        write('Case ', nowCase, ': ');
        init;
        main;
  end;
end.
