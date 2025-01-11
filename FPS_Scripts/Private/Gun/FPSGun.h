// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSGun.generated.h"

UCLASS()
class AFPSGun : public AActor
{
	GENERATED_BODY() 
	
public:	
	// Sets default values for this actor's properties
	AFPSGun();

	UFUNCTION(BlueprintCallable)
	void FireBulletCPP(UClass* BulletClass, FTransform Transform);

	UFUNCTION(BlueprintCallable)
	void FireTimerCPP(float time);
	
	UFUNCTION(BlueprintCallable)
	void FireReleasedCPP();

	//BP의 Pure처럼 만드려면 const
	UFUNCTION(BlueprintCallable)
	bool IsFiringCPP() const;

	UFUNCTION(BlueprintCallable)
	void MakeRecoilCPP();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float BulletSpeedCPP;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FTimerHandle TimerCPP;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsFiredCPP;
};
