@echo OFF
REM build script for the engine

SetLocal EnableDelayedExpansion

REM get list of all .cpp files
SET cppFiles=src/**.cpp

REM FOR /R %%f in (src/**.cpp) do (
REM     SET cppFiles = !cppFiles! %%f
REM )

REM echo "files: " %cppFiles%

SET assembly=engine

SET compilerFlags=-g -shared -Wvarargs -Wall -Werror 
REM -Wall -Werror

REM add source file dirs
SET includeFlags=-Isrc -I../src/

REM add libraries to link (i.e. lglfw lglad etc...)
SET linkerFlags=-luser32

REM add defines for configurations
SET defines=-D_DEBUG -DIEXPORT -D_CRT_SECURE_NO_WARNINGS 

ECHO building %assembly%...

clang %cppFiles% %compilerFlags% -o ../bin/%assembly%.dll %defines% %includeFlags% %linkerFlags%