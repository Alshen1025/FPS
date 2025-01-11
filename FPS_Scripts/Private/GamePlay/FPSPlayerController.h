// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <Widget/FPSGamePlayWidget.h>
#include <InputMappingContext.h>
#include "FPSPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class AFPSPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

	UPROPERTY(Category = Controller, EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UInputMappingContext> FPSMappingContext;

	UPROPERTY(Category = Controller, EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> GameplayWidget;

	UPROPERTY(Category = Controller, EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> ResultWidget;
public:
	UFUNCTION()
	void OnEndGameCPP();
};
