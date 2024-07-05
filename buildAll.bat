@echo OFF
REM build everything

ECHO building everthing...

REM go into engine/ and call build.bat
PUSHD engine
CALL build.bat
POPD
IF %ERRORLEVEL% NEQ 0 (echo error: %ERRORLEVEL% && exit)

REM go into sandbox/ and call build.bat
PUSHD sandbox
CALL build.bat
POPD
IF %ERRORLEVEL% NEQ 0 (echo error: %ERRORLEVEL% && exit)

ECHO all assemblies built successfully.