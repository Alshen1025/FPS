// Fill out your copyright notice in the Description page of Project Settings.


#include "Cheat/MyCheatManager.h"
#include <FPSGameUserSettings.h>

void UMyCheatManager::FPSSetResolution(int32 width, int32 height)
{
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		UserSettings->SetScreenResolution(FIntPoint(width, height));
		UserSettings->ApplySettings(false);
	}
}

void UMyCheatManager::FPSSetWindowMode(int32 WindowMode)
{
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		EWindowMode::Type NewWindowMode = (EWindowMode::Type)WindowMode;
		UserSettings->SetFullscreenMode(NewWindowMode);
		UserSettings->ApplySettings(false);
	}
}

void UMyCheatManager::FPSSetMouseSensitivity(float Value)
{
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		UserSettings->SetMouseSensitivity(Value);
		UserSettings->ApplySettings(false);
	}
}

void UMyCheatManager::FPSSetBrightness(float value)
{
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		UserSettings->SetAutoExposureBrightness(value);
		UserSettings->ApplySettings(false);
	}

}
