// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Components/TextBlock.h>
#include "Blueprint/UserWidget.h"
#include <Components/Button.h>
#include <Components/GridPanel.h>
#include "FPSResult.generated.h"




/**
 * 
 */
UCLASS()
class UFPSResult : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;


	UFUNCTION(BlueprintCallable)
	void InitRankingCPP();

	UFUNCTION()
	void OnRestartClicked();

	UFUNCTION()
	void OnExitClicked();

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> TextScore;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> TextRanking;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UGridPanel> RankingTable;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonRestart;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonExit;
};
