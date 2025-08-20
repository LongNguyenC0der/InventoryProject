#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_SlottedItem.generated.h"

UCLASS()
class INVENTORY_API UInv_SlottedItem : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetImageBrush(const FSlateBrush& Brush) const;
	void UpdateStackCount(int32 StackCount);

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> Image_Icon;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> Text_StackCount;

	int32 GridIndex;
	FIntPoint GridDimensions;
	TWeakObjectPtr<class UInv_InventoryItem> InventoryItem;
	bool bIsStackable = false;

public:
	void SetIsStackable(bool bStackable) { bIsStackable = bStackable; }
	bool IsStackable() const { return bIsStackable; }
	UImage* GetImageIcon() const { return Image_Icon; }
	void SetGridIndex(int32 Index) { GridIndex = Index; }
	int32 GetGridIndex() const { return GridIndex; }
	void SetGridDimensions(const FIntPoint& Dimensions) { GridDimensions = Dimensions; }
	FIntPoint GetGridDimensions() const { return GridDimensions; }
	void SetInventoryItem(UInv_InventoryItem* Item) { InventoryItem = Item; }
	UInv_InventoryItem* GetInventoryItem() const { return InventoryItem.Get(); }
};
