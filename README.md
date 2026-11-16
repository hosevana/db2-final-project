# db2-final-project
Final Project for Integrated Database Systems

## Connection Instructions
### Python:
  Start a Codespace on Github with this repository.
  Open a terminal and enter the following commands to run the python project: 
  ```sh
  python -m pip install pymongo
  python py_CRUD/test_py.py
  ```
### C#:
  Start a Codespace on Github with this repository.
  Open a terminal and enter the following commands to run the C# project: 
  ```sh
  dotnet add package MongoDB.Driver
  cd cs_CRUD
  dotnet run
  ```
### C++:
  Start a Codespace on Github with this repository.
  Open a terminal and enter the following commands:
  ```sh
  cd cpp_CRUD
  cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE="$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake"
  cmake --build build
  ./build/test_cpp
  ```
### Java:
  Start a Codespace on Github with this repository.
  Open a terminal and enter the following command to run the java project.
  ```sh
  mvn -f java_CRUD/pom.xml exec:java
  ```
