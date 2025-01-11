// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/Slider.h>
#include <Components/EditableText.h>
#include <Components/Button.h>
#include "FPSUserSettingWidget.generated.h"




/**
 * 
 */
UCLASS()
class UFPSUserSettingWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;

	void InitConponents();
	void BindEvents();


	UFUNCTION()
	void OnWidthChanged(const FText& Text);
	UFUNCTION()
	void OnHeightChanged(const FText& Text);
	UFUNCTION()
	void OnFullScreenClicked();
	UFUNCTION()
	void OnBorderlessClicked();
	UFUNCTION()
	void OnWindowedClicked();
	UFUNCTION()
	void OnMouseSensitivityChanged(float value);
	UFUNCTION()
	void OnBrightnessChanged(float value);
	UFUNCTION()
	void OnExitClicked();
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UEditableText> EditWidth;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UEditableText> EditHeight;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonFullScreen;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonBorderless;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonWindowed;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<USlider> SliderMouseSensitivity;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UEditableText> TextMouseSensitivity;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<USlider> SliderBrightness;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UEditableText> TextBrightness;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonExit;
};
