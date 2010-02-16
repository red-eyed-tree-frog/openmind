#include "StdAfx.h"
#include "ConsoleGeneratorProxy.h"

#include "ProportionGenerator.h"

#include <iostream>
#include <loki/Typelist.h>
#include <boost/lexical_cast.hpp>

namespace
{
	typedef GoalGenerator::ptr_t (*GeneratorMaker_t)();

	const GeneratorMaker_t Generators[] =
	{
		ProportionGenerator::Make
	};

	typedef	Loki::TL::MakeTypelist<
		ProportionGenerator
	>::Result generators_tl;


//#define StartTypeList ;\
//#define , <TypeList
	//typedef 

	//Loki::TL::

	//template class T;
	//struct AddGeneratorType
	//{

	//};
}

ConsoleGeneratorProxy::ConsoleGeneratorProxy(void)
: base_t(L"ConsoleGeneratorProxy_Menu")
{
	BOOST_FOREACH(GeneratorMaker_t generator, Generators)
	{
		_generators.push_back(generator());
	}
}

ConsoleGeneratorProxy::~ConsoleGeneratorProxy(void)
{
}

Goal::ptr_t ConsoleGeneratorProxy::GenerateGoal()
{
	std::wcout << L"Here is list of available goal generators:" << std::endl;
	std::wcout << L"0. Exit" << std::endl;
	size_t generatorsCount = _generators.size();
	size_t i = 0 ;
	for ( ; i < generatorsCount; ++i)
	{
		std::wcout
			<< L'\t' << boost::lexical_cast<std::wstring>(i+1) << L' '
			<< _generators[i]->Name() << std::endl;
	}
	std::wcout << L"choose someone:" << std::endl;

	do
	{
		i = boost::lexical_cast<size_t>(std::wcin.get());
	} while (i != 0 && i > generatorsCount);

	if (!i)
	{
		exit(0);
	}

	return _generators[i-1]->GenerateGoal();	
}