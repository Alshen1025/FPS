// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "FPSGameUserSettings.generated.h"

/**
 * 
 */
UCLASS()
class UFPSGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	float GetMouseSensitivity() const;

	UFUNCTION(BlueprintCallable)
	float GetAutoEcposureBrightness() const;

	UFUNCTION(BlueprintCallable)
	void SetAutoExposureBrightness(float value);

	UFUNCTION(BlueprintCallable)
	void SetMouseSensitivity(float value);
	
protected:
	virtual void SetToDefaults() override;
protected:
	UPROPERTY(Config)
	float MouseSensitivity;

	UPROPERTY(Config)
	float AutoExposureBrightness;
};
