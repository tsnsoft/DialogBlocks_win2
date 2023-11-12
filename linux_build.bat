wsl `wx-config --cxx --cxxflags` -o linux_app *.cpp `wx-config --libs`
start /b wsl ./linux_app
