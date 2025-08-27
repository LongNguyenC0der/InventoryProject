#pragma once

#include "CoreMinimal.h"
#include "Widgets/Composite/Inv_Leaf.h"
#include "Inv_Leaf_LabeledValue.generated.h"

UCLASS()
class INVENTORY_API UInv_Leaf_LabeledValue : public UInv_Leaf
{
	GENERATED_BODY()
	
public:
	virtual void NativePreConstruct() override;
	void SetText_Label(const FText& Text, bool bCollapse) const;
	void SetText_Value(const FText& Text, bool bCollapse) const;

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> Text_Label;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> Text_Value;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 FontSize_Label = 12;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 FontSize_Value = 18;
};