echo("Bruteforce Method:")
Measure-Command { .\bf.exe }
echo("Optimal Method:")
Measure-Command { .\op.exe }
echo("Table Method:")
Measure-Command { .\tb.exe }