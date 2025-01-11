// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/FPSUserSettingWidget.h"
#include <FPSGameUserSettings.h>

void UFPSUserSettingWidget::NativeConstruct()
{
	Super::NativeConstruct();
	InitConponents();
	BindEvents();
}

void UFPSUserSettingWidget::InitConponents()
{
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		FIntPoint Resolution = UserSettings->GetScreenResolution();
		EditWidth->SetText(FText::AsNumber(Resolution.X));
		EditHeight->SetText(FText::AsNumber(Resolution.Y));

		EWindowMode::Type WindowMode = UserSettings->GetFullscreenMode();
		switch (WindowMode)
		{
		case EWindowMode::Fullscreen:
			ButtonFullScreen->SetIsEnabled(false);
			break;
		case EWindowMode::WindowedFullscreen:
			ButtonBorderless->SetIsEnabled(false);
			break;
		case EWindowMode::Windowed:
			ButtonWindowed->SetIsEnabled(false);
			break;
		}

		float MouseSensitivity = UserSettings->GetMouseSensitivity();
		SliderMouseSensitivity->SetValue(MouseSensitivity);
		TextMouseSensitivity->SetText(FText::AsNumber(MouseSensitivity));

		float AutoExposureBrightness = UserSettings->GetAutoEcposureBrightness();
		float Brightness = (AutoExposureBrightness * -1.0) + 5.0;
		SliderBrightness->SetValue(Brightness);
		TextBrightness->SetText(FText::AsNumber(Brightness));
	}
}

void UFPSUserSettingWidget::BindEvents()
{
	EditWidth->OnTextChanged.AddUniqueDynamic(this, &UFPSUserSettingWidget::OnWidthChanged);
	EditHeight->OnTextChanged.AddUniqueDynamic(this, &UFPSUserSettingWidget::OnHeightChanged);
	ButtonFullScreen->OnClicked.AddUniqueDynamic(this, &UFPSUserSettingWidget::OnFullScreenClicked);
	ButtonBorderless->OnClicked.AddUniqueDynamic(this, &UFPSUserSettingWidget::OnBorderlessClicked);
	ButtonWindowed->OnClicked.AddUniqueDynamic(this, &UFPSUserSettingWidget::OnWindowedClicked);
	SliderMouseSensitivity->OnValueChanged.AddUniqueDynamic(this, &UFPSUserSettingWidget::OnMouseSensitivityChanged);
	SliderBrightness->OnValueChanged.AddUniqueDynamic(this, &UFPSUserSettingWidget::OnBrightnessChanged);
	ButtonExit->OnClicked.AddUniqueDynamic(this, &UFPSUserSettingWidget::OnExitClicked);
}

void UFPSUserSettingWidget::OnWidthChanged(const FText& Text)
{
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		if (Text.IsNumeric())
		{
			FString String = Text.ToString();
			FIntPoint Resolution = UserSettings->GetScreenResolution();
			int32 Width = FCString::Atoi(*String);
			int32 Height = Resolution.Y;
			UserSettings->SetScreenResolution(FIntPoint(Width, Height));
			UserSettings->ApplySettings(false);
		}
	}
}

void UFPSUserSettingWidget::OnHeightChanged(const FText& Text)
{
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		if (Text.IsNumeric())
		{
			FString String = Text.ToString();
			FIntPoint Resolution = UserSettings->GetScreenResolution();
			int32 Width = Resolution.X;
			int32 Height =  FCString::Atoi(*String);
			if ((Width >= 720) && (Height >= 480))
			{
				UserSettings->SetScreenResolution(FIntPoint(Width, Height));
				UserSettings->ApplySettings(false);
			}
		}
	}
}

void UFPSUserSettingWidget::OnFullScreenClicked()
{
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		UserSettings->SetFullscreenMode(EWindowMode::Fullscreen);
		UserSettings->ApplySettings(false);
		ButtonFullScreen->SetIsEnabled(false);
		ButtonBorderless->SetIsEnabled(true);
		ButtonWindowed->SetIsEnabled(true);
	}
}

void UFPSUserSettingWidget::OnBorderlessClicked()
{
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		UserSettings->SetFullscreenMode(EWindowMode::WindowedFullscreen);
		UserSettings->ApplySettings(false);
		ButtonFullScreen->SetIsEnabled(true);
		ButtonBorderless->SetIsEnabled(false);
		ButtonWindowed->SetIsEnabled(true);
	}
}

void UFPSUserSettingWidget::OnWindowedClicked()
{
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		UserSettings->SetFullscreenMode(EWindowMode::Windowed);
		UserSettings->ApplySettings(false);
		ButtonFullScreen->SetIsEnabled(true);
		ButtonBorderless->SetIsEnabled(true);
		ButtonWindowed->SetIsEnabled(false);
	}
}

void UFPSUserSettingWidget::OnMouseSensitivityChanged(float value)
{
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		UserSettings->SetMouseSensitivity(value);
		UserSettings->ApplySettings(false);

		TextMouseSensitivity->SetText(FText::AsNumber(value));
	}
}

void UFPSUserSettingWidget::OnBrightnessChanged(float value)
{
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		float AutoExposureBrightness = (value - 5.0) * -1.0;

		UserSettings->SetAutoExposureBrightness(AutoExposureBrightness);
		UserSettings->ApplySettings(false);
		TextBrightness->SetText(FText::AsNumber(value));
	}
}

void UFPSUserSettingWidget::OnExitClicked()
{
	RemoveFromParent();
}
