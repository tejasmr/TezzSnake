Remove-Item .\build -Recurse

mkdir build
Set-Location build
cmake .. -G "MinGW Makefiles"
cmake --build .
.\build\Debug\app.exe
Set-Location ..