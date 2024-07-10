@echo OFF
REM build script for the engine

SetLocal EnableDelayedExpansion

REM get list of all .cpp files
set "cppFiles="

PUSHD src
REM Iterate through all .cpp files recursively
for /r %%x in (*.cpp) do (
    set "_curFilePath=%%~x"
    REM Remove the leading .\ and add the path to cppFiles
    set "cppFiles=!cppFiles! !_curFilePath:~2!"
)

if defined cppFiles set "cppFiles=!cppFiles:~1!"
POPD

SET assembly=engine

SET compilerFlags=-g -shared -Wvarargs -Wall -Werror
REM -Wall -Werror

REM add source file dirs
SET includeFlags=-I./src/

REM add libraries to link (i.e. lglfw lglad etc...)
SET linkerFlags=

REM add defines for configurations
SET defines=-D_DEBUG -DIEXPORT -D_CRT_SECURE_NO_WARNINGS 

ECHO building %assembly%...

clang++ %cppFiles% %compilerFlags% -o ../bin/%assembly%.dll %defines% %includeFlags% %linkerFlags%

ECHO %assembly% building complete with no errors.