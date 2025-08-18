#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inv_InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryItemChange, class UInv_InventoryItem*, Item);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class INVENTORY_API UInv_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInv_InventoryComponent();
	void ToggleInventoryMenu();

	FInventoryItemChange OnItemAdded;
	FInventoryItemChange OnItemRemoved;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<class UInv_InventoryBase> InventoryMenuClass;

	UPROPERTY()
	TObjectPtr<UInv_InventoryBase> InventoryMenu;

	TWeakObjectPtr<APlayerController> OwningController;

	bool bInventoryMenuOpen;

	void ConstructInventory();
	void OpenInventoryMenu();
	void CloseInventoryMenu();
};
