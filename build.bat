@echo off
echo Building Neurowill-Code (NWC) Demo...
cl /EHsc /std:c++17 nwcore/bridge.cpp examples/main_demo.cpp /Fe:nwcore_demo.exe
echo Done.
