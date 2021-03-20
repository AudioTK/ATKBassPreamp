echo off
echo Making BassPreamp win distribution ...

echo ------------------------------------------------------------------
echo Updating version numbers ...

call python update_version.py

echo ------------------------------------------------------------------
echo Building ...

call "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64

msbuild Builds/VisualStudio2019_32/BassPreamp.sln /p:configuration=release /p:platform=win32
msbuild Builds/VisualStudio2019/BassPreamp.sln /p:configuration=release /p:platform=x64

echo ------------------------------------------------------------------
echo Making Installer ...

"%ProgramFiles(x86)%\Inno Setup 5\iscc" ".\installer\BassPreamp.iss"

pause
