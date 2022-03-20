﻿#pragma once

#include "CoreMinimal.h"
#include "SGraphNode.h"
#include "SGraphPin.h"
#include "KismetPins/SGraphPinObject.h"

class UMDFastBindingGraphNode;
class UMDFastBindingObject;

class MDFASTBINDINGEDITOR_API SMDFastBindingSelfGraphPinWidget : public SGraphPinObject
{
public:
	using SGraphPinObject::Construct;
	
#if ENGINE_MAJOR_VERSION >= 5
	virtual bool ShouldDisplayAsSelfPin() const override { return true; }
#endif
};

/**
 * 
 */
class MDFASTBINDINGEDITOR_API SMDFastBindingGraphNodeWidget : public SGraphNode
{
public:
	SLATE_BEGIN_ARGS(SMDFastBindingGraphNodeWidget)
		{
		}

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UMDFastBindingGraphNode* InNode);

#if ENGINE_MAJOR_VERSION <= 4
	virtual void MoveTo(const FVector2D& NewPosition, FNodeSet& NodeFilter) override;
#else
	virtual void MoveTo(const FVector2D& NewPosition, FNodeSet& NodeFilter, bool bMarkDirty = true) override;
#endif

	UMDFastBindingGraphNode* GetGraphNode() const;

	UMDFastBindingObject* GetBindingObject() const;

protected:
	virtual void UpdateErrorInfo() override;

	virtual TSharedPtr<SGraphPin> CreatePinWidget(UEdGraphPin* Pin) const override;
	
	virtual void CreateBelowPinControls(TSharedPtr<SVerticalBox> MainBox) override;

	virtual void CreateInputSideAddButton(TSharedPtr<SVerticalBox> InputBox) override;

	virtual FReply OnAddPin() override;

	bool IsSelfPin(UEdGraphPin& Pin) const;
	
};
