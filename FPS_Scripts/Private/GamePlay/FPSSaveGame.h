// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "FPSSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class UFPSSaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<float> ScoresCPP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> TimesCPP;
};
