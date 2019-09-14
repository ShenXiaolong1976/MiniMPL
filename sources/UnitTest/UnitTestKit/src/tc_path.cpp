#include <UnitTestKit\tc_path.h>
#include <MiniMPL\arrayTrait.hpp>

#include <shlwapi.h>
#pragma comment(lib,"shlwapi.lib")

namespace UnitTest
{
    stlStringA getOutputPathA()
    {   
        stlStringA::value_type path[MAX_PATH];
//         GetModuleFileName(NULL,path,MAX_PATH);
//         //GetModuleFileName(NULL, modulename,arraySize(modulename));
//         PathRemoveFileSpec(path);  //���ļ�ȫ·���г�ȥ�ļ�������չ��

        GetCurrentDirectoryA(arraySize(path),path);
        return path;
    }

    stlStringW getOutputPathW()
    {
        stlStringW::value_type  path[MAX_PATH];
        //         GetModuleFileName(NULL,path,MAX_PATH);
        //         //GetModuleFileName(NULL, modulename,arraySize(modulename));
        //         PathRemoveFileSpec(path);  //���ļ�ȫ·���г�ȥ�ļ�������չ��

        GetCurrentDirectoryW(arraySize(path),path);
        return path;
    }

}