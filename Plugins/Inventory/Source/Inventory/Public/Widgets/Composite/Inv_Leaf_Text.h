#pragma once

#include "CoreMinimal.h"
#include "Widgets/Composite/Inv_Leaf.h"
#include "Inv_Leaf_Text.generated.h"

UCLASS()
class INVENTORY_API UInv_Leaf_Text : public UInv_Leaf
{
	GENERATED_BODY()
	
public:
	virtual void NativePreConstruct() override;
	void SetText(const FText& Text) const;

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> Text_LeafText;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 FontSize = 12;
};
