﻿#pragma once

#include "IMDFastBindingPropertySetter.h"

/**
 * 
 */
class MDFASTBINDING_API FMDFastBindingPropertySetter_Objects : public IMDFastBindingPropertySetter
{
public:
	virtual void SetProperty(const FProperty& DestinationProp, void* DestinationValuePtr, const FProperty& SourceProp, const void* SourceValuePtr) const override;
	virtual bool CanSetProperty(const FProperty& DestinationProp, const FProperty& SourceProp) const override;

};
