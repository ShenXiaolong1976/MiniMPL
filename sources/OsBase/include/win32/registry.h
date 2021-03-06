#ifndef __REGISTRY_H__
#define __REGISTRY_H__
/***********************************************************************************************************************
* Description         :
* Author              : Shen.Xiaolong(2009-2016), xlshen@126.com  xlshen2002@hotmail.com
* Copyright           : free to use / modify / sale in free and commercial software with those head comments.
***********************************************************************************************************************/
#include <MiniMPL/libConfig.h>
#include <MiniMPL/productSpecialDef.h>
#include <Windows.h>

namespace OS_Win32
{
    class CRegistry
    {//or use ATL::CRegKey
    public:
		//HKEY is called as hive
		//https://docs.microsoft.com/en-us/windows/win32/sysinfo/registry-hives
        CRegistry(HKEY rootKey);
        virtual ~CRegistry();

        //interface
        bool	listSubKeys(stlString const& key,stlVector<stlString>& subKeys);
        bool	readBinaryValue(stlString const& valueName, unsigned char* pValue, ULONG& nBytes);
        bool	readStringValue(stlString const& valueName, stlString& val);


        bool	open(stlString const& keyPath,REGSAM dwAccess=KEY_READ);
        bool	close();

    protected:
        stlString getErrorText(DWORD eCode);
        bool      verifyKeyPath(stlString const& keyPath);

    protected:
        stlString       m_lastErrorText;
        HKEY			m_rootKey;

        HKEY			m_lastOpenedKey;
        stlString	    m_keyPath;
        REGSAM			m_dwAccess;
    };
}


#endif // __REGISTRY_H__
