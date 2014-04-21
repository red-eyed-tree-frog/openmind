#pragma once
#include "GoalGenerator.h"

#include <boost/lexical_cast.hpp>

template <class ChildT>
class GeneralGoalGenerator :
	public GoalGenerator
{
	typedef GoalGenerator base_t;
public:
	typedef boost::shared_ptr<ChildT>	ptr_t;

	GeneralGoalGenerator(const string_t& name)
		: base_t(name.c_str())
	{
	}

	~GeneralGoalGenerator(void)
	{
	}

	static base_t::ptr_t Make()
	{
		return base_t::ptr_t(
			new ChildT(
				const_cast<wchar_t*>(boost::lexical_cast<std::wstring>(typeid(ChildT).name()).c_str())
			));
	}
};
