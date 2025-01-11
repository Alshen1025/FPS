// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include <InputAction.h>
#include "FPSCharacter.generated.h"


UENUM(BlueprintType)
enum class StateOfCharacterCPP : uint8
{
	Idle,
	Aimming,
	Reloading,
	Swapping,
	Running
};



UCLASS()
class AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

	UFUNCTION(BlueprintCallable)
	virtual float GetSpeedCPP() const;

	UFUNCTION(BlueprintCallable)
	virtual bool CanRunCPP() const;

	UFUNCTION(BlueprintCallable)
	virtual void TickRunCPP();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void Brightness();

	UFUNCTION(BlueprintCallable)
	virtual void OnTriggerRun(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	virtual void OnTriggerTurnPitch(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	virtual void OnTriggerTurnYaw(const FInputActionValue& Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
	StateOfCharacterCPP StateCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
	bool IsRunPressedCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadWrite)
	float MoveForwardValueCPP;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USoundBase> FootstepLeftSoundCPP;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UInputAction> RunInputAction;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UInputAction> TrunPitchInputAction;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UInputAction> TurnYawInputAction;

private:
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> ShadowBodyCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> LowerBodyCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> CameraCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> FirstPersonCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UChildActorComponent> ChildActorBackCPP;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UChildActorComponent> ChildActorHandCPP;
	
};
