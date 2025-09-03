// Перебор множеств
Const n=10;
Var a:array[1..n] of byte;
    i:integer;

Procedure Perebor(k:integer);
Var i:integer;
begin
    If k>n then begin
        For i:=1 to n do Write(a[i]:2);
        Writeln;
        Exit
    end;
    For i:=0 to 1 do begin
       a[k]:=i;
       Perebor(k+1)
    end
end;


begin
    Perebor(1);
    
end.
