// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "MyCheatManager.generated.h"

/**
 * 
 */
UCLASS()
class UMyCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(exec)
	void FPSSetResolution(int32 width, int32 height);

	UFUNCTION(exec)
	void FPSSetWindowMode(int32 WindowMode);

	UFUNCTION(exec)
	void FPSSetMouseSensitivity(float value);

	UFUNCTION(exec)
	void FPSSetBrightness(float value);
};
