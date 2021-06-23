rm .\build -Recurse

mkdir build
cmake -S . -B .\build
cmake --build .\build
.\build\Debug\app.exe