vld-2.5.1-setup.exe支持VS008-VS015
http://vld.codeplex.com/
https://github.com/KindDragon/vld
vld是一个非常方便的内存泄露检测工具，使用极其简单。
1.  使用安装包(vld-2.4rc2-setup.exe)安装，其会自动更新VC的库文件目录
2.  在应用程序的最前面加上#include <vld.h>重新编译即可。
2.1 如果使用MFC程序，则需要把#include <vld.h>加入到MFC的预编译头文件的后面即可。