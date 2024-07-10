@echo OFF
REM build script for the sandbox

SetLocal EnableDelayedExpansion

REM get list of all .cpp files
SET cppFiles=src/**.cpp
REM FOR /R %%f in (*.cpp) do (
REM     SET cppFiles= !cppFiles! %%f
REM )

REM echo "files: " %cppFiles%

SET assembly=sandbox

SET compilerFlags=
REM -Wall -Werror

REM add source file dirs
SET includeFlags=-I../engine/src/

REM add libraries to link
SET linkerFlags=-L../bin/ -lengine

REM add defines for configurations
SET defines=-D_DEBUG -DIIMPORT

ECHO building %assembly%...

clang++ %cppFiles% %compilerFlags% -o ../bin/%assembly%.exe %defines% %includeFlags% %linkerFlags%

ECHO %assembly% building complete with no errors.