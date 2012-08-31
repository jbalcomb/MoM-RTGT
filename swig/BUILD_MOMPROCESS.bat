REM "c:\Program Files (x86)\Microsoft Visual Studio 9.0\VC\bin\vcvars32.bat"
c:\swigwin-2.0.8\swig.exe -python -c++ -DPACKED_STRUCT momprocess.i
cl /LD /EHsc /o _momprocess.pyd /I c:\Python32\include momprocess_wrap.cxx MoMProcessCommon.cpp MoMProcessWindows.cpp MoMUtility.cpp c:\Python32\libs\python32.lib user32.lib
c:\Python32\python.exe example_momprocess.py