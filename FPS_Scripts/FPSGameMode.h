// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FFPSGameModeOnEndGame, AFPSGameMode, OnEndGameCPP);

UENUM(BlueprintType)
enum class StateOfGameCPP : uint8
{
	Ready,
	Playing,
	Ended,

};
UCLASS()
class AFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFPSGameMode();

	UFUNCTION(BlueprintCallable)
	void UpdateRankingCPP();

	UFUNCTION(BlueprintCallable)
	StateOfGameCPP GetStateCPP() const; 

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FFPSGameModeOnEndGame OnEndGameCPP;

	UFUNCTION(BlueprintCallable)
	FDateTime GetTimeCPP() const;

	UFUNCTION(BlueprintCallable)
	int32 GetRankingCPP() const;

	UFUNCTION(BlueprintCallable)
	TArray<float> GetRankingScoresCPP() const;

	UFUNCTION(BlueprintCallable)
	TArray<FString> GetRankingTimesCPP() const;


protected:
	UPROPERTY(Category = Gamemode, VisibleAnywhere, BlueprintReadWrite)
	FDateTime StartTimeCPP;

	UPROPERTY(Category = Gamemode, VisibleAnywhere, BlueprintReadWrite)
	FDateTime EndTimeCPP;

	UPROPERTY(Category = Gamemode, VisibleAnywhere, BlueprintReadWrite)
	TArray<float> RankingScoresCPP;

	UPROPERTY(Category = Gamemode, VisibleAnywhere, BlueprintReadWrite)
	TArray<FString> RankingTimesCPP;

	UPROPERTY(Category = Gamemode, VisibleAnywhere, BlueprintReadWrite)
	int32 RankingCPP;

	UPROPERTY(Category = Gamemode, VisibleAnywhere, BlueprintReadWrite)
	float ScoreCPP;

	UPROPERTY(Category = Gamemode, VisibleAnywhere, BlueprintReadWrite)

	StateOfGameCPP StateCPP;
	
};



