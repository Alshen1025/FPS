// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/FPSResult.h"
#include <FPS/FPSGameMode.h>
#include <Kismet/GameplayStatics.h>
#include <Blueprint/WidgetTree.h>
#include <Components/GridSlot.h>



void UFPSResult::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	ButtonRestart->OnClicked.AddDynamic(this, &UFPSResult::OnRestartClicked);
	ButtonExit->OnClicked.AddDynamic(this, &UFPSResult::OnExitClicked);
}

void UFPSResult::InitRankingCPP()
{
	AFPSGameMode* GameMode = Cast<AFPSGameMode>(UGameplayStatics::GetGameMode(this));
	if (GameMode)
	{
		int32 Ranking = GameMode->GetRankingCPP();
		TArray<float> Scores = GameMode->GetRankingScoresCPP();
		TArray<FString> Times = GameMode->GetRankingTimesCPP();

		{
			FString Text = TEXT("Your ranking = #") + FString::FromInt(Ranking);
			TextRanking->SetText(FText::FromString(Text));
		}
		for (int32 Index = 0; Index < Scores.Num(); ++Index)
		{
			int32 Row = Index + 1;

			UTextBlock* Rank = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
			if (Rank)
			{
				Rank->SetText(FText::AsNumber(Row));
				UGridSlot* ChildSlot = RankingTable->AddChildToGrid(Rank, Row, 0);
				ChildSlot->SetNudge(FVector2D(0.0, 20.0 * Row));
			}

			UTextBlock* Score = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
			if (Score)
			{
				Score->SetText(FText::AsNumber(Scores[Index]));
				UGridSlot* ChildSlot = RankingTable->AddChildToGrid(Score, Row, 1);
				ChildSlot->SetNudge(FVector2D(200, 20.0 * Row));
			}

			UTextBlock* Time = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
			if (Time)
			{
				Time->SetText(FText::FromString(Times[Index]));
				UGridSlot* ChildSlot = RankingTable->AddChildToGrid(Time, Row, 2);
				ChildSlot->SetNudge(FVector2D(400, 20.0 * Row));
			}

		}
	} 
}

void UFPSResult::OnRestartClicked()
{
	UGameplayStatics::OpenLevel(this, FName(*UGameplayStatics::GetCurrentLevelName(this)));
}

void UFPSResult::OnExitClicked()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, true);
}
