#ifndef __STDWRAPPER_HPP__
#define __STDWRAPPER_HPP__
/***********************************************************************************************************************
* Description         : pack some std feature to use easily. e.g. replace std::make_shared
* Author              : Shen.Xiaolong (2009-Tue ) , xlshen@126.com  xlshen2002@hotmail.com
* Copyright           : free to use / modify / sale in free and commercial software with those head comments.
***********************************************************************************************************************/
#include <MiniMPL/innerDetail/stdwrapper_detail.hpp>
#include <MiniMPL/innerDetail/macro_traitimpl.hpp>

namespace MiniMPL
{
	namespace StdWrapper
	{
		struct maxValue		: public InnerDetail::ValueComparer<maxValue>
		{ 
			template<typename T>  CompileValue	operator T() const { return (std::numeric_limits<T>::max)(); } 
		};		

		struct minValue		: public InnerDetail::ValueComparer<minValue>
		{ 
			template<typename T>  CompileValue	operator T() const { return (std::numeric_limits<T>::min)(); } 
		};

		struct sharedPtrGenerater	: public InnerDetail::sharedPtrGeneraterImpl		 {};	//replace std::make_shared interface except return base pointer when creating derived class object.
		struct sharedPtrArray		: public InnerDetail::sharedPtrArrayImpl			 {};		
	}	
}

static MiniMPL::StdWrapper::maxValue					_maxValue;
static MiniMPL::StdWrapper::minValue					_minValue;
static MiniMPL::StdWrapper::sharedPtrGenerater			_sharedPtrGenerater;	//it is not suitable to create derived class, return base class pointer
static MiniMPL::StdWrapper::sharedPtrArray				_sharedPtrArray;

#endif // __STDWRAPPER_HPP__
