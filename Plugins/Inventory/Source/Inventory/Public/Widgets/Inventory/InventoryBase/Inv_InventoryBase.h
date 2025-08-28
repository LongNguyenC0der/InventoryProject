#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/Inv_GridTypes.h"
#include "Inv_InventoryBase.generated.h"

UCLASS()
class INVENTORY_API UInv_InventoryBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual FInv_SlotAvailabilityResult HasRoomForItem(class UInv_ItemComponent* ItemComponent) const { return FInv_SlotAvailabilityResult(); }
	virtual void OnItemHovered(class UInv_InventoryItem* Item) {}
	virtual void OnItemUnhovered() {}
	virtual bool HasHoverItem() const { return false; }
	virtual class UInv_HoverItem* GetHoverItem() const { return nullptr; }
};