// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/FPSGamePlayWidget.h"
#include <FPS/FPSGameMode.h>
#include <Kismet/GameplayStatics.h>

void UFPSGamePlayWidget::TickTimeCPP()
{
	AFPSGameMode* GameMode = Cast<AFPSGameMode>(UGameplayStatics::GetGameMode(this));
	if (GameMode)
	{
		StateOfGameCPP State = GameMode->GetStateCPP();
		FDateTime StartTime = GameMode->GetTimeCPP();
		FDateTime Now = FDateTime::Now();
		FTimespan Delta = Now - StartTime;

		switch (State)
		{
		case StateOfGameCPP::Ready:
			TextTime->SetText(FText::FromString(TEXT("")));
				break;
		case StateOfGameCPP::Playing:
			FString Minutes = FString::FromInt(Delta.GetMinutes());
			FString Seconds = FString::FromInt(Delta.GetSeconds());
			FString MilliSeconds = FString::FromInt(Delta.GetFractionMilli());
			FString Text = TEXT("Stopwatch>") + Minutes + TEXT(":") + Seconds + TEXT(".") + MilliSeconds;
			TextTime->SetText(FText::FromString(Text));
			break;

		}
	}
}
