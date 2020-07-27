#pragma once

struct ICloneable
{
	virtual ~ICloneable() {}
	virtual ICloneable* clone() const = 0;
};