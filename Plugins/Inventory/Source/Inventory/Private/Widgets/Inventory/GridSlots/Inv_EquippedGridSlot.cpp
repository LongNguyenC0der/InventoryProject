#include "Widgets/Inventory/GridSlots/Inv_EquippedGridSlot.h"
#include "Widgets/Inventory/HoverItem/Inv_HoverItem.h"
#include "InventoryManagement/Utils/Inv_InventoryStatics.h"

void UInv_EquippedGridSlot::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    Super::NativeOnMouseEnter(InGeometry, InMouseEvent);

    if (!IsAvailable()) return;
    UInv_HoverItem* HoverItem = UInv_InventoryStatics::GetHoverItem(GetOwningPlayer());
    if (!IsValid(HoverItem)) return;

    if (HoverItem->GetItemType().MatchesTag(EquipmentTypeTag))
    {
        SetOccupiedTexture();
    }
}

void UInv_EquippedGridSlot::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
    Super::NativeOnMouseLeave(InMouseEvent);

    if (!IsAvailable()) return;
    UInv_HoverItem* HoverItem = UInv_InventoryStatics::GetHoverItem(GetOwningPlayer());
    if (!IsValid(HoverItem)) return;

    if (HoverItem->GetItemType().MatchesTag(EquipmentTypeTag))
    {
        SetUnoccupiedTexture();
    }
}

FReply UInv_EquippedGridSlot::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    EquippedGridSlotClicked.Broadcast(this, EquipmentTypeTag);
    return FReply::Handled();
}