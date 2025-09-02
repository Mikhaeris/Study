uses GraphABC;

var
  frames: array of Picture;
  frameCount, i: integer;

begin
  frameCount := 10;

  SetWindowSize(500, 500);
  
  SetLength(frames, frameCount);
  for i := 0 to frameCount - 1 do
    frames[i] := Picture.Create('C:\Users\Thinkpad\Documents\Projects\Pascal\Pendulum\photo\c46a9e5508844c6b93bc04d048d45cc6IsMFDtrKZXOd7X1A-' + IntToStr(i) + '.jpg');
  
  while true do
  begin
    for i := 0 to frameCount - 1 do
    begin
      Lockdrawing;
      ClearWindow;
      frames[i].Draw(0, 0, WindowWidth, WindowHeight);
      Redraw;
      Sleep(100);
    end;
    
    for i := frameCount-1 downto 0 do
    begin
      Lockdrawing;
      ClearWindow;
      frames[i].Draw(0, 0, WindowWidth, WindowHeight);
      Redraw;
      Sleep(100);
    end;
  end;
end.
