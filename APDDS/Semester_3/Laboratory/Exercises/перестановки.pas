//Перестановки
Const n=5;
Type SetInt=Set of byte;
Var a:array[1..n] of byte;

Procedure Perebor(k:integer;m:SetInt);
begin
   If k>n then begin
       For i:=1 to n do Write(a[i]);
       Writeln;
       Exit
   end;
   For i:=1 to n do
      If i in m then begin
         a[k]:=i;
         Perebor(k+1,m-[i])
      end

end;


Begin
   Perebor(1,[1..n]);
end.
