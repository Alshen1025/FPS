// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "UObject/ConstructorHelpers.h"

AFPSGameMode::AFPSGameMode()
{
	//// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	//if (PlayerPawnBPClass.Class != NULL)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
}

void AFPSGameMode::UpdateRankingCPP()
{
	int32 RankingIndex = 0;
	for (int32 Index = 0; Index < RankingScoresCPP.Num(); ++Index)
	{
		float Element = RankingScoresCPP[Index];
		if (Element >= ScoreCPP)
		{
			RankingIndex++;
		}
		else
		{
			break;
		}
	}
	RankingCPP = RankingIndex + 1;
	RankingScoresCPP.Insert(ScoreCPP, RankingIndex);
	RankingTimesCPP.Insert(EndTimeCPP.ToString(), RankingIndex);
	if (RankingScoresCPP.Num() > 10)
	{
		RankingScoresCPP.RemoveAt(RankingScoresCPP.Num() - 1);
		RankingTimesCPP.RemoveAt(RankingTimesCPP.Num() - 1);
	}
}

StateOfGameCPP AFPSGameMode::GetStateCPP() const
{
	return StateCPP;
}

FDateTime AFPSGameMode::GetTimeCPP() const
{
	return StartTimeCPP;
}

int32 AFPSGameMode::GetRankingCPP() const
{
	return RankingCPP;
}

TArray<float> AFPSGameMode::GetRankingScoresCPP() const
{
	return RankingScoresCPP;
}

TArray<FString> AFPSGameMode::GetRankingTimesCPP() const
{
	return RankingTimesCPP;
}
