// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameUserSettings.h"

float UFPSGameUserSettings::GetMouseSensitivity() const
{
	return MouseSensitivity;
}

float UFPSGameUserSettings::GetAutoEcposureBrightness() const
{
	return AutoExposureBrightness;
}

void UFPSGameUserSettings::SetAutoExposureBrightness(float value) 
{
	AutoExposureBrightness = value;
}

void UFPSGameUserSettings::SetMouseSensitivity(float value)
{
	MouseSensitivity = value;
}

void UFPSGameUserSettings::SetToDefaults()
{
	Super::SetToDefaults();
	MouseSensitivity = 1.0;
	AutoExposureBrightness = 0.0;
}
