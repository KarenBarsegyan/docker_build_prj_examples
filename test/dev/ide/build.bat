@echo off

:: Specify target name
set TARGET_NAME=GAZ_NN_PKE

:: Specify build system: STANDARD | NINJA
::set BUILD_SYSTEM=STANDARD
set BUILD_SYSTEM=NINJA

:: Timeouts (in secs.)
set ERROR_TIMEOUT=20
set SUCCESS_TIMEOUT=5

:: Parallel jobs count (for Standard build system)
set JOBS_COUNT=25

:: CMake root directory (relatively Shortcuts dir)
set CMAKE_ROOT_DIR="%~dp0..\..\.."
:: CMake build directory
set CMAKE_BUILD_DIR="%CMAKE_ROOT_DIR%\build"

:: Clear CMake cache directory
echo -- Clean CMake cache folder
if exist %CMAKE_BUILD_DIR% (
    rd /s /q %CMAKE_BUILD_DIR%
)
mkdir %CMAKE_BUILD_DIR%


:: Build
cd "%CMAKE_BUILD_DIR%"
pwd
if %BUILD_SYSTEM% EQU STANDARD (
    :: Standard build system
    cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" "%CMAKE_ROOT_DIR%"
) else (
    :: Ninja build system
    cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja "%CMAKE_ROOT_DIR%"
)

:: Clear and Build target
cmake --build . --target clean
cmake --build . --target all -j %JOBS_COUNT%


:: Wait for any key
if %ERRORLEVEL% EQU 0 (
    :: All OK - wait for short timeout or any key
    timeout /t %SUCCESS_TIMEOUT%
) else (
    :: Errors - wait for long timeout or any key
::    timeout /t %ERROR_TIMEOUT%
    pause
)
