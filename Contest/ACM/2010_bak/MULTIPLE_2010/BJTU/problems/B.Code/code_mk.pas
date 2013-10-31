type integer = longint;

var filename : string;
    f        : text;

procedure make(test : char; n : integer; rand : integer);
var i : integer;
begin
  filename := 'code' + test + '.in';
  write(f, 'Making ', filename, ' ... ... ');
  assign(output, filename); rewrite(output);
  writeln(n);
  if rand = 1
    then for i := 1 to n do write(random(n) + 1, ' ')
    else for i := 1 to n do if i < n then write(i + 1, ' ') else write(n);
  writeln;
  close(output);
  writeln(f, 'Done');
end;

begin
  assign(f, ''); rewrite(f);
  writeln(f, 'Generating CODE Input Data ... ...:');
  randseed := 14566;
  make('0', 3, 1);
  make('1', 6, 1);
  make('2', 9, 1);
  make('3', 12, 1);
  make('4', 15, 0);
  make('5', 18, 1);
  make('6', 21, 1);
  make('7', 24, 1);
  make('8', 27, 1);
  make('9', 30, 0);
  writeln(f, 'Input Data Done');
end.

