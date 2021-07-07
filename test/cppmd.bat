@echo off
rename %1 *.cpp
g++ %1.cpp -o %1
%1
del %1.cpp
del %1.exe

