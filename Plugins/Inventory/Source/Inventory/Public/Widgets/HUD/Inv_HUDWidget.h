#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_HUDWidget.generated.h"

UCLASS()
class INVENTORY_API UInv_HUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void ShowPickupMessage(const FString& Message);

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void HidePickupMessage();

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UInv_InfoMessage> InfoMessage;

	UFUNCTION()
	void OnNoRoom();
};
