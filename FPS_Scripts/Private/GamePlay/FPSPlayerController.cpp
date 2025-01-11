// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/FPSPlayerController.h"
#include <EnhancedInputSubsystems.h>
#include <Kismet/GameplayStatics.h>
#include <FPS/FPSGameMode.h>

void AFPSPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(FPSMappingContext, 0);
	}
	
	UUserWidget* Widget = CreateWidget(this, GameplayWidget);
	if (Widget)
	{
		Widget->AddToViewport();
	}
	AFPSGameMode* GameMode = Cast<AFPSGameMode>(UGameplayStatics::GetGameMode(this));
	if (GameMode)
	{
		GameMode->OnEndGameCPP.AddUniqueDynamic(this, &AFPSPlayerController::OnEndGameCPP);
	}
}

void AFPSPlayerController::OnEndGameCPP()
{
	UUserWidget* Widget = CreateWidget(this, ResultWidget);
	if (Widget)
	{
		Widget->AddToViewport();
	}
}
