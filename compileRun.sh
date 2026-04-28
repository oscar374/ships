#!/bin/bash
cd build
cmake --build . --config Release
cd ..
powershell -ExecutionPolicy Bypass -Command ".\build\Release\Ships.exe"